//�����: �������� ���� ���-23

/// �-���, ������. ��������� �����, �������� ���.�����
float fact(float x)
{
    //�� �����. ��������� = 1
    float f = 1;
    //���� �� 1 �� ������ �����
    for (int i = 1; i <= x; i++)
        //���������� ����������
        f = f * i;
    return f;
}

///���������� �, �������� x,y,z
float a_calc(float x, float y, float z)

{
    //��������� � �� �������
    return log(abs((y - sqrt(abs(x))) * (x - y / (z + x * x / 4))));

}

///���������� b, �������� x,y,z
float b_calc(float x, float y, float z)

{
    //��������� b �� �������
    return x - x * x / fact(3) + pow(x, 6) / fact(5);

}

