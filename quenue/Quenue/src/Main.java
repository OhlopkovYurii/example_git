//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
            Queue.all_assert();

            // ������� ������� ��� ����� �����
            Queue<Integer> queue = new Queue<>();
            queue.enqueue(1); // ��������� 1
            queue.enqueue(2); // ��������� 2
            queue.enqueue(3); // ��������� 3

            queue.print(); // ������� ����������: 1 2 3
            System.out.println("������: " + queue.size()); // ������� ������: 3
            System.out.println("������ �������: " + queue.peek()); // ������� ������ �������: 1
            System.out.println("��������: " + queue.dequeue()); // ��������� � �������: 1

            queue.print(); // ������� ����������: 2 3
            System.out.println("������: " + queue.size()); // ������� ������: 2
            if (!queue.isEmpty())
            {
                    System.out.println("������� �� �����");
            };
        //TIP Press <shortcut actionId="ShowIntentionActions"/> with your caret at the highlighted text
        // to see how IntelliJ IDEA suggests fixing it.


    }
}