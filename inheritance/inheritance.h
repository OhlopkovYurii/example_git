#pragma once

#include<iostream>
#include<string>
#include <vector>
#include <cassert>

using namespace std;

///����������� ����� - �������� ���������������
class Means_transportation
{
public:
    //����������� ����� - ���������
    //= 0 - ��� ����������, ������ ������� ������ ����� ������
    virtual string to_string() const = 0;
};

///����� ���������, ����������� �� ������������ ������ - �������� ���������������
class Transport : public Means_transportation
{
private:
    ///��������
    ::string name;

    ///��� ������
    unsigned short year_build;
    ///������
    unsigned int mile_age;

    ///������ �������
    unsigned int consumption;

    ///����
    unsigned long long price;
    ///��. �������� ��/�
    unsigned int average_speed;

public:
    ///����������� �� ���������
    Transport();

    ///����������� � �����������
    /// string name1, - �������� ��
    /// unsigned short year_build1,  - ��� ������
    /// unsigned int mile_age1, - ������
    /// unsigned int consumption1,  - ������ �������
    /// const unsigned long long& price1, - ����
    /// unsigned int average_speed1 - ��.��������
    Transport(string name1, unsigned short year_build1, unsigned int mile_age1,
        unsigned int consumption1, const unsigned long long& price1,
        unsigned int average_speed1);
    
    ///�����-���������, ������������� �� ������������ ������ Means_transportation
    void move()
    {
        cout << "Transport is moving" << endl;
    }

    ///��������� ���������� �� ������� � ���� ������
    string to_string() const override
    {
        //std::string pi = "pi is " + std::to_string(3.1415926);
        string s = "Transport\n��������: " +  name + "\n��� ������: " + ::to_string(year_build) + "\n������: "
            + ::to_string(mile_age) + "\n������ �������: " + ::to_string(consumption) +
            "\n����: " + ::to_string(price) + "\n������� ��������: "
            + ::to_string(average_speed) + "\n";


        return s;

    }
    ///������ name1 - ���
    void set_name(string name1);


    ///������ year_build1 ��� ������
    void set_year_build(unsigned short year_build1);

    ///������ ��� �������, mile_age1 - ������
    void set_mile_age(unsigned int mile_age1);

    ///������ ��� ������, consumption1 - ������
    void set_consumption(unsigned int consumption1);

    ///������ ��� ����, price1 - ����
    void set_price(unsigned long long price1);

    ///������ - ��������� ��.��������,average_speed1 - ��.��������
    void set_average_speed(unsigned int average_speed1);

    ///��������� �����
    string get_name() const;

    ///��������� ���� ������
    unsigned short get_year_build() const;

    ///��������� �������
    unsigned int get_mile_age() const;


    ///��������� �������
    unsigned int get_consumption() const;

    ///��������� ����, price1 - ����
    unsigned long long get_price() const;

    ///��������� ��.��������
    unsigned int get_average_speed() const;



};

///����� - ��������� ������������ ��������, ����������� �� ������ ���������
class Air : public Transport
{
private:
    //��������� ������
    unsigned int flight_range;

    //������ ������
    unsigned int flight_altitude;

public:
    ///����������� �� �����.
    Air();

    ///����������� � �����������
    /// string name1, - �������� ��
    /// unsigned short year_build1,  - ��� ������
    /// unsigned int mile_age1, - ������
    /// unsigned int consumption1,  - ������ �������
    /// const unsigned long long& price1, - ����
    /// unsigned int average_speed1 - ��.��������
    /// unsigned int flight_range1, - ��������� ������
    /// unsigned int flight_altitude1 - ������ ������
    Air(string name1, unsigned short year_build1, unsigned int mile_age1,
        unsigned int consumption1, const unsigned long long& price1,
        unsigned int average_speed1, unsigned int flight_range1, unsigned int flight_altitude1);

    ///�����-���������, ������������� �� ������������ ������ Means_transportation
    void move()
    {
      
        cout << "Air Transport " + get_name() + " is flying" << endl;
    }

    ///������ ��������� ��������� ������, flight_range1 - ��������� ������
    void set_flight_range(unsigned int flight_range1);

    ///������ ��������� ������ ������, flight_altitude1 - ������ ������
    void set_flight_altitude(unsigned int flight_altitude1);

    ///��������� ��������� ������
    unsigned int get_flight_range() const;
    ///��������� ������ ������
    unsigned int get_flight_altitude() const;

    ///��������� ���������� �� ������� � ���� ������, ���������������� ����� �� Transport
    string to_string() const override
    {
        
        string s = "Air " + Transport::to_string() + "��������� �����: " + ::to_string(flight_range) +
            "\n������ ������: " + ::to_string(flight_altitude);


        return s;

    }

};


///����� - �������� ������������ ��������, ����������� �� ������ ���������
class Land : public Transport
{
private:
    ///�����������
    string transmission;

    //���-�� ����
    unsigned short number_of_wheels;
public:
    ///����������� �� ���������
    Land();

    ///����������� � �����������
    /// string name1, - �������� ��
    /// unsigned short year_build1,  - ��� ������
    /// unsigned int mile_age1, - ������
    /// unsigned int consumption1,  - ������ �������
    /// const unsigned long long& price1, - ����
    /// unsigned int average_speed1 - ��.��������
    /// string transmission1 - �����������
    /// unsigned short number_of_wheels1 - ���-�� �����
    Land(string name1, unsigned short year_build1, unsigned int mile_age1,
        unsigned int consumption1, const unsigned long long& price1,
        unsigned int average_speed1, string transmission1, 
        unsigned short number_of_wheels1);

    ///�����-���������, ������������� �� ������������ ������ Means_transportation
    void move()
    {
        cout << "Land Transport " + get_name() + " is coming" << endl;
    }

    ///��������� ���������� �� ������� � ���� ������, ���������������� ����� �� Transport
    string to_string() const override
    {
               //std::string pi = "pi is " + std::to_string(3.1415926);
        string s ="Land " +  Transport::to_string() + "�����������: " + transmission +
            "\n���������� ����: " + ::to_string(number_of_wheels);


        return s;

    }

    ///��������� ����������� transmission1 - ������������
    void set_transmission(string transmission1);

   
    ///��������� ���-�� �����
    void set_number_of_wheels(unsigned short number_of_wheels1);

    ///��������� �����������
    string get_transmission();

    
    ///��������� ���-�� �����
    unsigned short get_number_of_wheels();


};

///������ ���������� �� ��������, ����������� � �������
void print_means_transportation(vector<Transport*> arr);

///����� - ������
void repair();
///����� - ������, name1 - �������� ��
void repair(string name1);

///�������� ������ ���������
void all_assert();




