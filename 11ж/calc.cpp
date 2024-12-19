//Автор: Охлопков Юрий ИВТ-23

/// ф-ция, вычисл. факториал числа, передача вещ.числа
float fact(float x)
{
    //по умолч. факториал = 1
    float f = 1;
    //цикл от 1 до самого числа
    for (int i = 1; i <= x; i++)
        //нахождение факториала
        f = f * i;
    return f;
}

///вычисление а, передача x,y,z
float a_calc(float x, float y, float z)

{
    //вычисляем а по формуле
    return log(abs((y - sqrt(abs(x))) * (x - y / (z + x * x / 4))));

}

///вычисление b, передача x,y,z
float b_calc(float x, float y, float z)

{
    //вычисляем b по формуле
    return x - x * x / fact(3) + pow(x, 6) / fact(5);

}

