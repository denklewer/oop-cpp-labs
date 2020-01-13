//=======================================================================
//	Занятие №6. Шаблоны функций. Шаблоны классов. Стандартные шаблоны С++.
//				Обработка исключений.
//=======================================================================
#pragma once
#include "stdafx.h"
#include "Vector.h"
#include "MyString.h"
#include "Stack.h"
#include <vector>
#include <list>
#include <algorithm>
//#include "MyMan.h"

//============= Шаблон функции для вывода с помощью итератора
template <class T> void pr(T& v, string s)
{
	cout<<"\n\n\t"<<s.c_str()<<"  # Sequence:\n";
	
	// Итератор любого контейнера
	T::iterator p;
	int i;

	for (p = v.begin(), i=0;  p != v.end();  p++, i++)
		cout << endl << i+1 <<". "<< *p;
	cout << '\n';
}

template <class T>
void Swap(T& x, T& y)
{
	T* temp=new T();
	*temp = x;
	x = y;
	y = *temp;

}

void print(Vector &v){
	v.Out();
}
bool pred(Vector &v){
	if ((v.GetX() > 2)&&(v.GetY() > 2)){ return true; }
	return false;
}
bool pred2(Vector* v){
	if ((v->GetX() > 2) && (v->GetY() > 2)){ return true; }
	return false;
}
bool FirstM(string s){
	if (s[0]=='M'){ return true; }
	return false;
}

//----------------------------
string Fstr = "";

	bool FindStr(string s)
	{
		if (Fstr == s){ return true; }
		return false;
	}









