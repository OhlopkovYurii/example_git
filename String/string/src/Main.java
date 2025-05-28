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

        System.out.println("������ ������ ������ " + myString.charAt(0));
        System.out.println("������ ������ ������ " + myString.charAt(1));

        MyString myStringOther = new MyString(charArrOther);
        MyString res1 = myString.concatenation(myStringOther);
        res1.print();


        System.out.println("������ ������ " +myString.length());
        MyString res = myString.substring(2,5);
        System.out.println("������� ������ � 2 �� 5 ������\n");
        res.print();

        if (myString.isEmpty())
        {
            System.out.println("������ �����");
        }
        else
            System.out.println("������ �� �����");


        if (myString.isEqual(myStringOther))
        {
            System.out.println("������ ���������");
        }
        else
            System.out.println("������ �� ���������");







    }
}