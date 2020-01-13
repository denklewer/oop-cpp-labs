#include "stdafx.h"
#include "String.h"



void String::Copy(char* s)
{
	

	// Динамически выделяем требуемое количество памяти.
	int len = strlen(s) + 1;
	char* tmp = new char[len];
	m_pStr = tmp;
	// + 1, так как нулевой байт тоже нужно скопировать
	// Если память выделена, копируем строку-аргумент в строку-член класса
	if (m_pStr)
		strcpy_s(m_pStr, len, s);
}

// Определение конструктора.
String::String()
{
	m_pStr = 0;
	Copy("");
}
String::String(char* s)
{
	m_pStr = 0;
	Copy(s);
}

// Определение деструктора.
String::~String()
{
	// Освобождение памяти, занятой в конструкторе для строки-члена класса
	delete[] m_pStr;
}

// Метод класса
String& String::operator= (const String& s)	// Присвоение
{
	if (this == &s) // проверка того, не указывают  первое значение  и то, которое пытаемся присвоить на один и тот же объект
		return *this;
	Copy(s.m_pStr);

	return *this;
}

void String::Clear(){
	m_pStr = "";
}

String String::substr(int start, int end){
	char* tmp = new char[30];
	strcpy_s(tmp, 30, m_pStr);
	return tmp;
}
bool String::compare(String str){
	if (m_pStr == str.GetString()){
		return 1;
	}
	return 0;
}
bool String::operator== ( String& s){
	if (m_pStr == s.GetString()){
		return 1;
	}
	return 0;
}
String String::operator+ (String& s){
	String tmp;
	char* buf=(char*)malloc(strlen(s.GetString()) + strlen(m_pStr) + 1);

	sprintf(buf, "%s%s",m_pStr , s.GetString());
	tmp.Copy(buf);

	return tmp;
}

String String::operator+ (char* s){
	String tmp;
	char* buf = (char*)malloc(strlen(s + strlen(m_pStr) + 1));

	sprintf(buf, "%s%s", m_pStr, s);
	tmp.Copy(buf);
	return tmp;
}

bool String::operator> (String& s){
	if (m_pStr > s.GetString()){
		return 1;
	}
	return 0;
}
bool String::operator< (String& s){
	return  s>(*this);
}




char* String::GetString()
{
	return m_pStr;
}

int String::GetLength()
{
	return strlen(m_pStr) + 1;
}
