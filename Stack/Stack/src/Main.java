//�������� ����

//https://github.com/ivtipm/Data-structures-and-algorithms/blob/main/current_plans/2025/2025_part_1.md#������-9-���������-������-����

public class Main {
    public static void main(String[] args) {
        Stack stack_test = new Stack();
        //�����
        stack_test.all_assert();


        Stack stack = new Stack();
        //���������� ��-���
        stack.add(1);
        stack.add(2);
        stack.add(3);
        stack.add(4);
        stack.add(5);

        //������
        stack.print();
        //��������� �������
        System.out.println("������� ����� " + stack.getTop());

        //�� ���� �� ����
        if (!stack.isEmpty())
            System.out.println("���� �� ������");
        else {
            System.out.println("���� ������");

        }
        stack.del();
        stack.print();
        System.out.println("������� ����� ����� �������� ������� " + stack.getTop());

        // �������� ��-���
        stack.del();
        stack.del();
        stack.del();
        stack.del();
        if (!stack.isEmpty())
            System.out.println("���� �� ������");
        else {
            System.out.println("���� ������");

        }

        stack.print();


    }
}
