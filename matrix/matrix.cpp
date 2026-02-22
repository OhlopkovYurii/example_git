//////Автор: Охлопков ИВТ-23
////файл с методами
//#include "matrix.h"
//
//using namespace std;
//template <typename T>
////констуктор по умолчанию
//Matrix<T>::Matrix() : matrix() {}
//template Matrix<int>::Matrix();
//
//template <typename T>
////конструктор с параметрами
////matrix1 - матрица
//Matrix<T>::Matrix(const vector<vector<T>>& matrix1) : matrix(matrix1) {}
//template Matrix<int>::Matrix(const vector<vector<int>>& matrix1);
//
//
//template <typename T>
//
/////оператор() для неконстантного элемента
/////возвращает элемент матрицы по индексам 
/////size_t i, size_t j - номер строки и номер столбца
//T& Matrix<T>::operator () (size_t i, size_t j) {
//    return matrix[i][j];
//}
//template int& Matrix<int>::operator() (size_t i, size_t j);
//
//
///// оператор() для неконстантного элемента
///// возвращает строку вектора
///// size_t i - номер строки
//template <typename T>
//vector<T>& Matrix<T>::operator () (size_t i) {
//    return matrix[i];
//}
//template vector<int>& Matrix<int>::operator() (size_t i);
//
//
//
///// оператор() для константного элемента
///// возвращает элемент матрицы по индексам 
///// size_t i, size_t j - номер строки и номер столбца
//template <typename T>
//T const& Matrix<T>::operator () (size_t i, size_t j) const {
//    return matrix[i][j];
//}
//template int const& Matrix<int>::operator() (size_t i, size_t j) const;
//
//
//
/////геттер - возвращает кол-во строк матрицы
//template <typename T>
//size_t Matrix<T>::get_rows() const {
//    return matrix.size();
//}
//template size_t Matrix<int>::get_rows() const;
//
//
//
/////геттер - возвращает кол-во столбцов матрицы
//template <typename T>
//size_t Matrix<T>::get_cols() const {
//    //если матрица не пустая
//    if (matrix.empty()) {
//        return 0;
//    }
//    return matrix[0].size();
//}
//template size_t Matrix<int>::get_cols() const;
//
//
/////сеттер - меняет кол-во строк матрицы
/////size_t num_rows - кол-во строк
//template <typename T>
//void Matrix<T>::set_rows(size_t num_rows)
//{
//    //изменение кол-ва строк матрицы
//    matrix.resize(num_rows);
//}
//template void Matrix<int>::set_rows(size_t num_rows);
//
/////сеттер - меняет кол-во столбцов матрицы
/////size_t num_cols - кол-во столбцов
//template <typename T>
//void Matrix<T>::set_cols(size_t num_cols)
//{
//    // Изменяем размер каждого внутреннего вектора (столбцы)
//    for (auto& row : matrix) {
//        row.resize(num_cols);
//    }
//}
//template void Matrix<int>::set_cols(size_t num_cols);
//
//
//
/////печать матрицы
//template <typename T>
//void Matrix<T>::print_mtrx() {
//    for (size_t i = 0; i < matrix.size(); i++)
//    {
//        for (size_t j = 0; j < matrix[0].size(); j++)
//        {
//            cout << fixed;
//            cout.precision(2);
//            cout << matrix[i][j] << "\t";
//
//        }
//        cout << '\n';
//    }
//}
//template void Matrix<int>::print_mtrx();
//
//
//
//
/////сеттер - заполнение матрицы одним значением
/////T data - число
//template <typename T>
//void Matrix<T>::set_mtrx_one_value(T data)
//{
//    for (size_t i = 0; i < matrix.size(); i++)
//    {
//        for (size_t j = 0; j < matrix[0].size(); j++)
//        {
//            matrix[i][j] = data;
//        }
//    }
//}
//template void Matrix<int>::set_mtrx_one_value(int data);
//
//
/////сеттер - заполнение матрицы рандомным значением
//template <typename T>
//void Matrix<T>::set_mtrx_random_value()
//{
//    srand(time(0));
//    for (size_t i = 0; i < matrix.size(); i++)
//    {
//        for (size_t j = 0; j < matrix[0].size(); j++)
//        {
//            matrix[i][j] = rand() % 100 - 50; // -50...50
//        }
//    }
//}
//template void Matrix<int>::set_mtrx_random_value();
//
//
/////транспонирование матрицы
//template <typename T>
//void Matrix<T>::transpose() 
//{
//    double t;
//    for (size_t i = 0; i < matrix.size(); i++)
//    {
//        for (size_t j = i; j < matrix[0].size(); j++)
//        {
//            //обмен элементами
//            t = matrix[i][j];
//            matrix[i][j] = matrix[j][i];
//            matrix[j][i] = t;
//        }
//    }
//}
//template void Matrix<int>::transpose();//либо int matrix[][5], либо int (*matrix)[5]
//
//
//
//
/////создание диагональной матрицы
//template <typename T>
//void Matrix<T>::create_diagonal_matrix()
//{
//    for (size_t i = 0; i < matrix.size(); i++)
//    {
//        for (size_t j = 0; j < matrix[0].size(); j++)
//        {
//            if (i != j)
//                matrix[i][j] = 0;
//
//        }
//    }
//}
//template void Matrix<int>::create_diagonal_matrix();
//
//
/////нахождение определителя
/////возвращает определитель
//template <typename T>
//double Matrix<T>::determinant() {
//    size_t n = matrix.size(); // Получаем размер матрицы
//
//    if (n == 0) return 0; // Если матрица пустая, возвращаем 0
//
//    // Создаем временную матрицу типа double для вычислений
//    std::vector<std::vector<double>> a(n, std::vector<double>(n));
//
//    // Копируем элементы исходной матрицы в новую матрицу, преобразуя их к типу double
//    for (size_t i = 0; i < n; ++i) {
//        for (size_t j = 0; j < n; ++j) {
//            a[i][j] = static_cast<double>(matrix[i][j]); // Преобразуем элемент в double
//        }
//    }
//
//    double det = 1.0; // Начальное значение определителя
//
//    // Алгоритм Гаусса-Жордана для нахождения определителя
//    for (size_t i = 0; i < n; ++i) {
//        size_t maxRow = i; // Индекс строки с максимальным элементом в текущем столбце
//
//        // Находим строку с максимальным значением в данном столбце
//        for (size_t k = i + 1; k < n; ++k) {
//            if (std::abs(a[k][i]) > std::abs(a[maxRow][i])) {
//                maxRow = k;
//            }
//        }
//
//        // Если максимальный элемент близок к нулю, матрица вырождена
//        if (std::abs(a[maxRow][i]) < 1e-9) return 0.0;
//
//        // Меняем местами текущую строку и строку с максимальным элементом
//        if (maxRow != i) {
//            std::swap(a[i], a[maxRow]);
//            det *= -1.0; // Изменение знака определителя при перестановке строк
//        }
//
//        det *= a[i][i]; // Умножаем текущий элемент на определитель
//
//        // Приводим все элементы ниже текущего к нулю
//        for (size_t k = i + 1; k < n; ++k) {
//            double factor = a[k][i] / a[i][i]; // Коэффициент для вычитания
//            for (size_t j = i; j < n; ++j) {
//                a[k][j] -= factor * a[i][j]; // Вычитание произведения текущей строки
//            }
//        }
//    }
//
//    return det; // Возвращаем найденный определитель
//}
//template double Matrix<int>::determinant();
//
//
/////меняем строки матрицы
/////std::vector<std::vector<T>>& matrix - матрица, строки которой меняются
///// size_t row1 - номер строки, size_t row - номер строки
//template <typename T>
//void Matrix<T>::swap_line(std::vector<std::vector<T>>& matrix, size_t row1, size_t row2) {
//    //используем встроенную функцию вектора
//    std::swap(matrix[row1], matrix[row2]);
//}
////template void Matrix<int>::swap_line(std::vector<std::vector<int>>& matrix, size_t row1, size_t row2);
//
//
////template void print_vector(vector<int> a);
//
//
//
