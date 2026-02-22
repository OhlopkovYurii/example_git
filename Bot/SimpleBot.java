/// Автор: Охлопков Юрий ИВТ-23


/// Все классы в Java наследуются от класса Object.
/// Класс Object является корневым классом и предоставляет базовые методы,
/// такие как toString(), hashCode() и equals(), которые доступны для всех объектов в Java
///

package com.example.simplebot;



import java.util.*;
//для регулярных выражений
import java.util.regex.*;

import static com.example.simplebot.Controller.TextField_name;

/// класс простой чат-бот
public class SimpleBot {

    //имя пользователя
    public String name;





    //общие фразы, ответ на повествовательное предложение
    public String[] COMMON_PHRASES = {
            "Нет ничего ценнее слов, сказанных к месту и ко времени.",
            "Порой молчание может сказать больше, нежели уйма слов.",
            //Controller.set_name() +  "Перед тем как писать/говорить всегда лучше подумать.",
            "Вежливая и грамотная речь говорит о величии души.",
           // Controller.set_name() +"Приятно когда текст без орфографических ошибок.",
            "Многословие есть признак неупорядоченного ума.",
            "Слова могут ранить, но могут и исцелять.",
           // Controller.set_name() + "Записывая слова, мы удваиваем их силу.",
            "Кто ясно мыслит, тот ясно излагает."
            //Controller.set_name() + "Боюсь Вы что-то не договариваете."
            };
    //уклончивые фразы, ответ на вопрос
    public String[] ELUSIVE_ANSWERS = {
            "Вопрос непростой, прошу тайм-аут на раздумья.",
            "Не уверен, что располагаю такой информацией.",
            //Controller.set_name() +"Может лучше поговорим о чём-то другом?",
            "Простите, но это очень личный вопрос.",
            "Не уверен, что Вам понравится ответ.",
           // Controller.set_name() + "Поверьте, я сам хотел бы это знать.",
            "Вы действительно хотите это знать?",
            "Уверен, Вы уже догадались сами.",
            //Controller.set_name()+ "Зачем Вам такая информация?",
            "Давайте сохраним интригу?"};
    //запросы пользователя
    //
    //Map в Java — это структура данных, которая содержит набор пар «ключ-значение».
    //
    //HashMap в Java — это структура данных, одна из коллекций языка.
    // Представляет собой хэш-таблицу — набор из пар «ключ-значение»,
    // где у ключей есть хэши, то есть числовые уникальные идентификаторы.
    public Map<String, String> PATTERNS_FOR_ANALYSIS = new HashMap<String, String>() {{
        // hello
        put("хай", "hello");
        put("привет", "hello");
        put("здорово", "hello");
        put("здравствуй", "hello");
        //study
        put("что\\s.*умеешь", "study");
        put("что\\s.*можешь", "study");
        // who
        put("кто\\s.*ты", "who");
        put("ты\\s.*кто", "who");
        // name
        put("как\\s.*зовут", "name");
        put("как\\s.*имя", "name");
        put("есть\\s.*имя", "name");
        put("какое\\s.*имя", "name");
        // howareyou
        put("как\\s.*дела", "howareyou");
        put("как\\s.*жизнь", "howareyou");
        // whatdoyoudoing
        put("зачем\\s.*тут", "whatdoyoudoing");
        put("зачем\\s.*здесь", "whatdoyoudoing");
        put("что\\s.*делаешь", "whatdoyoudoing");
        put("чем\\s.*занимаешься", "whatdoyoudoing");
        // whatdoyoulike
        put("что\\s.*нравится", "whatdoyoulike");
        put("что\\s.*любишь", "whatdoyoulike");
        // iamfeelling
        put("кажется", "iamfeelling");
        put("чувствую", "iamfeelling");
        put("испытываю", "iamfeelling");
        // yes
        put("^да", "yes");
        put("согласен", "yes");
        // whattime
        put("который\\s.*час", "whattime");
        put("сколько\\s.*время", "whattime");
        put("время", "whattime");
        // bye
        put("прощай", "bye");
        put("увидимся", "bye");
        put("до\\s.*свидания", "bye");
        put("пока", "bye");
    }};
    //ответы в соответствии с запросом пользователя
    public Map<String, String> ANSWERS_BY_PATTERNS = new HashMap<String, String>() {{
       // put("hello", Controller.Bot.get_name() + "Здравствуйте, рад Вас видеть.");
        put("who", "Я обычный чат-бот.");
        put("name", "Зовите меня Чаттер :)");
        put("howareyou", "Спасибо, что интересуетесь. У меня всё хорошо.");
        put("whatdoyoudoing", "Я пробую общаться с людьми.");
        put("whatdoyoulike", "Мне нравиться думать что я не просто программа.");
        put("iamfeelling", "Как давно это началось? Расскажите чуть подробнее.");
        put("yes", "Согласие есть продукт при полном непротивлении сторон.");
        put("bye", "До свидания. Надеюсь, ещё увидимся.");
        put("study", "Я могу вычислять математическое выражение с операциями +, -, *, /\nунарные плюс и минус, скобки учитываю)\nа также функции sqrt, sin, cos, tan в градусах\nи возведение в степень (^).\" ");
    }};
    Pattern pattern; // //Pattern - нахождения соответствия строке
    Random random; // для рандомных ответов
    Date date; // для даты и времени

