/// Автор: Охлопков Юрий ИВТ-23
package com.example.demo1;
//для abs
import java.lang.Math;

/// класс автомобиль
public class Auto_class {

    //пробег
    private static float mile_age;
    //расход топлива
    private static float consumption;
    //год сборки
    private static int year_build;
    //кол-во владельцев авто
    private static int num_owner;
    //пробег в год
    private static float mile_age_in_year;
    //цена
    private static long price;

    //трансмиссия
    private static String data_transmission;
    //руль
    private static String data_handlebar;


    /// конструктор по умолчанию
    Auto_class() {
        //пробег
        mile_age = 0;
        //расход топлива
        consumption = 0;
        //год сборки
        year_build = 2010;
        //кол-во владельцев авто
        num_owner = 0;
        //пробег в год
        mile_age_in_year = 0;
        //цена
        price = 0;
        //трансмиссия
        data_transmission = "Механика";
        //руль
        data_handlebar = "Левый";
    }



    //конструктор с параметрами
    Auto_class(
            float mile_age1,
            float consumption1,
            int year_build1,
            int num_owner1,
            float mile_age_in_year1,
            long price1,
            String data_transmission1,
            String data_handlebar1)

    {
        //сеттеры
        setMile_age(mile_age1);
        setConsumption(consumption1);
        setYear_build(year_build1);
        setNum_owner(num_owner1);
        setMile_age_in_year(mile_age_in_year1);
        setPrice(price1);

        setData_transmission(data_transmission1 );
        setData_handlebar(data_handlebar1);
    }



    /// сеттер - пробег
    /// float mile_age1 - пробег
    public void setMile_age(float mile_age1)
    {
        mile_age = mile_age1;


    }

    /// геттер для пробега
    public float getMile_age()
    {
        return mile_age;
    }

    /// сеттер расход топлива
    /// float consumption1 расход топлива
    public void setConsumption(float consumption1)
    {
        consumption = consumption1;

    }

    /// геттер для расхода топлива
    public float getConsumption()
    {
        return consumption;
    }

    /// сеттер для года сборки
    public void setYear_build(int year_build1)
    {
        year_build = year_build1;


    }

    /// геттер для года сборки
    public int getYear_build()
    {
        return year_build;
    }


    /// сеттер для кол-ва владельцев
    /// num_owner1 - кол-во владельцев
    public void setNum_owner(int num_owner1)
    {
        num_owner = num_owner1;

    }

    /// геттер для кол-ва владельцев
    public int getNum_owner()
    {
        return num_owner;
    }


    /// сеттер для пробега в год
    /// mile_age_in_year1 пробег в год
    public void setMile_age_in_year(float mile_age_in_year1)
    {
        mile_age_in_year = mile_age_in_year1;
    }


    /// геттер для пробега в год
    public float getMile_age_in_year()
    {
        return mile_age_in_year;
    }


    /// сеттер для цены
    /// price1 - цена
    public void setPrice(long price1)
    {
        price = price1;


    }


    /// геттер для цены
    public long getPrice()
    {
        return price;
    }


    /// сеттер для трансмиссии
    /// data_transmission1 - трансмиссия
    public void setData_transmission(String data_transmission1)
    {

        data_transmission = data_transmission1;

    }

    /// геттер для трансмиссии
    public String getData_transmission()
    {
        return data_transmission;
    }

    /// сеттер для руля
    /// data_handlebar1 -  руль
    public void setData_handlebar(String data_handlebar1)
    {
        data_handlebar = data_handlebar1;

    }


    ///геттер для руля
    public String getData_handlebar()
    {
        return data_handlebar;
    }


    /// функция вычисляющая пробег в год
    /// float mile_age - пробег
    /// int year_build - год сборки
    /// int currentYear - текущий год
    public static float mile_age_in_year(float mile_age, int year_build, int currentYear)
    {

        return mile_age/(currentYear - year_build);
    }


