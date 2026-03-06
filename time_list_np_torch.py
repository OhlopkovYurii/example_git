__author__ = "Ohlopkov"


"""
3. Скорость работы: List vs NumPy vs Torch
Сравните время перемножения двух матриц

представляя матрицы как списки Python
представляя матрицы как numpy array
представляя матрицы как torch tensor (на GPU и CPU)
Объясните разницу во времени.

Чтобы результаты были надёжными, повторите замеры несколько раз. 
Используйте такие размеры матриц, чтобы перемножение занимало как минимум несколько десятков секунд на CPU.

https://github.com/ivtipm/ProcessCalculus/blob/master/tasks/readme.md#3-скорость-работы-list-vs-numpy-vs-torch

"""
import time, numpy as np, torch, random
import create_list_np_torch
#кол-во строк
n = 500
#кол-во столбцов
m = 500
#количество итераций для цикла
num = 3

#диапазон для рандомных чисел
begin = 0
end = 100
#время измерений
s1, s2, s3 = 0.0, 0.0, 0.0


for i in range(num):
    #создание матриц в виде обычных списков
    A, B, r = create_list_np_torch.create_list_mtrx(n, m, begin, end)

    curr1 = time.time()

    #перемножение матриц
    r = create_list_np_torch.mult_list_mtrx(A, B, r)

    curr2 = time.time()
    s1+=curr2-curr1

    #создание матриц как numpy списков
    A2, B2 = create_list_np_torch.create_np_mtrx(n, m)
    r2 = np.dot(A2, B2)

    curr3 = time.time()
    s2+=curr3-curr2

    #создание  матриц как torch списков
    A3 = torch.randn(n, m)

    B3 = torch.randn(n, m)

    r3 = A3.mul(B3)
    curr4 = time.time()
    s3+=curr4-curr3

s1 = s1 / num
s2 = s2 / num
s3 = s3 / num

print(f"Время перемножения матриц как обычных списков: {s1}")
print(f"Время перемножения матриц как numpy array: {s2}")
print(f"Время перемножения матриц как torch array: {s3}")