void main()
{

	//===========================================================
	// Шаблоны функций
	//===========================================================
	// Создайте шаблон функции перестановки двух параметров - Swap().
	// Проверьте работоспособность созданного шаблона с помощью
	// приведенного ниже фрагмента.





	{
		int i = 1, j = -1;
		Swap(i, j);

		double a = 0.5, b = -5.5;
		Swap(a, b);

		Vector u(1, 2), w(-3, -4);
		Swap(u, w);

		// Если вы достаточно развили класс MyString в предыдущей работе,
		// то следующий фрагмент тоже должен работать корректно.
		
		MyString s1 ("Your fault"), s2 ("My forgiveness");
		Swap (s1, s2);
	}
	//===========================================================
	// Шаблоны классов
	//===========================================================
	// Создайте шаблон класса MyStack для хранения элементов любого типа T.
	// В качестве основы для стека может быть выбран массив.
	// Для задания максимального размера стека может быть использован
	// параметр-константа шаблона
	// Обязательными операциями со стеком являются "Push" и "Pop","GetSize" и "Capacity"
	// Необязательной - может быть выбор по индексу (operator[]).
	// Для того, чтобы гарантировать корректное выполнение этих операций 
	// следует генерировать исключительные ситуации.
	

	Stack <int> st1(5);
	Stack <double> st2(5);
	Stack <Vector> st3(5);
	
	// С помощью шаблона MyStack создайте стек переменных типа int, затем
	// стек переменных типа double и, наконец, стек из переменных типа Vector 
	// Если вы подготовите три класса для обработки исключений,
	// то следующий фрагмент должен работать
	try
	{
		cout << "\tTest MyStack\n";
		Stack <int> stack(3);

		cout << "\nInteger Stack capacity: " << stack.Capacity();

		stack.Push(1);
		stack.Push(2);
		stack.Push(3);
		
		cout << "\nInteger Stack has: " << stack.GetSize() << " elements";

//	stack.Push(4);	// Здесь должно быть "выброшено" исключение

		cout << "\nInteger Stack pops: " << stack.Pop();
		cout << "\nInteger Stack pops: " << stack.Pop();
		
		cout << "\nInteger Stack has: " << stack.GetSize() << " elements";
		stack.Pop();
	//	stack.Pop();		// Здесь должно быть "выброшено" исключение
		stack.Push(2);
		
	//	int i = stack[3];	// Здесь должно быть "выброшено" исключение
		
		Stack<Vector> ptStack(5);
		
		cout << "\nVector Stack capacity: " << ptStack.Capacity();
		
		ptStack.Push(Vector(1,1));
		ptStack.Push(Vector(2,2));
		
		cout << "\nVector Stack pops: ";
		// Используйте метод класса Vector для вывода элемента
		ptStack.Pop().Out();
		
		cout << "\nVector Stack has: " << ptStack.GetSize() << " elements";
	}
	catch (StackOverflow)
	{
		cout << "\nStack overflow";
	}
	catch (StackUnderflow)
	{
		cout << "\nStack underflow";
	}
	catch (StackOutOfRange o)
	{
		o.Out();
	}

	stop;

	//=======================================================================
	// Контейнеры стандартной библиотеки. Последовательности типа vector
	//=======================================================================
	
	// Создайте пустой вектор целых чисел. Узнайте его размер с помощью метода size(),
	// С помощью метода push_back() заполните вектор какими-либо значениями.
	// Получите новый размер вектора и выведите значения его элементов.
	// В процессе работы с вектором вы можете кроме количества реально заполненных
	// элементов (size()) узнать максимально возможное количество элементов (max_size()),
	// а также зарезервированную память (capacity()).
	unsigned i=0;
	vector<int> v;
	int n = v.size(); //0
	v.push_back(-1);  
	v.push_back(-2);
	n = v.size();  // 2
	n = v.capacity();// 2
	n = v.max_size(); // 1073741823
		
	// Так как мы часто будем выводить последовательности, то целесообразно
	// создать шаблон функции для вывода любого контейнера.
	// Проанализируйте коды такого шабдлона (pr), который приведен выше
	// Используйте его для вывода вашего вектора

	pr (v, "Vector of ints");
	
	// Используем другой конструктор для создания вектора вещественных
	// с начальным размером в 2 элемента и заполнением (222.).
	// Проверим параметры вектора. Затем изменим размер вектора и его заполнение
	// (метод - resize()) и вновь проверим параметры.
	
	vector<double> vd(2);
	vd.push_back(222.); 
	vd.push_back(1.3);
	pr (vd, "Vector of doubles");
	n = vd.size(); //4
	n = vd.capacity(); //4
	n = vd.max_size(); // 536870911
	vd.resize( 4);
	vd.push_back(22.);
	vd.push_back(1.0);
	pr (vd, "After resize");
	n = vd.size(); //6
	n = vd.capacity();//6
	n = vd.max_size(); // 536870911
	stop;
	// Используя метод at(), а также операцию выбора [], измените значения
	// некоторых элементов вектора и проверьте результат.
	vd.at(0) = 2.5;
	vd[1] = 3.9;


	pr (vd, "After at");
	stop;
	// Создайте вектор вещественных, который является копией существующего.
	vector < double>wd = vd;
	stop;

	pr (wd, "Copy");
	
	// Создайте вектор, который копирует часть существующей последовательности
	vector<double> ud;
	ud.assign(&wd[0], &wd[2]);
	pr (ud, "Copy part");

	stop;
	// Создайте вектор вещественных, который является копией части обычного массива.
	double ar[] = { 0., 1., 2., 3., 4., 5. };


	vector<double> va(ar+1, ar + 5);
pr (va, "Copy part of array");
stop;
	// Создайте вектор символов, который является копией части обычной строки
	char s[] = "Array is a succession of chars";
	  
	vector<char> vc(s, s + 10);
	pr (vc, "Copy part of c-style string");

	// Создайте вектор элементов типа Vector и инициализируйте
	// его вектором с координатами (1,1).
	vector<Vector> vv;
	vv.push_back(Vector(1, 1));
		
	
	cout << "\n\nvector of Vectors\n";
	for (i = 0; i < vv.size(); i++)
	{
		vv[i].Out();
	}
	stop;
	// Создайте вектор указателей на Vector и инициализируйте его адресами
	// объектов класса Vector
	
	vector<Vector*> vp;

	cout << "\n\nvector of pointers to Vector\n";
	vp.push_back(new Vector(1, 2));
	vp.push_back(new Vector(3, 4));
	for ( i = 0; i < vp.size(); i++)
	{vp[i]->Out(); }
	stop;
	// Научитесь пользоваться методом assign и операцией
	// присваивания = для контейнеров типа vector.
	vp.assign(10, new Vector(1, 2));

	cout << "\n\nAfter assign\n";
	for ( i=0;  i < vp.size();  i++)
		vp[i]->Out();
	stop;
	// Декларируйте новый вектор указателей на Vector и инициализируйте его 
	// с помощью второй версии assign
	vector<Vector*> vpNew;
	vpNew.assign(&vp[0], &vp[4]);
	
	cout << "\n\nNew vector after assign\n";
for (i=0;  i < vpNew.size();  i++)
		vpNew[i]->Out();

stop;
	// На базе шаблона vector создание двухмерный массив и
	// заполните его значениями разными способами.
	// Первый вариант - прямоугольная матрица
	// Второй вариант - ступенчатая матрица

	
	//========= Ступенчатая матрица
	vector <vector<double>> vdd(6);
	unsigned j=0;
		for ( i=0;  i < vdd.size();  i++)
		vdd[i] = vector<double>(i+1, double(i));
	
cout << "\n\n\tTest vector of vector<double>\n";
	for ( i=0;  i < vdd.size();  i++)
	{
		cout << endl;
		for (j=0;  j < vdd[i].size();  j++)
			cout << vdd[i][j] << "  ";
	}	
  
	stop;

	//===================================
	// Простейшие действия с контейнерами
	//===================================
	//3б. Получение значения первого и последнего элементов последовательности.
	//Получение размера последовательности. Присваивание значений
	//элементов одной последовательности элементам другой - assign().


	//Создайте и проинициализируйте вектор из элементов char. Размер -
	//по желанию.
	vector<char> vch(4);
	for ( i = 0; i < vch.size(); i++){
		vch[i] = i+48;
}

	//Создайте и проинициализируйте массив из элементов char. Размер -
	//по желанию.
	char cMas[] = "1234567";



	//Получите значение первого элемента вектора ( front() )
	cout << "\n first element is : "<< vch.front();

	//Получите значение последнего элемента вектора ( back() )
	cout << "\n last element is : " << vch.back();

	//Получите размер вектора
	cout << "\n size of vector is : " << vch.size();

	//Присвойте вектору любой диапазон из значений массива cMas.
	vch = vector<char>(cMas, cMas+5);

	//Проверьте размер вектора, первый и последний элементы.
	cout << "\n now first element is : " << vch.front();
	cout << "\n now last element is : " << vch.back();
	cout << "\n  now size of vector is : " << vch.size();
	stop;


	//3в. Доступ к произвольным элементам вектора с проверкой - at()
	//и без проверки - []
	//Создайте неинициализированный вектор из 8 элементов char - vChar2.
	vector<char> vChar2(8);
	for ( i = 0; i < vChar2.size(); i = i + 2){
		vChar2.at(i) = vch[i / 2];
	}
	char str2[] = "KUKU";
	for ( i = 1; i < vChar2.size(); i = i + 2){
		vChar2[i] = str2[i/2];
	}

	//С помощью at() присвойте четным элементам вектора значения
	//элементов vChar1 из предыдущего задания,
	//а с помощью [] присвойте нечетным элементам вектора vChar2 значения
	//массива {'K','U','K','U'}.

	
	  stop;
	//	vChar2.at(9) = 0;  исключение
//		vChar2[9] = 0;  крах программы

	//Попробуйте "выйти" за границы вектора с помощью at() и
	//с помощью []. Обратите внимание: что происходит при
	//попытке обращения к несуществующему элементу в обоих случаях

  
	stop;

	//3г.Добавьте в конец вектора vChar2  - букву Z (push_back()). Для
	vChar2.push_back('Z');


	//расширения кругозора можете ее сразу же и выкинуть (pop_back())
	vChar2.pop_back();
  
	stop;

	//3д. Вставка-удаление элемента последовательности insert() - erase()
	//Очистка последовательности - clear()



	//Вставьте перед каждым элементом вектора vChar2 букву 'W'
	for (i = 0; i <  vChar2.size(); i = i + 2){
		vChar2.insert(vChar2.begin()+i, 'W');
	}
	stop;
	//Вставьте перед 5-ым элементом вектора vChar2 3 буквы 'X'
	vChar2.insert(vChar2.begin() + 4, 3, 'X');
	stop;
	//Вставьте перед 2-ым элементом вектора vChar2 с третьего по
	//шестой элементы массива "aaabbbccc"
	char str[] = "aaabbbccc";
		vChar2.insert(vChar2.begin() + 1, str + 3, str + 6);
		stop;
	//Сотрите c первого по десятый элементы vChar2
		vChar2.erase(vChar2.begin(), vChar2.begin() + 9);
  
	stop;

	//Уничтожьте все элементы последовательности - clear()
	vChar2.clear();

	stop;

	//Создание двухмерного массива

	stop;

///////////////////////////////////////////////////////////////////

	//Задание 4. Списки. Операции, характерные для списков.
	//Создайте два пустых списка из элементов Vector - ptList1 и
	//ptList2
	list<Vector> ptList1;
	list<Vector> ptList2;
		

	//Наполните оба списка значениями с помощью методов push_back(),
	//push_front, insrert()
	ptList1.push_back(Vector(1,1));
	ptList1.push_front(Vector(2, 1));
	ptList2.insert(ptList2.begin(), ptList1.begin(),ptList1.end());
	ptList1.insert(++ptList1.begin(), ptList2.begin(), ptList2.end());
	stop;
	//Отсортируйте списки - sort().
	ptList1.sort();
	ptList2.sort();
	//Подсказка: для того, чтобы работала сортировка, в классе Vector
	//должен быть переопределен оператор "<"

  
	stop;

	//Объедините отсортированные списки - merge(). Посмотрите: что
	//при этом происходит со вторым списком.
	ptList1.merge(ptList2);   // обнуляется

	stop;

	//Исключение элемента из списка - remove()
	//Исключите из списка элемент с определенным значением.
	//Подсказка: для этого необходимо также переопределить
	//в классе Vector оператор "=="
	ptList1.remove(Vector(2, 1));

	stop;

///////////////////////////////////////////////////////////////////

	//Задание 5. Стандартные алгоритмы.Подключите заголовочный файл
	// <algorithm>
	//5а. Выведите на экран элементы ptList1 из предыдущего
	//задания с помощью алгоритма for_each()
	
	 
	for_each(ptList1.begin(), ptList1.end(),print );


	stop;

	//5б.С помощью алгоритма find() найдите итератор на элемент Vector с
	//определенным значением. С помощью алгоритма find_if() найдите
	//итератор на элемент, удовлетворяющий определенному условию, 
	//например, обе координаты точки должны быть больше 2.
	//Подсказка: напишите функцию-предикат, которая проверяет условие
	//и возвращает boolean-значение (предикат может быть как глобальной
	//функцией, так и методом класса)

	ptList1.push_back(Vector(2, 1));
	ptList1.push_back(Vector(3, 4));
	Vector b;
	b=*find(ptList1.begin(), ptList1.end(), Vector(2, 1));
	cout << "\nUsing function find()\n";
	b.Out();
	cout << "\nUsing function find_if()\n";
	b = *find_if(ptList1.begin(), ptList1.end(), pred);
	b.Out();
	  stop;

	//Создайте список из указателей на элеметы Vector. С помощью 
	//алгоритма find_if() и предиката (можно использовать предикат - 
	//метод класса Vector, определенный в предыдущем задании) найдите в
	//последовательности элемент, удовлетворяющий условию

		list<Vector*> ptList3;
		ptList3.push_back(new Vector(1, 1));
		ptList3.push_back(new Vector(1, 2));
		ptList3.push_back(new Vector(1, 3));
		ptList3.push_back(new Vector(2, 1));
		ptList3.push_back(new Vector(5, 7));
		ptList3.push_back(new Vector(1, 4));
		cout << "\n 2.Using function find_if()\n";
		Vector* res;
		res = *find_if(ptList3.begin(), ptList3.end(), pred2);
		res->Out();
	  stop;

	//5в. Создайте список элементов Vector. Наполните список
	//значениями. С помощью алгоритма replace() замените элемент
	//с определенным значением новым значением. С помощью алгоритма
	//replace_if() замените элемент, удовлетворяющий какому-либо
	//условию на определенное значение. Подсказка: условие
	//задается предикатом.

		list<Vector> ptList4;
		ptList4.push_back( Vector(1, 1));
		ptList4.push_back( Vector(1, 2));
		ptList4.push_back( Vector(1, 3));
		ptList4.push_back( Vector(2, 1));
		ptList4.push_back( Vector(5, 7));
		ptList4.push_back( Vector(1, 4));

		replace(ptList4.begin(), ptList4.end(), Vector(2, 1), Vector(3, 3));
  //Сформировали значения элементов списка
		replace_if(ptList4.begin(), ptList4.end(), pred, Vector(2, 2));
  
	stop;


	//5г. Создайте вектор строк (string). С помощью алгоритма count()
	//сосчитайте количество одинаковых строк. С помощью алгоритма
	//count_if() сосчитайте количество строк, начинающихся с заданной
	//буквы
	vector<string> vs;
	vs.push_back("Mama");
	vs.push_back("Papa");
	vs.push_back("Mama");
	vs.push_back("Brother");
	vs.push_back("Brother");
	vs.push_back("Sister");
	vs.push_back("Mama");
	int rez = 0;
	rez= count(vs.begin(), vs.end(), "Mama");
	rez=count_if(vs.begin(), vs.end(), FirstM);
	//5д. С помощью алгоритма count_if() сосчитайте количество строк,
	//которые совпадают с заданной строкой. Подсказка: смотри тему
	//объекты-функции
	Fstr = "Brother";
	rez = count_if(vs.begin(), vs.end(),FindStr);

	stop;

	cout <<"\n\n";
}