//Автор: Охлопков ИВТ-23
//заголовочный файл

//директива, разработанная для контроля за тем,
// чтобы конкретный исходный файл при компиляции подключался строго один раз
#pragma once

//для вектора
#include<vector>
#include <iostream>
#include <string>
//для abs
#include <cmath>
#include <cassert>




using namespace std;

//шаблон
template <typename T>

/*
Класс Матрица
*/
class Matrix
{
private:
    ///матрица
    vector<vector<T>> matrix;


public:

    //констуктор по умолчанию
    Matrix() : matrix() {}



    //конструктор с параметрами
    //matrix1 - матрица
    Matrix(const vector<vector<T>>& matrix1) : matrix(matrix1) {}
    



    ///оператор() для неконстантного элемента
    ///возвращает элемент матрицы по индексам 
    ///size_t i, size_t j - номер строки и номер столбца
    T& operator () (size_t i, size_t j) {
        return matrix[i][j];
    }


    /// оператор() для неконстантного элемента
    /// возвращает строку вектора
    /// size_t i - номер строки
    vector<T>& operator () (size_t i) {
        return matrix[i];
    }



    /// оператор() для константного элемента
    /// возвращает элемент матрицы по индексам 
    /// size_t i, size_t j - номер строки и номер столбца
    T const& operator () (size_t i, size_t j) const {
        return matrix[i][j];
    }



    ///геттер - возвращает кол-во строк матрицы
    //template <typename T>
    size_t get_rows() const {
        return matrix.size();
    }



    ///геттер - возвращает кол-во столбцов матрицы
    size_t get_cols() const {
        //если матрица не пустая
        if (matrix.empty()) {
            return 0;
        }
        return matrix[0].size();
    }


    ///сеттер - меняет кол-во строк матрицы
    ///size_t num_rows - кол-во строк
    void set_rows(size_t num_rows)
    {
        //изменение кол-ва строк матрицы
        matrix.resize(num_rows);
    }

    ///сеттер - меняет кол-во столбцов матрицы
    ///size_t num_cols - кол-во столбцов
    void set_cols(size_t num_cols)
    {
        // Изменяем размер каждого внутреннего вектора (столбцы)
        for (auto& row : matrix) {
            row.resize(num_cols);
        }
    }



    ///печать матрицы
    void print_mtrx() {
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix[0].size(); j++)
            {
                cout << fixed;
                cout.precision(2);
                cout << matrix[i][j] << "\t";

            }
            cout << '\n';
        }
    }




    ///сеттер - заполнение матрицы одним значением
    ///T data - число
    void set_mtrx_one_value(T data)
    {
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix[0].size(); j++)
            {
                matrix[i][j] = data;
            }
        }
    }


    ///сеттер - заполнение матрицы рандомным значением
    void set_mtrx_random_value(int start, int end)
    {
        srand(time(0));
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix[0].size(); j++)
            {
                matrix[i][j] = rand() % (end - start + 1) + start; // matrix[i][j] = start...end
            }
        }
    }


    ///транспонирование матрицы
    void transpose()
    {
        double t;
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = i; j < matrix[0].size(); j++)
            {
                //обмен элементами
                t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
    }




    ///создание диагональной матрицы
    void create_diagonal_matrix()
    {
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix[0].size(); j++)
            {
                if (i != j)
                    matrix[i][j] = 0;

            }
        }
    }


    ///нахождение определителя
    ///возвращает определитель
    double determinant() {
        size_t n = matrix.size(); // Получаем размер матрицы

        if (n == 0) return 0; // Если матрица пустая, возвращаем 0

        // Создаем временную матрицу типа double для вычислений
        std::vector<std::vector<double>> a(n, std::vector<double>(n));

        // Копируем элементы исходной матрицы в новую матрицу, преобразуя их к типу double
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                a[i][j] = static_cast<double>(matrix[i][j]); // Преобразуем элемент в double
            }
        }

        double det = 1.0; // Начальное значение определителя

        // Алгоритм Гаусса-Жордана для нахождения определителя
        for (size_t i = 0; i < n; ++i) {
            size_t maxRow = i; // Индекс строки с максимальным элементом в текущем столбце

            // Находим строку с максимальным значением в данном столбце
            for (size_t k = i + 1; k < n; ++k) {
                if (std::abs(a[k][i]) > std::abs(a[maxRow][i])) {
                    maxRow = k;
                }
            }

            // Если максимальный элемент близок к нулю, матрица вырождена
            if (std::abs(a[maxRow][i]) < 1e-9) return 0.0;

            // Меняем местами текущую строку и строку с максимальным элементом
            if (maxRow != i) {
                std::swap(a[i], a[maxRow]);
                det *= -1.0; // Изменение знака определителя при перестановке строк
            }

            det *= a[i][i]; // Умножаем текущий элемент на определитель

            // Приводим все элементы ниже текущего к нулю
            for (size_t k = i + 1; k < n; ++k) {
                double factor = a[k][i] / a[i][i]; // Коэффициент для вычитания
                for (size_t j = i; j < n; ++j) {
                    a[k][j] -= factor * a[i][j]; // Вычитание произведения текущей строки
                }
            }
        }

        return det; // Возвращаем найденный определитель
    }


    ///меняем строки матрицы
    ///std::vector<std::vector<T>>& matrix - матрица, строки которой меняются
    /// size_t row1 - номер строки, size_t row - номер строки
    void swap_line(size_t row1, size_t row2) {
        //используем встроенную функцию вектора
        std::swap(matrix[row1], matrix[row2]);
    }

};


