#  Класс "Матрица"

_Автор: Охлопков Юрий ИВТ-23_
##### Аннотация
Это класс, представлющий собой матрицу. 
Написан на языке C++
В основе лежит класс ```vector```. 
Позволяет упростить работу с матрицами.




## Описание
В классе реализовано:
• доступ к отдельным элементам матрицы (использование оператора() )
• заполнение матрицы одним значением
• заполнение матрицы случайными числами
• сложение и вычитание матриц (использование оператора ```+``` ```+=``` ```-``` ```-=```)
• умножение на число
• умножение матрицы на матрицу (использование оператора ```*``` ```*=```)
• транспонирование
• создание диагональной матрицы.
• вычисление определителя
• вычисление обратной матрицы 
• доступ к строкам матрицы
• применения функции к элементам матрицы
•Недопустимые или невозможные
операции над матрицами обрабатываются с помощью механизма генерации исключений.
• Вычисление корней системы линейных уравнений.

## Методы
```c++
шаблон
template <typename T>
```
Возвращаемый тип|Название метода
:--------------|:---------------
```T& ```            | [```operator () (size_t i, size_t j)```](#anchor1) 
```vector< T >&```   | [```operator () (size_t i)```](#anchor2) 
```T const&```       | [```operator () (size_t i, size_t j) const ```](#anchor3)
```size_t ```        | [```get_rows() const```](#anchor4)
```size_t```         | [```get_cols() const```](#anchor5)
```void ```          | [```set_rows(size_t num_rows)```](#anchor6)
```void ```          | [```set_cols(size_t num_cols)```](#anchor7)
```void ```          | [```print_mtrx()```](#anchor8)
```void ```          | [```set_mtrx_one_value(T data)```](#anchor9)
```void ```          | [```set_mtrx_random_value(int start, int end)```](#anchor10)
```void  ```         | [```transpose()```](#anchor11)
```void	 ```         | [```create_diagonal_matrix()```](#anchor12)
```double```	     | [```determinant()```](#anchor13)
## Функции
Возвращаемый тип                  |Название функции
:--------------                   |:---------------
```Matrix< T >                ``` | [```operator+(const Matrix< T >& m1 const Matrix< T >& m2)```](#anchor14)
```Matrix< T >                ``` | [```operator+=(Matrix< T >& m1, const Matrix< T >& m2)```](#anchor15)
```Matrix< T >                ``` | [```operator-(const Matrix< T >& m1, const Matrix< T >& m2)```](#anchor16)
```Matrix< T >                ``` | [```operator-=(Matrix< T >& m1, const Matrix< T >& m2)```](#anchor17)
```Matrix< T >                ``` | [```operator*(const Matrix< T >& m1, T data)```](#anchor18)
```Matrix< T >                ``` | [```operator*(const Matrix< T >& m1, const Matrix< T >& m2)```](#anchor19)
```Matrix< T >                ``` | [```operator*=(Matrix< T >& m1, const Matrix< T >& m2)```](#anchor20)
```bool                       ``` | [```operator==(const Matrix< T >& m1, const Matrix< T >& m2)```](#anchor21)
```bool                       ``` | [```operator==(const vector< T >& v1, const vector< T >& v2)```](#anchor22)
```void                       ``` | [```print_len_mtrx(vector< T >& m)```](#anchor23)
```double                     ``` | [```average_mtrx(const Matrix< T >& m1)```](#anchor24)
```Matrix< T >                ``` | [```zero_mtrx(Matrix< T >& m1)```](#anchor25)
```vector< double >           ``` | [```root_mtrx(const Matrix< T >& a, const vector< T >& c)```](#anchor26)
```vector< vector< double > > ``` | [```inverse(Matrix< T >& matrix)```](#anchor27)
```void                       ``` | [```print_vector(vector< T > a)```](#anchor28)
```void                      ```  | [```all_assert()```](#anchor29)


# Документация: методы
<a id="anchor1"></a>
###### 
```c++
T& operator () (size_t i, size_t j)
```
Оператор() для неконстантного элемента
возвращает элемент матрицы по индексам 
```size_t i, size_t j``` - номер строки и номер столбца
- - -
<a id="anchor2"></a>

###### 
```c++
vector< T >& operator () (size_t i)
```
оператор() для неконстантного элемента
возвращает строку вектора
```size_t i``` - номер строки
- - -
<a id="anchor3"></a>
######
```c++
T const& operator () (size_t i, size_t j) const
```
оператор() для константного элемента
возвращает элемент матрицы по индексам 
```size_t i, size_t j``` - номер строки и номер столбца

- - -
<a id="anchor4"></a>

###### 
```c++
size_t get_rows() const
```
геттер - возвращает кол-во строк матрицы
- - -
<a id="anchor5"></a>

###### 
```c++
size_t	get_cols() const
```
геттер - возвращает кол-во столбцов матрицы
- - -
<a id="anchor6"></a>

###### 
```c++
void set_rows(size_t num_rows)
```
сеттер - меняет кол-во строк матрицы
```size_t num_rows``` - кол-во строк
- - -
<a id="anchor7"></a>
###### 
```c++
void set_cols(size_t num_cols)
```
сеттер - меняет кол-во столбцов матрицы
```size_t num_cols``` - кол-во столбцов


- - -
<a id="anchor8"></a>

###### 
```c++
void 	print_mtrx()
```
печать матрицы

- - -
<a id="anchor9"></a>

###### 
```c++
void set_mtrx_one_value(T data)
```
сеттер - заполнение матрицы одним значением
```T data``` - число

- - -
<a id="anchor10"></a>

######
```c++
void set_mtrx_random_value(int start, int end)
```
сеттер - заполнение матрицы рандомным значением

- - -
<a id="anchor11"></a>

###### 
```c++
void   transpose()
```
транспонирование матрицы

- - -
<a id="anchor12"></a>

###### 
```c++
void	create_diagonal_matrix()
```
создание диагональной матрицы

- - -
<a id="anchor13"></a>

######
```c++
double	determinant()
```
нахождение определителя
возвращает определитель

# Документация: функции
<a id="anchor14"></a>

###### 
```c++
Matrix< T > operator+(const Matrix< T >& m1 const Matrix< T >& m2) 
```
```operator+```  - сложение матриц
```const Matrix<T>& m1``` - матрица, ```const Matrix<T>& m2``` - матрица
возвращает новую матрицу как результат сложения двух матриц
если размеры матриц не совпадают, выбрасывается исключение в виде строки

- - -
<a id="anchor15"></a>

###### 
```c++
Matrix< T > operator+=(Matrix< T >& m1, const Matrix< T >& m2) 
```
```operator+=``` - оператор для сложение исходной матрицы и другой матрицы
результат записывается в исходную матрицу
```const Matrix<T>& m1``` - матрица, ```const Matrix<T>& m2``` - матрица
возвращает новую исходную матрицу
если размеры матриц не совпадают, выбрасывается исключение в виде строки
- - -
<a id="anchor16"></a>

######
```c++
Matrix< T >  operator-(const Matrix< T >& m1, const Matrix< T >& m2) 
```
```operator-```  - вычитание матриц
```const Matrix<T>& m1``` - матрица, ```const Matrix<T>& m2``` - матрица
возвращает новую матрицу как результат вычитания двух матриц
если размеры матриц не совпадают, выбрасывается исключение в виде строки
- - -
<a id="anchor17"></a>

######
```c++
Matrix< T >  operator-=(Matrix< T >& m1, const Matrix< T >& m2)
```
```operator-=``` - оператор для вычитания исходной матрицы и другой матрицы
результат записывается в исходную матрицу
```const Matrix<T>& m1``` - матрица, ```const Matrix<T>& m2``` - матрица
возвращает новую исходную матрицу
если размеры матриц не совпадают, выбрасывается исключение в виде строки
- - -
<a id="anchor18"></a>

###### 
```c++
Matrix< T > operator*(const Matrix< T >& m1, T data)
```
```operator*```  - умножение матрицы на число
```const Matrix<T>& m1``` - матрица, ```T data``` -  число
возвращает новую матрицу как результат умножение матрицы на число
- - -
<a id="anchor19"></a>

######
```c++
Matrix< T >  operator*(const Matrix< T >& m1, const Matrix< T >& m2)
```
```operator*```  - умножение матрицы на матрицу
```const Matrix<T>& m1``` - матрица, ```const Matrix<T>& m2``` - матрица
возвращает новую матрицу как результат умножение матрицы на матрицу
если кол-во столбцов 1-й матрицы не равно
кол-ву строк 2-й, выбрасывается исключение в виде строки
- - -
<a id="anchor20"></a>

###### 
```c++
Matrix< T >  operator*=(Matrix< T >& m1, const Matrix< T >& m2)
```
```operator*=```  - умножение исходной матрицы на матрицу
```Matrix<T>& m1``` - матрица, ```const Matrix<T>& m2``` - матрица
возвращает новую исходную матрицу как результат умножения исходной матрицы на матрицу
если кол-во столбцов 1-й матрицы не равно
кол-ву строк 2-й, выбрасывается исключение в виде строки
- - -
<a id="anchor21"></a>

######
```c++
bool  operator==(const Matrix< T >& m1, const Matrix< T >& m2)
```
```operator==```  - сравнение матриц поэлементно
```const Matrix<T>& m1``` - матрица1, ```const Matrix<T>& m2``` - матрица2
возвращает ```true``` если матрицы равны или ```false```  если не равны
- - -
<a id="anchor22"></a>

######
```c++
bool  operator==(const vector< T >& v1, const vector< T >& v2)
```
```operator==```  - сравнение массивов поэлементно
```const vector<T>& v1``` - вектор1, ```const vector<T>& v2``` - вектор2
возвращает ```true``` если вектора равны или ```false```  если не равны
- - -
<a id="anchor23"></a>

######
```c++
void print_len_mtrx(vector< T >& m)
```
печать строки матрицы
```vector<T>& m``` - вектор- строка матрицы
- - -
<a id="anchor24"></a>

###### 
```c++
double average_mtrx(const Matrix< T >& m1)
```
среднее арифметическое элементов матрицы
```const Matrix<T>& m1``` - матрица
возвращает среднее арифметическое = сумма элементов / кол-во эл-тов
если матрица пустая, выбрасывается исключение в виде строки
- - -
<a id="anchor25"></a>

###### 
```c++
Matrix< T > zero_mtrx(Matrix< T >& m1)
```
обнуление матрицы
```Matrix<T>& m1``` - матрица
возвращает новую обнулённую матрицу
- - -
<a id="anchor26"></a>

###### 
```c++
vector< double > root_mtrx(const Matrix< T >& a, const vector< T >& c)
```
нахождение корней матрицы, метод Холецкого
```const Matrix<T>& a``` - система линейных уравнений, в которой записаны коэффициенты 
перед переменными, ```const vector<T>& c``` - вектор-столбец свободных коэфф.
возвращает вектор-столбец корней
- - -
<a id="anchor27"></a>

###### 
```c++
vector< vector< double > > inverse(Matrix< T >& matrix)
```
нахождение обратной матрицы
```Matrix<T>& matrix``` - матрица
возвращает новую обратную матрицу
выбрасывается исключение в виде строки если матрица вырождена (определитель равен нулю)
- - -
<a id="anchor28"></a>

###### 
```c++
void print_vector(vector< T > a)
```
печать вектора
```vector< T > a``` - вектор с типом T
- - -
<a id="anchor29"></a>

###### 
```c++
void  all_assert()
```
Проверка методов и функций