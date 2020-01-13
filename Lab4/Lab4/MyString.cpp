#pragma once
#include "stdafx.h"
#include "MyString.h"
#include "cstring"

void MyString::Copy (char* s)
{
	delete [] m_pStr;
	// Динамически выделяем требуемое количество памяти.
	int len = strlen(s) + 1;
	m_pStr = new char[len];
	// + 1, так как нулевой байт тоже нужно скопировать
	// Если память выделена, копируем строку-аргумент в строку-член класса
	if (m_pStr)
		strcpy_s (m_pStr, len, s);
}

// Определение конструктора.
MyString::MyString()
{
	m_pStr = 0;
		Copy("");
}
MyString::MyString (char* s)
{
	m_pStr = 0;
	Copy(s);
}

// Определение деструктора.
MyString::~MyString()
{
	
	// Освобождение памяти, занятой в конструкторе для строки-члена класса
	delete[] m_pStr;
}

// Метод класса
MyString& MyString::operator= (const MyString& s)	// Присвоение
{
	if (this == &s) // проверка того, не указывают  первое значение  и то, которое пытаемся присвоить на один и тот же объект
		return *this;
	Copy(s.m_pStr);
	
	return *this;
}





char* MyString::GetString()
{
	return m_pStr;
}
char* MyString::substr(int a,int b)
{
	char* s="";
	strcpy_s(s, b, m_pStr);
	return  s;
}

int MyString::GetLength()
{
	return strlen(m_pStr) + 1;
}
bool MyString::operator== (MyString & s)	
{
	if (s.GetString() ==m_pStr) { return true; }


	return false;
}
bool MyString::compare (MyString & s)
{
	if (s.GetString() == m_pStr) { return true; }


	return false;
}