///operator+  - сложение матриц
///const Matrix<T>& m1 - матрица, const Matrix<T>& m2 - матрица
///возвращает новую матрицу как результат сложения двух матриц
///если размеры матриц не совпадают, выбрасывается исключение в виде строки
template <typename T>
Matrix<T> operator+(const Matrix<T>& m1, const Matrix<T>& m2) {
    //если размер матриц не совпадает, вызываем исключение
    if (m1.get_rows() != m2.get_rows() || m1.get_cols() != m2.get_cols()) {
        throw invalid_argument("Матрицы должны быть одинакового размера");
    }
    Matrix<T> result = m1;
    ///цикл для сложения матриц 
    for (size_t i = 0; i < m1.get_rows(); ++i) {
        for (size_t j = 0; j < m1.get_cols(); ++j) {
            result(i, j) += m2(i, j);
        }
    }
    return result;
}


///operator+= - оператор для сложение исходной матрицы и другой матрицы
///результат записывается в исходную матрицу
///const Matrix<T>& m1 - матрица, const Matrix<T>& m2 - матрица
///возвращает новую исходную матрицу
///если размеры матриц не совпадают, выбрасывается исключение в виде строки
/// 
template <typename T>
Matrix<T> operator+=(Matrix<T>& m1, const Matrix<T>& m2) {
    if (m1.get_rows() != m2.get_rows() || m1.get_cols() != m2.get_cols()) {
        throw invalid_argument("Матрицы должны быть одинакового размера");
    }
    Matrix<T> result = m1;
    for (size_t i = 0; i < m1.get_rows(); ++i) {
        for (size_t j = 0; j < m1.get_cols(); ++j) {
            result(i, j) += m2(i, j);
        }
    }
    m1 = result;
    return m1;
}


///operator-  - вычитание матриц
///const Matrix<T>& m1 - матрица, const Matrix<T>& m2 - матрица
///возвращает новую матрицу как результат вычитания двух матриц
///если размеры матриц не совпадают, выбрасывается исключение в виде строки
/// 
template <typename T>
Matrix<T> operator-(const Matrix<T>& m1, const Matrix<T>& m2) {
    if (m1.get_rows() != m2.get_rows() || m1.get_cols() != m2.get_cols()) {
        throw invalid_argument("Матрицы должны быть одинакового размера");
    }
    Matrix<T> result = m1;
    for (size_t i = 0; i < m1.get_rows(); ++i) {
        for (size_t j = 0; j < m1.get_cols(); ++j) {
            result(i, j) -= m2(i, j);
        }
    }
    return result;
}


