#pragma once
#include <cstring>
class String
{
private:
	char* m_pStr;		// Ёлемент данных класса (адрес строки)
	int len;
public:
	String();
	String(char* s);	// ќбъ€вление конструктора
	String(char s);
	~String();		// ќбъ€вление деструктора

	void Copy(char* s);
	char* GetString();
	int GetLength();	// ќбъ€вление метода (длина строки)
	void Clear();
	String& operator= (const String& s);	// ѕрисвоение
	 
	String(const String &str) { Copy(str.m_pStr); };// конструктор копировани€

	String substr(int start, int end);
	bool compare(String str);
	bool operator== ( String& s);
virtual	String* operator+ ( String& s);
	String operator+ (char* s);
	bool operator> (String& s);
	bool operator< (String& s);
	virtual	void MakeNegative(){};
};
