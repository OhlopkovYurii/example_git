
/// автор Охлопков ИВТ-23
///
///
public static void main(String[] args) {
        DynamicArr<Integer> arr_test  = new DynamicArr<Integer>();
        DynamicArr.all_assert();


        DynamicArr<Integer> arr  = new DynamicArr<Integer>();
        //вставка элементов
        arr.push(10);
        arr.push(20);
        arr.push(30);
        arr.push(40);
        arr.push(50);
        System.out.println("Размер массива: " + arr.size());
        System.out.println("Вместимость массива: " + arr.getCapacity());
        System.out.println("Элементы массива: ");
        arr.print();
        //замена по индексу
        arr.set(1, 1);
        System.out.println("Элементы массива после замены по индексу: ");
        arr.print();
        //получение 1-го эл-та
        System.out.println("1-й эл-т массива: " + arr.get(1));
        //удаление эл-та
        arr.pop();
        //arr.pop(1);
        System.out.println("Размер массива: " + arr.size());
        System.out.println("Вместимость массива: " + arr.getCapacity());
        System.out.println("Элементы массива: ");
        arr.print();
    }

