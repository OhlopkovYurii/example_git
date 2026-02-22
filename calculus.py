"""
модуль с функциями:
    перемножение элементов последовательности
    подсчет элементов
    сумма из произведений элементов
    ввод элементов
    создание новой матрицы
    печать матрицы

"""

__author__ = "Охлопков"


def mult_elem_list(arr1:list[float], n:int)->float:
    """
    функция перемножает элементы последовательности
    n - размер последовательности
    возвращает произведение типа float
    """
    p = 1.0
    for i in range(n):
        p*=arr1[i]
    return p    


def item_counter(a:list[int], n:int)->int:
    """
    функция считает элементы, которые нечетные, а порядковый номер четный
    Нумерация элементов с 1
    n - размер последовательности
    возвращает количество с типом int
    """
    k=0
    for i in range(n):
        #проверка что число натуральное
        if(a[i]>0):
            if (i+1) % 2 == 0 and a[i] % 2 != 0:
                k+=1
    return k



def sum_of_mult_inc_elem(n:int)->int:
    """
    функция подсчитывает сумму из произведений элементов типа k*(k+1)*(k+2)*...*k**2
    n - количество слагаемых
    """
    S=0
    for i in range(1,n+1):
        s = i
        p = 1
        while (s<=i**2):
            p*=s
            s+=1
        S += p
    return S



def input_elem_mtrx(matrix_a, n):
    """
    функция ввода элементов матрицы
    matrix_a - матрица
    n - размер матрицы
    """
    for i in range(n):
        for j in range(n):
            matrix_a[i][j] = float(input(f"Введите элемент матрицы {i+1, j+1} "))
    return matrix_a


def create_new_mtrx_with_condition(matrix_a, matrix_b):
    """
    создание новой матрицы их старой по условию
    matrix_a - старая матрица
    matrix_b - новая матрица
    n - размер матрицы
    возвращает новую матрицу
    """
    
  
    n, _ = matrix_a.shape  # получаем  размер

    #.ndim — возвращает количество измерений (осей) в массиве. Для 2D-матрицы результат будет 2.
    for i in range(n):
        for j in range(n):
            #можно обратиться к целой строке или столбцу с помощью оператора :
            # Он позволяет выбрать все элементы указанной строки или столбца:
            #sum() - возвращает сумму всех элементов массива.
            matrix_b[i,j] = matrix_a.sum() - matrix_a[i,:].sum()  - matrix_a[:,j].sum() + matrix_a[i,j]
    return matrix_b

def print_mtrx(matrix_b, n):
    """
    печать матрицы
    matrix_b - матрица
    n - размер матрицы
    """
    for i in range(n):
        for j in range(n):
            print(f"Элемент матрицы {i+1, j+1, matrix_b[i,j]}")
    