    /// метод склейки строк
    public static String to_string()
    {

//        пробег
//        mile_age

//        расход топлива
//        consumption

//        год сборки
//        year_build

//        кол-во владельцев авто
//        num_owner

//        пробег в год
//        mile_age_in_year

//        цена
//        price

//        трансмиссия
//        data_transmission

//        руль
//        data_handlebar


        return "Пробег: "+ String.valueOf(mile_age) + "\n"+
                "Пробег в год: "+ String.valueOf(mile_age_in_year) + "\n"+
                "Год сборки: "  +    String.valueOf( year_build ) + "\n"+
                "Кол-во владельцев: " + String.valueOf (num_owner)+ "\n"+
                "Цена: " + String.valueOf( price) + "\n"+
                "Расход топлива: " + String.valueOf( consumption) +"\n"+
                "Трансмиссия: " + data_transmission + "\n"+
                "Руль: " + data_handlebar;
    }

    public static  void all_assert()
    {
        //создание одного объекта класса
        Auto_class car0 = new Auto_class();

        //погрешность
        double eps = 0.000001;

        //проверка геттеров сеттеров
        //
        //
        //присвоить цену
        car0.setPrice(500000);
        assert(Math.abs(car0.getPrice() - 500000) < eps);

        //присвоить цену
        car0.setPrice(0);
        assert(Math.abs(car0.getPrice() - 0) < eps);


        //присвоить цену
        car0.setPrice(Long.MAX_VALUE);
        assert(Math.abs(car0.getPrice() - Long.MAX_VALUE) < eps);

        //присвоить руль (левый/правый)
        car0.setData_handlebar("левый");
        assert(car0.getData_handlebar() == "левый");

        car0.setData_handlebar("-");
        assert(car0.getData_handlebar() == "-");

        //присвоить трансмиссию
        car0.setData_transmission("automatic");
        assert(car0.getData_transmission() == "automatic");

        car0.setData_transmission("mechanic");
        assert(car0.getData_transmission() == "mechanic");

        car0.setData_transmission("robot");
        assert(car0.getData_transmission() == "robot");

        //to_my_string()
        //1
        car0.setMile_age(10000);
        car0.setMile_age_in_year(Math.round(mile_age_in_year(10000, 2015, AutoController.currentYear)));
        car0.setYear_build(2015);
        car0.setNum_owner(3);
        car0.setPrice(1000000);
        car0.setConsumption(12);
        car0.setData_transmission("механика");
        car0.setData_handlebar("левый");
        assert(car0.to_string() == "Пробег: 10000\nПробег в год: 1000\nГод сборки: 2015\nКол-во владельцев: 3\nЦена: 1000000\nРасход топлива: 12\nТрансмиссия: механика\nРуль: левый");

        //2
        car0.setMile_age(Float.MAX_VALUE+1);
        car0.setMile_age_in_year(Math.round(mile_age_in_year(Float.MAX_VALUE+1, Integer.MAX_VALUE+1, Integer.MAX_VALUE+1)));
        car0.setYear_build(Integer.MAX_VALUE+1);
        car0.setNum_owner(Integer.MAX_VALUE+1);
        car0.setPrice(Long.MAX_VALUE);
        car0.setConsumption(Float.MAX_VALUE);
        car0.setData_transmission("робот");
        car0.setData_handlebar("-");
        assert(car0.to_string() == "Пробег: 3.4028235E38\nПробег в год: 2.1474836E9\nГод сборки: -2147483648\nКол-во владельцев: -2147483648\nЦена: 9223372036854775807\nРасход топлива: 3.4028235E38\nТрансмиссия: робот\nРуль: -");


        //3
        car0.setMile_age(Float.MIN_VALUE-1);
        car0.setMile_age_in_year(Math.round(mile_age_in_year(Float.MIN_VALUE-1, Integer.MIN_VALUE-1, Integer.MIN_VALUE-1)));
        car0.setYear_build(Integer.MIN_VALUE-1);
        car0.setNum_owner(Integer.MIN_VALUE-1);
        car0.setPrice(Long.MIN_VALUE-1);
        car0.setConsumption(Float.MIN_VALUE-1);
        car0.setData_transmission("робот");
        car0.setData_handlebar("-");
        assert(car0.to_string() == "Пробег: -1.0\n" +
                "Пробег в год: -2.1474836E9\n" +
                "Год сборки: 2147483647\n" +
                "Кол-во владельцев: 2147483647\n" +
                "Цена: 9223372036854775807\n" +
                "Расход топлива: -1.0\n" +
                "Трансмиссия: робот\n" +
                "Руль: -");


    }

}


////
///
