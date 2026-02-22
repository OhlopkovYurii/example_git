/// Автор: Охлопков Юрий ИВТ-23


/// Все классы в Java наследуются от класса Object.
/// Класс Object является корневым классом и предоставляет базовые методы,
/// такие как toString(), hashCode() и equals(), которые доступны для всех объектов в Java
///

package com.example.simplebot;

import javafx.event.ActionEvent;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

public class Controller {
    /// кнопка отправки сообщения
    public Button Button_send;
    /// строка ввода запроса
    public TextField TextField_input;
    /// поле вывода
    public TextArea TextArea_output;
    /// экземпляр класс простой бот
    public SimpleBot Bot  = new SimpleBot();

    //поле ввода имени
    static public TextField TextField_name;





    /// обработчик события нажатие на кнопку отправки сообщения
    public void ButtonEnter(ActionEvent actionEvent) {
        SimpleBot.all_assert();
        String s = TextField_input.getText();
        //Bot.set_name(TextField_name.getText());


        //проверка
        if (s != ""){

                //добавляем сообщение пользователя в поле ввода
                TextArea_output.setText(TextArea_output.getText() + "\n" +  s);
                //добавляем сообщение чат бота в поле ввода
                TextArea_output.setText(TextArea_output.getText() + "\n" + "Chatter: "  + Bot.sayInReturn(s));

        }

        //очищение поля ввода
        TextField_input.setText("");

    }






    }
