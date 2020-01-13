// Lab1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

int n;	 // ���������� ����������. �� ��������� ��� ����������.

namespace space	 // � ������������ ���� - space
{
	int n = 1;	 // ��������� ���������� n
}				 // space ���������� ������� ��������� ���� ����������

void  main()
{
	setlocale(LC_CTYPE, ".1251");		// ������� ��������� ����� ������� ��������
	setlocale(LC_MONETARY, ".1251");
	// �������� ��������� �� �����, ������� �� ���������� ����������  � ��������������� ���������, �������� ����
	// ����������� ��������. �������� �������� �� ������ ������������� ����������  signed � unsigned ����� ������.
	char c = 'A'; // 65 'A' 0x41 
	// � ����������� ������ ������� ���������� ���������� ���������� � ����������������� 
	// �������� ���������� ����� ���������� ��������� ������. �� ������ ������ �� � ���� Autos.
	c = 0x42;		// 66 'B' 0x42
	c = -1;		// -1 '�' 0xff
	c = CHAR_BIT;	 // ������ ���������� ���� char
	stop;

	// � ������������ �������� ���������, ������������ ���������� sizeof ���
	// ���������� ���� wchar_t (�� ������)
	wchar_t cw = L'�';
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

	short s = 0xffff;	 // ����� compiler ���������� warning (different data types)
	s = short(0xffff);
	s = 1;

	//==== �������� ���, ����� ������ warnings
	unsigned short us = 0xffff;
	us = 5;

	long l = 0xffffffff;
	l = -128;

	l = FLT_MAX_EXP;	// ��� ��� ��������� �� ������ ����� � ����� limits � ��������� �� ����� � ������� �������
	l = DBL_MAX_EXP;

	l = FLT_MANT_DIG;
	l = DBL_DIG;

	l = FLT_MANT_DIG;
	l = DBL_MANT_DIG;

	float f = -12.56;	 // ����� warning. ������� ���.
	f = -1.e-27f;

	f = FLT_MAX;
	f = FLT_MIN;

	double d = 0.1234567890123456789123456789;
	d = -0.123456789012345e+306;
	d = DBL_MAX;
	d = DBL_MIN;
	d = DBL_EPSILON; // ����� ��������� �������� ����� ����� ���-�� ���� double

	uc = ~0;		 // ��������� ���������
	i = ~0;
	stop;
	// ������ (��� ����������) ��� ������� ���������� ����� ������
	// ��������� �� ��������, ������� �� ���������� � ���� Autos. ���������� ������� ��������� ������������.
	d = f = i = s = c = 1 / 3;
	c = s = i = f = d = 100 / 3;
	c = s = i = f = d = 10 / 3;
	c = s = i = f = d = 1 / 3.;

	// ������ "����������" ������������� �������� ���������� �����.	 ��������� ����������.
	i = 256;
	c = i;

	uc = 255;
	unsigned char u = 2, sum = uc + u;
	stop;

	// ����� ���������� �����	��������� ������� ����������� � ������� (3) � (4)
	i = 100;
	f = d = i / 3;							// (3)
	f = d = (double)i / 3;		// (4)
	f = d = double(i) / 3;			// (4)
	f = d = static_cast<double>(i) / 3;		// (4)
	stop;

	// ������� ��������, ������� ��������� � ����� �������������. � ���� ��������� ���������� ������
	//  ���������� � ����� � ��� �� ������ n.  ���� - ����������, ������ ���������� � ����� ������������ ����,
	// ������ - ��������� ������ ������� main(), ��������� - ��������� ������ �����. 
	//  �������� ��������, ��� ���������� ���������� � ��, ��� � ������������ ���� space - ��������� ��� ������� main()
	// ����������, � ����� �� ������� ���������� ���� ���������, c������������ ������� �������� � ������� ���������
	// ������ ����������. ��� ���������� ������� ������������� ������������  ��������� "Watches" ��� "Locals" ����
	// "Autos". ���������: � ���� "Watches" ����� ��������� ����� ��� ���������� (n, ::n, � space::n)
	n = 100;
	space::n = 200;
	n++;
	int n;		//��� ����� ��� ���������� ?
	n = 10;
	::n++;

	{				//  ������ �����
		int n;		// ��� ���������� ����� ������ �����
		n = -1;
		n++;
		::n++;
		space::n++;
	}		// ����� �����
	n--;
	::n--;
	space::n--;

	// ������������ ������ ������ - static �������� ������� �� �����, �������� �������� ��  ������ ���������
	// ���������� nLoc � nStat
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
	// ������������ - enum. �������� �������� �� ����� � ������� ������������� ��������
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
		// ����� ������������� ���������� ����� ��������� enum-���������� 
		int i = r;
		r = RANK(i++);		// �������� �������������� ���� ��������� ����
		i = r;
		r = RANK(++i);
		i = r;
	}
	RANK rr = eColonel;
	stop;
	//	���������� ��� bool.	�������� ������� �� �����, ������� �� ���������� ���������� b
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

	//	����������� const
	const double pi = acos(-1.);
	double space_permiability = 4.e-7 * pi;		//	��������� ������������� �������
	const int dozen = 12;
	int var = dozen;

	//	���������������� ��������� ������� � ��������� ������ ���������� (l-value �������� left value)
	//	dozen = 1;
	//	��������� �������� ����������. ��������� ��������, ������� ��������� ���������� version.
	//	��� ����� ������� ��� ����, ����� ��������� ��� ������?
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

	//� ���� ClassView ��� Solution Explorer ��������� ����� �� ��� ������� ����� ������� Project/Properties.
	//	� ������� Property Pages �������� �� ����� Configuration Properties, ���������, ��� � ������� Code Generation
	//	����������� ��������� ���������� _DEBUG. �������� ��������� ������������� � ��� �++, �������
	//	� ����������� �� ����������� ������������ ������� (_DEBUG ��� NDEBUG) ������� ���������������
	//	���������. �������� ������������ ������� (� ������� Property Pages) � ��������� ��� ���.
	//	����� �������� ������������ ����������� ������� Configuration Manager

	//	���������� �����. ��������� ���� �������������. 
	{
		// ���� while ���� ������������, ����� ���������� ���������� �������� (����������) �����.
		// �������� & � ��� ��������� AND.  �������� &= � ��� ��������� AND � �����������.
		// ���� ���������, �� �������� �������� �������� ����� �.doc
		cout << "\n\nGradually eat out all the units:\n\n";
		unsigned short us = 0xff;
		while (us)
		{
			cout << hex << us << endl;
			us &= us - 1;
		}
		cout << hex << us << "\nDone\n";
		// ���� for ���� ������������, ����� �������� ���������� �������� �/��� ���� ��� ����������.
		// ���������: odd - �������, even - ������.
		cout << "\n\nShow even-odd:\n\n";
		for (int i = 0; i<10; i++)
		{
			if (i & 1)
				cout << i << " - odd\n";
			else
				cout << i << " - even\n";
		}
		// ���� do-while ������������ �� �����, ��� ��� ��� ������� 
		// �������� ���������� ��� �������� ����� ������.
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