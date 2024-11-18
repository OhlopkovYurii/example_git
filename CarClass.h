//Автор: Охлопков ИВТ-23

#pragma once
#include <string>
#include <chrono>
using namespace std;
/// Класс Автомобиль
class CarClass{
//Закрытый доступ
private:
    ///год сборки
    unsigned short year_build;
    ///пробег
    unsigned int mile_age;
    ///трансмиссия
    string transmission;
    ///расход топлива
    unsigned int consumption;
    ///кол-во владельцев
    unsigned int num_owners;
    ///цена
    unsigned long long price;
    ///руль (левый / правый)
    bool handlebar_left;

//открытый доступ
public:

    /// конструктор по умолчанию
    CarClass();

    /// конструктор с параметрами
    /// year_build1 - год сборки, mile_age1 - пробег, transmission1 - трансмиссия
    /// consumption1 - расход топлива, num_owners1 - кол-во владельцев, 
    /// price1 - цена, handlebar_left - руль (левый / правый)
    CarClass(unsigned short year_build1, unsigned int mile_age1, const string &transmission1,
        unsigned int consumption1, unsigned int num_owners1, const unsigned long long &price1,
        bool handlebar_left);
    
    ///цвет
    string color;
    ///модель
    string model;
    //продавец
    string seller;
    ///покупатель
    string buyer;
   

    ///получение года сборка
    unsigned short get_year_build() const;
    ///получение пробега
    unsigned int get_mile_age() const;
    ///получение трансмиссии
    string get_transmission() const;
    ///получение расхода топлива
    unsigned int get_consumption() const;
    ///получение кол-ва владельцев
    unsigned int get_num_owners() const;
    ///получение цены
    unsigned int get_price() const;
    ///получение руля
    string get_handlebar_left() const;

    



    ///сеттеры
    ///для год сборки
    void set_year_build(unsigned short year_build1);
    ///для пробега
    void set_mile_age(unsigned int mile_age1);
    ///для  трансмиссии
    void set_transmission(string transmission1);
    ///для расхода топлива
    void set_consumption(unsigned int consumption1);
    ///для кол-ва владельцев
    void set_num_owners(unsigned int num_owners1);
    ///для  цены
    void set_price(unsigned long long price1);
    /// для руля
    void set_handlebar_left(bool handlebar_left1);

   

    ///метод изменение цены, price1 -изнач. цена, discount1 - цена, на которую нужно повысить снизить цену
    long int change_price(unsigned long long &price1, long int discount1) const;
    ///метод склеивание текста
    string to_my_string() const;
    //Проверка assert'ов
    void all_assert();
};