// ������������� ������, ����� ������ ���
//
#pragma once
#include "stdafx.h"
#include "ByteString.h"
void print(String* a[],int n){
	for (int i = 0; i < n; i++)
	{
		cout << "a(" << i << ") =" << a[i]->GetString() << "\n";
	}
}

void main(){

	setlocale(LC_ALL, "Russian");
	
	String *ar [5];

	for (int i = 0; i < 5; i++){
		cout << "\n������� �������� �������� a(" << i << ") =";
		char* elem = new char[];
		cin >> elem;
		ar[i] =new ByteString(elem);
	}




	char in = 0;

	for (int i = 0; in != '5'; i++){
		print(ar, 5);
		cout << "\n �������� ���� �� �������: \n 1.������� ����� ������  \n 2 ��������� �������������� �������� � ���������� \n 3.�������� �������� ������-�� ��������\n 4.��������� �� ��������� 2 ��������\n 5. ����� \n";
		cin >> in;
		switch (in)
		{
		case '1':{
							 delete ar[5];
							 String*ar = new String[5];
							 for (i = 0; i < 5; i++){
								 cout << "\n������� �������� �������� a(" << i << ") =";
								 char* elem = new char[];
								 cin >> elem;
								 ar[i] = elem;

							 }} continue;
		case '2': {
								cout << "\n �������� ���� ������� � ������� ������ �������� \n";
								char in2 = 0;
								cin >> in2;
								cout << "\n �������� �������������� ��������: \n 1.��������� � ��������  \n 2. �������� �������������� ���(������� �������������) \n 3. ������� \n";
								char in3 = 0;
								cin >> in3;
								switch (in3)
								{
								case '1': {cout << "\n ������� �����, ������� ������ ���������\n";
									char* tmp = new char[];
									cin >> tmp;
									ByteString btmp(tmp);
									in2 = in2 - 48;
									ar[in2] = *ar[in2] + btmp;
									continue; }
								case '2': {ar[in2 - 48]->MakeNegative(); continue; }
								case '3': {cout << "\n ������� �����, ������� ������ �������\n";
									char* tmp = new char[];
									cin >> tmp;
									ByteString btmp(tmp);
									in2 = in2 - 48;
									btmp.MakeNegative();
									ar[in2] = *ar[in2] + btmp; continue; }
								}
		} continue;
		case '3':{	cout << "\n �������� ���� ������� � ������� ������ ��������";
			char in2 = 0;
			cin >> in2;
			cout << "\n ������� ����� �����";
			char* elem = new char[];
			cin >> elem;
			ar[in2] = new ByteString(elem);
		} continue;
		case '4': {cout << "\n ������� ����� ������� ��������\n";
			cin >> in;
			cout << "\n ������� ����� ������� ��������\n";
			char in2 = 0;
			cin >> in2;
			if (*ar[in - 48] == *ar[in2 - 48]) {
				cout << "�������� ����� \n";

			}
			else { cout << "�������� �� ����� \n"; }
		} continue;

		case '5': {break;
		}
		default: cout << "����� �� ������ ������\n";
			break;
		}
		break;
	}








	stop;
}