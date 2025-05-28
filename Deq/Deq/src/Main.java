//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Deq.all_assert();

        double eps = 0.000001;
        // Создаем очередь для целых чисел
        Deq<Integer> deq = new Deq<>();


        deq.pushFrontDeq(1); // Добавляем 1
        deq.pushFrontDeq(2); // Добавляем 2
        deq.pushFrontDeq(3); // Добавляем 3


        deq.pushBackDeq(4);
        deq.pushBackDeq(5);
        deq.pushBackDeq(6);
        deq.pushBackDeq(0);

        deq.print();//печать

        System.out.println(deq.size()); // Выводим размер: 6
        System.out.println(deq.peek()) ; // Выводим первый элемент: 3
        System.out.println(deq.get_front()) ; // Извлекаем и выводим: 3


        assert(deq.size() - 5 < eps); // Выводим размер 5
        assert(!deq.isEmpty());

        System.out.println(deq.get_front()); // Извлекаем и выводим 2
        System.out.println(deq.get_front()); // Извлекаем и выводим 1
        System.out.println(deq.get_front()); // Извлекаем и выводим 4
        System.out.println(deq.get_front()); // Извлекаем и выводим 5
        System.out.println(deq.get_front()); // Извлекаем и выводим 6

        /// извлечение из пустой очереди
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

        System.out.println(deq.size()); // Выводим размер: 3
        deq.peek(); // Выводим первый элемент: 11


        deq.popFrontDeq();
        System.out.println(deq.size()); // Выводим размер: 2
        System.out.println(deq.peek()); // Выводим первый элемент: 12



        deq.popFrontDeq();
        System.out.println(deq.size()); // Выводим размер: 1
        System.out.println(deq.peek()); // Выводим первый элемент: 13




        /// извлечение из пустой очереди
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