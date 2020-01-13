#include "stdafx.h"
#include "ByteString.h"


ByteString::ByteString()
{
	Copy("0");
}

ByteString::ByteString(char s)
{

	
	
	Copy(&s);
}


ByteString::ByteString( char* s){
	bool flag = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++){
		if ((s[i] != '0') && (s[i] != '1')){
			Copy("0");
			flag = 1;
			break;
		}
		
	}
	if (flag != 1){
		Copy(s);
	}

}

void ByteString::MakeNegative(){
	int len = GetLength()-1;
	int i = 0;
	
	char* s = new char[8];
	strcpy_s(s, 9, "00000000");
	char* olds = new char[len];
	strcpy_s(olds, len+1, GetString());


	for (i = 0; i < 8; i++){
		if (i <len){
		if (olds[i] == '0'){
			s[i + (8 - len)] = '1';
		}
		else { s[i+(8-len)] = '0'; }
	}
		else { s[7-i] = '1'; }
}
	Copy(s);
	ByteString tmp("1");
	ByteString *btmp= new ByteString(s);
	btmp = *btmp + tmp;
	Copy(btmp->GetString());
}
ByteString& ByteString::operator= ( ByteString& s){
	if (this == &s) // проверка того, не указывают  первое значение  и то, которое пытаемся присвоить на один и тот же объект
		return *this;
	Copy(s.GetString());

	return *this;
}
int Max(int a, int b){
	if (a > b){ return a; }
	else { return b; }
}
ByteString* ByteString::operator+ (String& s){
	int len1 = GetLength();
	int len2 = s.GetLength();
	String str;
	if (len1 > len2){
		if (len1-1 == 8){
			str.Copy(s.GetString());
			int b = len2;
			for (int i = 1; i <= (len1-b); i++){
				len2 = len2 + 1;
				char* temp = new char[len2];
				strcpy_s(temp, len2, "0");
				strcat_s(temp, len2,str.GetString());
				
				str.Copy(temp);
			}
			s.Copy(str.GetString());

		}
	}
	if (len2 > len1){
		if (len2-1 == 8){
			str.Copy(GetString());
			int b = len1;
			for (int i = 1; i <= (len2 - b); i++){
				len1 = len1 + 1;
				char* temp = new char[len1];
				strcpy_s(temp, len1, "0");
				strcat_s(temp, len1,str.GetString() );

				str.Copy(temp);
			}

			Copy(str.GetString());
		}
	}
	bool flag = 0;
	char* tmp = new char[Max(len1,len2)];
	if (len1 > len2){
		strcpy_s(tmp,len1,GetString());
	
	}
else
{
	strcpy_s(tmp, len2, s.GetString());
}


	char* s1 = new char[GetLength()];
	strcpy_s(s1,len1,GetString());
	char* s2 = new char[s.GetLength()];
	strcpy_s(s2,len2,s.GetString());
	int j = 0;
	int i = 0;
	int max = 0;
	max = Max(len1, len2) - 2;

	for ( i = len1-2,  j = len2-2; (i >= 0)&&(j>=0); i--,j--){
	
		if (s1[i] == '0'){
			if (s2[j] == '0'){
				if (flag == 1){ tmp[Max(i, j)] = '1'; flag = 0; }
				else { tmp[Max(i, j)] = '0'; }
				
			}
			else {
				if (flag == 0){
					tmp[ Max(i, j)]  = '1';
				}
				else{  tmp[ Max(i, j)] = '0'; flag = 1; }
			}
		}
		else{
			if (s2[j] == '0'){
				if (flag == 0) {
					tmp[ Max(i, j)] = '1';
					
				}
				else { tmp[ Max(i, j)] = '0'; flag = 1; }
			}
			else{
				if (flag == 0) {
					tmp[Max(i, j)] = '0'; flag = 1;
				}
				else { tmp[Max(i, j)] = '1'; flag = 1; }
			}
		}
		max = Max(i, j);
	}
	if (flag == 1){
		max = max - 1;
		if (tmp[max] == '0'){
			tmp[max] = '1';
			flag = 0;
		}
		else {
			
			while (max>=0){
				if (tmp[max] == '0'){
					tmp[max] = '1';
					flag = 0;
					break;
				}
				else {
					tmp[max] = '0';
				}
				max = max - 1;
			}
			
		}
	}
	if (flag == 1){ cout << "Переполнение битовой строки"; }
	



	ByteString b(tmp);
	delete tmp;
	delete s1;
	delete s2;

	return new ByteString(b);
}

bool ByteString::operator== (ByteString& s){
	if (GetString() == s.GetString()){
		return 1;
	}
	return 0;
}




ByteString::~ByteString()
{

}
