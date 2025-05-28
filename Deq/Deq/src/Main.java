//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Deq.all_assert();

        double eps = 0.000001;
        // ������� ������� ��� ����� �����
        Deq<Integer> deq = new Deq<>();


        deq.pushFrontDeq(1); // ��������� 1
        deq.pushFrontDeq(2); // ��������� 2
        deq.pushFrontDeq(3); // ��������� 3


        deq.pushBackDeq(4);
        deq.pushBackDeq(5);
        deq.pushBackDeq(6);
        deq.pushBackDeq(0);

        deq.print();//������

        System.out.println(deq.size()); // ������� ������: 6
        System.out.println(deq.peek()) ; // ������� ������ �������: 3
        System.out.println(deq.get_front()) ; // ��������� � �������: 3


        assert(deq.size() - 5 < eps); // ������� ������ 5
        assert(!deq.isEmpty());

        System.out.println(deq.get_front()); // ��������� � ������� 2
        System.out.println(deq.get_front()); // ��������� � ������� 1
        System.out.println(deq.get_front()); // ��������� � ������� 4
        System.out.println(deq.get_front()); // ��������� � ������� 5
        System.out.println(deq.get_front()); // ��������� � ������� 6

        /// ���������� �� ������ �������
        try
        {
            deq.get_front();
            //System.exit(1);

        }
        catch(IllegalStateException ex)
        {

        }

        deq.pushBackDeq(11);
        deq.pushBackDeq(12);
        deq.pushBackDeq(13);

        System.out.println(deq.size()); // ������� ������: 3
        deq.peek(); // ������� ������ �������: 11


        deq.popFrontDeq();
        System.out.println(deq.size()); // ������� ������: 2
        System.out.println(deq.peek()); // ������� ������ �������: 12



        deq.popFrontDeq();
        System.out.println(deq.size()); // ������� ������: 1
        System.out.println(deq.peek()); // ������� ������ �������: 13




        /// ���������� �� ������ �������
        try
        {
            deq.popFrontDeq();
            //System.exit(1);

        }
        catch(IllegalStateException ex)
        {

        }



    }
}