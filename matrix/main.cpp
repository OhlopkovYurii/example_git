//�����: �������� ���-23
//������� ����
#include "matrix.h"

#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    all_assert();

    //������������� ������� 1
    Matrix<int> m1({
           {1, 2, 3},
        {4, 5, 6},
        {7, 8, 10}
        });

    //������������� ������� 2
    Matrix<int> m2({
           {5, 2, 3},
           {4, 2, 6},
           {8, 8, 9},
        });

    //������������� ������� 3
    Matrix<int> m3;

    //������� �������� �����.
    vector<int> v6{ 66,81,159,93,64 };


    //������������� ������� 4
    Matrix<int> m4({
        {36, 5, 5, 2, 1},
        {4, 31, 1, 4, 4},
        {5, 3, 47, 2, 3 },
        {1, 5, 1, 39, 1},
        {3, 5, 5, 4, 28}
        });
    
   

    ///������ �������, root_mtrx(m4, v6) - ���������� ������ - ����� ������� m4, v6 - ������� ����. �����
    ::cout << "����� ������� �������� ��������� ������� m4 � ������� v6\n";
    print_vector(root_mtrx(m4, v6));
    ::cout << "\n";

    //���������� �������� �������
    //������ �������
    //����� ������������ ������� 1
    ::cout << "������������ ������� m1\n";
    ::cout << to_string(m1.determinant());
    ::cout << "\n";


    try
    {   //���������� �������� �����. ��-��� �������
        ::cout << "������� �������������� ��-��� �������\n";
        ::cout << to_string(average_mtrx(m1));
        ::cout << "\n";
    }
    catch (const char* error_message)
    {
        ::cout << error_message << endl;
    }



    


    try
    {
        

        //��������� ������� �� �����
        Matrix<int> mult_num;
        mult_num = m1 * 2;
        ::cout << "m1 * 2 = " << endl;
        mult_num.print_mtrx();

        //������������ ������
        ::cout << "m1 *= m2 " << endl;
        m1 *= m2;
        m1.print_mtrx();

        //������������ ������
        Matrix<int> mult_mtrx;
        mult_mtrx = m1 * m2;
        ::cout << "m1 * m2 = " << endl;
        mult_mtrx.print_mtrx();


        //�������� ������, ���-� ������������ � sum
        Matrix<int> sum;
        sum = m1 + m2;
        ::cout << "m1 + m2 = " << endl;
        sum.print_mtrx();

        //�������� ������, ���-� ������������ � m1
        m1 += m2;
        ::cout << "m1 += m2 = " << endl;
        m1.print_mtrx();

        //��������� ������, ���-� ������������ � dif
        Matrix<int> dif;
        dif = m1 - m2;
        ::cout << "m1 - m2 = " << endl;
        dif.print_mtrx();

  

        //��������� ������, ���-� ������������ � m1
        m1 -= m2;
        ::cout << "m1 -= m2 = " << endl;
        m1.print_mtrx();



    }
    catch (const char* error_message)
    {
        ::cout << error_message << endl;
    }



    


    //��������� ��-�� �������
    m1(1, 1) = 1;

    //���������� ������� ���������
    ::cout << "���������� ������� m1 ���������\n";
    m1.set_mtrx_one_value(2);
    m1.print_mtrx();


    //���������� ������� ��������� ���������
    ::cout << "���������� ������� ��������� ���������\n";
    m1.set_mtrx_random_value(10, 20);
    m1.print_mtrx();

    //����������������
    ::cout << "����������������� �������\n";
    m1.transpose();
    m1.print_mtrx();

    //�������� ������������ �������
    ::cout << "�������� ������������ �������\n";
    m1.create_diagonal_matrix();
    m1.print_mtrx();


    //������ 1� ������ �������
    ::cout << "������ 1� ������ �������\n";
    print_len_mtrx(m1(1));
    ::cout << "\n";

    //��������� �������
    ::cout << "��������� ������� m1\n";
    zero_mtrx(m1);
    m1.print_mtrx();
}


