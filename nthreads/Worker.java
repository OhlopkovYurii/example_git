//Охлопков ИВТ_23

package com.example.demo1;

import java.util.Arrays;
import java.util.Random;
import java.util.function.DoubleConsumer;

/// класс, отвечающий за сортировку массива, его заполнение
public class Worker {

    public static int n = 1; //кол-во эл-тов
    private int[] arr;  //массив
    ///volatile используется для того, чтобы изменения, вносимые в переменную, были немедленно видны всем потокам
    public volatile boolean stop = false; //для остановки вычислений


    ///констуктор с парметром - кол-во эл-тов массива
    Worker(int n1) {
        n = Math.max(n1, 1);
    }

    ///DoubleConsumer стандартный функциональный интерфейс из пакета java.util.function
    ///Он представляет собой функцию, которая принимает один аргумент типа double, но не возвращает никакого значения
    ///runWithProgress ожидает любой объект, у которого есть метод accept(double) с возвращаемым типом void
    public void runWithProgress(DoubleConsumer progressUpdater) {
        stop = false;
        arr = full_rand_array(n);

        if (stop) return;

        arr = bubbleSortWithProgress(arr, progressUpdater);
    }


    /// сортировка пузырьком с отслеживанием прогресса
    /// //DoubleConsumer стандартный функциональный интерфейс из пакета java.util.function
    /// Он представляет собой функцию, которая принимает один аргумент типа double, но не возвращает никакого значения
    /// source - исходный массив
    private int[] bubbleSortWithProgress(int[] source, DoubleConsumer progressUpdater) {
        int[] sorted = Arrays.copyOf(source, source.length);
        int n = sorted.length;

        for (int i = 0; i < n; i++) {
            if (stop) return sorted;

            for (int j = 0; j < n - i - 1; j++) {
                if (stop) return sorted;

                if (sorted[j] > sorted[j + 1]) {
                    int temp = sorted[j];
                    sorted[j] = sorted[j + 1];
                    sorted[j + 1] = temp;
                }
            }

            // Обновляем прогресс
            if (progressUpdater != null) {
                double progress = (i + 1.0) / n;
                progressUpdater.accept(progress);
            }
        }
        return sorted;
    }

    /// Обычная сортировка пузырьком без прогресса
    ///    arr - исходный массив
    public static int[] bubbleSort(int[] arr) {
        int[] sorted = Arrays.copyOf(arr, arr.length);
        int n = sorted.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (sorted[j] > sorted[j + 1]) {
                    int temp = sorted[j];
                    sorted[j] = sorted[j + 1];
                    sorted[j + 1] = temp;
                }
            }
        }
        return sorted;
    }


    /// заполнение массива ранжомными числами
    /// n - кол-во эл-тов
    public static int[] full_rand_array(int n) {
        Random random = new Random();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = random.nextInt(100) + 1;
        }
        return arr;
    }


    /// копирование массива arr
    public void setArray(int[] arr) {
        //clone() создаёт новый экземпляр класса текущего объекта и инициализирует все его поля значениями соответствующих полей этого объекта
        this.arr = arr.clone();
    }

    ///геттер - возвращает массив
    public int[] getResult() {
        return arr;
    }
}