//todo: ...

//Автор: Охлопков Юрий ИВТ-23

//заголовочные файлы:

//для abs, pow
#include <cmath>
//для cout, cin
#include <iostream>
//для assert
#include <cassert>
//для exit
#include <cstdlib>
//файл модуля с ф-цией fact
#include "calc.h"


//чтобы не писать каждый раз std::cout...
using namespace std;

///главная ф-ция
int main()
{
    //погрешность
    const float acc = 0.00001;

    //тесты ф-ции fact()
    assert(fabs(fact<int>(0)- 1.0) < acc);
    assert(fabs(fact<int>(4) - 24.0) < acc);
    assert(fabs(fact<int>(10) - 3628800.0)< acc);

    //тесты ф-ции a_calc()
    assert(fabs(a_calc<int,int,int>f(2, 2, 2) - (-0.247118)) < acc);
    assert(fabs(a_calc<int, int, int>(3, 4, 5) - (1.71426)) < acc);
    assert(fabs(a_calc<int, int, int>(-2, -2, -2) - (2.61424)) < acc);

    //тесты ф-ции b_calc()
    assert(fabs(b_calc<int, int, int>(2, 2, 2) - 1.86667) < acc);
    assert(fabs(b_calc<int, int, int>(3, 4, 5) - (7.575)) < acc);
    assert(fabs(b_calc<int, int, int>(-2, -2, -2) - (-2.13333)) < acc);

    //объявление переменных 
    float x=0, y=0, z=0, a=0, b=0;

    //ввод x,y,z
    cout << "Write x\n";
    cin >> x;

    cout << "Write y\n";
    cin >> y;

    cout << "Write z\n";
    cin >> z;

    //проверка верного ввода x,y,z (нельзя найти ln(0) )
    if ((y - sqrt(abs(x))) == 0 || (x - y / (z + x * x / 4)) == 0)
    {
        
        cout << "Write other x,y,z" << endl;
        //выход из программы с успешным завершением
        exit(EXIT_SUCCESS);
    }
        
    a = a_calc<float, float, float>(x,y,z);
    b = b_calc<float, float, float>(x, y, z);

    //вывод a,b
    cout << "a = " << a << " ";
    cout << "b = " << b << endl;


}

