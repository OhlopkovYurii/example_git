//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        MyString.all_assert();
        DynamicArr<Character> charArr = new DynamicArr<>();
        charArr.push('H');
        charArr.push('e');
        charArr.push('l');
        charArr.push('l');
        charArr.push('o');

        DynamicArr<Character> charArrOther = new DynamicArr<>();
        charArrOther.push('W');
        charArrOther.push('o');
        charArrOther.push('r');
        charArrOther.push('l');
        charArrOther.push('d');


        // Call the MyString constructor
        MyString myString = new MyString(charArr);

        System.out.println("первый символ строки " + myString.charAt(0));
        System.out.println("второй символ строки " + myString.charAt(1));

        MyString myStringOther = new MyString(charArrOther);
        MyString res1 = myString.concatenation(myStringOther);
        res1.print();


        System.out.println("Размер строки " +myString.length());
        MyString res = myString.substring(2,5);
        System.out.println("Обрезка строки с 2 по 5 символ\n");
        res.print();

        if (myString.isEmpty())
        {
            System.out.println("Строка пуста");
        }
        else
            System.out.println("Строка не пуста");


        if (myString.isEqual(myStringOther))
        {
            System.out.println("Строки одинаковы");
        }
        else
            System.out.println("Строки не одинаковы");







    }
}