///operator-= - оператор для вычитания исходной матрицы и другой матрицы
///результат записывается в исходную матрицу
///const Matrix<T>& m1 - матрица, const Matrix<T>& m2 - матрица
///возвращает новую исходную матрицу
///если размеры матриц не совпадают, выбрасывается исключение в виде строки
/// 
template <typename T>
Matrix<T> operator-=(Matrix<T>& m1, const Matrix<T>& m2) {
    if (m1.get_rows() != m2.get_rows() || m1.get_cols() != m2.get_cols()) {
        throw invalid_argument("Матрицы должны быть одинакового размера");
    }
    Matrix<T> result = m1;
    for (size_t i = 0; i < m1.get_rows(); ++i) {
        for (size_t j = 0; j < m1.get_cols(); ++j) {
            result(i, j) -= m2(i, j);
        }
    }
    m1 = result;
    return m1;
}


///operator*  - умножение матрицы на число
///const Matrix<T>& m1 - матрица, T data -  число
///возвращает новую матрицу как результат умножение матрицы на число
template <typename T>
Matrix<T> operator*(const Matrix<T>& m1, T data) {
    Matrix<T> result = m1;
    for (size_t i = 0; i < m1.get_rows(); ++i) {
        for (size_t j = 0; j < m1.get_cols(); ++j) {
            result(i, j) *= data;
        }
    }
    return result;
}




///operator*  - умножение матрицы на матрицу
///const Matrix<T>& m1 - матрица, const Matrix<T>& m2 - матрица
///возвращает новую матрицу как результат умножение матрицы на матрицу
///если кол-во столбцов 1-й матрицы не равно
/// кол-ву строк 2-й, выбрасывается исключение в виде строки
/// 
template <typename T>
Matrix<T> operator*(const Matrix<T>& m1, const Matrix<T>& m2)
{
    //проверка
    //кол-во столбцов 1-й матрицы должно равняться кол-ву строк 2-й
    if (m1.get_cols() != m2.get_rows()) {
        throw std::invalid_argument("Невозможно перемножить матрицы: количество столбцов первой матрицы не совпадает с количеством строк второй.");
    }

    // Создаем новую матрицу нужного размера
    Matrix<T> result;

    // Изменяем размер внешнего вектора (строки)
    result.set_rows(m1.get_rows()); //resize(m1.get_rows());
    result.set_cols(m2.get_cols()); //resize(m1.get_rows());

    ///цикл для вычисления 
    for (size_t i = 0; i < m1.get_rows(); ++i) {
        for (size_t j = 0; j < m2.get_cols(); ++j) {
            result(i, j) = 0;
            for (size_t k = 0; k < m2.get_rows(); ++k)
            {
                result(i, j) += m1(i, k) * m2(k, j);

            }
        }
    }
    return result;
}


///operator*=  - умножение исходной матрицы на матрицу
///Matrix<T>& m1 - матрица, const Matrix<T>& m2 - матрица
///возвращает новую исходную матрицу как результат умножения исходной матрицы на матрицу
///если кол-во столбцов 1-й матрицы не равно
///кол-ву строк 2-й, выбрасывается исключение в виде строки
template <typename T>
Matrix<T> operator*=(Matrix<T>& m1, const Matrix<T>& m2)
{
    //проверка
    //кол-во столбцов 1-й матрицы должно равняться кол-ву строк 2-й
    if (m1.get_cols() != m2.get_rows()) {
        throw "Невозможно перемножить матрицы: количество столбцов первой матрицы не совпадает с количеством строк второй.";
    }

    // Создаем новую матрицу нужного размера
    Matrix<T> result;

    // Изменяем размер внешнего вектора (строки)
    result.set_rows(m1.get_rows()); //resize(m1.get_rows());
    result.set_cols(m2.get_cols()); //resize(m1.get_rows());



    ///цикл для вычисления 
    for (size_t i = 0; i < m1.get_rows(); ++i) {
        for (size_t j = 0; j < m2.get_cols(); ++j) {
            result(i, j) = 0;
            for (size_t k = 0; k < m2.get_rows(); ++k)
            {
                result(i, j) += m1(i, k) * m2(k, j);

            }
        }
    }
    m1 = result;
    return m1;
}





