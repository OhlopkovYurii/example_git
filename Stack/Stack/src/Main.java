//Охлопков Юрий

//https://github.com/ivtipm/Data-structures-and-algorithms/blob/main/current_plans/2025/2025_part_1.md#лекция-9-структуры-данных-стек

public class Main {
    public static void main(String[] args) {
        Stack stack_test = new Stack();
        //тесты
        stack_test.all_assert();


        Stack stack = new Stack();
        //добавление эл-тов
        stack.add(1);
        stack.add(2);
        stack.add(3);
        stack.add(4);
        stack.add(5);

        //печать
        stack.print();
        //получение вершины
        System.out.println("Вершина стека " + stack.getTop());

        //не пуст ли стек
        if (!stack.isEmpty())
            System.out.println("Стек не пустой");
        else {
            System.out.println("Стек пустой");

        }
        stack.del();
        stack.print();
        System.out.println("Вершина стека после удаления вершины " + stack.getTop());

        // удаление эл-тов
        stack.del();
        stack.del();
        stack.del();
        stack.del();
        if (!stack.isEmpty())
            System.out.println("Стек не пустой");
        else {
            System.out.println("Стек пустой");

        }

        stack.print();


    }
}
