// lab7.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#pragma once
#include "stdafx.h"
#include "Array.h"
#include <fstream>

typedef int Type;
typedef Array<Type> TypeArray;


void main(){
	const unsigned SZ = 5;
	const Type Init[5] = { 1, 2, 3, 4, 5 };
	TypeArray a,				// ������ ������
		b(3),         
		c(SZ, Init),  // ������ �� SZ ��-� � ��������������
		d(c);         // �-� �����
	cout << c<<endl;
	
	cout << d << endl;
	c.Insert(d, 1, 1, 2);      // (������, ����� ���� ��������, ����� � ������ ������, ����� ����� ���������)
	cout << c << endl;
	cout << d << endl;
	stop;


	
}