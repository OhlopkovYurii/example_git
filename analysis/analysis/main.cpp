//Автор Охлопков
//Напишите программу для поиска второго по величине элемента в списке из N значений.
// Сколько сравнений делает Ваш алгоритм в наихудшем случае ? 
// Результаты тестирования вывести в текстовый файл.

//https ://github.com/ivtipm/Data-structures-and-algorithms/blob/main/tasks/task_s1_alg_analysis.md

#include <iostream> 
#include "analysis.h"
using namespace std;

///работа с файлами


int main() {
    //тесты
    all_assert();


    int arr[5]{ 3,2,1,5,4 };
    size_t n = sizeof(arr) / sizeof(arr[0]);
    try
    {
        cout << "The second largest number " <<search_max2<int>(arr, n) << "\n";
    }
    catch (invalid_argument ex)
    {
        cout << ex.what();
    }

    int arr1[]{ 30, 40, 50, 60, 60 };
    size_t n1 = sizeof(arr1) / sizeof(arr1[0]);
    //cout << search_max2<int>(arr1, n1) << "\n";
    try
    {
        cout << "The second largest number "  << search_max2<int>(arr1, n1) << "\n";
    }
    catch (invalid_argument ex)
    {
        cout << ex.what();
    }

    write_file<int>(arr,n, search_max2<int>(arr, n), "analysis.txt");

    read_file("analysis.txt");

    
}