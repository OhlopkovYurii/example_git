
__author__ = "Охлопков"

import calculus
import math
import sys

"""
136л
https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

"""
import tests

tests.test_5()

if __name__ == "__main__":
    # Проверяем количество аргументов
    if len(sys.argv) < 3:
        print("Использование: python script.py <n> <arr[0]> <arr[1]> ... <arr[n-1]>")
        sys.exit(1)

    n = int(sys.argv[1])
    arr = [0.0] * n

    for i in range(0, n):
        arr[i] = float(sys.argv[i+2])

    p = calculus.mult_elem_list(arr, n)

    p = abs(p)

    p = math.sqrt(p)


    print(f"Размер: {n}")
    for i in range(0, n):
        print(f"Элемент {i}: {arr[i]}")


    print(f"Результат: {p:.5f}")

