//Охлопков ИВТ-23

package com.example.demo1;

import javafx.application.Platform;
import javafx.concurrent.Task;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;

///главный контроллер
public class MainWindowController {

    ///поле для вывода старого массива
    @FXML private TextArea area_old;
    ///поле для вывода нового массива
    @FXML private TextArea area_new;
    /// прогрессбар
    @FXML private ProgressBar progressBar;

    /// кол-во потоков
    @FXML private TextField threadsField;
    /// размер массива (в млн)
    @FXML private TextField arraySizeField;
    /// метка - время
    @FXML private Label timeLabel;

    /// ссылка на объект типа Worker
    private Worker w;

    /// запуск сортировки в основной программе
    public void run_here(ActionEvent mouseEvent) {
        long startTime = System.currentTimeMillis();

        progressBar.setProgress(0.0);

        int size = Integer.parseInt(arraySizeField.getText());
        w = new Worker(size);
        int[] arr = Worker.full_rand_array(size);

        area_old.setText("Old Arr (" + size + " элементов):\n" + formatArray(arr));
        area_new.setText("Сортировка...");

        arr = Worker.bubbleSort(arr);

        long duration = System.currentTimeMillis() - startTime;

        area_new.setText("Sort Arr:\n" + formatArray(arr));
        timeLabel.setText("Время (Run Here): " + duration + " мс");
        progressBar.setProgress(1.0);
    }

    /// запуск сортировки в потоке
    public void run_in_thread2(ActionEvent e) {
        long startTime = System.currentTimeMillis();

        int size = Integer.parseInt(arraySizeField.getText());
        w = new Worker(size);
        int[] old = Worker.full_rand_array(size);

        area_old.setText("Old Arr (" + size + " элементов):\n" + formatArray(old));
        area_new.setText("Сортировка...");
        progressBar.setProgress(0.0);

        Task<Void> task = new Task<>() {
            @Override
            protected Void call() throws Exception {
                w.setArray(old);
                w.runWithProgress(p -> updateProgress(p, 1.0));
                int[] res = w.getResult();
                long duration = System.currentTimeMillis() - startTime;

                Platform.runLater(() -> {
                    area_new.setText("Sort Arr:\n" + formatArray(res));

                    timeLabel.setText("Время (Run in Thread): " + duration + " мс");
                    progressBar.setProgress(1.0);
                });
                return null;
            }
        };

        progressBar.progressProperty().bind(task.progressProperty());
        new Thread(task).start();
    }

    ///запуск сортировки в параллельных потоках
    public void runParallelBubble(ActionEvent e) {
        int numThreads = Integer.parseInt(threadsField.getText());
        int size = Integer.parseInt(arraySizeField.getText());

        ParallelBubbleSorter sorter = new ParallelBubbleSorter(size);
        int[] old = sorter.getArray();

        area_old.setText("Исходный массив (" + size + " элементов):\n" + formatArray(old));
        area_new.setText("Параллельная сортировка...");
        progressBar.setProgress(0.0);

        // Task предоставляет дополнительное состояние и наблюдаемые свойства, полезные для программирования асинхронных задач в JavaFX
        // реализация Task должна переопределять метод call() . Этот метод вызывается в фоновом потоке
        Task<Void> task = new Task<>() {
            @Override
            protected Void call() throws Exception {
                long start = System.currentTimeMillis();

                //лямбда-выражение, которое Java автоматически превращает в объект, реализующий интерфейс ProgressListener
                sorter.parallelBubbleSort(numThreads, p -> updateProgress(p, 1.0));

                long duration = System.currentTimeMillis() - start;

                Platform.runLater(() -> {
                    area_new.setText("Отсортированный массив:\n" + formatArray(sorter.getArray()));
                    timeLabel.setText("Время (Параллельно, " + numThreads + " потоков): " + duration + " мс");
                    progressBar.setProgress(1.0);
                });
                return null;
            }
        };

        //Автоматически обновляет ProgressBar каждый раз, когда меняется прогресс в Task
        //progressBar.progressProperty() возвращает объект типа DoubleProperty — это свойство, которое хранит текущий прогресс
        //task.progressProperty() возвращает ReadOnlyDoubleProperty — свойство прогресса задачи, его менять нельзя
        //.bind() Создаёт однонаправленную привязку: значение progressBar.progressProperty() будет всегда равно значению task.progressProperty()
        progressBar.progressProperty().bind(task.progressProperty());
        new Thread(task).start();
    }

    /// обработчик события - нажатие на кнопку stop
    public void stop(ActionEvent mouseEvent) {
        w.stop = true;

        // Сбрасываем прогрессбар
        //метод unbind() удаляет привязку имени к объекту
        progressBar.progressProperty().unbind();
        progressBar.setProgress(0.0);
        Platform.runLater(() -> area_new.setText("Сортировка остановлена"));
    }

    /// возврат массива в виде StringBuilder, предоставляет изменяемую последовательность символов
    ///    int[] arr - массив
    private String formatArray(int[] arr) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < arr.length; i++) {
            sb.append(arr[i]).append(" ");
            if ((i + 1) % 10 == 0) sb.append("\n");
        }
        return sb.toString();
    }
}