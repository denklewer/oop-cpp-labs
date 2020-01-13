// lab7.cpp: определяет точку входа для консольного приложения.
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
	TypeArray a,				// пустой массив
		b(3),         
		c(SZ, Init),  // массив из SZ эл-в с инициализацией
		d(c);         // к-р копии
	cout << c<<endl;
	
	cout << d << endl;
	c.Insert(d, 1, 1, 2);      // (массив, место куда вставить, место с какого начать, место каким закончить)
	cout << c << endl;
	cout << d << endl;
	stop;


	
}