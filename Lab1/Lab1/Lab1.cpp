// Lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

int n;	 // Глобальная переменная. По умолчанию она обнуляется.

namespace space	 // В пространстве имен - space
{
	int n = 1;	 // Объявлена переменная n
}				 // space определяет область видимости этой переменной

void  main()
{
	setlocale(LC_CTYPE, ".1251");		// Функция установки нашей кодовой страницы
	setlocale(LC_MONETARY, ".1251");
	// Выполняя программу по шагам, следите за значениями переменных  и интерпретируйте результат, объясняя себе
	// наблюдаемые значения. Обратите внимание на разную интерпретацию отладчиком  signed и unsigned типов данных.
	char c = 'A'; // 65 'A' 0x41 
	// В комментарии справа полезно проставить десятичное символьное и шестнадцатиричное 
	// значения переменной после выполнения указанной строки. Вы должны видеть их в окне Autos.
	c = 0x42;		// 66 'B' 0x42
	c = -1;		// -1 'я' 0xff
	c = CHAR_BIT;	 // Размер переменной типа char
	stop;

	// В комментариях напишите результат, возвращаемый оператором sizeof для
	// переменной типа wchar_t (ее размер)
	wchar_t cw = L'Ф';
	size_t ns = sizeof(cw);

	unsigned char uc = 0x41;
	uc = 'B';
	uc = -1;
	stop;

	int i = 1;
	i = -1;
	stop;

	unsigned int ui = 1;
	ui = -1;

	short s = 0xffff;	 // Здесь compiler генерирует warning (different data types)
	s = short(0xffff);
	s = 1;

	//==== Измените код, чтобы убрать warnings
	unsigned short us = 0xffff;
	us = 5;

	long l = 0xffffffff;
	l = -128;

	l = FLT_MAX_EXP;	// Все эти константы вы должны найти в файле limits и объяснить их смысл с помощью рисунка
	l = DBL_MAX_EXP;

	l = FLT_MANT_DIG;
	l = DBL_DIG;

	l = FLT_MANT_DIG;
	l = DBL_MANT_DIG;

	float f = -12.56;	 // Здесь warning. Уберите его.
	f = -1.e-27f;

	f = FLT_MAX;
	f = FLT_MIN;

	double d = 0.1234567890123456789123456789;
	d = -0.123456789012345e+306;
	d = DBL_MAX;
	d = DBL_MIN;
	d = DBL_EPSILON; // Самая маленькая разность между двумя пер-ми типа double

	uc = ~0;		 // Побитовое отрицание
	i = ~0;
	stop;
	// Раннее (при компиляции) или неявное приведение типов данных
	// Объясните те значения, которые вы наблюдаете в окне Autos. Определите порядок выполения присваиваний.
	d = f = i = s = c = 1 / 3;
	c = s = i = f = d = 100 / 3;
	c = s = i = f = d = 10 / 3;
	c = s = i = f = d = 1 / 3.;

	// Пример "небрежного" использования неявного приведения типов.	 Объясните результаты.
	i = 256;
	c = i;

	uc = 255;
	unsigned char u = 2, sum = uc + u;
	stop;

	// Явное приведение типов	Объясните разницу результатов в строках (3) и (4)
	i = 100;
	f = d = i / 3;							// (3)
	f = d = (double)i / 3;		// (4)
	f = d = double(i) / 3;			// (4)
	f = d = static_cast<double>(i) / 3;		// (4)
	stop;

	// Область действия, область видимости и время существования. В этом фрагменте фигурируют четыре
	//  переменных с одним и тем же именем n.  Одна - глобальная, вторая определена в своем пространстве имен,
	// третья - локальная внутри функции main(), четвертая - локальная внутри блока. 
	//  Обратите внимание, что глобальная переменная и та, что в пространстве имен space - объявлены вне функции main()
	// Определите, к какой из четырех переменных идет обращение, cформулируйте область действия и область видимости
	// каждой переменной. Для выполнения задания рекомендуется пользоваться  закладкой "Watches" или "Locals" окна
	// "Autos". Подсказка: В окно "Watches" можно поместить сразу все переменные (n, ::n, и space::n)
	n = 100;
	space::n = 200;
	n++;
	int n;		//Где живет эта переменная ?
	n = 10;
	::n++;

	{				//  Начало блока
		int n;		// Эта переменная живет внутри блока
		n = -1;
		n++;
		::n++;
		space::n++;
	}		// Конец блока
	n--;
	::n--;
	space::n--;

	// Спецификатор класса памяти - static Выполняя задание по шагам, обратите внимание на  разное поведение
	// переменных nLoc и nStat
	{
	Again:
		int outer;
		for (int i = 0; i<5; i++)
		{
			static int nStat;
			{
				int nLoc = 0;
				nLoc++;		nStat++;
			}
			outer = nStat;
		}
		if (outer < 10)
			goto Again;
	}
	// Перечисления - enum. Обратите внимание на явную и неявную инициализацию констант
	enum RANK
	{
		eSoldier,
		eSergeant,
		eCorporal,
		eLieutenant,
		eCaptain = 6,
		eMajor,
		eColonel = eMajor + 3,
		eGeneral = 20
	};
	typedef RANK RANG;

	RANG r = eSoldier;
	if (r == eSoldier)
		r = eSergeant;

	if (r == eSergeant)
	{
		// Любой целочисленной переменной можно присвоить enum-переменную 
		int i = r;
		r = RANK(i++);		// Обратное преобразование надо указывать явно
		i = r;
		r = RANK(++i);
		i = r;
	}
	RANK rr = eColonel;
	stop;
	//	Логический тип bool.	Выполняя задание по шагам, следите за значениями переменной b
	{
		int n = 127;
		bool b = n != 0;
		b = n == 0;
		b = n > 0;
		b = n <= 0;
		b = n > 1;

		int num = static_cast<int>(b);
		if (b)
			cout << "\n\t My flag is: true" << "   or: " << b
			<< "\n\t Conversion to int: " << num << endl;
		b = n == num;
		cout << "\n\t Now the flag is: false" << "   or: " << b;
	}

	//	Модификатор const
	const double pi = acos(-1.);
	double space_permiability = 4.e-7 * pi;		//	Магнитная проницаемость пустоты
	const int dozen = 12;
	int var = dozen;

	//	Раскомментируйте следующую строчку и объясните ошибку компиляции (l-value означает left value)
	//	dozen = 1;
	//	Директивы условной трансляции. Объясните значение, которое принимает переменная version.
	//	Что нужно сделать для того, чтобы результат был другим?
#define _MSVER400
	char *version;
#if defined _MSVER400
	version = "version 4.00";
#elif defined _MSVER311
	version = "version 3.11";
#else
	version = "version Unknown";
#endif

	cout << endl << version;
	stop;

	//В окне ClassView или Solution Explorer поставьте фокус на имя проекта дайте команду Project/Properties.
	//	В диалоге Property Pages щелкните на папке Configuration Properties, убедитесь, что в разделе Code Generation
	//	установлена константа компиляции _DEBUG. Создайте директивы препроцессора и код С++, которые
	//	в зависимости от действующей конфигурации проекта (_DEBUG или NDEBUG) выводят соответствующее
	//	сообщение. Измените конфигурацию проекта (в диалоге Property Pages) и проверьте ваш код.
	//	Чтобы изменить конфигурацию пользуйтесь кнопкой Configuration Manager

	//	Простейшие циклы. Объясните суть происходящего. 
	{
		// Цикл while надо использовать, когда неизвестно количество итераций (повторений) цикла.
		// Операция & — это побитовое AND.  Операция &= — это побитовое AND с присвоением.
		// Если непонятно, то прочтите документ Операции языка С.doc
		cout << "\n\nGradually eat out all the units:\n\n";
		unsigned short us = 0xff;
		while (us)
		{
			cout << hex << us << endl;
			us &= us - 1;
		}
		cout << hex << us << "\nDone\n";
		// Цикл for надо использовать, когда известно количество итераций и/или есть код подготовки.
		// Подсказка: odd - нечетое, even - четное.
		cout << "\n\nShow even-odd:\n\n";
		for (int i = 0; i<10; i++)
		{
			if (i & 1)
				cout << i << " - odd\n";
			else
				cout << i << " - even\n";
		}
		// Цикл do-while программисты не любят, так как они требуют 
		// большего напряжения при разгадке своей логики.
		char c = ' ';
		do
		{
			if (c == 'a')
				cout << "\nAction is a delegate type in C#";
			else if (c == 'b')
				cout << "\nbreak is one of the 'leave' statements in all C-like languages";
			else if (c == 'c')
				cout << "\ncontinue is a 'go on' statement in all C-like languages";
			else if (c == 'd')
				cout << "\ndo-while is a rarely used loop statement in all C-like languages";
			else
				cout << "\nPlease read the rules of this loop";
			cout << "\n\nEnter chars: a, b, c, d (q - to quit):\n\n";
			cin >> c;
			if (c == 'q')
				cout << "\nI am going to leave the loop\n";
		} while (c != 'q');
		stop;
	}