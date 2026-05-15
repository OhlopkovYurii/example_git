//Охлопков ИВТ-23


/*
Пул потоков — это набор предварительно созданных потоков многократного использования, которые всегда готовы к выполнению задач. Вместо того чтобы создавать новый поток каждый раз, когда нужно что-то запустить (что требует больших затрат памяти и ресурсов процессора), пул потоков поддерживает фиксированное количество потоков. При отправке задачи:

Если поток свободен, он сразу же берет задачу на себя и выполняет ее.
Если все потоки заняты, задача ожидает в очереди, пока не освободится один из потоков.
После выполнения задачи поток не завершает работу. Он возвращается в пул и ожидает следующей задачи.
https://www.geeksforgeeks.org/java/thread-pools-java/


 */

package com.example.threads_pool;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

import java.util.Random;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

/// класс Контроллер
public class Controller {

    /// кол-во потоков
    @FXML private TextField num_threads;
    /// кол-во эл-тов в массиве
    @FXML private TextField num_elem;
    /// поле для вывода массива
    @FXML private TextArea area_old;
    /// поле для вывода результата
    @FXML private TextArea area_new;

    ///ссылка на объект типа ExecutorService, который управляет асинхронным выполнением задач с использованием пулов потоков
    private ExecutorService currentPool;
    ///ссылка на объект типа класс для хранения общей суммы
    private SharedData shared;
    /// ссылка на объект типа Класс-флаг для остановки
    private StopFlag stopFlag;

    /// создание массива размера size (эл-т от 0 до 99)
    private int[] generateArray(int size) {
        int[] arr = new int[size];
        Random rand = new Random();
        for (int i = 0; i < size; i++) {
            arr[i] = rand.nextInt(100);
        }
        return arr;
    }

    /// вывод первых 20 элементов массива arr
    private String arrayToString(int[] arr) {
        /*
        StringBuilder — класс в Java, который представляет изменяемую последовательность символов.
        В отличие от неизменяемого класса String, StringBuilder позволяет модифицировать содержимое без создания новых объектов,
        что делает его более эффективным в плане использования памяти при частых изменениях строк
         */
        StringBuilder sb = new StringBuilder();
        int len = Math.min(20, arr.length);
        for (int i = 0; i < len; i++) {
            sb.append(arr[i]).append(" ");
        }
        if (arr.length > 20) sb.append("...");
        return sb.toString();
    }

    @FXML
    /// запуск пула потоков
    public void run_here(ActionEvent event) {

        //проверка ввода данных
        int threadsCount;
        int arraySizeMillions;
        try {
            threadsCount = Integer.parseInt(num_threads.getText());
            arraySizeMillions = Integer.parseInt(num_elem.getText());
            if (threadsCount < 1) threadsCount = 1;
            if (arraySizeMillions < 1) arraySizeMillions = 1;
        } catch (NumberFormatException e) {
            area_new.setText("введите целые числа");
            return;
        }


        final int finalThreadsCount = threadsCount;
        final int finalArraySizeMillions = arraySizeMillions;


        //Класс Thread — основной инструмент для работы с потоками в Java
        Thread waiter = new Thread(() -> {
            int arraySize = finalArraySizeMillions * 1_000_000;  // переводим млн в реальный размер

            // сброс флага остановки
            stopFlag = new StopFlag();
            // создаём массив
            int[] array = generateArray(arraySize);

            shared = new SharedData();

            area_old.setText("Массив (первые 20 элементов):\n" + arrayToString(array) +
                    "\nРазмер: " + arraySize + " элементов\nПотоков: " + finalThreadsCount);
            area_new.setText("Вычисление суммы... (нажмите 'Остановить' для прерывания)");

            // засекаем время
            long startTime = System.nanoTime();


        /*
        Метод newFixedThreadPool в классе Executors в Java создаёт пул потоков с фиксированным количеством потоков
         */
            currentPool = Executors.newFixedThreadPool(finalThreadsCount);

            // Делим массив на части (чанки)
        /*
        Чанки — это логические блоки данных или кода,
        на которые разбивают большие объёмы информации для более эффективной обработки, передачи или хранения.
         */
            int chunkSize = arraySize / finalThreadsCount;
            for (int i = 0; i < finalThreadsCount; i++) {
                int start = i * chunkSize;
                int end = (i == finalThreadsCount - 1) ? arraySize : start + chunkSize;
                Worker worker = new Worker(array, start, end, shared, stopFlag);
                //submit ставит задачу worker в очередь пула
                currentPool.submit(worker);
            }

            // завершаем приём новых задач
            currentPool.shutdown();

            

            try {
                // Ждём, пока все потоки закончат, или пока не пройдёт таймаут (проверяем каждые 100 мс)
                //запущенные и стоящие в очереди задачи еще выполняются. awaitTermination заставляет программу ждать их завершения определенное время
                //TimeUnit.MILLISECONDS - единица измерения
                //возвращает true — если пул успел завершиться
                while (!currentPool.awaitTermination(100, TimeUnit.MILLISECONDS)) {
                    if (stopFlag.isStopped()) {
                        // принудительно завершаем пул
                        currentPool.shutdownNow();
                        break;
                    }
                }
                long endTime = System.nanoTime();
                double seconds = (endTime - startTime) / 1_000_000_000.0;
                long sum = shared.getTotalSum();
                String result;
                if (stopFlag.isStopped()) {
                    result = "Остановлено пользователем.\nЧастичная сумма = " + sum + "\nВремя = " + seconds + " сек";
                } else {
                    //% - начало плейсхолдера d - десятич число
                    result = String.format("Сумма всех элементов = %d\nВремя = %.3f секунд", sum, seconds);
                    System.out.printf("Потоков: %d, размер: %d, сумма: %d, время: %.3f сек\n",
                            finalThreadsCount, arraySize, sum, seconds);
                }
                final String finalResult = result;

                //Platform.runLater ожидает объект типа Runnable. Это функциональный интерфейс, у которого есть только один метод void run()
                //ставь в очередь на выполнение в UI-поток, передаем задачу главному потоку, не блокируя фоновый поток
                    Platform.runLater(() -> area_new.setText(finalResult));
            } catch (InterruptedException e) {
                Platform.runLater(() -> area_new.setText("Прервано"));
            }
        });
        // Помечает поток как демон-поток или пользовательский поток.
        //Поток демона - это фоновый поток в Java, который поддерживает пользовательские потоки и
        // не препятствует JVM после завершения всех пользовательских потоков.
        waiter.setDaemon(true);
        waiter.start();
    }

    @FXML
    /// остановка пула потоков
    public void stop(ActionEvent event) {
        if (stopFlag != null) {
            stopFlag.stop();
        }
        if (currentPool != null && !currentPool.isShutdown()) {
            currentPool.shutdownNow();
        }
        area_new.setText("Остановка...");
    }
}