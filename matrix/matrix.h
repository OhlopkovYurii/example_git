//�����: �������� ���-23
//������������ ����

//���������, ������������� ��� �������� �� ���,
// ����� ���������� �������� ���� ��� ���������� ����������� ������ ���� ���
#pragma once

//��� �������
#include<vector>
#include <iostream>
#include <string>
//��� abs
#include <cmath>
#include <cassert>




using namespace std;

//������
template <typename T>

/*
����� �������
*/
class Matrix
{
private:
    ///�������
    vector<vector<T>> matrix;


public:

    //���������� �� ���������
    Matrix() : matrix() {}



    //����������� � �����������
    //matrix1 - �������
    Matrix(const vector<vector<T>>& matrix1) : matrix(matrix1) {}
    



    ///��������() ��� �������������� ��������
    ///���������� ������� ������� �� �������� 
    ///size_t i, size_t j - ����� ������ � ����� �������
    T& operator () (size_t i, size_t j) {
        return matrix[i][j];
    }


    /// ��������() ��� �������������� ��������
    /// ���������� ������ �������
    /// size_t i - ����� ������
    vector<T>& operator () (size_t i) {
        return matrix[i];
    }



    /// ��������() ��� ������������ ��������
    /// ���������� ������� ������� �� �������� 
    /// size_t i, size_t j - ����� ������ � ����� �������
    T const& operator () (size_t i, size_t j) const {
        return matrix[i][j];
    }



    ///������ - ���������� ���-�� ����� �������
    //template <typename T>
    size_t get_rows() const {
        return matrix.size();
    }



    ///������ - ���������� ���-�� �������� �������
    size_t get_cols() const {
        //���� ������� �� ������
        if (matrix.empty()) {
            return 0;
        }
        return matrix[0].size();
    }


    ///������ - ������ ���-�� ����� �������
    ///size_t num_rows - ���-�� �����
    void set_rows(size_t num_rows)
    {
        //��������� ���-�� ����� �������
        matrix.resize(num_rows);
    }

    ///������ - ������ ���-�� �������� �������
    ///size_t num_cols - ���-�� ��������
    void set_cols(size_t num_cols)
    {
        // �������� ������ ������� ����������� ������� (�������)
        for (auto& row : matrix) {
            row.resize(num_cols);
        }
    }



    ///������ �������
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




    ///������ - ���������� ������� ����� ���������
    ///T data - �����
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


    ///������ - ���������� ������� ��������� ���������
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


    ///���������������� �������
    void transpose()
    {
        double t;
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = i; j < matrix[0].size(); j++)
            {
                //����� ����������
                t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
    }




    ///�������� ������������ �������
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


    ///���������� ������������
    ///���������� ������������
    double determinant() {
        size_t n = matrix.size(); // �������� ������ �������

        if (n == 0) return 0; // ���� ������� ������, ���������� 0

        // ������� ��������� ������� ���� double ��� ����������
        std::vector<std::vector<double>> a(n, std::vector<double>(n));

        // �������� �������� �������� ������� � ����� �������, ���������� �� � ���� double
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                a[i][j] = static_cast<double>(matrix[i][j]); // ����������� ������� � double
            }
        }

        double det = 1.0; // ��������� �������� ������������

        // �������� ������-������� ��� ���������� ������������
        for (size_t i = 0; i < n; ++i) {
            size_t maxRow = i; // ������ ������ � ������������ ��������� � ������� �������

            // ������� ������ � ������������ ��������� � ������ �������
            for (size_t k = i + 1; k < n; ++k) {
                if (std::abs(a[k][i]) > std::abs(a[maxRow][i])) {
                    maxRow = k;
                }
            }

            // ���� ������������ ������� ������ � ����, ������� ���������
            if (std::abs(a[maxRow][i]) < 1e-9) return 0.0;

            // ������ ������� ������� ������ � ������ � ������������ ���������
            if (maxRow != i) {
                std::swap(a[i], a[maxRow]);
                det *= -1.0; // ��������� ����� ������������ ��� ������������ �����
            }

            det *= a[i][i]; // �������� ������� ������� �� ������������

            // �������� ��� �������� ���� �������� � ����
            for (size_t k = i + 1; k < n; ++k) {
                double factor = a[k][i] / a[i][i]; // ����������� ��� ���������
                for (size_t j = i; j < n; ++j) {
                    a[k][j] -= factor * a[i][j]; // ��������� ������������ ������� ������
                }
            }
        }

        return det; // ���������� ��������� ������������
    }


    ///������ ������ �������
    ///std::vector<std::vector<T>>& matrix - �������, ������ ������� ��������
    /// size_t row1 - ����� ������, size_t row - ����� ������
    void swap_line(size_t row1, size_t row2) {
        //���������� ���������� ������� �������
        std::swap(matrix[row1], matrix[row2]);
    }

};


