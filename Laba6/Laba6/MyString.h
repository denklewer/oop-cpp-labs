#pragma once
class MyString
{
private:
	char* m_pStr;		// Ёлемент данных класса (адрес строки)
public:
    MyString ();
	MyString (char* s);	// ќбъ€вление конструктора
    ~MyString();		// ќбъ€вление деструктора

	void Copy (char* s);
	char* GetString();	// ќбъ€вление метода (accessor)
	int GetLength();	// ќбъ€вление метода (длина строки)
	MyString& operator= (const MyString& s);	// ѕрисвоение

	MyString(const MyString &str) { Copy(str.m_pStr); };// конструктор копировани€



};
