#pragma once
#include <cstring>
class String
{
private:
	char* m_pStr;		// ������� ������ ������ (����� ������)
	int len;
public:
	String();
	String(char* s);	// ���������� ������������
	String(char s);
	~String();		// ���������� �����������

	void Copy(char* s);
	char* GetString();
	int GetLength();	// ���������� ������ (����� ������)
	void Clear();
	String& operator= (const String& s);	// ����������
	 
	String(const String &str) { Copy(str.m_pStr); };// ����������� �����������

	String substr(int start, int end);
	bool compare(String str);
	bool operator== ( String& s);
virtual	String* operator+ ( String& s);
	String operator+ (char* s);
	bool operator> (String& s);
	bool operator< (String& s);
	virtual	void MakeNegative(){};
};
