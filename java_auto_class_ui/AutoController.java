/// Автор: Охлопков Юрий ИВТ-23

package com.example.demo1;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

//для current_year
import java.net.URL;
import java.time.Year;
import java.util.ResourceBundle;

/// Класс-контроллер
public class AutoController implements Initializable {
    @FXML
    //текст.поле - кол-во владельцев авто
    public TextField Edit_num_owner;
    //текст.поле - пробег
    public TextField edit_mile_age;
    //текст.поле - цена
    public TextField edit_price;
    //текст.поле - год сборки
    public TextField edit_year_build;
    //текст.поле - расход топлива
    public TextField edit_consumption;
    //текст. область для вывода параметров авто
    public TextArea area_parameters;

    //текст.поле - трансмиссия
    public TextField edit_transmission;
    //текст.поле - руль
    public TextField edit_handlebar;
    //метка - данные введены некорректно
    @FXML
    public Label Label_message_error;

    //текущий год
    public static int currentYear = Year.now().getValue();

    //кнопка выхода
    public Button button_exit;

    //кнопка об авторе
    public Button button_about_author;


    @FXML
    /// обработкик события - нажатие на кнопку "Собрать данные"
    protected void onButtonCalc() {
        if ( Check() )
        {
            //создаем экземпляр класса Auto, записываем в конструктор данные с формы
            Auto_class Auto = new Auto_class(
                    Float.parseFloat(edit_mile_age.getText()),
                    Float.parseFloat(edit_consumption.getText()),
                    Integer.parseInt(edit_year_build.getText()),
                    Integer.parseInt(Edit_num_owner.getText()),
                    Auto_class.mile_age_in_year(Float.parseFloat(edit_mile_age.getText()),Integer.parseInt(edit_year_build.getText()),currentYear),
                    Long.parseLong(edit_price.getText()),
                    edit_transmission.getText(),
                    edit_handlebar.getText());

            //загружаем параметры авто в текст.область
            area_parameters.setText(Auto.to_string());
        }


    }


    ///проверка ввода пробега
    boolean Check_Mile_age()
    {
        //берем введенную строку в поле пробег
        String s = edit_mile_age.getText();
        //если она пустая
        if (s == null || s.isEmpty())
        {
            //показываем сообщение об ошибке
            Label_message_error.setVisible(true);
            return false;
        }

        //цикл по символам строки
        for (int i = (s.charAt(0) == '-') ? 1 : 0; i < s.length(); i++) {
            // В строке найден недопустимый символ.
            if (!Character.isDigit(s.charAt(i))) {
                //показываем сообщение об ошибке
                Label_message_error.setVisible(true);
                return false;
            }
        }

        // Если мы здесь, значит, строка содержит только цифры. 🎉
        //скрываем сообщение об ошибке
        Label_message_error.setVisible(false);
        return true;

    }



    ///проверка ввода расхода топлива
    boolean Check_Consumption()
    {
        //берем введенную строку в поле пробег
        String s = edit_consumption.getText();
        //если она пустая
        if (s == null || s.isEmpty())
        {
            //показываем сообщение об ошибке
            Label_message_error.setVisible(true);
            return false;
        }
        //цикл по символам строки
        for (int i = (s.charAt(0) == '-') ? 1 : 0; i < s.length(); i++) {
            // В строке найден недопустимый символ.
            if (!Character.isDigit(s.charAt(i))) {
                //показываем сообщение об ошибке
                Label_message_error.setVisible(true);
                return false;
            }
        }

        // Если мы здесь, значит, строка содержит только цифры. 🎉
        float consumption = Float.parseFloat(s);
        //если расход топлива положителен
        if (consumption>0)
        {
            //скрываем сообщение об ошибке
            Label_message_error.setVisible(false);
            return true;
        }

        else
            return false;

    }


    ///проверка ввода года сборки
    boolean Check_Year_build()
    {
        //берем введенную строку в поле пробег
        String s = edit_year_build.getText();
        //если она пустая
        if (s == null || s.isEmpty())
        {
            //показываем сообщение об ошибке
            Label_message_error.setVisible(true);
            return false;
        }
        //цикл по символам строки
        for (int i = (s.charAt(0) == '-') ? 1 : 0; i < s.length(); i++) {
            // В строке найден недопустимый символ
            if (!Character.isDigit(s.charAt(i))) {
                //показываем сообщение об ошибке
                Label_message_error.setVisible(true);
                return false;
            }
        }
        //год сборки
        int year_build1;
        // Если мы здесь, значит, строка содержит только цифры. 🎉
        year_build1 = Integer.parseInt(edit_year_build.getText());

        //если год сборки больше текущего года или меньше 1900 года
        if (year_build1 > currentYear && year_build1 <= 1900)
        {
            //показываем сообщение об ошибке
            Label_message_error.setVisible(true);
            //делаем год сборки = 2010
            year_build1 = 2010;
            return false;
        }
        else
        {

            //скрываем сообщение об ошибке
            Label_message_error.setVisible(false);
            return true;
        }

    }


