//�����: �������� ���-23
#include "CarClass.h"
#include <cassert>
#include <iostream>
using namespace std;
/// ����������� �� ���������
/// year_build1 - ��� ������, mile_age1 - ������, transmission1 - �����������
/// consumption1 - ������ �������, num_owners1 - ���-�� ����������, 
/// price1 - ����, handlebar_left - ���� (����� / ������)
CarClass::CarClass() {
    year_build = 1;  mile_age = 10'000; transmission = "automatic";
    consumption = 10; num_owners = 3; price = 1'000'000'000; handlebar_left = true;

}

/// ����������� � �����������
/// year_build1 - ��� ������, mile_age1 - ������, transmission1 - �����������
/// consumption1 - ������ �������, num_owners1 - ���-�� ����������, 
/// price1 - ����, handlebar_left - ���� (����� / ������)
CarClass::CarClass(unsigned short year_build1, unsigned int mile_age1, const string &transmission1,
    unsigned int consumption1, unsigned int num_owners1, const unsigned long long &price1, bool handlebar_left1)
{
    //�������
    set_year_build(year_build1);
    
    set_mile_age(mile_age1);

    set_transmission(transmission1);

    set_consumption(consumption1);

    set_num_owners(num_owners1);

    set_price(price1);

    set_handlebar_left(handlebar_left1);



}
///������ year_build1 ��� ������
void CarClass::set_year_build(unsigned short year_build1)
{
    //���������� - ������� �����
    time_t current_time;
    //����� � ��� � 1 ��� 1970 �
    current_time = time(NULL);
    //������� ���
    int a;
    //31537970 ������ � 1 ����
    a = 1970 + current_time / 31537970;
    
    //const auto now_year= chrono::system_clock::now();

    //�������� ������������
    if (year_build1 >= 0 && year_build1 <= a)
    {
        year_build = year_build1;

    }
    //����� 0
    else year_build = 0;


}

///������ ��� �������, mile_age1 - ������
void CarClass::set_mile_age(unsigned int mile_age1)
{
  
  this->mile_age = mile_age1;

}
///������ ���  �����������, transmission1 - �����������
void CarClass::set_transmission(string transmission1)
{
    //��������
    if (transmission1 == "automatic" || transmission1 == "mechanics" || transmission1 == "robot")
    {
        this->transmission = transmission1;

    }
    else  transmission1 = "Nan";
}

///������ ��� ������, consumption1 - ������
void CarClass::set_consumption(unsigned int consumption1)
{
   
   this->consumption = consumption1;

}
///������ ��� ���-�� ����������,  num_owners1 - ���-�� ����������
void CarClass::set_num_owners(unsigned int num_owners1)
{
   
    this->num_owners = num_owners1;

}
///������ ��� ����, price1 - ����
void CarClass::set_price(unsigned long long price1)
{
    //��������
    if (price1 >= 0)
    {
        this->price = price1;

    }
    else  price1 = 0;
}
///������ ��� ����, handlebar1 - ���� (�����/������)
void CarClass::set_handlebar_left(bool handlebar_left1)
{

   this->handlebar_left = handlebar_left1;

}
///������ ��� ��������� ����, price1 -�����. ����, discount1 - ����, �� ������� ����� �������� ������� ����
long int CarClass::change_price(unsigned long long &price1, long int discount1) const
{   //���� ������
    if (discount1 <= 0)
    {
        price1 = price1 - discount1;
    }
    //���� ���������
    else
    {
        price1 = price1 + discount1;
    }
    return price1;
}

///������� �����
string CarClass::to_my_string() const
{
    //num_owners - ���-�� ���������� mile_age - ������ price - ���� 
    std::string s = ::to_string(num_owners) + " " + to_string(mile_age) + " " + to_string(price);
    return s;
}

void CarClass::all_assert() 
{
    //�������� assert
    int deviation = 0;
    unsigned long long a1 = 1'001'000;

    unsigned long long a2 = 100;

    unsigned long long a3 = 5'000'000;

    assert(change_price(a1, -1000) - 1'000'000 == deviation);
    assert(change_price(a2, -1000) - 0 == deviation);
    assert(change_price(a3, 1'000'000) - 6'000'000 == deviation);
}   

