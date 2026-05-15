//Охлопков ИВТ-23

package com.example.demo1;

import java.util.Arrays;
import java.util.Random;

/// класс отвечает за сортировку пузырьком
/// в которой отдельные потоки используют общую память
public class ParallelBubbleSorter {

    //массив
    private int[] arr;

    //размер массива
    private final int n;

    //флаг - остановка сортировки
    //volatile - модификатор переменных, гарантирует,
    // что изменения переменной в одном потоке будут немедленно видны всем другим потокам
    public volatile boolean stop = false;

    /// инициализация массива размером size
    public ParallelBubbleSorter(int size) {
        this.n = size;
        this.arr = generateRandomArray(size);
    }


    /// создание массива рамзером size из рандомных чисел
    private int[] generateRandomArray(int size) {
        Random rand = new Random();
        int[] a = new int[size];
        for (int i = 0; i < size; i++) {
            a[i] = rand.nextInt(500) + 1;
        }
        return a;
    }

    /// сортировка массива пузырьком используя numThreads потоков работающих параллельно
    ///ProgressListener Интерфейс прослушивателя для отслеживания хода передачи данных
    public void parallelBubbleSort(int numThreads, ProgressListener listener) {
        stop = false;

        for (int phase = 0; phase < n; phase++) {   // n фаз Каждая фаза выполняет один проход пузырьковой сортировки
            if (stop) return;

            Thread[] threads = new Thread[numThreads];
            int segmentSize = n / numThreads;

            //Цикл создания потоков
            for (int t = 0; t < numThreads; t++) {
                final int start = t * segmentSize;

                //последний поток забирает оставшиеся элементы
                final int end = (t == numThreads - 1) ? n : start + segmentSize;

                /*
                Effectively final переменные — это переменные, которые не имеют явного модификатора final,
                но по факту используются как неизменяемые (чтобы использовать в лямбда выражениях).
                Компилятор Java распознаёт их автоматически.
                 */
                int finalPhase = phase;
                threads[t] = new Thread(() -> {
                    //Внутренний цикл по элементам сегмента
                    for (int i = start; i < end - 1; i++) {
                        if (stop) return;
                        // Чередуем чётные и нечётные сравнения для предотвращения состояния гонки, чтобы пары не пересекались
                        if (i % 2 == finalPhase % 2) {
                            if (arr[i] > arr[i + 1]) {
                                swap(i, i + 1);
                            }
                        }
                    }
                });
                threads[t].start();
            }

            // Цикл ожидания потоков
            //  Блокируем основной поток до завершения каждого дочернего потока
            for (Thread thread : threads) {
                try {
                    thread.join();
                }
                //если текущий поток был прерван во время ожидания
                catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            if (listener != null) {
                double progress = (phase + 1.0) / n;
                //реализация метода находится не в интерфейсе, а в том месте,
                // где создаём объект слушателя p -> updateProgress(p, 1.0)
                listener.onProgress(progress);
            }
        }
    }

    /// смена 2х элементов с индексами i и j между собой в массиве
    private void swap(int i, int j) {
        synchronized (arr) {   // мьютекс
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }


    /// геттер возврат копии массива
    public int[] getArray() {
        return Arrays.copyOf(arr, arr.length);
    }

    /// остановка сортировки
    public void stop() {
        this.stop = true;
    }

    /*
    Функциональный интерфейс — это интерфейс, который содержит ровно один абстрактный метод (метод без реализации).
    Он предназначен для использования с лямбда-выражениями
     */
    ///интерфейс для обновления прогресса
    public interface ProgressListener {
        void onProgress(double progress);
    }
}