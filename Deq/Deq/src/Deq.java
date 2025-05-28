/// Автор Охлопков ИВТ-23




/// Класс Двунаправленная Очередь
/// Дженерики (обобщения) — это особые средства языка Java для реализации
/// обобщённого программирования: особого подхода к описанию данных и алгоритмов,
/// позволяющего работать с различными типами данных без изменения их описания
public class Deq<T> {
    private DynamicArr<T> arr; // Динамический массив для хранения элементов очереди
    private long rear;        // Индекс последнего элемента

    // Конструктор
    public Deq() {
        arr = new DynamicArr<>();
        rear = -1; // Очередь пуста
    }

    /// Добавление элемента в конец очереди
    /// item  - данные
    public void pushBackDeq(T item) {
        arr.pushBack(item);
        rear++;
    }

    /// добавление элемента в начало очереди
    /// item - элемент
    public void pushFrontDeq(T item)
    {
        arr.pushFront(item);
        rear++;
    }

    /// удаление из начала очереди
    public void popFrontDeq()
    {
        arr.pop_front();
        rear--;
    }

    /// удаление из конца очереди
    public void popBackDeq()
    {
        arr.pop_back();
        rear--;
    }


    /// Извлечение элемента из начала очереди
    /// возвращаем новый 1й элемент очереди
    public T get_front() {
        if (isEmpty()) {
            throw new IllegalStateException("Очередь пуста");
        }
       // T item = arr.get((int) front);
        T item = arr.get(0);
        arr.pop_front(); // удаляем 1й элемент
        rear--;//сдвигаем индекс конца очереди
        if (0 > rear) {
            rear = -1; // Сбрасываем индексы, если очередь опустела
        }
        return item;
    }



    /// Просмотр первого элемента без извлечения
    /// бросается IllegalStateException  если Очередь пуста
    public T peek() {
        if (isEmpty()) {
            throw new IllegalStateException("Очередь пуста");
        }
        return arr.get(0);
    }

    /// Проверка, пуста ли очередь
    public boolean isEmpty() {
        return rear < 0;
    }

    /// Получение размера очереди
    public long size() {
        if (isEmpty()) return 0;
        return rear + 1;
    }

    /// Печать очереди
    /// если Очередь пуста выходим из метода
    public void print() {
        if (isEmpty()) {
            System.out.println("Очередь пуста");
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
        // Создаем очередь для целых чисел
        Deq<Integer> deq = new Deq<>();


        deq.pushFrontDeq(1); // Добавляем 1
        deq.pushFrontDeq(2); // Добавляем 2
        deq.pushFrontDeq(3); // Добавляем 3


        deq.pushBackDeq(4);
        deq.pushBackDeq(5);
        deq.pushBackDeq(6);


        assert(deq.size()- 6 <eps); // Выводим размер: 6
        assert(deq.peek() - 1 < eps); // Выводим первый элемент: 1
        assert(deq.get_front() - 1 < eps); // Извлекаем и выводим: 1


        assert(deq.size() - 5 < eps); // Выводим размер 5
        assert(!deq.isEmpty());

        assert(deq.get_front() - 2 < eps); // Извлекаем и выводим 2
        assert(deq.get_front() - 3 < eps); // Извлекаем и выводим 3
        assert(deq.get_front() - 4 < eps); // Извлекаем и выводим 4
        assert(deq.get_front() - 5 < eps); // Извлекаем и выводим 5
        assert(deq.get_front() - 6 < eps); // Извлекаем и выводим 6

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

        assert(deq.size()- 3 <eps); // Выводим размер: 3
        assert(deq.peek() - 11 < eps); // Выводим первый элемент: 11


        deq.popFrontDeq();
        assert(deq.size()- 2 <eps); // Выводим размер: 2
        assert(deq.peek() - 12 < eps); // Выводим первый элемент: 12



        deq.popFrontDeq();
        assert(deq.size()- 1 <eps); // Выводим размер: 1
        assert(deq.peek() - 13 < eps); // Выводим первый элемент: 13




        ///извлечение из пустой очереди
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
