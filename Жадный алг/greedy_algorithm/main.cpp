///����� �������� ���-23

//��� ���������
#include <windows.h>

//��� ����� ������
#include <iostream>
#include "greedy_algorithm.h"
//��� std ����� cout � cin
using namespace std;

int main(int argc, char* argv[]) {

    //���������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<Lesson> activities;
    if (argc <= 1) {
        std::cerr << "���������� ������� ���� �� ���� ���� ��������� ����������" << std::endl;
        cerr << "������� �������� ����� exe (�������� greedy_algorithm.exe) � ����� ������ ���������," <<
            "������� ������ �������� (�������� 2 3 4 5)\ngreedy_algorithm.exe 2 3 4 5";
        //����� �� ��������� 
        return 1;
    }

    for (int i = 1; i < argc; i += 2) { // ������������ �������: ������ � �����
        char* endptr;
        Lesson lesson;
        lesson.startTime = std::strtod(argv[i], &endptr);
        if (*endptr != '\0') {
            std::cerr << "������ �������������� startTime: " << argv[i] << std::endl;
            return 1;
        }
        if (i + 1 >= argc) {
            std::cerr << "������������ ���������� ��� �������� ����� ���������" << std::endl;
            return 1;
        }
        lesson.endTime = std::strtod(argv[i + 1], &endptr);
        if (*endptr != '\0') {
            std::cerr << "������ �������������� endTime: " << argv[i + 1] << std::endl;
            return 1;
        }

        activities.push_back(lesson);
    }

    // �������� ������������ ����� ������ activities
    for (const auto& lesson : activities) {
        std::cout << "������: " << lesson.startTime << ", �����: " << lesson.endTime << std::endl;
    }


    all_assert();

    int count = selectLesson(activities);
    cout << count << "\n";

    std::vector<Lesson> activities2 = { {1, 3}, {2, 4}, {3, 5}, {5,7}, {6,8}, {7,9} };
    count = selectLesson(activities2);
    cout << count;
    return 0;
}
