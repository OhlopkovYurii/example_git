/// Автор: Охлопков Юрий ИВТ-23

package com.example.demo1;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

/* Классы в Java - ссылочный тип данных.
Ссылочные типы данных в Java не содержат значения, а ссылаются на место, где они расположены. */
/// Класс приложения AutoApplication
public class AutoApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(AutoApplication.class.getResource("main_window.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 772, 468);
        stage.setTitle("Car Class");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args)
    {

        launch();
    }
}