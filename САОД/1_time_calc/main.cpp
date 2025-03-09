// �����: �������� �.�.


#include <random>
#include <iostream>
#include "Arr_sort.h"
#include <chrono>
#include <algorithm>
using namespace chrono;
using namespace std;

/// ���������� ����� ���������� ������� func
template <typename Func>
int measure_time(Func func) { // � ��������� ����� ������������ std::function �� <functional>

	auto t0 = steady_clock::now();  // ������ ��������� �������
	func(); // ���������� ��������, ��� ��� �������
	auto t1 = steady_clock::now();  // ����� ��������� �������

	auto delta = duration_cast<milliseconds>(t1 - t0);  // ����� � �������������
	delta /= 1000; //����� � ���.
	//cout << "Time (milliseconds): " << delta.count() << endl;
	return delta.count();
}

int main()
{
	test_is_sorted(); // ���� ������� ����������
	test_sequential_search(); // ���� ������� ����������������� ������
	test_binary_search(); // ���� ������� ��������� ������
	
	size_t size = 100'000'000; // ������ �������
	const int MIN_VALUE = 0; // ����������� �������� ��������
	const int MAX_VALUE = 1'000'000; // ������������ �������� ��������
	int total_time = 0; // ����� ���� ��������� �������
	int total_time_sort = 0;


	unsigned long long* array = CreateArr<unsigned long long>(size, MIN_VALUE, MAX_VALUE); // ������ �� ��������� �����
	// ������ ��� ������� � ����������� ��� ������������ ��������� �����������
	// ����� ��� ������������� ���������� ��������� �����
	random_device rd;
	mt19937 gen(rd());  // ��������� ��������� �����
	uniform_int_distribution<> distr(0, MAX_VALUE); // ����������� �������������

	//  [&]  ���������� ��� ���������� � �������� ������� ��������� � ������� ������
	//   () - ���������
	//   { �������� }
	//������� std::sort() �� ������������� ����� <algorithm> ������������� ��� ���������� �������� ���������. 
	//������ ��� ��������� ������� ������������ ��������� � �������� ��������� ������������ ���������
	total_time_sort = measure_time(  [&]() {sort(&array[0], &array[size]);}  );

	cout <<"����� ���������� �������, ������������� �� ��������� ����� " + total_time_sort;

	cout << "\n";

	/*for (int i = 0; i < size; i++) {
		cout << array[i] << " " << i << "\n";
	}*/


	 //�������� 10000 ��������� ��� �����������������
	cout << "start of cycle";
	for (int i = 0; i < 1000; i++) {
		total_time_sort += measure_time([&](){ 
			mergeSort(array, 0, size - 1); 
			});
	}
	
	


	cout << "������� ����� ���������� ������� � ���., ����������� �� 1000 ���������: = " << total_time / 1000.0 << "\n"; // ������� ����� ���������� ����� 100 ���������
	delete[] array;

	total_time = 0;
	// ��������� ������������ ������ �� ��������� �����
	unsigned long long* monotonic_array = Monotonously_increasing_arr<unsigned long long>(size, MIN_VALUE, MAX_VALUE);

	// �������� 10000 ��������� ��� �����������������
	for (int i = 0; i < 1000; i++) {
		unsigned long long value_to_search = distr(gen); // ��������� �����, ������� ����� ������ � �������
		total_time += measure_time([&]() { // ����������� �������� - ��������� �������(��, ��� ������ ������)
			size_t index = sequential_search<unsigned long long>(monotonic_array, size, value_to_search);
			});
	}
	// ������� ����� ���������� ����� 1000 ���������
	cout << "������� ����� � ���. ���������� ��������� ������������� ������� �� ��������� ����� ����� 1000 ��������� = " << total_time / 1000.0 << "\n";

	total_time = 0;

	// �������� 1000 ��������� ��� ��������� ������
	for (int i = 0; i < 1000; i++) {
		unsigned long long value_to_search = distr(gen); // ��������� �����, ������� ����� ������ � �������
		total_time += measure_time([&]() { // ����������� �������� - ��������� �������(��, ��� ������ ������)
			size_t index = binary_search_recursive<unsigned long long>(monotonic_array, 0, size-1, value_to_search);
			});
	}
	// ������� ����� ���������� ����� 10000 ��������� ��� ��������� ������
	cout << "������� ����� ���������� ������� ������� ��������� ������ � ���. ����� 1000 ��������� ��� ��������� ������ = " << total_time / 1000.0;
	delete[] monotonic_array; 


	cout << "\n" << total_time_sort;
}

