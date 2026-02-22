__author__ = "Охлопков"


"""
114ж
https://ivtipm.github.io/Programming/Glava04/index04.htm#z114

"""
import tests

tests.test_4()

n = int(input("n = "))
p = 1
for i in range(2, n):
    p *= (i+1) / (i+2)

print(f"Результат: {p:.10f}")