///печать строки матрицы
///vector<T>& m - вектор- строка матрицы
template <typename T>
void print_len_mtrx(vector<T>& m) {
    for (size_t i = 0; i < m.size(); i++)
    {
        cout << fixed;
        cout.precision(2);
        cout << m[i] << "\t";
    }
}


template <typename T>
///среднее арифметическое элементов матрицы
///const Matrix<T>& m1 - матрица
///возвращает среднее арифметическое = сумма элементов / кол-во эл-тов
/// если матрица пустая, выбрасывается исключение в виде строки
double average_mtrx(const Matrix<T>& m1)
{
    if (m1.get_rows() == 0) throw "Матрица пустая";
    T sum = 0;
    for (size_t i = 0; i < m1.get_rows(); ++i) {
        for (size_t j = 0; j < m1.get_cols(); ++j) {
            sum += m1(i, j);
        }
    }
    return static_cast<double>(sum) / (m1.get_rows() * m1.get_cols());

}


template <typename T>
///обнуление матрицы
///Matrix<T>& m1 - матрица
///возвращает новую обнулённую матрицу
Matrix<T> zero_mtrx(Matrix<T>& m1)
{

    for (size_t i = 0; i < m1.get_rows(); ++i) {
        for (size_t j = 0; j < m1.get_cols(); ++j) {
            m1(i, j) = 0;
        }
    }
    return m1;

}


template <typename T>
///нахождение корней матрицы 
///const Matrix<T>& a - система линейных уравнений, в которой записаны коэффициенты 
///перед переменными, const vector<T>& c - вектор-столбец свободных коэфф.
///возвращает вектор-столбец корней
vector<double> root_mtrx(const Matrix<T>& a, const vector<T>& c)
{
    //размер матрицы
    const size_t n = a.get_rows();

    //конечный вариант корней
    vector<double> x(n);
    //промежуточный вариант корней
    vector<double> xx(n);



    //погрешность
    double e = 0.000001;
    //флаг - для выхода из цикла
    bool flag = true;

    //цикл нахождения корней
    do
    {
        for (int i = 0; i <= n - 1; i++)
        {
            xx[i] = c[i];
            for (int j = 0; j <= n - 1; j++)
            {
                if (j < i)
                {
                    xx[i] = xx[i] - a(i, j) * xx[j];
                }
                else if (j > i)
                    xx[i] = xx[i] - a(i, j) * x[j];
            }
            xx[i] = xx[i] / a(i, i);

        }
        int how_many = 0;
        for (int i = 0; i <= n - 1; i++)
        {
            if (abs(x[i] - xx[i]) < e)
                how_many = how_many + 1;
            x[i] = xx[i];
        }

        if (how_many == n)
            flag = false;





    } while (flag);
    return x;

}


template <typename T>
///нахождение обратной матрицы
///Matrix<T>& matrix - матрица
///возвращает новую обратную матрицу
/// выбрасывается исключение в виде строки если матрица вырождена (определитель равен нулю)
vector<vector<double>> inverse(Matrix<T>& matrix) {
    size_t n = matrix.get_rows();

    // Создание расширенной матрицы
    std::vector<std::vector<T>> augmentedMatrix(n, std::vector<T>(2 * n));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            augmentedMatrix[i][j] = static_cast<T>(matrix(i, j));
        }
        augmentedMatrix[i][i + n] = 1.0; // Единичная матрица справа
    }


    // Метод Гаусса-Жордана
    for (size_t i = 0; i < n; ++i) {
        size_t maxRow = i;
        for (size_t k = i + 1; k < n; ++k) {
            if (std::abs(augmentedMatrix[k][i]) > std::abs(augmentedMatrix[maxRow][i])) {
                maxRow = k;
            }
        }

        if (std::abs(augmentedMatrix[maxRow][i]) < 1e-9) {
            throw std::runtime_error("Матрица вырождена (определитель равен нулю)");
        }

        if (maxRow != i) {
            std::swap(augmentedMatrix[i], augmentedMatrix[maxRow]);
        }

        double pivot = augmentedMatrix[i][i];
        for (size_t j = 0; j < 2 * n; ++j) {
            augmentedMatrix[i][j] /= pivot;
        }

        for (size_t k = 0; k < n; ++k) {
            if (k != i) {
                double factor = augmentedMatrix[k][i];
                for (size_t j = 0; j < 2 * n; ++j) {
                    augmentedMatrix[k][j] -= factor * augmentedMatrix[i][j];
                }
            }
        }
    }

    // Извлечение обратной матрицы
    std::vector<std::vector<double>> inverseMatrix(n, std::vector<double>(n));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            inverseMatrix[i][j] = augmentedMatrix[i][j + n];
        }
    }

    return inverseMatrix;
}


