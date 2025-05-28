//�������� ����

//https://github.com/ivtipm/Data-structures-and-algorithms/blob/main/current_plans/2025/2025_part_1.md#������-9-���������-������-����

//������ ��-��� ����� �������
//���� �� ������� �����
//������ - ��� ������  DynamicArr

import javax.management.DynamicMBean;

///����� ����
public class Stack<T> {

    ///������ �������
    private int top;

    /// ������� ������
    DynamicArr arr;

    ///�����������
    Stack()
    {
        //size = size1;
        arr = new DynamicArr();
        top=-1;
    }


    /// ���������� ��-�� � ������� �����
    /// data - �����
    void add(int data)
    {

        top++;
        arr.push(data);
    }

    /// �������� �� �������
    void del()
    {
        top--;
    }

    // ��������� ������� �����
    T getTop() {
        if (top < 0) {
            throw new IllegalStateException("���� ����");
        }
        return (T) arr.get((int) top); // ������ ��������� ���������� T
    }

    /// �������� �� ������ �� ����
    boolean isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /// ������ �����
    void print()
    {
        int cur_top = top;
        //top = 0;
        while(top > -1)
        {
            System.out.println(getTop());
            top--;
        }
        top = cur_top;

    }

    /// ��������
    static void  all_assert()
    {
        double eps = 0.000001;
        Stack<Integer> stack = new Stack();
        //�������� ��-� � ����
        stack.add(1);
        assert(stack.getTop() - 1 < eps);
        stack.add(2);
        assert(stack.getTop() - 2 < eps);
        stack.add(3);
        assert(stack.getTop() - 3 < eps);
        stack.add(4);
        assert(stack.getTop() - 4 < eps);
        stack.add(5);
        assert(stack.getTop() - 5 < eps);

        //�� ������ �� ��
        assert(stack.isEmpty() == false);

        //�������� ��-��� �� �����
        stack.del();
        assert(stack.getTop() - 4 < eps);

        stack.del();
        stack.del();
        stack.del();
        stack.del();
        //�������� �� ������� �����
        stack.del();
        assert(stack.isEmpty() == true);


    }
}
