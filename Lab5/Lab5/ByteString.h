#pragma once
#include "String.h"
class ByteString :
	public String
{
public:
	ByteString();
	ByteString(char* s);
	ByteString(char s);
virtual	void MakeNegative();
	~ByteString();
	ByteString& operator= (ByteString& s);	// Присвоение
virtual	ByteString* operator+( String& s);

	ByteString( ByteString &str) { Copy(str.GetString()); };  //копирование
	bool operator== (ByteString& s);
};