///печать вектора
///vector<T > a - вектор
template <typename T>
void print_vector(vector<T > a) {
    for (size_t i = 0; i < a.size(); i++)
    {

        cout << fixed;
        cout.precision(2);
        cout << a[i] << "\t";


    }
}

///Проверка методов и функций
void all_assert()
{
    //погрешность
    double epsilon = 0.000001;


    //целочисленная матрица 1
    Matrix<int> a1({
           {1, 2, 3},
        {4, 5, 6},
        {7, 8, 10}
        });

    //целочисленная матрица 2
    Matrix<int> a2({
           {5, 2, 3},
           {4, 2, 6},
           {8, 8, 9},
        });


    //целочисленная матрица 4
    Matrix<int> a4({
        {36, 5, 5, 2, 1},
        {4, 31, 1, 4, 4},
        {5, 3, 47, 2, 3 },
        {1, 5, 1, 39, 1},
        {3, 5, 5, 4, 28}
        });

    //столбец свобоных коэфф.
    vector<int> v6{ 66,81,159,93,64 };

    // Получение результата
    vector<double> result_left = root_mtrx(a4, v6);

    // Результат, который должен получиться (корни матрицы)
    vector<double> result_right{ 1, 2, 3, 2, 1 };


    // Проверка результата (корни матрицы)
    assert(result_left.size() == result_right.size());
    for (size_t i = 0; i < result_left.size(); ++i) {
        assert(fabs(result_left[i] - result_right[i]) < epsilon);
    }

    
    

    // Проверяем детерминант
    assert(fabs(a1.determinant() + 3.0) < epsilon);

    //проверка среднего арифм.
    assert(fabs(average_mtrx(a1) - 5.11111111) < epsilon);

    //умножение матрицы на число
    Matrix<int> mult_num;
    mult_num = a1 * 2;

    Matrix<int> rez ({{2,4,6},
                      {8,10,12},
                      {14,16,20} });

 
    for (size_t i = 0; i < mult_num.get_rows(); i++) {
        for (size_t j = 0; j < mult_num.get_cols(); j++) {
            assert(fabs(mult_num(i,j) - rez(i,j)) < epsilon);
        }
    }

    //перемножение матриц
    Matrix<int> rez1({ {37, 30,  42},
                    {88, 66,  96},
                    {147,110, 159} });
    
        
        
    a1 *= a2;

    for (size_t i = 0; i < rez1.get_rows(); i++) {
        for (size_t j = 0; j < rez1.get_cols(); j++) {
            assert(fabs(a1(i, j) - rez1(i, j)) < epsilon);
        }
    }

    //перемножение матриц
    Matrix<int> rez2({ {641,     470,     669},
                    {1472,    1076,   1524},
                    {2447,    1786,   2532} });



    Matrix<int> mult_mtrx;
    mult_mtrx = a1 * a2;

    for (size_t i = 0; i < mult_mtrx.get_rows(); i++) {
        for (size_t j = 0; j < mult_mtrx.get_cols(); j++) {
            assert(fabs(mult_mtrx(i, j) - rez2(i, j)) < epsilon);
        }
    }

    //сумма матриц

    Matrix<int> sum1({ {42,     32,     45},
                    {92,    68,   102},
                    {155,    118,   168} }); 
    Matrix<int> sum;
    sum = a1 + a2;


    for (size_t i = 0; i < sum.get_rows(); i++) {
        for (size_t j = 0; j < sum.get_cols(); j++) {
            assert(fabs(sum(i, j) - sum1(i, j)) < epsilon);
        }
    }

    //оператор +=

    Matrix<int> sum2({ {42,     32,     45},
                    {92,    68,   102},
                    {155,    118,   168} }); 
    
    a1 += a2;
    for (size_t i = 0; i < a1.get_rows(); i++) {
        for (size_t j = 0; j < a1.get_cols(); j++) {
            assert(fabs(a1(i, j) - sum2(i, j)) < epsilon);
        }
    }
    //разность матриц
    Matrix<int> dif1({ {37,     30,     42},
                    {88,    66,   96},
                    {147,    110,   159} }); ;
    Matrix<int> dif;
    dif = a1 - a2;
    for (size_t i = 0; i < dif.get_rows(); i++) {
        for (size_t j = 0; j < dif.get_cols(); j++) {
            assert(fabs(dif(i, j) - dif1(i, j)) < epsilon);
        }
    }
    ///оператор -=
    a1 -= a2;
 
    for (size_t i = 0; i < a1.get_rows(); i++) {
        for (size_t j = 0; j < a1.get_cols(); j++) {
            assert(fabs(a1(i, j) - dif1(i, j)) < epsilon);
        }
    }
   
    //изменение эл-та матрицы
    dif1(1, 1) = 1;
    assert(dif1(1, 1) - 1 < epsilon);

    //заполнение матрицы числом 2
    dif1.set_mtrx_one_value(2);
    for (size_t i = 0; i < a1.get_rows(); i++) {
        for (size_t j = 0; j < a1.get_cols(); j++) {
            assert(dif1(i, j) - 2 < epsilon);

        }
    }
    
    //транспонирование матрицы
    Matrix<int> a5({ {37,     30,     42},
                    {88,    66,   96},
                    {147,    110,   159} });

    Matrix<int> trans1({ {37,     30,     42},
                        {88,    66,   96},
                        {147,    110,   159} }); 
    a5.transpose();

    for (size_t i = 0; i < a5.get_rows(); i++) {
        for (size_t j = 0; j < a5.get_cols(); j++) {
            assert(a5(i, j) - trans1(j,i) < epsilon);

        }
    }

    //создание диагональной матрицы
    Matrix<int> a6({ {37,     30,     42},
                    {88,    66,   96},
                    {147,    110,   159} });

    Matrix<int> diag1({ {37,     0,     0},
                        {0,    66,   0},
                        {0,    0,   159} });


    a6.create_diagonal_matrix();

    for (size_t i = 0; i < a6.get_rows(); i++) {
        for (size_t j = 0; j < a6.get_cols(); j++) {
            assert(a6(i, j) - diag1(j, i) < epsilon);

        }
    }


    //обнуление матрицы
    Matrix<int> a7({ {37,     30,     42},
                    {88,    66,   96},
                    {147,    110,   159} });

    Matrix<int> zero1({ {0,     0,     0},
                        {0,    0,   0},
                        {0,    0,   0} });


    a7 = zero_mtrx(a7);

    for (size_t i = 0; i < a7.get_rows(); i++) {
        for (size_t j = 0; j < a7.get_cols(); j++) {
            assert(a7(i, j) - zero1(j, i) < epsilon);

        }
    }

    //поменять местами строки
    Matrix<int> a8({ {37,     30,     42},
                    {88,    66,   96},
                    {147,    110,   159} });

    Matrix<int> swap_a8({ {88,    66,   96},
                        {37,     30,     42},
                         {147,    110,   159} });



    a8.swap_line(0, 1);

    for (size_t i = 0; i < a8.get_rows(); i++) {
        for (size_t j = 0; j < a8.get_cols(); j++) {
            assert(a8(i, j) - swap_a8(i, j) < epsilon);

        }
    }
   

}