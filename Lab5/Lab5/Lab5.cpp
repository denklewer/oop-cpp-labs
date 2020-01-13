// ПРОМЕЖУТОЧНАЯ ВЕРСИЯ, ПОЧТИ НИЧЕГО НЕТ
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
		cout << "\nВведите значение элемента a(" << i << ") =";
		char* elem = new char[];
		cin >> elem;
		ar[i] =new ByteString(elem);
	}




	char in = 0;

	for (int i = 0; in != '5'; i++){
		print(ar, 5);
		cout << "\n Выберите один из пунктов: \n 1.создать новый массив  \n 2 Выполнить арифметические действия с элементами \n 3.Поменять значение какого-то элемента\n 4.Проверить на равенство 2 элемента\n 5. Выход \n";
		cin >> in;
		switch (in)
		{
		case '1':{
							 delete ar[5];
							 String*ar = new String[5];
							 for (i = 0; i < 5; i++){
								 cout << "\nВведите значение элемента a(" << i << ") =";
								 char* elem = new char[];
								 cin >> elem;
								 ar[i] = elem;

							 }} continue;
		case '2': {
								cout << "\n Выберите один элемент с которым хотите работать \n";
								char in2 = 0;
								cin >> in2;
								cout << "\n Выберите математическую операцию: \n 1.Прибавить к элементу  \n 2. Получить дополнительный код(сделать отрицательным) \n 3. Вычесть \n";
								char in3 = 0;
								cin >> in3;
								switch (in3)
								{
								case '1': {cout << "\n Введите число, которое хотите прибавить\n";
									char* tmp = new char[];
									cin >> tmp;
									ByteString btmp(tmp);
									in2 = in2 - 48;
									ar[in2] = *ar[in2] + btmp;
									continue; }
								case '2': {ar[in2 - 48]->MakeNegative(); continue; }
								case '3': {cout << "\n Введите число, которое хотите вычесть\n";
									char* tmp = new char[];
									cin >> tmp;
									ByteString btmp(tmp);
									in2 = in2 - 48;
									btmp.MakeNegative();
									ar[in2] = *ar[in2] + btmp; continue; }
								}
		} continue;
		case '3':{	cout << "\n Выберите один элемент с которым хотите работать";
			char in2 = 0;
			cin >> in2;
			cout << "\n Введите новое число";
			char* elem = new char[];
			cin >> elem;
			ar[in2] = new ByteString(elem);
		} continue;
		case '4': {cout << "\n Введите номер первого элемента\n";
			cin >> in;
			cout << "\n Введите номер второго элемента\n";
			char in2 = 0;
			cin >> in2;
			if (*ar[in - 48] == *ar[in2 - 48]) {
				cout << "Элементы равны \n";

			}
			else { cout << "Элементы не равны \n"; }
		} continue;

		case '5': {break;
		}
		default: cout << "Введён не верный символ\n";
			break;
		}
		break;
	}








	stop;
}