//для кодировки
#include <windows.h>
#include "inheritance.h"
int main()
{
    srand(time(NULL));
    //для кодировки
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //проверка
    all_assert();
    
    
    
    
    //создание объекта класса Транспорт
    Transport ship("ship", 2010, 1000, 20, 1'000'000, 40);
    //вывод информации об объекте
    cout << ship.to_string();
    //вызов метода move - двигаться
    ship.move();

    //создание объекта класса Воздушный Транспорт
    Air plane("plane", 2010, 1000, 20, 1'000'000, 40, 10'000, 10'000);
    //вывод информации об объекте
    cout << plane.to_string();
    //вызов метода move - двигаться
    plane.move();

    //создание объекта класса Наземный Транспорт
    Land car("car", 2010, 1000, 20, 1'000'000, 40, "automatic",  4);
    Land car2("car2", 2010, 1000, 20, 1'000'000, 40, "automatic", 4);
    cout << car.to_string();
    ///Вызов метода move из производного класса Land
    car.move();
    ///Вызов метода move из базового класса Transport
    car2.Transport::move();

    //     !!!! ship : "Transport [10]" отличается по уровням косвенного обращения от "Transport"	inheritance	D : \студенчество\3 семестр\ООП\inheritance\inheritance\main.cpp	28

    // массивы
    ///Transport ship[10];
    Air planes[15];
    Land cars[20];

    //массив из указателей на объекты класса Транспортные средства
    Transport* Means_transportation[45];

    //класс Transport стал иметь указатели на его объекты
    for (size_t i = 0; i < 10; i++)
    {
        Means_transportation[i] = new  Transport("ship", rand() % 10 + 5, 1 + rand() % 1000, 1 + rand() % 20, 1'000'000 + rand() % 10'000'000,
            1 + rand() % 10);
    }
    //класс Air стал иметь указатели на его объекты
    for (size_t i = 10; i < 25; i++)
    {
        Means_transportation[i] = new  Air("plane", rand() % 10 + 5, 1 + rand() % 1000, 1 + rand() % 20, 1'000'000 + rand() % 10'000'000,
            1 + rand() % 10, 100 + rand() % 10'000, 100 + rand() % 10'000);
    }

    //класс Land стал иметь указатели на его объекты
    for (size_t i = 25; i < 45; i++)
    {
        Means_transportation[i] = new  Land("car", rand() % 10 + 5, 1 + rand() % 1000, rand() % 20, 1'000'000 + rand() % 10'000'000,
            1 + rand() % 10, "mechanic", rand() % 10);
    }

    //вывод информации об всех объектах массива
    for (size_t i = 0; i < 45; i++)
    {
        cout << Means_transportation[i]->to_string();
    }

    //массив - вектор из указателей на объекты класса транспортные средства
    vector<Transport*> means_transportation2;
    for (size_t i = 0; i < 10; i++)
    {
        means_transportation2.push_back(new Air("plane", rand() % 10 + 5, 1 + rand() % 1000, 1 + rand() % 20, 1'000'000 + rand() % 10'000'000,
            1 + rand() % 10, 100 + rand() % 10'000, 100 + rand() % 10'000));
    }

    //вывод информации об объектах
    print_means_transportation(means_transportation2);

    //создание указателей на объекты
    Transport* t = new Transport();
    Land* l = new Land();
    Air* a = new Air();

    //присвоение типа указателю в зависимости от значения в rand() % 2
    Transport* o = (rand() % 2 == 0) ? t : l;
    //вывод информации об объекте (вызывается переопределенный метод)
    cout << o->to_string();
    cout << endl;
    //вызов метода двигаться (не виртуальный метод), всегда будет Transport is moving
    o->move(); //дин.полиморфизм не работает

    // !!!

    // ошибка	c4703	используется потенциально неинициализированная локальная 
    // переменная - указатель "o2"
    //Transport* o2;
    //switch (rand()%3){
    //
    //    case 0: o2 = t; break;
    //    case 1: o2 = l; break;
    //    case 2: o2 = a; break;
    //}
    //o2->set_name("transport");
    //cout << o2->to_string();
    //o2->move(); // дин. полиморфизм не работает

    {
        //создание указателей на объекты
        Transport* t = new Transport();
        Land* l = new Land();
        Air* a = new Air();

        //приведение типа
        Transport* o = a;

        //dynamic_cast - применяется для полиморфного приведения типов на этапе выполнения программы
        dynamic_cast<Air*> (o)->move(); //дин. полиморф работает
        o->move(); //дин. полиморф не работает
    } 

    //пример static_poly - статич. полиморфизма - перегрузка функций
    repair();
    cout << endl;
    repair("ship");
    
};
