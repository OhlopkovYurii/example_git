//Автор Охлопков
//Напишите программу для поиска второго по величине элемента в списке из N значений.
// Сколько сравнений делает Ваш алгоритм в наихудшем случае ? 
// Результаты тестирования вывести в текстовый файл.
// 
#include "analysis.h"
#include <cassert>
#include <iostream>



///тесты
void all_assert()
{
    double eps = 0.00001;

    int arr[]{ 3,2,1,5,4 };
    size_t n = sizeof(arr) / sizeof(arr[0]);
    assert( search_max2<int>(arr, n)-4 < eps);

    int arr1[]{ 30, 40, 50, 60, 60};
    size_t n1 = sizeof(arr1) / sizeof(arr1[0]);
    assert(search_max2<int>(arr1, n1) - 50 < eps);


    float arr2[]{ -30.2, -30.2};
    size_t n2 = sizeof(arr2) / sizeof(arr2[0]);
    assert(search_max2<float>(arr2, n2) - ( - 30.2) < eps);

    int arr3[]{ 3};
    size_t n3 = sizeof(arr3) / sizeof(arr3[0]);
    try
    {
        assert(search_max2<int>(arr3, n3) - 3 < eps);
        exit(1);
    }
    catch (std::invalid_argument ex)
    {
        
    }
}

void read_file(std::string filename) {
    std::string line;

    std::ifstream in(filename); // окрываем файл для чтения
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            std::cout << line << std::endl;
        }
    }
    in.close();     // закрываем файл
}