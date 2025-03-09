// �����: �������� �.�.
#pragma once
#include <iostream>
// ���������� ��� ��������� ��������� �����
#include <random>   
#include <fstream>
using namespace std;

/// ���������� ������ ���� T* ������� size � ����������� ��������� min_value � ������������ max_value

template <typename T>//������
T* CreateArr(size_t size, T min, T max) {
    // ������ ��� ������� � ����������� ��� ������������ ��������� �����������
    // ����� ��� ������������� ���������� ��������� �����
    random_device rd;
    mt19937 gen(rd());  // ��������� ��������� �����
    uniform_int_distribution<> distr(min, max); // ����������� �������������

    T* array1 = new T[size];  // �������� �������

    for (size_t i = 0; i < size; ++i) {
        array1[i] = distr(gen);  // ���������� ������� ���������� �������
    }

    return array1;

}

/// ���������� ��������� ������������ ������ ���� T* ������� size � ����������� ��������� min_value 
template <typename T>
T* Monotonously_increasing_arr(size_t size, T min_value, T max_value) {
    // ������ ��� ������� � ����������� ��� ������������ ��������� �����������
     // ����� ��� ������������� ���������� ��������� �����
    random_device rd;
    mt19937 gen(rd());  // ��������� ��������� �����
    uniform_int_distribution<> distr(min_value, max_value); // ����������� �������������
    T* array = new T[size];  // �������� �������
    array[0] = distr(gen); // ������� ������� ������ ��������� �������
    for (size_t i = 1; i < size; ++i) {
        // ���������� ������� ���������� �������
        array[i] = array[i - 1] + distr(gen) / 100000; // ��� ����������� ����������� � ������� ���������� �������� ���������� distr(gen)/100000

    }
    return array;
}

/// ���������� ������ array ���� T* ������� size � ���� filename
template <typename T>
void write_file(T* array, size_t size, const string& filename) {
    ofstream f(filename); // ��������� ���� �� ������
    if (f.is_open()) {
        for (size_t i = 0; i < size; ++i) {
            f << array[i] << " ";
        }
        f.close();
    }
}

// ���������� ������� ��������, ���������� �� ������, ������������ ������ array ���� T* ������� ��� ���
template <typename T>
bool arr_is_sorted(T* array, size_t size) {
    for (size_t i = 1; i < size; ++i) {
        if (array[i] < array[i - 1]) { // ���� ������ ��������� ��-� ������� ������ �����������
            return false;  // ���� ������� �������
        }
    }
    return true; // ���� ������ ������������
}

/// ���� ������� value ������ ���������� ����������������� ������ - ���������� ������ �������� � ������� array ���� T* ������� size
/// ���� �� ������ - ���������� ������ �� 1 ������ �������� ������� �������
template <typename T>
size_t sequential_search(T* array, size_t size, T value) {
    for (size_t i = 0; i < size; ++i) {
        if (array[i] == value) { // ���� ������� ������� ������������� ��������
            return i;  // ���������� ������ ���������� ��������

        }
    }
    return size;  // ���� ������� �� ������, ���������� ������ �� 1 ������ ����������
}

/// ��������� ����������� ������� ��������� ������
/// ���������� ������ ��������, ���� �� ������, ����� -1
/// T* array - ������ � ����� T
/// long long left - ������ ������ ������ ��-�� �������, �� ��������� = size - 1
/// long long right - ������ ������ ������� ��-�� �������, �� �����. = 0
/// T value - �������� ��-�� ������� 
template <typename T>
long long binary_search_recursive(T* array, long long left, long long right, T value) {
    if (left > right) {
        return -1; // ������� �� ������
    }
    // ��������� ��������� ������ ������� [l,r]
    long long mid = left + (right - left) / 2.0; 
    //��������� ���� �� ���������� ���������
    if (array[mid] == value) {
        return mid; // ������ �������

    }
    
    else if (array[mid] < value) {
        return binary_search_recursive(array, mid + 1, right, value); // ���� � ������ �����
    }
    else {
        return binary_search_recursive(array, left, mid - 1, value); // ���� � ����� �����
    }
}


