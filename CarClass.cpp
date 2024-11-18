//Автор: Охлопков ИВТ-23
#include "CarClass.h"
#include <cassert>
#include <iostream>
using namespace std;
/// конструктор по умолчанию
/// year_build1 - год сборки, mile_age1 - пробег, transmission1 - трансмиссия
/// consumption1 - расход топлива, num_owners1 - кол-во владельцев, 
/// price1 - цена, handlebar_left - руль (левый / правый)
CarClass::CarClass() {
    year_build = 1;  mile_age = 10'000; transmission = "automatic";
    consumption = 10; num_owners = 3; price = 1'000'000'000; handlebar_left = true;

}

/// конструктор с параметрами
/// year_build1 - год сборки, mile_age1 - пробег, transmission1 - трансмиссия
/// consumption1 - расход топлива, num_owners1 - кол-во владельцев, 
/// price1 - цена, handlebar_left - руль (левый / правый)
CarClass::CarClass(unsigned short year_build1, unsigned int mile_age1, const string &transmission1,
    unsigned int consumption1, unsigned int num_owners1, const unsigned long long &price1, bool handlebar_left1)
{
    //сеттеры
    set_year_build(year_build1);
    
    set_mile_age(mile_age1);

    set_transmission(transmission1);

    set_consumption(consumption1);

    set_num_owners(num_owners1);

    set_price(price1);

    set_handlebar_left(handlebar_left1);



}
///сеттер year_build1 год сборки
void CarClass::set_year_build(unsigned short year_build1)
{
    //переменная - текущее время
    time_t current_time;
    //время в сек с 1 янв 1970 г
    current_time = time(NULL);
    //текущий год
    int a;
    //31537970 секунд в 1 году
    a = 1970 + current_time / 31537970;
    
    //const auto now_year= chrono::system_clock::now();

    //проверка корректности
    if (year_build1 >= 0 && year_build1 <= a)
    {
        year_build = year_build1;

    }
    //иначе 0
    else year_build = 0;


}

///сеттер для пробега, mile_age1 - пробег
void CarClass::set_mile_age(unsigned int mile_age1)
{
  
  this->mile_age = mile_age1;

}
///сеттер для  трансмиссии, transmission1 - трансмиссия
void CarClass::set_transmission(string transmission1)
{
    //проверка
    if (transmission1 == "automatic" || transmission1 == "mechanics" || transmission1 == "robot")
    {
        this->transmission = transmission1;

    }
    else  transmission1 = "Nan";
}

///сеттер для расход, consumption1 - расход
void CarClass::set_consumption(unsigned int consumption1)
{
   
   this->consumption = consumption1;

}
///сеттер для кол-во владельцев,  num_owners1 - кол-во владельцев
void CarClass::set_num_owners(unsigned int num_owners1)
{
   
    this->num_owners = num_owners1;

}
///сеттер для цены, price1 - цена
void CarClass::set_price(unsigned long long price1)
{
    //проверка
    if (price1 >= 0)
    {
        this->price = price1;

    }
    else  price1 = 0;
}
///сеттер для руля, handlebar1 - руль (левый/правый)
void CarClass::set_handlebar_left(bool handlebar_left1)
{

   this->handlebar_left = handlebar_left1;

}
///сеттер для изменения цены, price1 -изнач. цена, discount1 - цена, на которую нужно повысить снизить цену
long int CarClass::change_price(unsigned long long &price1, long int discount1) const
{   //если скидка
    if (discount1 <= 0)
    {
        price1 = price1 - discount1;
    }
    //если повышение
    else
    {
        price1 = price1 + discount1;
    }
    return price1;
}

///Склейка строк
string CarClass::to_my_string() const
{
    //num_owners - кол-во владельцев mile_age - пробег price - цены 
    std::string s = ::to_string(num_owners) + " " + to_string(mile_age) + " " + to_string(price);
    return s;
}

void CarClass::all_assert() 
{
    //проверка assert
    int deviation = 0;
    unsigned long long a1 = 1'001'000;

    unsigned long long a2 = 100;

    unsigned long long a3 = 5'000'000;

    assert(change_price(a1, -1000) - 1'000'000 == deviation);
    assert(change_price(a2, -1000) - 0 == deviation);
    assert(change_price(a3, 1'000'000) - 6'000'000 == deviation);
}   