    //конструктор без параметров
    public SimpleBot() {
        //рандомное значение из списка
        random = new Random();
        //текущая дата
        date = new Date();
    }

    /**
     * Вычисляет математическое выражение, заданное строкой.
     * Поддерживает базовые арифметические операции (+, -, *, /), скобки, унарные плюс и минус,
     * а также функции sqrt, sin, cos, tan и возведение в степень (^).
     *
     * @param str Строка, содержащая математическое выражение.
     * @return Результат вычисления выражения.
     * @throws RuntimeException Если выражение некорректно.
     */
    double eval(final String str) {
        return new Object() {
            // pos - текущая позиция в строке, ch - текущий символ
            int pos = -1, ch;


        /**
         * Считывает следующий символ из строки.
         * Если достигнут конец строки, ch устанавливается в -1.
         */
        void nextChar() {
            ch = (++pos < str.length()) ? str.charAt(pos) : -1;
        }


        /**
         * Проверяет, совпадает ли текущий символ с заданным.
         * Пропускает пробелы перед символом.
         * Если совпадает, считывает следующий символ и возвращает true.
         * Иначе возвращает false.
         *
         * @param charToEat Символ для сравнения.
         * @return true, если символ совпадает, иначе false.
         */
        boolean eat(int charToEat) {
            while (ch == ' ') nextChar(); // Пропускаем пробелы
            if (ch == charToEat) {
                nextChar();// Считываем следующий символ
                return true;
            }
            return false;
        }


        /**
         * Начинает разбор выражения.
         * Вызывает parseExpression() для разбора выражения.
         * Проверяет, что весь ввод был обработан.
         *
         * @return Результат вычисления выражения.
         * @throws RuntimeException Если в конце строки остались необработанные символы.
         */
        double parse() {
            nextChar();// Считываем первый символ
            double x = parseExpression();
            if (pos < str.length()) throw new RuntimeException("Unexpected: " + (char)ch);// Ошибка, если строка не была полностью разобрана
            return x;
        }


        /**
         * Разбирает сложение и вычитание.
         *
         * @return Результат вычисления выражения.
         */
        double parseExpression() {
            double x = parseTerm();
            //Это бесконечный цикл
            for (;;) {
                if      (eat('+')) x += parseTerm(); // Сложение
                else if (eat('-')) x -= parseTerm(); // Вычитание
                else return x;
            }
        }
        /**
         * Разбирает умножение и деление.
         *
         * @return Результат вычисления выражения.
         */
        double parseTerm() {
            double x = parseFactor();
            //Это бесконечный цикл
            for (;;) {
                if      (eat('*')) x *= parseFactor(); // Умножение
                else if (eat('/')) x /= parseFactor(); // Деление
                else return x;
            }
        }

        /**
         * Разбирает числа, скобки, функции и унарные операторы.
         *
         * @return Результат вычисления выражения.
         * @throws RuntimeException Если встречается неизвестная функция или некорректный символ.
         */
        double parseFactor() {
            if (eat('+')) return +parseFactor(); // unary plus
            if (eat('-')) return -parseFactor(); // unary minus

            double x;
            int startPos = this.pos;
            if (eat('(')) { // Скобки
                x = parseExpression();
                if (!eat(')')) throw new RuntimeException("Missing ')'");// Ошибка, если нет закрывающей скобки
            } else if ((ch >= '0' && ch <= '9') || ch == '.') { // Числа
                while ((ch >= '0' && ch <= '9') || ch == '.') nextChar();// Считываем все цифры числа
                x = Double.parseDouble(str.substring(startPos, this.pos));// Преобразуем строку в число
            } else if (ch >= 'a' && ch <= 'z') { // Функции
                while (ch >= 'a' && ch <= 'z') nextChar(); // Считываем имя функции
                String func = str.substring(startPos, this.pos);
                if (eat('(')) {
                    x = parseExpression(); // Разбираем аргумент функции
                    if (!eat(')')) throw new RuntimeException("Missing ')' after argument to " + func); // Ошибка, если нет закрывающей скобки после аргумента
                } else {
                    x = parseFactor(); // Обрабатываем как переменную (например, x, y, etc.)
                }

                // Вычисляем значение функции
                if (func.equals("sqrt")) x = Math.sqrt(x);
                else if (func.equals("sin")) x = Math.sin(Math.toRadians(x));
                else if (func.equals("cos")) x = Math.cos(Math.toRadians(x));
                else if (func.equals("tan")) x = Math.tan(Math.toRadians(x));
                else throw new RuntimeException("Unknown function: " + func); // Ошибка, если функция неизвестна
            } else {
                throw new RuntimeException("Unexpected: " + (char)ch); // Ошибка, если символ некорректен
            }

            if (eat('^')) x = Math.pow(x, parseFactor()); // Возведение в степень

            return x;
        }
            }.parse(); // Вызываем parse() для начала разбора
    }

