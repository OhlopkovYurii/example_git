__author__ = "Охлопков"

"""
677а

https://ivtipm.github.io/Programming/Glava20/index20.htm#z677

"""
import numpy as np
import calculus

import tests

tests.test_8()

n = int(input("Введите число n "))

# символ _ в циклах он используется, чтобы показать, что эта переменная не применяется в вычислениях и не имеет никакого значения.


#создание матрицы из рандомных чисел от 0 до 1
matrix_a = np.random.rand(n, n)
#функция copy, чтобы создать независимую копию
matrix_b = matrix_a.copy()


matrix_a = calculus.input_elem_mtrx(matrix_a, n)

matrix_b = calculus.create_new_mtrx_with_condition(matrix_a, matrix_b)

print(matrix_b)
