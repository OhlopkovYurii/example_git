__author__ = "Охлопков"

""" 
6 Даны катеты прямоугольного треугольника. Найти его гипотенузу и площадь.
"""
import math
import tests

tests.test_1()

a = float(input("Введите 1й катет "))
b = float(input("Введите 2й катет "))

h = math.sqrt(a*a + b*b)
s = 1/2 * a * b

print(f"Гипотенуза = {h:.1f}")
print(f"Площадь = {s:.1f}")