#include "inheritance.h"
///класс транспорт, наследуется от Абстрактного класса - средства транспортировки
Transport::Transport() {}

///конструктор с параметрами
/// string name1, - название ТС
/// unsigned short year_build1,  - год сборки
/// unsigned int mile_age1, - пробег
/// unsigned int consumption1,  - расход топлива
/// const unsigned long long& price1, - цена
/// unsigned int average_speed1 - ср.скорость
Transport::Transport(string name1, unsigned short year_build1, unsigned int mile_age1,
    unsigned int consumption1, const unsigned long long& price1,
    unsigned int average_speed1)
{
    name = name1;
    year_build = year_build1;
    mile_age = mile_age1;
    consumption = consumption1;
    price = price1;
    average_speed = average_speed1;




}

///сеттер name1 - имя
void Transport::set_name(string name1)
{
    this->name = name1;
}

///сеттер year_build1 год сборки
void Transport::set_year_build(unsigned short year_build1)
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
void Transport::set_mile_age(unsigned int mile_age1)
{

    this->mile_age = mile_age1;

}

///сеттер для расход, consumption1 - расход
void Transport::set_consumption(unsigned int consumption1)
{

    this->consumption = consumption1;

}

///сеттер для цены, price1 - цена
void Transport::set_price(unsigned long long price1)
{
    //проверка
    if (price1 >= 0)
    {
        this->price = price1;

    }
    else  price1 = 0;
}

///сеттер - изменение ср.скорости,average_speed1 - ср.скорость
void Transport::set_average_speed(unsigned int average_speed1)
{
    this->average_speed = average_speed1;
}

///получение имени
string Transport::get_name() const { return name; };

///сеттер year_build1 год сборки
unsigned short Transport::get_year_build() const { return year_build; }

///сеттер для пробега, mile_age1 - пробег
unsigned int Transport::get_mile_age() const { return mile_age; }


///сеттер для расход, consumption1 - расход
unsigned int Transport::get_consumption() const { return consumption; }

///сеттер для цены, price1 - цена
unsigned long long Transport::get_price() const { return price; }

///получение ср.скорости
unsigned int Transport::get_average_speed() const { return average_speed; }

///конструктор по умолч.
Air::Air() {}

///конструктор с параметрами
/// string name1, - название ТС
/// unsigned short year_build1,  - год сборки
/// unsigned int mile_age1, - пробег
/// unsigned int consumption1,  - расход топлива
/// const unsigned long long& price1, - цена
/// unsigned int average_speed1 - ср.скорость
/// unsigned int flight_range1, - дальность полета
/// unsigned int flight_altitude1 - высота полета
Air::Air(string name1, unsigned short year_build1, unsigned int mile_age1,
    unsigned int consumption1, const unsigned long long& price1,
    unsigned int average_speed1, unsigned int flight_range1, unsigned int flight_altitude1)
{
    //параметры

    Transport(name1, year_build1, mile_age1,
        consumption1, price1,
        average_speed1);

    ///сеттеры
    /*set_name(name1);
    set_year_build(year_build1);
    set_mile_age(mile_age1);
    set_consumption(consumption1);
    set_price(price1);
    set_average_speed(average_speed1);*/

    flight_range = flight_range1;
    flight_altitude = flight_altitude1;
}



///сеттер изменение дальности полета, flight_range1 - дальность полета
void Air::set_flight_range(unsigned int flight_range1)
{
    flight_range = flight_range1;
}
///сеттер изменение высоты полета, flight_altitude1 - высота полета
void Air::set_flight_altitude(unsigned int flight_altitude1)
{
    flight_altitude = flight_altitude1;
}

///получение дальности полета
unsigned int Air::get_flight_range() const
{
    return flight_range;
}

///получение высоты полета
unsigned int Air::get_flight_altitude() const
{
    return flight_altitude;
}

///конструктор по умолчанию

Land::Land() {}

///конструктор с параметрами
/// string name1, - название ТС
/// unsigned short year_build1,  - год сборки
/// unsigned int mile_age1, - пробег
/// unsigned int consumption1,  - расход топлива
/// const unsigned long long& price1, - цена
/// unsigned int average_speed1 - ср.скорость
/// string transmission1 - трансмиссия
/// unsigned short number_of_wheels1 - кол-во колес
Land::Land(string name1, unsigned short year_build1, unsigned int mile_age1,
    unsigned int consumption1, const unsigned long long& price1,
    unsigned int average_speed1, string transmission1, 
    unsigned short number_of_wheels1)

{
    ///сеттеры
    Transport(name1, year_build1, mile_age1,
        consumption1, price1,
        average_speed1);

    transmission = transmission1;
    number_of_wheels = number_of_wheels1;

}



///изменение трансмиссии transmission1 - трансмиссиия
void Land::set_transmission(string transmission1)
{

    transmission = transmission1;
}


