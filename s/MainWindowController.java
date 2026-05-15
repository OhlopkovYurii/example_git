//Охлопков ИВТ_23

package com.example.demo;

import javafx.application.Platform;
import javafx.concurrent.Task;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.ProgressBar;
import javafx.scene.control.TextArea;
import java.util.Arrays;
import java.util.function.DoubleConsumer;

public class MainWindowController {

    //поле для вывода старого массива
    @FXML TextArea area_old;
    //поле для вывода нового массива
    @FXML TextArea area_new;
    //компонент показывает прогресс вычислений
    @FXML ProgressBar progressBar;

    //кол-во эл-тов массива
    private static int N = 100_000;
    //объект класса Worker
    private Worker w = new Worker(N);

    // метод запуск. основной поток
    public void run_here(ActionEvent mouseEvent) {
        progressBar.setProgress(0.0);

        int[] arr = Worker.full_rand_array(N);

        area_old.setText("Old Arr:\n" + formatArray(arr));

        area_new.setText("Сортировка...");
        progressBar.setProgress(0.1);

        arr = thread_foo(arr);

        area_new.setText("Sort Arr:\n" + formatArray(arr));
        progressBar.setProgress(1.0);
    }

    //
    private static int[] thread_foo(int[] arr) {
        return Worker.bubbleSort(arr);
    }

    //запуск в отдельном потоке
    public void run_in_thread2(ActionEvent e) {
        int[] old = Worker.full_rand_array(N);

        area_old.setText("Old Arr:\n" + formatArray(old));
        area_new.setText("Сортировка...");

        //для установки текущего значения прогресса
        progressBar.setProgress(0.0);


        //Task - абстрактный класс предназначен для выполнения
        // трудоёмких операций в фоновом потоке, не блокируя при этом интерфейс пользователя
        Task<Void> task = new Task<>() {
            @Override
            protected Void call() throws Exception {
                w.setArray(old);

                //анонимный внутренний класс
                //new DoubleConsumer() - Создание анонимного объекта класса, который реализует интерфейс DoubleConsumer
                w.runWithProgress(new DoubleConsumer() {
                    @Override
                    //p - текущ прогресс
                    public void accept(double p) {
                        updateProgress(p, 1.0);
                    }
                });

                return null;
            }

            @Override
            //вывод сортированного массива и изменение состояния прогрессбар на 100%
            protected void succeeded() {
                int[] res = w.getResult();
                Platform.runLater(() -> {
                    area_new.setText("Sort Arr:\n" + formatArray(res));
                    progressBar.setProgress(1.0);
                });
            }
        };

        //Автоматически обновляет ProgressBar каждый раз, когда меняется прогресс в Task
        //progressBar.progressProperty() возвращает объект типа DoubleProperty — это свойство, которое хранит текущий прогресс
        //task.progressProperty() возвращает ReadOnlyDoubleProperty — свойство прогресса задачи, его менять нельзя
        //.bind() Создаёт однонаправленную привязку: значение progressBar.progressProperty() будет всегда равно значению task.progressProperty()
        progressBar.progressProperty().bind(task.progressProperty());

        //запуск фонового потока для выполнения задачи Task
        new Thread(task).start();
    }


    /// обработчик события - нажатие на кнопку stop
    public void stop(ActionEvent mouseEvent) {
        w.stop = true;                    // останавливаем цикл сортировки

        // Сбрасываем прогрессбар
        //метод unbind() удаляет привязку имени к объекту
        progressBar.progressProperty().unbind();
        progressBar.setProgress(0.0);

        Platform.runLater(() -> {
            area_new.setText("Сортировка остановлена");
        });
    }

    // возврат массива в виде StringBuilder, предоставляет изменяемую последовательность символов
    //    int[] arr - массив
    private String formatArray(int[] arr) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < arr.length; i++) {
            sb.append(arr[i]).append(" ");
            if ((i + 1) % 10 == 0) sb.append("\n");
        }
        return sb.toString();
    }
}