    ///проверка ввода кол-ва владельцев
    boolean Check_Num_owner()
    {
        //берем введенную строку в поле пробег
        String s = Edit_num_owner.getText();
        //если она пустая
        if (s == null || s.isEmpty())
        {
            //показываем сообщение об ошибке
            Label_message_error.setVisible(true);
            return false;
        }
        //цикл по символам строки
        for (int i = (s.charAt(0) == '-') ? 1 : 0; i < s.length(); i++) {
            // В строке найден недопустимый символ.
            if (!Character.isDigit(s.charAt(i))) {
                //показываем сообщение об ошибке
                Label_message_error.setVisible(true);
                return false;
            }
        }

        int num_owner1;
        // Если мы здесь, значит, строка содержит толькedit_mile_ageо цифры. 🎉
        //преобразуем строку в int
        num_owner1 = Integer.parseInt(Edit_num_owner.getText());
        if (num_owner1 >=0)
        {
            Label_message_error.setVisible(false);
            return true;
        }

        //скрываем сообщение об ошибке


        else
            return false;
    }






    ///проверка ввода цены
    boolean Check_Price()
    {
        //берем введенную строку в поле пробег
        String s = edit_price.getText();
        if (s == null || s.isEmpty())
        {
            //показываем сообщение об ошибке
            Label_message_error.setVisible(true);
            return false;
        }
        //цикл по символам строки
        for (int i = (s.charAt(0) == '-') ? 1 : 0; i < s.length(); i++) {
            // В строке найден недопустимый символ.
            if (!Character.isDigit(s.charAt(i))) {
                //показываем сообщение об ошибке
                Label_message_error.setVisible(true);
                return false;
            }
        }

        long price1;
        // Если мы здесь, значит, строка содержит только dit_mile_ageо цифры. 🎉
        //преобразуем строку в int
        price1 = Integer.parseInt(edit_price.getText());
        //если цена положительна
        if (price1>0)
        {


            //скрываем сообщение об ошибке
            Label_message_error.setVisible(false);
            return true;
        }
        else
            return false;

    }





    ///провекра ввода трансмиссии
    boolean Check_Data_transmission()
    {

        String s = edit_transmission.getText();

        if (s.equals("Механика") || s.equals("механика") || s.equals("Mechanic") || s.equals("mechanic") |
                s.equals("Автомат") || s.equals("автомат") || s.equals("automat") || s.equals("Automat") |
                s.equals("Робот") || s.equals("робот") || s.equals("robot") || s.equals("Robot"))
        {
            return true;
        }
        else {
            //показываем сообщение об ошибке
            Label_message_error.setVisible(true);
            return false;
        }
    }



    ///проверка ввода типа руля
    boolean Check_Data_handlebar()
    {

        String s = edit_handlebar.getText();

        if (s.equals("-") || (s.equals("Левый")) || (s.equals("левый")) || (s.equals("Left")) || (s.equals("left")) ||
                (s.equals("Правый")) || (s.equals("правый")) || (s.equals("right")) || (s.equals("Right")))

        {
            return true;
        }
        else {
            //показываем сообщение об ошибке
            Label_message_error.setVisible(true);
            return false;
        }
    }

    /// общая проверка ввода
    boolean Check()
    {
        if (Check_Num_owner() & Check_Price() & Check_Consumption() & Check_Data_handlebar() &
        Check_Data_transmission() & Check_Mile_age() &
          Check_Year_build())
            return true;
        else {
            Label_message_error.setVisible(true);
            return false;
        }
    }



    /// обработчик события - выход из программы
    public void onButtonExit(ActionEvent actionEvent) {
        System.exit(0);
    }

    /// обработчик события - показать инф-цию об авторе
    public void onButtonAuthor(ActionEvent actionEvent) {
        button_about_author.setText("Охлопков\n   Юрий");

    }

    @Override
    /// метод, который вызывается для инициализации контроллера после полной обработки его корневого элемента в JavaFX
    /// url — местоположение файла FXML, или null, если местоположение не известно
    /// resources — ресурсы, используемые для локализации корневого объекта, или null, если корневой объект не локализован
    public void initialize(URL url, ResourceBundle resourceBundle) {
        //вызов ассертов
        Auto_class.all_assert();
    }
}