//�����: �������� ���-23

#include <iostream>
#include "CarClass2.h"
#include <fstream>
#include <string>
using namespace std;

//�������� �����
void print_car(const CarClass& car) {
    cout << car.to_my_string();
}

int main() {
    

    all_assert();

    ofstream file_in("file_in.txt");          // ����� ��� ������

    ifstream file_out("file_out.txt");          // ����� ��� ������
   // file.open("file.txt", ios::in); // �������� ���� ��� ������

    
    //������ �� ��������
    // 100 ��� ������ ������ �� �����.
    CarClass car[100];
    

    //�������� ������ ������� ������
    CarClass car4;

    //���������� ����
    car[4].set_price(500'000);
    // cout << car[4].to_string();

    //��� ������ �� ��������
    // 200 ��� ������ ������ �� �����.
    CarClass *car2 = new CarClass[200];    

    //���������� ����
    car2[4].set_price(500'000);
    // cout << car2[4].to_string();

    // delete[] car2;



    // ������ �� ���������� �� �������
    CarClass* car3[3];      // ������� �� �������

    // ����������� ��������� ������
    CarClass* car5 = new CarClass();

    

    //��������� ����
    car4.set_price(500'000);



    // year_build1 - ��� ������, mile_age1 - ������, transmission1 - �����������
    // consumption1 - ������ �������, num_owners1 - ���-�� ����������, 
    // price1 - ����, handlebar_left - ���� (����� / ������)
    //���������� ����������
    for (size_t i = 0; i < 3; i++) {
        car3[i] = new CarClass(rand() % 20, rand() % 50'000,"automatic", rand() % 10, rand() % 5, rand() % 1'000'000, true);
        

        cout << car3[i]->to_my_string() << "\n";
    }

    //������ � ����
    // ���� ���� ������
    if (file_in.is_open())
    {
        // ���������� ��������� ������ �� ����� �����
        file_in.seekp(0, std::ios::end);

        for (size_t i = 0; i < 3; i++) {
            string data = car3[i]->to_my_string();
            file_in << data  << endl;
        }
        file_in.close();
    }
    cout << '\n';


 
    //������ �� �����
    // ���� ���� ������
    if (file_out.is_open())
    {
        while (1) {
            //���������� � �ar5 ���-�� ����������
            string s;
            file_out >> s; 
            car5->set_num_owners(stoi(s));

            //���������� � �ar5 ������
            file_out >> s; 
            car5->set_mile_age(stoi(s));

            //���������� � �ar5 ����
            file_out >> s; 
            car5->set_price(stoi(s));
            if (file_out.eof()) break;
            
            
        }
    }
    //����� ����� car5 
    cout << "car5"<< endl;
    
    cout <<  to_string(car5->get_num_owners()) << endl;
    cout <<  to_string(car5->get_mile_age())   << endl;
    cout <<  to_string(car5->get_price());

    //�������� �������
    for (size_t i = 0; i < 3; i++)
        delete car3[i];


    //�������� �������
    delete car5;

    file_out.close();
    file_in.close();

   

}