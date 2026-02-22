//Автор: Охлопков ИВТ-23
//главный файл
#include "matrix.h"

#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    all_assert();

    //целочисленная матрица 1
    Matrix<int> m1({
           {1, 2, 3},
        {4, 5, 6},
        {7, 8, 10}
        });

    //целочисленная матрица 2
    Matrix<int> m2({
           {5, 2, 3},
           {4, 2, 6},
           {8, 8, 9},
        });

    //целочисленная матрица 3
    Matrix<int> m3;

    //столбец свобоных коэфф.
    vector<int> v6{ 66,81,159,93,64 };


    //целочисленная матрица 4
    Matrix<int> m4({
        {36, 5, 5, 2, 1},
        {4, 31, 1, 4, 4},
        {5, 3, 47, 2, 3 },
        {1, 5, 1, 39, 1},
        {3, 5, 5, 4, 28}
        });
    
   

    ///печать вектора, root_mtrx(m4, v6) - возвращает вектор - корни матрицы m4, v6 - столбец своб. коэфф
    ::cout << "Корни системы линейных уравнений матрицы m4 и столбца v6\n";
    print_vector(root_mtrx(m4, v6));
    ::cout << "\n";

    //нахождение обратной матрицы
    //печать матрицы
    //вывод определителя матрицы 1
    ::cout << "Определитель матрицы m1\n";
    ::cout << to_string(m1.determinant());
    ::cout << "\n";


    try
    {   //нахождение среднего арифм. эл-тов матрицы
        ::cout << "Среднее арифметическое эл-тов матрицы\n";
        ::cout << to_string(average_mtrx(m1));
        ::cout << "\n";
    }
    catch (const char* error_message)
    {
        ::cout << error_message << endl;
    }



    


    try
    {
        

        //умножение матрицы на число
        Matrix<int> mult_num;
        mult_num = m1 * 2;
        ::cout << "m1 * 2 = " << endl;
        mult_num.print_mtrx();

        //перемножение матриц
        ::cout << "m1 *= m2 " << endl;
        m1 *= m2;
        m1.print_mtrx();

        //перемножение матриц
        Matrix<int> mult_mtrx;
        mult_mtrx = m1 * m2;
        ::cout << "m1 * m2 = " << endl;
        mult_mtrx.print_mtrx();


        //сложение матриц, рез-т записывается в sum
        Matrix<int> sum;
        sum = m1 + m2;
        ::cout << "m1 + m2 = " << endl;
        sum.print_mtrx();

        //сложение матриц, рез-т записывается в m1
        m1 += m2;
        ::cout << "m1 += m2 = " << endl;
        m1.print_mtrx();

        //вычитание матриц, рез-т записывается в dif
        Matrix<int> dif;
        dif = m1 - m2;
        ::cout << "m1 - m2 = " << endl;
        dif.print_mtrx();

  

        //вычитание матриц, рез-т записывается в m1
        m1 -= m2;
        ::cout << "m1 -= m2 = " << endl;
        m1.print_mtrx();



    }
    catch (const char* error_message)
    {
        ::cout << error_message << endl;
    }



    


    //изменение эл-та матрицы
    m1(1, 1) = 1;

    //заполнение матрицы значением
    ::cout << "заполнение матрицы m1 значением\n";
    m1.set_mtrx_one_value(2);
    m1.print_mtrx();


    //заполнение матрицы рандомным значением
    ::cout << "заполнение матрицы рандомным значением\n";
    m1.set_mtrx_random_value(10, 20);
    m1.print_mtrx();

    //транспонирование
    ::cout << "транспонированная матрица\n";
    m1.transpose();
    m1.print_mtrx();

    //создание диагональной матрицы
    ::cout << "создание диагональной матрицы\n";
    m1.create_diagonal_matrix();
    m1.print_mtrx();


    //печать 1й строки матрицы
    ::cout << "печать 1й строки матрицы\n";
    print_len_mtrx(m1(1));
    ::cout << "\n";

    //обнуление матрицы
    ::cout << "Обнуление матрицы m1\n";
    zero_mtrx(m1);
    m1.print_mtrx();
}