/* ������� 6. ����������
���������� ��������� ����������
���������� ��������. �������� ��������� ������� ��� ������� ���� ��������������� ��������. (�� 6 �����).
���� ��� ��������� ���������� ����������, ���������� �� O(n^2) � ������� ������ (�� 6 �����).
������� ���������� (quick sort). �������� ��������� ������� ��� ���������� �������(���������) ������������ �������� ��������.
���������� �����
�������� �����.
��������� � ���� ������ �� ��� �������. ����� �������.
�������������� �������, ������ ��������� � ���������� � ����.
���������� ������ BigO ��� ��������� ��������� ��������� ��� ������ ������� ������� ������, ������ �������������� ������ ������.
��������� ������ ������� ���������� ������� � ����������� �� ��� �������
��� ������������� ����������. �������� ����� ������ � ������� ��������� BigO ��� �������� ������.
�������� ������ ������� ������ ��� ������� ���������� ������� �� ����������� ����������. ��������, ����� �������� ��� ������� ���������.
���������� ��������� � ��������� ������� ������ ������� �� ���������� ������� � ������.*/

// ������� ��� ������� ���� ��������������� �����������
template <typename T>
void merge(T* arr, size_t left, size_t mid, size_t right) {
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    T* leftArr = new T[n1];
    T* rightArr = new T[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

/// ���������� �������� ������� arr � ����� �������� left � ������ �������� right
/// ��������� ���������: O(n log n) ��� ���� ������� ������� ������
/// �������������� ������: O(n)
template <typename T>
void mergeSort(T* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


/// ���������� ��������� ������� array ������� size
/// ��������� ���������: O(n) ��� ������� ������, O(n^2) - ��� �������� � ������� ������
/// �������������� ������: O(1)
template <typename T>
void bubbleSort(T* array, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

/// ���������� ��������� ������� array ������� size
/// ��������� ���������: O(n) ��� ������� ������, O(n^2) - ��� �������� � ������� ������
/// �������������� ������: O(1)
template <typename T>
void insertionSort(T* array, size_t size) {
    for (size_t i = 1; i < size; i++) {
        T key = array[i];
        size_t j = i;
        while (j > 0 && array[j - 1] > key) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key;
    }
}

/// ���������� ����� ������� array ������� size, ��������� ���� ���������� �������������� � ������� gapFunction
/// ��������� ���������: O(n log n) � ������ ������, O(n(log(n))^2) - � ������� � ������ ������
/// �������������� ������: O(1)
template <typename T>
void shellSort(T* array, size_t size, size_t(*gapFunction)(size_t, size_t)) {
    for (size_t gap = gapFunction(size, 0); gap > 0; gap = gapFunction(size, gap)) {
        for (size_t i = gap; i < size; i++) {
            T temp = array[i];
            size_t j = i;
            while (j >= gap && array[j - gap] > temp) {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = temp;
        }
    }
}

/// ������� ��� ��������� ������� array � ������ �������� low � ������� �������� high ������������ �������� ��������
template <typename T>
size_t partition(T* array, size_t low, size_t high) {
    T pivot = array[high];
    size_t i = low;

    for (size_t j = low; j < high; j++) {
        if (array[j] < pivot) {
            swap(array[i], array[j]);
            i++;
        }
    }
    swap(array[i], array[high]);
    return i;
}

/// ������� ���������� ������� array � ������ �������� low � ������� �������� high
/// ��������� ���������: O(n log n) � ������ � ������� ������, O(n^2) - � ������ ������
/// �������������� ������: O(log n) 
template <typename T>
void quickSort(T* array, size_t low, size_t high) {
    if (low < high) {
        size_t pi = partition(array, low, high);
        if (pi > 0) quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}


/// ������������������ ����� (�������) - ��� ����������� � 2 ����
size_t shellGap(size_t size, size_t prevGap);

/// ���� ������� ���������� ������� is_sorted
void test_is_sorted();

/// ������� ������������ ����������������� ������
void test_sequential_search();

/// ���� ������� ��������� ������
void test_binary_search();

void testMergeSort();

// ����� ��� bubbleSort
void testBubbleSort();

// ����� ��� insertionSort
void testInsertionSort();

// ����� ��� shellSort
void testShellSort();

// ����� ��� quickSort
//void testQuickSort();
