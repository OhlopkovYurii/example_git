//�����: �������� ���-23

#pragma once
#include <string>
#include <chrono>
using namespace std;
/// ����� ����������
class CarClass{
//�������� ������
private:
    ///��� ������
    unsigned short year_build;
    ///������
    unsigned int mile_age;
    ///�����������
    string transmission;
    ///������ �������
    unsigned int consumption;
    ///���-�� ����������
    unsigned int num_owners;
    ///����
    unsigned long long price;
    ///���� (����� / ������)
    bool handlebar_left;

//�������� ������
public:

    /// ����������� �� ���������
    CarClass();

    /// ����������� � �����������
    /// year_build1 - ��� ������, mile_age1 - ������, transmission1 - �����������
    /// consumption1 - ������ �������, num_owners1 - ���-�� ����������, 
    /// price1 - ����, handlebar_left - ���� (����� / ������)
    CarClass(unsigned short year_build1, unsigned int mile_age1, const string &transmission1,
        unsigned int consumption1, unsigned int num_owners1, const unsigned long long &price1,
        bool handlebar_left);
    
    ///����
    string color;
    ///������
    string model;
    //��������
    string seller;
    ///����������
    string buyer;
   

    ///��������� ���� ������
    unsigned short get_year_build() const;
    ///��������� �������
    unsigned int get_mile_age() const;
    ///��������� �����������
    string get_transmission() const;
    ///��������� ������� �������
    unsigned int get_consumption() const;
    ///��������� ���-�� ����������
    unsigned int get_num_owners() const;
    ///��������� ����
    unsigned int get_price() const;
    ///��������� ����
    string get_handlebar_left() const;

    



    ///�������
    ///��� ��� ������
    void set_year_build(unsigned short year_build1);
    ///��� �������
    void set_mile_age(unsigned int mile_age1);
    ///���  �����������
    void set_transmission(string transmission1);
    ///��� ������� �������
    void set_consumption(unsigned int consumption1);
    ///��� ���-�� ����������
    void set_num_owners(unsigned int num_owners1);
    ///���  ����
    void set_price(unsigned long long price1);
    /// ��� ����
    void set_handlebar_left(bool handlebar_left1);

   

    ///����� ��������� ����, price1 -�����. ����, discount1 - ����, �� ������� ����� �������� ������� ����
    long int change_price(unsigned long long &price1, long int discount1) const;
    ///����� ���������� ������
    string to_my_string() const;
    //�������� assert'��
    void all_assert();
};