#pragma once
class MyString
{
private:
	char* m_pStr;		// ������� ������ ������ (����� ������)
public:
    MyString ();
	MyString (char* s);	// ���������� ������������
    ~MyString();		// ���������� �����������

	void Copy (char* s);
	char* GetString();	// ���������� ������ (accessor)
	int GetLength();	// ���������� ������ (����� ������)
	MyString& operator= (const MyString& s);	// ����������

	MyString(const MyString &str) { Copy(str.m_pStr); };// ����������� �����������



};
