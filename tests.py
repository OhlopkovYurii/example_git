"""
Модуль с тестами
"""

__author__ = "Охлопков"

import math, calculus, numpy as np
def test_1():
    """ 
    6 Даны катеты прямоугольного треугольника. Найти его гипотенузу и площадь.
    """
    #1
    a = 3
    b = 4
    h = math.sqrt(a*a + b*b)
    s = 1/2 * a* b

    assert h == 5
    assert s == 6

    #2
    a = 0
    b = 0
    h = math.sqrt(a*a + b*b)
    s = 1/2 * a* b
    assert h == 0
    assert s == 0

    #3
    a = 2
    b = 3
    h = math.sqrt(a*a + b*b)
    s = 1/2 * a* b
    assert h == math.sqrt(13)
    assert s == 3

    # print(f"Гипотенуза = {h:.1f}")
    # print(f"Площадь = {s:.1f}")


def test_2():
    """
    39 Даны два действительных числа. Вывести первое число, если оно больше второго, и оба числа, если это не так.
    """

    a = -3.5
    b = 3.6

    if a > b:
        
        #исключение AssertionError возникает, когда проверка с помощью оператора assert не проходит
        raise AssertionError()
    else:
        pass

    a = 7
    b = -1

    if a>b:
        pass
    else:
        raise AssertionError()

    a = 7
    b = 7

    if a>b:
        pass
    else:
        raise AssertionError()
        

def test_3():
    
    #угрожает
    k = 3
    l = 5

    m = 5
    n = 4


    
    if (m-1 == k and n-3 == l) \
    or (m+1 == k and n+2 == l) \
    or (m+1 == k and n-3 == l) \
    or (m-1 == k and n+2 == l)\
    or (m-2 == k and n+1 == l)\
    or (m-2 == k and n-1 == l)\
    or (m+2 == k and n-1 == l)\
    or (m+2 == k and n+1 == l):
        pass


    else:
        raise AssertionError()
    
    #не угрожает
    k = 4
    l = 5

    m = 5
    n = 4

    
    if (m-1 == k and n-3 == l) \
    or (m+1 == k and n+2 == l) \
    or (m+1 == k and n-3 == l) \
    or (m-1 == k and n+2 == l)\
    or (m-2 == k and n+1 == l)\
    or (m-2 == k and n-1 == l)\
    or (m+2 == k and n-1 == l)\
    or (m+2 == k and n+1 == l):
        AssertionError()


    else:
        pass


    #не угрожает
    k = 7
    l = 3

    m = 5
    n = 4

    
    if (m-1 == k and n-3 == l) \
    or (m+1 == k and n+2 == l) \
    or (m+1 == k and n-3 == l) \
    or (m-1 == k and n+2 == l)\
    or (m-2 == k and n+1 == l)\
    or (m-2 == k and n-1 == l)\
    or (m+2 == k and n-1 == l)\
    or (m+2 == k and n+1 == l):
        pass


    else:
        AssertionError()

def test_4():
    eps = 0.00001
    n = 3
    p = 1
    for i in range(2, n):
        p *= (i+1) / (i+2)
    assert p == 3/4

    n = 4
    p = 1
    for i in range(2, n):
        p *= (i+1) / (i+2)
    assert abs(p - 3/4 * 4/5)<eps

    n = 5
    p = 1
    for i in range(2, n):
        p *= (i+1) / (i+2)
    assert abs(p - 3/4 * 4/5 * 5/6)<eps


def test_5():
    #1
    n = 3
    arr = [1.,2.,3.]
    p = calculus.mult_elem_list(arr, n)
    assert p==6
    p = abs(p)
    assert p==6
    p = math.sqrt(p)
    assert p == math.sqrt(6)

    #2
    n = 4
    arr = [-1,2,3,6]
    p = calculus.mult_elem_list(arr, n)
    assert p==-36
    p = abs(p)
    assert p==36
    p = math.sqrt(p)
    assert p == 6

    #3
    n = 5
    arr = [0,0,0,0,0]
    p = calculus.mult_elem_list(arr, n)
    assert p==0
    p = abs(p)
    assert p==0
    p = math.sqrt(p)
    assert p == 0


def test_6():
    #1
    n = 3
    a = [1,2,3]
    # функция считает элементы, которые нечетные, а порядковый номер четный
    # Нумерация элементов с 1
    k = calculus.item_counter(a, n)
    assert k == 0


    #2
    n = 2
    a = [-2,-2]
    # функция считает элементы, которые нечетные, а порядковый номер четный
    # Нумерация элементов с 1
    k = calculus.item_counter(a, n)
    assert k == 0

    #2
    n = 5
    a = [0,0,0,0,0]
    # функция считает элементы, которые нечетные, а порядковый номер четный
    # Нумерация элементов с 1
    k = calculus.item_counter(a, n)
    assert k == 0 #0 - ненатур число

def test_7():
    #0
    n = 1
    S = calculus.sum_of_mult_inc_elem(n)
    assert S == 1

    #1
    n = 2
    S = calculus.sum_of_mult_inc_elem(n)
    assert S == 1+2*(2+1)*(2+2)

    #2
    n = 3
    S = calculus.sum_of_mult_inc_elem(n)
    assert S == 1+2*(2+1)*(2+2)+3*(3+1)*(3+2)*(3+3)*(3+4)*(3+5)*(3+6)

def test_8():
    #1
    matrix_a = np.array([
        [1,2],
        [-2,0]
    ])

    #функция copy, чтобы создать независимую копию
    matrix_b = np.array([
        [1,2],
        [-2,0]
    ])


    matrix_b = calculus.create_new_mtrx_with_condition(matrix_a, matrix_b)


    assert np.array_equal(matrix_b, np.array([[0,-2], [2,1]])), "Матрицы не равны"

    #2
    #создание матрицы из рандомных чисел от 0 до 1
    matrix_a = np.array([
        [1,2,3],
        [4,5,6],
        [7,8,9]
    ])

    #функция copy, чтобы создать независимую копию
    matrix_b = np.array([
        [1,2,3],
        [4,5,6],
        [7,8,9]
    ])


    matrix_b = calculus.create_new_mtrx_with_condition(matrix_a, matrix_b)

    
    assert np.array_equal(matrix_b, 
                          np.array([
                              [28,26,24], 
                              [22,20,18], 
                              [16,14,12]])), "Матрицы не равны"


    #3
    #создание матрицы из рандомных чисел от 0 до 1
    matrix_a = np.array([
        [0,0,0],
        [0,0,0],
        [0,0,0]
    ])

    #функция copy, чтобы создать независимую копию
    matrix_b = np.array([
        [1,2,3],
        [4,5,6],
        [7,8,9]
    ])


    matrix_b = calculus.create_new_mtrx_with_condition(matrix_a, matrix_b)


    assert np.array_equal(matrix_b, np.array([[0,0,0], [0,0,0], [0,0,0]])), "Матрицы не равны"