/// ����� �������� ���-23




/// ����� ��������������� �������
/// ��������� (���������) � ��� ������ �������� ����� Java ��� ����������
/// ����������� ����������������: ������� ������� � �������� ������ � ����������,
/// ������������ �������� � ���������� ������ ������ ��� ��������� �� ��������
public class Deq<T> {
    private DynamicArr<T> arr; // ������������ ������ ��� �������� ��������� �������
    private long rear;        // ������ ���������� ��������

    // �����������
    public Deq() {
        arr = new DynamicArr<>();
        rear = -1; // ������� �����
    }

    /// ���������� �������� � ����� �������
    /// item  - ������
    public void pushBackDeq(T item) {
        arr.pushBack(item);
        rear++;
    }

    /// ���������� �������� � ������ �������
    /// item - �������
    public void pushFrontDeq(T item)
    {
        arr.pushFront(item);
        rear++;
    }

    /// �������� �� ������ �������
    public void popFrontDeq()
    {
        arr.pop_front();
        rear--;
    }

    /// �������� �� ����� �������
    public void popBackDeq()
    {
        arr.pop_back();
        rear--;
    }


    /// ���������� �������� �� ������ �������
    /// ���������� ����� 1� ������� �������
    public T get_front() {
        if (isEmpty()) {
            throw new IllegalStateException("������� �����");
        }
       // T item = arr.get((int) front);
        T item = arr.get(0);
        arr.pop_front(); // ������� 1� �������
        rear--;//�������� ������ ����� �������
        if (0 > rear) {
            rear = -1; // ���������� �������, ���� ������� ��������
        }
        return item;
    }



    /// �������� ������� �������� ��� ����������
    /// ��������� IllegalStateException  ���� ������� �����
    public T peek() {
        if (isEmpty()) {
            throw new IllegalStateException("������� �����");
        }
        return arr.get(0);
    }

    /// ��������, ����� �� �������
    public boolean isEmpty() {
        return rear < 0;
    }

    /// ��������� ������� �������
    public long size() {
        if (isEmpty()) return 0;
        return rear + 1;
    }

    /// ������ �������
    /// ���� ������� ����� ������� �� ������
    public void print() {
        if (isEmpty()) {
            System.out.println("������� �����");
            return;
        }
        for (long i = 0; i <= rear; i++) {
            System.out.print(arr.get((int) i) + " ");
        }
        System.out.println();
    }

    public static void all_assert()
    {
        double eps = 0.000001;
        // ������� ������� ��� ����� �����
        Deq<Integer> deq = new Deq<>();


        deq.pushFrontDeq(1); // ��������� 1
        deq.pushFrontDeq(2); // ��������� 2
        deq.pushFrontDeq(3); // ��������� 3


        deq.pushBackDeq(4);
        deq.pushBackDeq(5);
        deq.pushBackDeq(6);


        assert(deq.size()- 6 <eps); // ������� ������: 6
        assert(deq.peek() - 1 < eps); // ������� ������ �������: 1
        assert(deq.get_front() - 1 < eps); // ��������� � �������: 1


        assert(deq.size() - 5 < eps); // ������� ������ 5
        assert(!deq.isEmpty());

        assert(deq.get_front() - 2 < eps); // ��������� � ������� 2
        assert(deq.get_front() - 3 < eps); // ��������� � ������� 3
        assert(deq.get_front() - 4 < eps); // ��������� � ������� 4
        assert(deq.get_front() - 5 < eps); // ��������� � ������� 5
        assert(deq.get_front() - 6 < eps); // ��������� � ������� 6

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

        assert(deq.size()- 3 <eps); // ������� ������: 3
        assert(deq.peek() - 11 < eps); // ������� ������ �������: 11


        deq.popFrontDeq();
        assert(deq.size()- 2 <eps); // ������� ������: 2
        assert(deq.peek() - 12 < eps); // ������� ������ �������: 12



        deq.popFrontDeq();
        assert(deq.size()- 1 <eps); // ������� ������: 1
        assert(deq.peek() - 13 < eps); // ������� ������ �������: 13




        ///���������� �� ������ �������
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
