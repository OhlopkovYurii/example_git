import java.util.Arrays;

public class DynamicArr<T> {
    // Статический массив
    private T[] arr;
    // Вместимость массива
    private long capacity;
    // Номер последнего элемента массива
    private long current;

    // Конструктор без параметров
    //Компилятор предупреждает, что приведение (T[]) может быть небезопасным
    @SuppressWarnings("unchecked")
    public DynamicArr() {
        // Инициализируем массив объектов и приводим к T[]
        arr = (T[]) new Object[1];
        capacity = 1;
        current = 0;
    }

    // Конструктор с параметрами
    //Компилятор предупреждает, что приведение (T[]) может быть небезопасным
    @SuppressWarnings("unchecked")
    public DynamicArr(T[] arr1, long capacity1, long current1) {
        if (arr1 == null || capacity1 < current1 || capacity1 <= 0) {
            throw new IllegalArgumentException("Неверные параметры конструктора");
        }
        this.arr = arr1.clone(); // Копируем массив для безопасности
        this.capacity = capacity1;
        this.current = current1;
    }

    // Вставка элемента в конец
    public void push(T data) {
        if (current >= capacity) {
            capacity *= 2;
            arr = Arrays.copyOf(arr, (int) capacity);
        }
        arr[(int) current] = data;
        current++;
    }

    // Замена элемента по индексу
    public void set(int index, T data) {
        if (index < 0 || index > current) {
            throw new IndexOutOfBoundsException("Индекс вне границ массива");
        }
        if (index == current) {
            push(data);
        } else {
            arr[index] = data;
        }
    }

    // Получение элемента по индексу
    public T get(int index) {
        if (index < 0 || index > current) {
            throw new IndexOutOfBoundsException("Индекс вне границ массива");
        }
        return arr[index]; // Возвращает T
    }

    // Удаление элемента с конца
    public T pop() {
        if (current <= 0) {
            throw new IllegalStateException("Массив пуст");
        }
        current--;
        T result = arr[(int) current];
        arr[(int) current] = null; // Очистка ссылки для сборщика мусора
        return result;
    }

    // Удаление элемента по индексу
    public T pop(int index) {
        if (index < 0 || index >= current) {
            throw new ArrayIndexOutOfBoundsException("Неверный индекс массива");
        }
        T result = arr[index];
        for (int i = index; i < current - 1; i++) {
            arr[i] = arr[i + 1];
        }
        current--;
        arr[(int) current] = null; // Очистка ссылки
        return result;
    }

    // Получение размера массива
    public long size() {
        return current;
    }

    // Получение вместимости массива
    public long getCapacity() {
        return capacity;
    }

    // Печать массива
    public void print() {
        for (int i = 0; i < current; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    // Тестовый метод
    public static void all_assert() {
        double eps = 0.000001;

        // Создаем экземпляр с обобщением Integer
        DynamicArr<Integer> arr = new DynamicArr<>();

        // Вставка элементов
        arr.push(10);
        arr.push(20);
        arr.push(30);
        arr.push(40);
        arr.push(50);

        assert Math.abs(arr.size() - 5) < eps;
        assert Math.abs(arr.getCapacity() - 8) < eps;

        assert Math.abs(arr.get(0) - 10) < eps;
        assert Math.abs(arr.get(1) - 20) < eps;
        assert Math.abs(arr.get(2) - 30) < eps;
        assert Math.abs(arr.get(3) - 40) < eps;
        assert Math.abs(arr.get(4) - 50) < eps;

        // Вставка по индексу
        arr.set(1, 100);
        assert Math.abs(arr.get(1) - 100) < eps;

        // Удаление последнего элемента
        arr.pop();
        assert Math.abs(arr.size() - 5) < eps;
        assert Math.abs(arr.getCapacity() - 8) < eps;

        assert Math.abs(arr.get(0) - 10) < eps;
        assert Math.abs(arr.get(1) - 100) < eps;
        assert Math.abs(arr.get(2) - 20) < eps;
        assert Math.abs(arr.get(3) - 30) < eps;
        assert Math.abs(arr.get(4) -40) < eps;
    }


}