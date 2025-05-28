import java.util.Arrays;


public class MyString {
    private final DynamicArr<Character> chars;


    public MyString(DynamicArr<Character> chars) {
        if (chars == null) {
            throw new IllegalArgumentException("Input DynamicArr cannot be null");
        }
        // Create a new DynamicArr and copy elements
        this.chars = new DynamicArr<>();
        for (int i = 0; i < chars.size(); i++) {
            this.chars.push(chars.get(i));
        }
    }

    // Empty constructor
    public MyString() {
        chars = new DynamicArr<>();
    }

    // Get length of the string
    public long length() {
        return chars.size();
    }

    // Get character at index
    public char charAt(int index) {
        if (index < 0 || index >= chars.size()) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        return chars.get(index);
    }

    public MyString substring(int startIndex, int endIndex) {
        if (startIndex < 0 || endIndex > chars.size() || startIndex > endIndex) {
            throw new IndexOutOfBoundsException("Invalid substring indices");
        }
        MyString result = new MyString();
        for (int i = startIndex; i < endIndex; i++) {
            result.chars.push(chars.get(i));
        }
        return result;
    }

    public MyString concatenation(MyString other) {
        MyString result = new MyString();
        for (int i=0; i<chars.size();i++)
        {
            result.push(chars.get(i));
        }

        for (int i=0; i<other.size();i++)
        {
            result.push(other.get(i));
        }

        return result;





    }

    public void push(char char1)
    {
        chars.push(char1);
    }

    public char get(int index)
    {
        return chars.get(index);
    }

    // Печать массива
    public void print() {
        chars.print();
    }

    public long size() {
        return chars.size();
    }


    // Check if string is empty
    public boolean isEmpty() {
        return chars.size() == 0;
    }


    // Check if string is empty
    public boolean isEqual(MyString other) {
        boolean flag = false;
        if (chars.size() == other.size())
        {
            for (int i=0; i<chars.size();i++)
            {
                if (chars.get(i) == other.get(i))
                {
                    flag = true;
                }
                else {
                    return false;
                }
            }
        }
        else return false;
        return flag;
    }

    public static void all_assert() {
        double eps = 0.000001;



        DynamicArr<Character> charArr = new DynamicArr<>();
        charArr.push('H');
        charArr.push('e');
        charArr.push('l');
        charArr.push('l');
        charArr.push('o');

        DynamicArr<Character> charArrOther = new DynamicArr<>();
        charArr.push('W');
        charArr.push('o');
        charArr.push('r');
        charArr.push('l');
        charArr.push('d');


        // Call the MyString constructor
        MyString myString = new MyString(charArr);

        assert(myString.charAt(0)=='H');
        assert(myString.charAt(0)=='e');

        MyString myStringOther = new MyString(charArrOther);

        MyString res1 = myString.concatenation(myStringOther);

        DynamicArr<Character> charTest = new DynamicArr<>();
        charTest.push('H');
        charTest.push('e');
        charTest.push('l');
        charTest.push('l');
        charTest.push('o');
        charTest.push('W');
        charTest.push('o');
        charTest.push('r');
        charTest.push('l');
        charTest.push('d');
        MyString myStringTest = new MyString(charTest);

        assert(res1.isEqual(myStringTest));



        assert(myString.length()-5<eps);
        MyString res = myString.substring(2,5);
        assert(res.get(2) == 'l');
        assert(res.get(3) == 'l');
        assert(res.get(4) == '0');

        assert(!myString.isEmpty());

    }


}
