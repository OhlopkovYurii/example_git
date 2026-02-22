#pragma once

#include<iostream>
#include<string>
#include <vector>
#include <cassert>

using namespace std;

///Абстрактный класс - средства транспортировки
class Means_transportation
{
public:
    //виртуальный метод - двигаться
    //= 0 - нет реализации, нельзя создать объект этого класса
    virtual string to_string() const = 0;
};

///класс транспорт, наследуется от Абстрактного класса - средства транспортировки
class Transport : public Means_transportation
{
private:
    ///название
    ::string name;

    ///год сборки
    unsigned short year_build;
    ///пробег
    unsigned int mile_age;

    ///расход топлива
    unsigned int consumption;

    ///цена
    unsigned long long price;
    ///ср. скорость км/ч
    unsigned int average_speed;

public:
    ///конструктор по умолчанию
    Transport();

    ///конструктор с параметрами
    /// string name1, - название ТС
    /// unsigned short year_build1,  - год сборки
    /// unsigned int mile_age1, - пробег
    /// unsigned int consumption1,  - расход топлива
    /// const unsigned long long& price1, - цена
    /// unsigned int average_speed1 - ср.скорость
    Transport(string name1, unsigned short year_build1, unsigned int mile_age1,
        unsigned int consumption1, const unsigned long long& price1,
        unsigned int average_speed1);
    
    ///метод-двигаться, переопределен от абстрактного класса Means_transportation
    void move()
    {
        cout << "Transport is moving" << endl;
    }

    ///получение информации об объекте в виде строки
    string to_string() const override
    {
        //std::string pi = "pi is " + std::to_string(3.1415926);
        string s = "Transport\nНазвание: " +  name + "\nгод сборки: " + ::to_string(year_build) + "\nПробег: "
            + ::to_string(mile_age) + "\nРасход топлива: " + ::to_string(consumption) +
            "\nЦена: " + ::to_string(price) + "\nСредняя скорость: "
            + ::to_string(average_speed) + "\n";


        return s;

    }
    ///сеттер name1 - имя
    void set_name(string name1);


    ///сеттер year_build1 год сборки
    void set_year_build(unsigned short year_build1);

    ///сеттер для пробега, mile_age1 - пробег
    void set_mile_age(unsigned int mile_age1);

    ///сеттер для расход, consumption1 - расход
    void set_consumption(unsigned int consumption1);

    ///сеттер для цены, price1 - цена
    void set_price(unsigned long long price1);

    ///сеттер - изменение ср.скорости,average_speed1 - ср.скорость
    void set_average_speed(unsigned int average_speed1);

    ///получение имени
    string get_name() const;

    ///получение года сборки
    unsigned short get_year_build() const;

    ///получение пробега
    unsigned int get_mile_age() const;


    ///получение расхода
    unsigned int get_consumption() const;

    ///получение цены, price1 - цена
    unsigned long long get_price() const;

    ///получение ср.скорости
    unsigned int get_average_speed() const;



};

///Класс - воздушные транспортные средства, наследуется от класса Транспорт
class Air : public Transport
{
private:
    //дальность полета
    unsigned int flight_range;

    //высота полета
    unsigned int flight_altitude;

public:
    ///конструктор по умолч.
    Air();

    ///конструктор с параметрами
    /// string name1, - название ТС
    /// unsigned short year_build1,  - год сборки
    /// unsigned int mile_age1, - пробег
    /// unsigned int consumption1,  - расход топлива
    /// const unsigned long long& price1, - цена
    /// unsigned int average_speed1 - ср.скорость
    /// unsigned int flight_range1, - дальность полета
    /// unsigned int flight_altitude1 - высота полета
    Air(string name1, unsigned short year_build1, unsigned int mile_age1,
        unsigned int consumption1, const unsigned long long& price1,
        unsigned int average_speed1, unsigned int flight_range1, unsigned int flight_altitude1);

    ///метод-двигаться, переопределен от абстрактного класса Means_transportation
    void move()
    {
      
        cout << "Air Transport " + get_name() + " is flying" << endl;
    }

    ///сеттер изменение дальности полета, flight_range1 - дальность полета
    void set_flight_range(unsigned int flight_range1);

    ///сеттер изменение высоты полета, flight_altitude1 - высота полета
    void set_flight_altitude(unsigned int flight_altitude1);

    ///получение дальности полета
    unsigned int get_flight_range() const;
    ///получение высоты полета
    unsigned int get_flight_altitude() const;

    ///получение информации об объекте в виде строки, переопределенный метод от Transport
    string to_string() const override
    {
        
        string s = "Air " + Transport::to_string() + "Дальность полёта: " + ::to_string(flight_range) +
            "\nВысота полета: " + ::to_string(flight_altitude);


        return s;

    }

};


///Класс - наземные транспортные средства, наследуется от класса Транспорт
class Land : public Transport
{
private:
    ///трансмиссия
    string transmission;

    //кол-во колёс
    unsigned short number_of_wheels;
public:
    ///конструктор по умолчанию
    Land();

    ///конструктор с параметрами
    /// string name1, - название ТС
    /// unsigned short year_build1,  - год сборки
    /// unsigned int mile_age1, - пробег
    /// unsigned int consumption1,  - расход топлива
    /// const unsigned long long& price1, - цена
    /// unsigned int average_speed1 - ср.скорость
    /// string transmission1 - трансмиссия
    /// unsigned short number_of_wheels1 - кол-во колес
    Land(string name1, unsigned short year_build1, unsigned int mile_age1,
        unsigned int consumption1, const unsigned long long& price1,
        unsigned int average_speed1, string transmission1, 
        unsigned short number_of_wheels1);

    ///метод-двигаться, переопределен от абстрактного класса Means_transportation
    void move()
    {
        cout << "Land Transport " + get_name() + " is coming" << endl;
    }

    ///получение информации об объекте в виде строки, переопределенный метод от Transport
    string to_string() const override
    {
               //std::string pi = "pi is " + std::to_string(3.1415926);
        string s ="Land " +  Transport::to_string() + "Трансмиссия: " + transmission +
            "\nКоличество колёс: " + ::to_string(number_of_wheels);


        return s;

    }

    ///изменение трансмиссии transmission1 - трансмиссиия
    void set_transmission(string transmission1);

   
    ///изменение кол-ва колес
    void set_number_of_wheels(unsigned short number_of_wheels1);

    ///получение трансмиссии
    string get_transmission();

    
    ///получение кол-ва колес
    unsigned short get_number_of_wheels();


};

///печать информации об объектах, находящихся в массиве
void print_means_transportation(vector<Transport*> arr);

///метод - ремонт
void repair();
///метод - ремонт, name1 - название ТС
void repair(string name1);

///проверка работы программы
void all_assert();




