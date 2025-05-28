/// Автор Охлопков ИВТ-23




/// Класс Очередь
/// Дженерики (обобщения) — это особые средства языка Java для реализации
/// обобщённого программирования: особого подхода к описанию данных и алгоритмов,
/// позволяющего работать с различными типами данных без изменения их описания
public class Queue<T> {
    private DynamicArr<T> arr; // Динамический массив для хранения элементов очереди
    private long rear;        // Индекс последнего элемента

    // Конструктор
    public Queue() {
        arr = new DynamicArr<>();
        rear = -1; // Очередь пуста
    }

    /// Добавление элемента в конец очереди
    /// item  - данные
    public void enqueue(T item) {
        arr.push(item);
        rear++;
    }

    /// Извлечение элемента из начала очереди
    /// возвращаем новый 1й элемент очереди
    public T dequeue() {
        if (isEmpty()) {
            throw new IllegalStateException("Очередь пуста");
        }
        T item = arr.get(0);
        arr.pop(); // Уменьшаем размер массива
        rear--;//сдвигаем индекс конца очереди
        if (0 > rear) {
            rear = -1; // Сбрасываем индексы, если очередь опустела
        }
        return item;
    }

    /// Просмотр первого элемента без извлечения
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
        Queue<Integer> queue = new Queue<>();
        queue.enqueue(1); // Добавляем 1
        queue.enqueue(2); // Добавляем 2
        queue.enqueue(3); // Добавляем 3


        assert(queue.size()- 3 <eps); // Выводим размер: 3
        assert(queue.peek() - 1 < eps); // Выводим первый элемент: 1
        assert(queue.dequeue() - 1 < eps); // Извлекаем и выводим: 1


        assert(queue.size() - 2 < eps); // Выводим размер: 2
        assert(!queue.isEmpty());

        assert(queue.dequeue() - 2 < eps); // Извлекаем и выводим: 2
        assert(queue.dequeue() - 3 < eps); // Извлекаем и выводим: 3

        /// извлечение из пустой очереди
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