    /// функция вычисляет мат. выражение
    /// msg - сообщение пользователя
    float math(String msg)
    {
        //строка до операнда
        String s1="";
        //строка после операнда
        String s2="";

        //массив из символов
        char[] charArray = msg.toCharArray();
        for (int i = 0; i < msg.length(); i++)
        {
            char ch = charArray[i];
            //если символ - операнд
            if (ch =='+' | ch =='*' | ch =='/' |ch =='-' )
            {
                //склеиваем символы первого числа
                for (int j = 0; j < i; j++)
                    s1 += charArray[j];
                //склеиваем символы второго числа
                for (int j = i+1; j < msg.length(); j++)
                    s2 += charArray[j];

                //делаем операции
                if (ch =='+') return Float.valueOf(s1) + Float.valueOf(s2);
                if (ch =='-') return Float.valueOf(s1) - Float.valueOf(s2);
                if (ch =='/' && Float.valueOf(s2) != 0) return Float.valueOf(s1) / Float.valueOf(s2);
                if (ch =='*') return Float.valueOf(s1) * Float.valueOf(s2);
            }
        }
        return 0;
    }


    /// сеттер имени пользователя s_name
    public void set_name(String s_name)
    {

        if (s_name != "")
            name =  s_name;




    }


    /// геттер имени
    public String get_name()
    {

        return name;

    }


    //метод ответ на запрос
    //msg - сообщение пользователя
    public String sayInReturn(String msg) {





        String say="";

        //сообщение - мат. выражение?
        try{
            say =  Double.toString(eval(msg));

        }
        catch(RuntimeException ex)   {

                //сообщение заканчивается знаком ?
                say =  (msg.trim().endsWith("?")) ?
                        //если да, то ставь уклончивые фразы, ответ на вопрос
                        ELUSIVE_ANSWERS[random.nextInt(ELUSIVE_ANSWERS.length)] :
                        //если нет, ставь общие фразы
                        COMMON_PHRASES[random.nextInt(COMMON_PHRASES.length)];

            }


        //из сообщения удаляются все знаки препинания, сообщение ставится в нижний регистр
        String message =
                String.join(" ", msg.toLowerCase().split("[ {,|.}?]+"));
        //берется объект o из Map
        for (Map.Entry<String, String> o : PATTERNS_FOR_ANALYSIS.entrySet()) {
            //проверка на соответствие
            pattern = Pattern.compile(o.getKey());
            //если есть совпадение по ключу
            if (pattern.matcher(message).find())
                //если спросили дату время
                if (o.getValue().equals("whattime")) return date.toString();
                //иначе возвращай ответ по ключу
                //else if (message.split(""))
                else    return ANSWERS_BY_PATTERNS.get(o.getValue());
        }

        return say;
    }

    public static void all_assert()
    {
        /// экземпляр класс простой бот
        SimpleBot Bot  = new SimpleBot();

        //мат. выражение
        assert(Bot.sayInReturn("5+5*2") == "15");

        //обычный вопрос
        assert(Bot.sayInReturn("Кто ты?") =="Я обычный чат-бот.");

        //повест. предложение, не подходящее под шаблон
        assert( Bot.sayInReturn("ыввывцвц4еуав") =="Нет ничего ценнее слов, сказанных к месту и ко времени." ||
                Bot.sayInReturn("ыввывцвц4еуав") ==  "Порой молчание может сказать больше, нежели уйма слов." ||
                Bot.sayInReturn("ыввывцвц4еуав") == "Вежливая и грамотная речь говорит о величии души." ||
                Bot.sayInReturn("ыввывцвц4еуав") == "Многословие есть признак неупорядоченного ума." ||
                Bot.sayInReturn("ыввывцвц4еуав") == "Слова могут ранить, но могут и исцелять."||
                Bot.sayInReturn("ыввывцвц4еуав") == "Кто ясно мыслит, тот ясно излагает.");

        //вопрос. предложение, не подходящее под шаблон
        assert( Bot.sayInReturn("ыввывцвц4еуав?") == "Вопрос непростой, прошу тайм-аут на раздумья."||
                Bot.sayInReturn("ыввывцвц4еуав?") ==  "Не уверен, что располагаю такой информацией."||
                Bot.sayInReturn("ыввывцвц4еуав?") == "Простите, но это очень личный вопрос."||
                Bot.sayInReturn("ыввывцвц4еуав?") == "Не уверен, что Вам понравится ответ."||
                Bot.sayInReturn("ыввывцвц4еуав?") == "Вы действительно хотите это знать?"||
                Bot.sayInReturn("ыввывцвц4еуав?") == "Уверен, Вы уже догадались сами."||
                Bot.sayInReturn("ыввывцвц4еуав?") == "Давайте сохраним интригу?");





    }
}