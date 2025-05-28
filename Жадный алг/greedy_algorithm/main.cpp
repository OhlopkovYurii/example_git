///Автор Охлопков ИВТ-23

//для кодировки
#include <windows.h>

//для ввода вывода
#include <iostream>
#include "greedy_algorithm.h"
//для std перед cout и cin
using namespace std;

int main(int argc, char* argv[]) {

    //кодировка
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<Lesson> activities;
    if (argc <= 1) {
        std::cerr << "Необходимо указать хотя бы одну пару временных интервалов" << std::endl;
        cerr << "Введите название файла exe (например greedy_algorithm.exe) и через пробел аргументы," <<
            "которые хотите передать (например 2 3 4 5)\ngreedy_algorithm.exe 2 3 4 5";
        //выход из программы 
        return 1;
    }

    for (int i = 1; i < argc; i += 2) { // обрабатываем попарно: начало и конец
        char* endptr;
        Lesson lesson;
        lesson.startTime = std::strtod(argv[i], &endptr);
        if (*endptr != '\0') {
            std::cerr << "Ошибка преобразования startTime: " << argv[i] << std::endl;
            return 1;
        }
        if (i + 1 >= argc) {
            std::cerr << "Недостаточно аргументов для указания конца интервала" << std::endl;
            return 1;
        }
        lesson.endTime = std::strtod(argv[i + 1], &endptr);
        if (*endptr != '\0') {
            std::cerr << "Ошибка преобразования endTime: " << argv[i + 1] << std::endl;
            return 1;
        }

        activities.push_back(lesson);
    }

    // Проверка правильности ввода данных activities
    for (const auto& lesson : activities) {
        std::cout << "Начало: " << lesson.startTime << ", Конец: " << lesson.endTime << std::endl;
    }


    all_assert();

    int count = selectLesson(activities);
    cout << count << "\n";

    std::vector<Lesson> activities2 = { {1, 3}, {2, 4}, {3, 5}, {5,7}, {6,8}, {7,9} };
    count = selectLesson(activities2);
    cout << count;
    return 0;
}
