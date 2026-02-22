__author__ = "Охлопков"

import calculus
import math

"""
136л
https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

"""
import tests

tests.test_5()

n = int(input("Введите число n "))

arr = [0.0] * n

for i in range(n):
    arr[i] = float(input(f"Введите число {i+1} "))

p = calculus.mult_elem_list(arr, n)

p = abs(p)

p = math.sqrt(p)

print(f"Результат: {p:.5f}")



