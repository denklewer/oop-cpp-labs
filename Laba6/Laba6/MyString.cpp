#pragma once
#include "stdafx.h"
#include "MyString.h"

void MyString::Copy (char* s)
{
	delete [] m_pStr;
	// ����������� �������� ��������� ���������� ������.
	int len = strlen(s) + 1;
	m_pStr = new char[len];
	// + 1, ��� ��� ������� ���� ���� ����� �����������
	// ���� ������ ��������, �������� ������-�������� � ������-���� ������
	if (m_pStr)
		strcpy_s (m_pStr, len, s);
}

// ����������� ������������.
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

// ����������� �����������.
MyString::~MyString()
{
	// ������������ ������, ������� � ������������ ��� ������-����� ������
	delete[] m_pStr;
}

// ����� ������
MyString& MyString::operator= (const MyString& s)	// ����������
{
	if (this == &s) // �������� ����, �� ���������  ������ ��������  � ��, ������� �������� ��������� �� ���� � ��� �� ������
		return *this;
	Copy(s.m_pStr);
	
	return *this;
}





char* MyString::GetString()
{
	return m_pStr;
}

int MyString::GetLength()
{
	return strlen(m_pStr) + 1;
}