///operator+  - �������� ������
///const Matrix<T>& m1 - �������, const Matrix<T>& m2 - �������
///���������� ����� ������� ��� ��������� �������� ���� ������
///���� ������� ������ �� ���������, ������������� ���������� � ���� ������
template <typename T>
Matrix<T> operator+(const Matrix<T>& m1, const Matrix<T>& m2) {
    //���� ������ ������ �� ���������, �������� ����������
    if (m1.get_rows() != m2.get_rows() || m1.get_cols() != m2.get_cols()) {
        throw invalid_argument("������� ������ ���� ����������� �������");
    }
    Matrix<T> result = m1;
    ///���� ��� �������� ������ 
    for (size_t i = 0; i < m1.get_rows(); ++i) {
        for (size_t j = 0; j < m1.get_cols(); ++j) {
            result(i, j) += m2(i, j);
        }
    }
    return result;
}


///operator+= - �������� ��� �������� �������� ������� � ������ �������
///��������� ������������ � �������� �������
///const Matrix<T>& m1 - �������, const Matrix<T>& m2 - �������
///���������� ����� �������� �������
///���� ������� ������ �� ���������, ������������� ���������� � ���� ������
/// 
template <typename T>
Matrix<T> operator+=(Matrix<T>& m1, const Matrix<T>& m2) {
    if (m1.get_rows() != m2.get_rows() || m1.get_cols() != m2.get_cols()) {
        throw invalid_argument("������� ������ ���� ����������� �������");
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


///operator-  - ��������� ������
///const Matrix<T>& m1 - �������, const Matrix<T>& m2 - �������
///���������� ����� ������� ��� ��������� ��������� ���� ������
///���� ������� ������ �� ���������, ������������� ���������� � ���� ������
/// 
template <typename T>
Matrix<T> operator-(const Matrix<T>& m1, const Matrix<T>& m2) {
    if (m1.get_rows() != m2.get_rows() || m1.get_cols() != m2.get_cols()) {
        throw invalid_argument("������� ������ ���� ����������� �������");
    }
    Matrix<T> result = m1;
    for (size_t i = 0; i < m1.get_rows(); ++i) {
        for (size_t j = 0; j < m1.get_cols(); ++j) {
            result(i, j) -= m2(i, j);
        }
    }
    return result;
}


///operator-= - �������� ��� ��������� �������� ������� � ������ �������
///��������� ������������ � �������� �������
///const Matrix<T>& m1 - �������, const Matrix<T>& m2 - �������
///���������� ����� �������� �������
///���� ������� ������ �� ���������, ������������� ���������� � ���� ������
/// 
template <typename T>
Matrix<T> operator-=(Matrix<T>& m1, const Matrix<T>& m2) {
    if (m1.get_rows() != m2.get_rows() || m1.get_cols() != m2.get_cols()) {
        throw invalid_argument("������� ������ ���� ����������� �������");
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


///operator*  - ��������� ������� �� �����
///const Matrix<T>& m1 - �������, T data -  �����
///���������� ����� ������� ��� ��������� ��������� ������� �� �����
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




///operator*  - ��������� ������� �� �������
///const Matrix<T>& m1 - �������, const Matrix<T>& m2 - �������
///���������� ����� ������� ��� ��������� ��������� ������� �� �������
///���� ���-�� �������� 1-� ������� �� �����
/// ���-�� ����� 2-�, ������������� ���������� � ���� ������
/// 
template <typename T>
Matrix<T> operator*(const Matrix<T>& m1, const Matrix<T>& m2)
{
    //��������
    //���-�� �������� 1-� ������� ������ ��������� ���-�� ����� 2-�
    if (m1.get_cols() != m2.get_rows()) {
        throw std::invalid_argument("���������� ����������� �������: ���������� �������� ������ ������� �� ��������� � ����������� ����� ������.");
    }

    // ������� ����� ������� ������� �������
    Matrix<T> result;

    // �������� ������ �������� ������� (������)
    result.set_rows(m1.get_rows()); //resize(m1.get_rows());
    result.set_cols(m2.get_cols()); //resize(m1.get_rows());

    ///���� ��� ���������� 
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


///operator*=  - ��������� �������� ������� �� �������
///Matrix<T>& m1 - �������, const Matrix<T>& m2 - �������
///���������� ����� �������� ������� ��� ��������� ��������� �������� ������� �� �������
///���� ���-�� �������� 1-� ������� �� �����
///���-�� ����� 2-�, ������������� ���������� � ���� ������
template <typename T>
Matrix<T> operator*=(Matrix<T>& m1, const Matrix<T>& m2)
{
    //��������
    //���-�� �������� 1-� ������� ������ ��������� ���-�� ����� 2-�
    if (m1.get_cols() != m2.get_rows()) {
        throw "���������� ����������� �������: ���������� �������� ������ ������� �� ��������� � ����������� ����� ������.";
    }

    // ������� ����� ������� ������� �������
    Matrix<T> result;

    // �������� ������ �������� ������� (������)
    result.set_rows(m1.get_rows()); //resize(m1.get_rows());
    result.set_cols(m2.get_cols()); //resize(m1.get_rows());



    ///���� ��� ���������� 
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





///������ ������ �������
///vector<T>& m - ������- ������ �������
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
///������� �������������� ��������� �������
///const Matrix<T>& m1 - �������
///���������� ������� �������������� = ����� ��������� / ���-�� ��-���
/// ���� ������� ������, ������������� ���������� � ���� ������
double average_mtrx(const Matrix<T>& m1)
{
    if (m1.get_rows() == 0) throw "������� ������";
    T sum = 0;
    for (size_t i = 0; i < m1.get_rows(); ++i) {
        for (size_t j = 0; j < m1.get_cols(); ++j) {
            sum += m1(i, j);
        }
    }
    return static_cast<double>(sum) / (m1.get_rows() * m1.get_cols());

}


template <typename T>
///��������� �������
///Matrix<T>& m1 - �������
///���������� ����� ��������� �������
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
///���������� ������ ������� 
///const Matrix<T>& a - ������� �������� ���������, � ������� �������� ������������ 
///����� �����������, const vector<T>& c - ������-������� ��������� �����.
///���������� ������-������� ������
vector<double> root_mtrx(const Matrix<T>& a, const vector<T>& c)
{
    //������ �������
    const size_t n = a.get_rows();

    //�������� ������� ������
    vector<double> x(n);
    //������������� ������� ������
    vector<double> xx(n);



    //�����������
    double e = 0.000001;
    //���� - ��� ������ �� �����
    bool flag = true;

    //���� ���������� ������
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
///���������� �������� �������
///Matrix<T>& matrix - �������
///���������� ����� �������� �������
/// ������������� ���������� � ���� ������ ���� ������� ��������� (������������ ����� ����)
vector<vector<double>> inverse(Matrix<T>& matrix) {
    size_t n = matrix.get_rows();

    // �������� ����������� �������
    std::vector<std::vector<T>> augmentedMatrix(n, std::vector<T>(2 * n));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            augmentedMatrix[i][j] = static_cast<T>(matrix(i, j));
        }
        augmentedMatrix[i][i + n] = 1.0; // ��������� ������� ������
    }


    // ����� ������-�������
    for (size_t i = 0; i < n; ++i) {
        size_t maxRow = i;
        for (size_t k = i + 1; k < n; ++k) {
            if (std::abs(augmentedMatrix[k][i]) > std::abs(augmentedMatrix[maxRow][i])) {
                maxRow = k;
            }
        }

        if (std::abs(augmentedMatrix[maxRow][i]) < 1e-9) {
            throw std::runtime_error("������� ��������� (������������ ����� ����)");
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

    // ���������� �������� �������
    std::vector<std::vector<double>> inverseMatrix(n, std::vector<double>(n));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            inverseMatrix[i][j] = augmentedMatrix[i][j + n];
        }
    }

    return inverseMatrix;
}


///������ �������
///vector<T > a - ������
template <typename T>
void print_vector(vector<T > a) {
    for (size_t i = 0; i < a.size(); i++)
    {

        cout << fixed;
        cout.precision(2);
        cout << a[i] << "\t";


    }
}

///�������� ������� � �������
void all_assert()
{
    //�����������
    double epsilon = 0.000001;


    //������������� ������� 1
    Matrix<int> a1({
           {1, 2, 3},
        {4, 5, 6},
        {7, 8, 10}
        });

    //������������� ������� 2
    Matrix<int> a2({
           {5, 2, 3},
           {4, 2, 6},
           {8, 8, 9},
        });


    //������������� ������� 4
    Matrix<int> a4({
        {36, 5, 5, 2, 1},
        {4, 31, 1, 4, 4},
        {5, 3, 47, 2, 3 },
        {1, 5, 1, 39, 1},
        {3, 5, 5, 4, 28}
        });

    //������� �������� �����.
    vector<int> v6{ 66,81,159,93,64 };

    // ��������� ����������
    vector<double> result_left = root_mtrx(a4, v6);

    // ���������, ������� ������ ���������� (����� �������)
    vector<double> result_right{ 1, 2, 3, 2, 1 };


    // �������� ���������� (����� �������)
    assert(result_left.size() == result_right.size());
    for (size_t i = 0; i < result_left.size(); ++i) {
        assert(fabs(result_left[i] - result_right[i]) < epsilon);
    }

    
    

    // ��������� �����������
    assert(fabs(a1.determinant() + 3.0) < epsilon);

    //�������� �������� �����.
    assert(fabs(average_mtrx(a1) - 5.11111111) < epsilon);

    //��������� ������� �� �����
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

    //������������ ������
    Matrix<int> rez1({ {37, 30,  42},
                    {88, 66,  96},
                    {147,110, 159} });
    
        
        
    a1 *= a2;

    for (size_t i = 0; i < rez1.get_rows(); i++) {
        for (size_t j = 0; j < rez1.get_cols(); j++) {
            assert(fabs(a1(i, j) - rez1(i, j)) < epsilon);
        }
    }

    //������������ ������
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

    //����� ������

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

    //�������� +=

    Matrix<int> sum2({ {42,     32,     45},
                    {92,    68,   102},
                    {155,    118,   168} }); 
    
    a1 += a2;
    for (size_t i = 0; i < a1.get_rows(); i++) {
        for (size_t j = 0; j < a1.get_cols(); j++) {
            assert(fabs(a1(i, j) - sum2(i, j)) < epsilon);
        }
    }
    //�������� ������
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
    ///�������� -=
    a1 -= a2;
 
    for (size_t i = 0; i < a1.get_rows(); i++) {
        for (size_t j = 0; j < a1.get_cols(); j++) {
            assert(fabs(a1(i, j) - dif1(i, j)) < epsilon);
        }
    }
   
    //��������� ��-�� �������
    dif1(1, 1) = 1;
    assert(dif1(1, 1) - 1 < epsilon);

    //���������� ������� ������ 2
    dif1.set_mtrx_one_value(2);
    for (size_t i = 0; i < a1.get_rows(); i++) {
        for (size_t j = 0; j < a1.get_cols(); j++) {
            assert(dif1(i, j) - 2 < epsilon);

        }
    }
    
    //���������������� �������
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

    //�������� ������������ �������
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


    //��������� �������
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

    //�������� ������� ������
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