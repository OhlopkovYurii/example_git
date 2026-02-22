//Автор: Охлопков ИВТ-23

#include <iostream>
#include "CarClass2.h"
#include <fstream>
#include <string>
using namespace std;

//печатать класс
void print_car(const CarClass& car) {
    cout << car.to_my_string();
}

int main() {
    

    all_assert();

    ofstream file_in("file_in.txt");          // поток для записи

    ifstream file_out("file_out.txt");          // поток для записи
   // file.open("file.txt", ios::in); // окрываем файл для записи

    
    //массив из объектов
    // 100 раз вызван констр по умолч.
    CarClass car[100];
    

    //создание одного объекта класса
    CarClass car4;

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

    // Динамически созданный объект
    CarClass* car5 = new CarClass();

    

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

    //запись в файл
    // если файл открыт
    if (file_in.is_open())
    {
        // Перемещаем указатель записи на конец файла
        file_in.seekp(0, std::ios::end);

        for (size_t i = 0; i < 3; i++) {
            string data = car3[i]->to_my_string();
            file_in << data  << endl;
        }
        file_in.close();
    }
    cout << '\n';


 
    //чтение из файла
    // если файл открыт
    if (file_out.is_open())
    {
        while (1) {
            //записываем в сar5 кол-во владельцев
            string s;
            file_out >> s; 
            car5->set_num_owners(stoi(s));

            //записываем в сar5 пробег
            file_out >> s; 
            car5->set_mile_age(stoi(s));

            //записываем в сar5 цену
            file_out >> s; 
            car5->set_price(stoi(s));
            if (file_out.eof()) break;
            
            
        }
    }
    //вывод полей car5 
    cout << "car5"<< endl;
    
    cout <<  to_string(car5->get_num_owners()) << endl;
    cout <<  to_string(car5->get_mile_age())   << endl;
    cout <<  to_string(car5->get_price());

    //удаление объекта
    for (size_t i = 0; i < 3; i++)
        delete car3[i];


    //удаление объекта
    delete car5;

    file_out.close();
    file_in.close();

   

}