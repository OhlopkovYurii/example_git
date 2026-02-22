__author__ = "Охлопков"


"""
178 Даны натуральные числа n, a 1...an. Определить количество членов ak последовательности a1,...,an:
е) имеющих четные порядковые номера и являющихся нечтными числами.
"""
import calculus, random

import tests

tests.test_6()

RND_MIN = 1
RND_MAX = 100

n = int(input("Введите число n "))

a = [0] * n
for i in range(n):
    a[i] = random.uniform(RND_MIN, RND_MAX)

for i in range(n):
    a[i] = float(input(f"Введите arr[{i}] "))

k = calculus.item_counter(a, n)
print(k)
    