///изменение кол-ва колес
void Land::set_number_of_wheels(unsigned short number_of_wheels1)
{

    number_of_wheels = number_of_wheels1;
}

///получение трансмиссии
string Land::get_transmission()
{

    return transmission;
}

///получение кол-ва колес
unsigned short Land::get_number_of_wheels()
{

    return number_of_wheels;
}


///печать информации об объектах, находящихся в массиве, vector<Transport*> arr - массив указателей на объекты
void print_means_transportation(vector<Transport*> arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i]->to_string();
    }
}

///метод - ремонт
void repair()
{
    cout << "Transport is repair";
}

///метод - ремонт, name1 - название ТС
void repair(string name1)
{
    cout << name1 + " is repair";
}

void all_assert()
{
    //объект класса воздушные транспортные средства
    Air A;

    ///проверка сеттера и геттера name
    {
        A.set_name("Plane");
        assert(A.get_name() == "Plane");

        A.set_name("");
        assert(A.get_name() == "");

        A.set_name("123");
        assert(A.get_name() == "123");

    }



    ///проверка ср. скорости UINT_MAX - макс. число типа unsigned int
    {
        A.set_average_speed(300);
        assert(A.get_average_speed() == 300);

        A.set_average_speed(UINT_MAX + 1);
        assert(A.get_average_speed() == 0);

        A.set_average_speed(-1);
        assert(A.get_average_speed() == UINT_MAX);
    }

    ///проверка года сборки USHRT_MAX - макс. число unsigned short
    {
        A.set_year_build(-1);
        assert(A.get_year_build() == 0);

        A.set_year_build(USHRT_MAX + 1);
        assert(A.get_year_build() == 0);

        A.set_year_build(2005);
        assert(A.get_year_build() == 2005);
    }

    ///проверка пробега UINT_MAX - макс. число типа unsigned int
    {
        A.set_mile_age(-1); 
        assert(A.get_mile_age() == UINT_MAX);

        A.set_mile_age(UINT_MAX + 1);
        assert(A.get_mile_age() == 0);

        A.set_mile_age(100);
        assert(A.get_mile_age() == 100);
    }

    ///проверка расхода топлива UINT_MAX - макс. число типа unsigned int
    {
        A.set_consumption(-1); 
        assert(A.get_consumption() == UINT_MAX);

        A.set_consumption(UINT_MAX + 1);
        assert(A.get_consumption() == 0);

        A.set_consumption(100);
        assert(A.get_consumption() == 100);
    }

    ///проверка цены  ULLONG_MAX - макс. число unsigned long long
    {
        A.set_price(-1); 
        assert(A.get_price() == ULLONG_MAX);

        A.set_price(ULLONG_MAX + 1);
        assert(A.get_price() == 0);

        A.set_price(100);
        assert(A.get_price() == 100);
    }

    ///проверка дальность полета UINT_MAX - макс. число типа unsigned int
    {
        A.set_flight_range(-1); 
        assert(A.get_flight_range() == UINT_MAX);

        A.set_flight_range(UINT_MAX + 1);
        assert(A.get_flight_range() == 0);

        A.set_flight_range(100);
        assert(A.get_flight_range() == 100);
    }

    ///проверка высота полета UINT_MAX - макс. число типа unsigned int
    {
        A.set_flight_altitude(-1); 
        assert(A.get_flight_altitude() == UINT_MAX);

        A.set_flight_altitude(UINT_MAX + 1);
        assert(A.get_flight_altitude() == 0);

        A.set_flight_altitude(100);
        assert(A.get_flight_altitude() == 100);
    }

    ///проверка to_string()
    {
        //1-я проверка
        A.set_name("Plane");
        A.set_year_build(2010);
        A.set_mile_age(100);
        A.set_consumption(100);
        A.set_price(10'000'000);
        A.set_average_speed(300);
        A.set_flight_range(1000);
        A.set_flight_altitude(10'000);

        assert(A.to_string() == "Air Transport\nНазвание: Plane\nгод сборки: 2010\nПробег: 100\nРасход топлива: 100\nЦена: 10000000\nСредняя скорость: 300\nДальность полёта: 1000\nВысота полета: 10000");
                                   

        //2-я проверка 
        A.set_name("Plane");
        A.set_year_build(2030); 
        A.set_mile_age(-1); //UINT_MAX
        A.set_consumption(-1);
        A.set_price(ULLONG_MAX + 1);
        A.set_average_speed(UINT_MAX + 1);
        A.set_flight_range(-1);
        A.set_flight_altitude(UINT_MAX + 1);

        assert(A.to_string() == "Air Transport\nНазвание: Plane\nгод сборки: 0\nПробег: 4294967295\nРасход топлива: 4294967295\nЦена: 0\nСредняя скорость: 0\nДальность полёта: 4294967295\nВысота полета: 0");
      


           
    }

    

    


    
}