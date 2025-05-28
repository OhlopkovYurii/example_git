/// ����� �������� ���-23




/// ����� �������
/// ��������� (���������) � ��� ������ �������� ����� Java ��� ����������
/// ����������� ����������������: ������� ������� � �������� ������ � ����������,
/// ������������ �������� � ���������� ������ ������ ��� ��������� �� ��������
public class Queue<T> {
    private DynamicArr<T> arr; // ������������ ������ ��� �������� ��������� �������
    private long rear;        // ������ ���������� ��������

    // �����������
    public Queue() {
        arr = new DynamicArr<>();
        rear = -1; // ������� �����
    }

    /// ���������� �������� � ����� �������
    /// item  - ������
    public void enqueue(T item) {
        arr.push(item);
        rear++;
    }

    /// ���������� �������� �� ������ �������
    /// ���������� ����� 1� ������� �������
    public T dequeue() {
        if (isEmpty()) {
            throw new IllegalStateException("������� �����");
        }
        T item = arr.get(0);
        arr.pop(); // ��������� ������ �������
        rear--;//�������� ������ ����� �������
        if (0 > rear) {
            rear = -1; // ���������� �������, ���� ������� ��������
        }
        return item;
    }

    /// �������� ������� �������� ��� ����������
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
        Queue<Integer> queue = new Queue<>();
        queue.enqueue(1); // ��������� 1
        queue.enqueue(2); // ��������� 2
        queue.enqueue(3); // ��������� 3


        assert(queue.size()- 3 <eps); // ������� ������: 3
        assert(queue.peek() - 1 < eps); // ������� ������ �������: 1
        assert(queue.dequeue() - 1 < eps); // ��������� � �������: 1


        assert(queue.size() - 2 < eps); // ������� ������: 2
        assert(!queue.isEmpty());

        assert(queue.dequeue() - 2 < eps); // ��������� � �������: 2
        assert(queue.dequeue() - 3 < eps); // ��������� � �������: 3

        /// ���������� �� ������ �������
        try
        {
            queue.dequeue();
            //System.exit(1);

        }
        catch(IllegalStateException ex)
        {

        }

    }




}
