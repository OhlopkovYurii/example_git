//Автор Охлопков
//Напишите программу для поиска второго по величине элемента в списке из N значений.
// Сколько сравнений делает Ваш алгоритм в наихудшем случае ? 
// Результаты тестирования вывести в текстовый файл.

///функция находит второй по величине элемент массива
//T* a - массив
// size_t size - размер
#include <string>
#include <fstream>
template <typename T>
T search_max2(T* a, size_t size)
{
    if (size < 2)
    {
        throw std::invalid_argument("невозможно найти 2й по величине элемент");
    }
    

    T max1, max2;

    // Инициализация max1 и max2 первыми двумя элементами
    if (a[0] > a[1]) {
        max1 = a[0];
        max2 = a[1];
    }
    else {
        max1 = a[1];
        max2 = a[0];
    }



    for (size_t i = 2; i < size; i++) {
        if (a[i] > max1) {
            max2 = max1;
            max1 = a[i];
        }
        else if (a[i] < max1 && a[i] >= max2) {
            max2 = a[i];
        }
    }

    return max2;

}


template <typename T>
void write_file(T* a, size_t size, T data, std::string filename)
{
    std::ofstream out;          // поток для записи
    out.open(filename);      // открываем файл для записи

    for (size_t i = 0; i < size; i++)
    {
        out << a[i] << " ";
    }
    if (out.is_open())
    {
        out << "The second largest number " << data << std::endl;
    }
    out.close();
}




void read_file(std::string filename);

///тесты
void all_assert();


