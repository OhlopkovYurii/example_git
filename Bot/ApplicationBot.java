/// Автор: Охлопков Юрий ИВТ-23


/// Все классы в Java наследуются от класса Object.
/// Класс Object является корневым классом и предоставляет базовые методы,
/// такие как toString(), hashCode() и equals(), которые доступны для всех объектов в Java
///

package com.example.simplebot;

import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;


public class ApplicationBot extends javafx.application.Application {
    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(ApplicationBot.class.getResource("main_window.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 467, 604);
        stage.setTitle("Chatter");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}