__author__ = "Охлопков"

"""
335а    

https://ivtipm.github.io/Programming/Glava10/index10.htm#z335


"""
import calculus

import tests

tests.test_7()

n = int(input("Введите число n "))

S = calculus.sum_of_mult_inc_elem(n)


print(f"Результат: {S:.10f}")




