#include "stdafx.h"
#include "String.h"



void String::Copy(char* s)
{
	

	// ����������� �������� ��������� ���������� ������.
	int len = strlen(s) + 1;
	char* tmp = new char[len];
	m_pStr = tmp;
	// + 1, ��� ��� ������� ���� ���� ����� �����������
	// ���� ������ ��������, �������� ������-�������� � ������-���� ������
	if (m_pStr)
		strcpy_s(m_pStr, len, s);
}

// ����������� ������������.
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

// ����������� �����������.
String::~String()
{
	// ������������ ������, ������� � ������������ ��� ������-����� ������
	delete[] m_pStr;
}

// ����� ������
String& String::operator= (const String& s)	// ����������
{
	if (this == &s) // �������� ����, �� ���������  ������ ��������  � ��, ������� �������� ��������� �� ���� � ��� �� ������
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
