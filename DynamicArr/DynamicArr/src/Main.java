
/// ����� �������� ���-23
///
///
public static void main(String[] args) {
        DynamicArr<Integer> arr_test  = new DynamicArr<Integer>();
        DynamicArr.all_assert();


        DynamicArr<Integer> arr  = new DynamicArr<Integer>();
        //������� ���������
        arr.push(10);
        arr.push(20);
        arr.push(30);
        arr.push(40);
        arr.push(50);
        System.out.println("������ �������: " + arr.size());
        System.out.println("����������� �������: " + arr.getCapacity());
        System.out.println("�������� �������: ");
        arr.print();
        //������ �� �������
        arr.set(1, 1);
        System.out.println("�������� ������� ����� ������ �� �������: ");
        arr.print();
        //��������� 1-�� ��-��
        System.out.println("1-� ��-� �������: " + arr.get(1));
        //�������� ��-��
        arr.pop();
        //arr.pop(1);
        System.out.println("������ �������: " + arr.size());
        System.out.println("����������� �������: " + arr.getCapacity());
        System.out.println("�������� �������: ");
        arr.print();
    }

