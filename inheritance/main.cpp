//��� ���������
#include <windows.h>
#include "inheritance.h"
int main()
{
    srand(time(NULL));
    //��� ���������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //��������
    all_assert();
    
    
    
    
    //�������� ������� ������ ���������
    Transport ship("ship", 2010, 1000, 20, 1'000'000, 40);
    //����� ���������� �� �������
    cout << ship.to_string();
    //����� ������ move - ���������
    ship.move();

    //�������� ������� ������ ��������� ���������
    Air plane("plane", 2010, 1000, 20, 1'000'000, 40, 10'000, 10'000);
    //����� ���������� �� �������
    cout << plane.to_string();
    //����� ������ move - ���������
    plane.move();

    //�������� ������� ������ �������� ���������
    Land car("car", 2010, 1000, 20, 1'000'000, 40, "automatic",  4);
    Land car2("car2", 2010, 1000, 20, 1'000'000, 40, "automatic", 4);
    cout << car.to_string();
    ///����� ������ move �� ������������ ������ Land
    car.move();
    ///����� ������ move �� �������� ������ Transport
    car2.Transport::move();

    //     !!!! ship : "Transport [10]" ���������� �� ������� ���������� ��������� �� "Transport"	inheritance	D : \������������\3 �������\���\inheritance\inheritance\main.cpp	28

    // �������
    ///Transport ship[10];
    Air planes[15];
    Land cars[20];

    //������ �� ���������� �� ������� ������ ������������ ��������
    Transport* Means_transportation[45];

    //����� Transport ���� ����� ��������� �� ��� �������
    for (size_t i = 0; i < 10; i++)
    {
        Means_transportation[i] = new  Transport("ship", rand() % 10 + 5, 1 + rand() % 1000, 1 + rand() % 20, 1'000'000 + rand() % 10'000'000,
            1 + rand() % 10);
    }
    //����� Air ���� ����� ��������� �� ��� �������
    for (size_t i = 10; i < 25; i++)
    {
        Means_transportation[i] = new  Air("plane", rand() % 10 + 5, 1 + rand() % 1000, 1 + rand() % 20, 1'000'000 + rand() % 10'000'000,
            1 + rand() % 10, 100 + rand() % 10'000, 100 + rand() % 10'000);
    }

    //����� Land ���� ����� ��������� �� ��� �������
    for (size_t i = 25; i < 45; i++)
    {
        Means_transportation[i] = new  Land("car", rand() % 10 + 5, 1 + rand() % 1000, rand() % 20, 1'000'000 + rand() % 10'000'000,
            1 + rand() % 10, "mechanic", rand() % 10);
    }

    //����� ���������� �� ���� �������� �������
    for (size_t i = 0; i < 45; i++)
    {
        cout << Means_transportation[i]->to_string();
    }

    //������ - ������ �� ���������� �� ������� ������ ������������ ��������
    vector<Transport*> means_transportation2;
    for (size_t i = 0; i < 10; i++)
    {
        means_transportation2.push_back(new Air("plane", rand() % 10 + 5, 1 + rand() % 1000, 1 + rand() % 20, 1'000'000 + rand() % 10'000'000,
            1 + rand() % 10, 100 + rand() % 10'000, 100 + rand() % 10'000));
    }

    //����� ���������� �� ��������
    print_means_transportation(means_transportation2);

    //�������� ���������� �� �������
    Transport* t = new Transport();
    Land* l = new Land();
    Air* a = new Air();

    //���������� ���� ��������� � ����������� �� �������� � rand() % 2
    Transport* o = (rand() % 2 == 0) ? t : l;
    //����� ���������� �� ������� (���������� ���������������� �����)
    cout << o->to_string();
    cout << endl;
    //����� ������ ��������� (�� ����������� �����), ������ ����� Transport is moving
    o->move(); //���.����������� �� ��������

    // !!!

    // ������	c4703	������������ ������������ �������������������� ��������� 
    // ���������� - ��������� "o2"
    //Transport* o2;
    //switch (rand()%3){
    //
    //    case 0: o2 = t; break;
    //    case 1: o2 = l; break;
    //    case 2: o2 = a; break;
    //}
    //o2->set_name("transport");
    //cout << o2->to_string();
    //o2->move(); // ���. ����������� �� ��������

    {
        //�������� ���������� �� �������
        Transport* t = new Transport();
        Land* l = new Land();
        Air* a = new Air();

        //���������� ����
        Transport* o = a;

        //dynamic_cast - ����������� ��� ������������ ���������� ����� �� ����� ���������� ���������
        dynamic_cast<Air*> (o)->move(); //���. �������� ��������
        o->move(); //���. �������� �� ��������
    } 

    //������ static_poly - ������. ������������ - ���������� �������
    repair();
    cout << endl;
    repair("ship");
    
};
