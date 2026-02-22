// Автор: Охлопков Ю.С.


#include <random>
#include <iostream>
#include "Arr_sort.h"
#include <chrono>
#include <algorithm>
using namespace chrono;
using namespace std;

/// Возвращает время выполнения функции func
template <typename Func>
int measure_time(Func func) { // в параметре можно использовать std::function из <functional>

	auto t0 = steady_clock::now();  // начало измерения времени
	func(); // компилятор понимает, что это функция
	auto t1 = steady_clock::now();  // конец измерения времени

	auto delta = duration_cast<milliseconds>(t1 - t0);  // время в миллисекундах
	delta /= 1000; //время в сек.
	//cout << "Time (milliseconds): " << delta.count() << endl;
	return delta.count();
}

int main()
{
	test_is_sorted(); // тест функции сортировки
	test_sequential_search(); // тест функции последовательного поиска
	test_binary_search(); // тест функции бинарного поиска
	
	size_t size = 100'000'000; // размер массива
	const int MIN_VALUE = 0; // минимальное значение элемента
	const int MAX_VALUE = 1'000'000; // максимальное значение элемента
	int total_time = 0; // сумма всех измерений времени
	int total_time_sort = 0;


	unsigned long long* array = CreateArr<unsigned long long>(size, MIN_VALUE, MAX_VALUE); // Массив из случайных чисел
	// Объект для доступа к аппаратному или программному источнику случайности
	// нужен для инициализации генератора случайных чисел
	random_device rd;
	mt19937 gen(rd());  // Генератор случайных чисел
	uniform_int_distribution<> distr(0, MAX_VALUE); // равномерное распределение

	//  [&]  фиксируйте все переменные в пределах области видимости с помощью ссылки
	//   () - параметры
	//   { действия }
	//Функция std::sort() из заголовочного файла <algorithm> предназначена для сортировки диапазон элементов. 
	//Первые два параметра функции представляют начальный и конечный итераторы сортируемого диапазона
	total_time_sort = measure_time(  [&]() {sort(&array[0], &array[size]);}  );

	cout <<"Время сортировка массива, составленного из случайных чисел " + total_time_sort;

	cout << "\n";

	/*for (int i = 0; i < size; i++) {
		cout << array[i] << " " << i << "\n";
	}*/


	 //Проводим 10000 измерений для последовательного
	cout << "start of cycle";
	for (int i = 0; i < 1000; i++) {
		total_time_sort += measure_time([&](){ 
			mergeSort(array, 0, size - 1); 
			});
	}
	
	


	cout << "среднее время сортировки массива в сек., проведенное за 1000 измерений: = " << total_time / 1000.0 << "\n"; // среднее время выполнения среди 100 измерений
	delete[] array;

	total_time = 0;
	// Монотонно возрастающий массив из случайных чисел
	unsigned long long* monotonic_array = Monotonously_increasing_arr<unsigned long long>(size, MIN_VALUE, MAX_VALUE);

	// Проводим 10000 измерений для последовательного
	for (int i = 0; i < 1000; i++) {
		unsigned long long value_to_search = distr(gen); // случайное число, которое будем искать в массиве
		total_time += measure_time([&]() { // фактический параметр - анонимная функция(всё, что внутри скобок)
			size_t index = sequential_search<unsigned long long>(monotonic_array, size, value_to_search);
			});
	}
	// среднее время выполнения среди 1000 измерений
	cout << "среднее время в сек. сортировки монотонно возрастающего массива из случайных чисел среди 1000 измерений = " << total_time / 1000.0 << "\n";

	total_time = 0;

	// Проводим 1000 измерений для бинарного поиска
	for (int i = 0; i < 1000; i++) {
		unsigned long long value_to_search = distr(gen); // случайное число, которое будем искать в массиве
		total_time += measure_time([&]() { // фактический параметр - анонимная функция(всё, что внутри скобок)
			size_t index = binary_search_recursive<unsigned long long>(monotonic_array, 0, size-1, value_to_search);
			});
	}
	// среднее время выполнения среди 10000 измерений для бинарного поиска
	cout << "среднее время сортировки массива методом бинарного поиска в сек. среди 1000 измерений для бинарного поиска = " << total_time / 1000.0;
	delete[] monotonic_array; 


	cout << "\n" << total_time_sort;
}

