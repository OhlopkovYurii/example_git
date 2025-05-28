//Охлопков Юрий

//https://github.com/ivtipm/Data-structures-and-algorithms/blob/main/current_plans/2025/2025_part_1.md#лекция-9-структуры-данных-стек

//добавл эл-тов сверх размера
//удал из пустого стека
//основа - дин массив  DynamicArr

import javax.management.DynamicMBean;

///Класс Стек
public class Stack<T> {

    ///индекс вершины
    private int top;

    /// динамич массив
    DynamicArr arr;

    ///конструктор
    Stack()
    {
        //size = size1;
        arr = new DynamicArr();
        top=-1;
    }


    /// добавление эл-та в вершину стека
    /// data - число
    void add(int data)
    {

        top++;
        arr.push(data);
    }

    /// удаление из вершины
    void del()
    {
        top--;
    }

    // Получение вершины стека
    T getTop() {
        if (top < 0) {
            throw new IllegalStateException("Стек пуст");
        }
        return (T) arr.get((int) top); // Теперь корректно возвращает T
    }

    /// проверка не пустой ли стек
    boolean isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /// печать стека
    void print()
    {
        int cur_top = top;
        //top = 0;
        while(top > -1)
        {
            System.out.println(getTop());
            top--;
        }
        top = cur_top;

    }

    /// проверки
    static void  all_assert()
    {
        double eps = 0.000001;
        Stack<Integer> stack = new Stack();
        //добавить эл-т в стек
        stack.add(1);
        assert(stack.getTop() - 1 < eps);
        stack.add(2);
        assert(stack.getTop() - 2 < eps);
        stack.add(3);
        assert(stack.getTop() - 3 < eps);
        stack.add(4);
        assert(stack.getTop() - 4 < eps);
        stack.add(5);
        assert(stack.getTop() - 5 < eps);

        //не пустой ли он
        assert(stack.isEmpty() == false);

        //удаление эл-тов из стека
        stack.del();
        assert(stack.getTop() - 4 < eps);

        stack.del();
        stack.del();
        stack.del();
        stack.del();
        //удаление из пустого стека
        stack.del();
        assert(stack.isEmpty() == true);


    }
}
