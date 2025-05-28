//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
            Queue.all_assert();

            // Создаем очередь для целых чисел
            Queue<Integer> queue = new Queue<>();
            queue.enqueue(1); // Добавляем 1
            queue.enqueue(2); // Добавляем 2
            queue.enqueue(3); // Добавляем 3

            queue.print(); // Выводим содержимое: 1 2 3
            System.out.println("Размер: " + queue.size()); // Выводим размер: 3
            System.out.println("Первый элемент: " + queue.peek()); // Выводим первый элемент: 1
            System.out.println("Извлечен: " + queue.dequeue()); // Извлекаем и выводим: 1

            queue.print(); // Выводим содержимое: 2 3
            System.out.println("Размер: " + queue.size()); // Выводим размер: 2
            if (!queue.isEmpty())
            {
                    System.out.println("Очередь не пуста");
            };
        //TIP Press <shortcut actionId="ShowIntentionActions"/> with your caret at the highlighted text
        // to see how IntelliJ IDEA suggests fixing it.


    }
}