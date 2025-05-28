/// ����� �������� ���-23

import java.util.Arrays;

/// ����� ������������ ������
public class DynamicArr<T> {
    // ����������� ������
    private T[] arr;
    // ����������� �������
    private long capacity;
    // ����� ���������� �������� �������
    private long current;

    // ����������� ��� ����������
    //���������� �������������, ��� ���������� (T[]) ����� ���� ������������
    @SuppressWarnings("unchecked")
    public DynamicArr() {
        // �������������� ������ �������� � �������� � T[]
        arr = (T[]) new Object[1];
        capacity = 1;
        current = 0;
    }

    /// ����������� � �����������
    ///���������� �������������, ��� ���������� (T[]) ����� ���� ������������
    /// T[] arr1, - ������
    /// long capacity1, �����������
    /// long current1 ����� ���������� �������� �������
    @SuppressWarnings("unchecked")
    public DynamicArr(T[] arr1, long capacity1, long current1) {
        if (arr1 == null || capacity1 < current1 || capacity1 <= 0) {
            throw new IllegalArgumentException("�������� ��������� ������������");
        }
        this.arr = arr1.clone(); // �������� ������ ��� ������������
        this.capacity = capacity1;
        this.current = current1;
    }


    /// ����������� �����������, other - ���������� ������
    public DynamicArr(DynamicArr other)
    {
        current = other.size();
        capacity = other.getCapacity();
        arr = (T[]) new Object[(int) capacity];
        // ����������� �������� �����������
        for (int i = 0; i < current; i++)
            arr[i] = (T) other.get(i);
    }


    /// ����� ��������� �����������
    public void copy_arr(T[] arr1)
    {
        this.arr = arr1.clone(); // �������� ������ ��� ������������
    }

    /// ������� �������� � �����
    /// data - �������
    public void push(T data) {
        if (current >= capacity) {
            capacity *= 2;
            arr = Arrays.copyOf(arr, (int) capacity);
        }
        arr[(int) current] = data;
        current++;
    }

    /// ������ �������� �� �������
    /// int index, - ������ ��-�� �������
    /// T data - �������
    /// ��������� ���������� IndexOutOfBoundsException ���� ������ ������� �� ������� �������
    public void set(int index, T data) {
        if (index < 0 || index > current) {
            throw new IndexOutOfBoundsException("������ ��� ������ �������");
        }
        if (index == current) {
            push(data);
        } else {
            arr[index] = data;
        }
    }

    ///��������� �������� �� �������
    /// index - ������ ��-��
    /// ��������� ���������� IndexOutOfBoundsException ���� index �� �������. �������
    public T get(int index) {
        if (index < 0 || index > current) {
            throw new IndexOutOfBoundsException("������ ��� ������ �������");
        }
        return arr[index]; // ���������� T
    }

    /// �������� �������� � �����
    /// ��������� ���������� IllegalStateException ���� ������ ����
    public T pop() {
        if (current <= 0) {
            throw new IllegalStateException("������ ����");
        }
        current--;
        //resize
        if (current <= capacity/2) {
            capacity /= 2;
        }

        T result = arr[(int) current];
        arr[(int) current] = null; // ������� ������ ��� �������� ������
        return result;
    }

    /// �������� �������� �� �������
    /// ArrayIndexOutOfBoundsException ���� �������� ������ �������
    public T pop(int index) {
        if (index < 0 || index >= current) {
            throw new ArrayIndexOutOfBoundsException("�������� ������ �������");
        }
        T result = arr[index];
        for (int i = index; i < current - 1; i++) {
            arr[i] = arr[i + 1];
        }
        current--;
        //resize
        if (current < capacity/2) {
            capacity /= 2;
        }
        arr[(int) current] = null; // ������� ������
        return result;
    }

    /// ��������� ������� �������
    public long size() {
        return current;
    }

    /// ��������� ����������� �������
    public long getCapacity() {
        return capacity;
    }

    /// ������ �������
    public void print() {
        for (int i = 0; i < current; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    /// �����
    public static void all_assert() {
        double eps = 0.000001;

        // ������� ��������� � ����� Integer
        DynamicArr<Integer> arr = new DynamicArr<>();

        // ������� ���������
        arr.push(10);
        arr.push(20);
        arr.push(30);
        arr.push(40);
        arr.push(50);

        assert Math.abs(arr.size() - 5) < eps;
        assert Math.abs(arr.getCapacity() - 8) < eps;

        //��������� ��-��
        assert Math.abs(arr.get(0) - 10) < eps;
        assert Math.abs(arr.get(1) - 20) < eps;
        assert Math.abs(arr.get(2) - 30) < eps;
        assert Math.abs(arr.get(3) - 40) < eps;
        assert Math.abs(arr.get(4) - 50) < eps;

        // ������ �� �������
        arr.set(1, 100);
        assert Math.abs(arr.get(1) - 100) < eps;

        // �������� ���������� ��������
        arr.pop();
        assert Math.abs(arr.size() - 5) < eps;
        assert Math.abs(arr.getCapacity() - 8) < eps;

        assert Math.abs(arr.get(0) - 10) < eps;
        assert Math.abs(arr.get(1) - 100) < eps;
        assert Math.abs(arr.get(2) - 20) < eps;
        assert Math.abs(arr.get(3) - 30) < eps;
        assert Math.abs(arr.get(4) -40) < eps;

        // �������� ���������� ��������
        arr.pop();
        assert Math.abs(arr.size() - 4) < eps;
        assert Math.abs(arr.getCapacity() - 4) < eps;

        // �������� ���������� ��������
        arr.pop();
        assert Math.abs(arr.size() - 3) < eps;
        assert Math.abs(arr.getCapacity() - 4) < eps;

        // �������� ���������� ��������
        arr.pop();
        assert Math.abs(arr.size() - 2) < eps;
        assert Math.abs(arr.getCapacity() - 2) < eps;

        // �������� ���������� ��������
        arr.pop();
        assert Math.abs(arr.size() - 1) < eps;
        assert Math.abs(arr.getCapacity() - 1) < eps;

        try
        {
            arr.pop();
            System.exit(1);
        }
        catch (IllegalStateException _)
        {

        }


        //����������� �����
        DynamicArr<Integer> arr2 = new DynamicArr<>(arr);
        assert Math.abs(arr2.get(0) - 10) < eps;
        assert Math.abs(arr2.get(1) - 100) < eps;
        assert Math.abs(arr2.get(2) - 20) < eps;
        assert Math.abs(arr2.get(3) - 30) < eps;
        assert Math.abs(arr2.get(4) -40) < eps;
    }


}