//Охлопков ИВТ-23

package com.example.threads_pool;


/// класс для работы с массивом
public class Worker implements Runnable {
    private final int[] array;       // общий массив
    private final int start;         // начальный индекс
    private final int end;           // конечный индекс
    private final SharedData shared; // общая сумма
    private final StopFlag stopFlag; // флаг остановки

    /// конструктор с параметрами
    /// int[] array, целочислен массив
    /// int start, нач индекс чанка
    /// int end,  конеч индекс чанка
    /// SharedData shared,  - ссылка на объект класса для хранения общей суммы
    /// StopFlag stopFlag - ссылка на объект класса-флага остановки
    public Worker(int[] array, int start, int end, SharedData shared, StopFlag stopFlag) {
        this.array = array;
        this.start = start;
        this.end = end;
        this.shared = shared;
        this.stopFlag = stopFlag;
    }

    @Override
    /// метод запуска подсчета суммы для части массива
    public void run() {
        long partialSum = 0;
        for (int i = start; i < end; i++) {
            // проверяем флаг остановки на каждой итерации
            if (stopFlag.isStopped()) {
                return;   // завершаем поток досрочно
            }
            partialSum += array[i];
        }
        shared.add(partialSum);
    }
}

// Класс для хранения общей суммы
class SharedData {
    private long totalSum = 0;

    //synchronized чтобы обеспечить, чтобы к методу одновременно имел доступ только один поток
    public synchronized void add(long value) {
        totalSum += value;
    }

    public long getTotalSum() {
        return totalSum;
    }

    public void reset() {
        totalSum = 0;
    }
}

// Класс-флаг для остановки
class StopFlag {
    //volatile обеспечивает видимость изменений значения stopped между потоками
    private volatile boolean stopped = false;

    public void stop() {
        stopped = true;
    }

    public boolean isStopped() {
        return stopped;
    }

    public void reset() {
        stopped = false;
    }
}