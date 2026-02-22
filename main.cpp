//Автор: Охлопков ИВТ-23

#include <iostream>
#include "CarClass.h"
#include <fstream>
using namespace std;

//печатать класс
void print_car(const CarClass& car) {
    cout << car.to_my_string();
}

int main() {

    all_assert();
    ofstream out;          // поток для записи
    file.open("file.txt"); // окрываем файл для записи

    

    // 100 раз вызван констр по умолч.
    CarClass car[100];
    

    //присвоение цены
    car[4].set_price(500'000);
    // cout << car[4].to_string();

    //дин массив из объектов
    // 200 раз вызван констр по умолч.
    CarClass *car2 = new CarClass[200];    

    //присвоение цены
    car2[4].set_price(500'000);
    // cout << car2[4].to_string();

    // delete[] car2;



    // массив из указателей на объекты
    CarClass* car3[3];      // объекты не созданы

    //создание одного объекта класса
    CarClass car4;
    //присвоить цену
    car4.set_price(500'000);



    // year_build1 - год сборки, mile_age1 - пробег, transmission1 - трансмиссия
    // consumption1 - расход топлива, num_owners1 - кол-во владельцев, 
    // price1 - цена, handlebar_left - руль (левый / правый)
    //присвоение параметров
    for (size_t i = 0; i < 3; i++) {
        car3[i] = new CarClass(rand() % 20, rand() % 50'000,"automatic", rand() % 10, rand() % 5, rand() % 1'000'000, true);
        

        cout << car3[i]->to_my_string() << "\n";
    }

    // если файл открыт
    if (file.is_open())
    {
        file >> car3[i]->to_my_string() << "\n";
    }



    //удаление объекта
    for (size_t i = 0; i < 3; i++)
        delete car3[i];

    file.close();

}