// Lab2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;

struct PRICE
{
	char *NameOfItem;		// Имя товара
	char *NameOfShop; // имя магазина
 int Price; // цена товара


};

typedef unsigned int uint;


void Sort( PRICE *p, uint size)
{
	bool Sorted = false;
	PRICE *p1, *p2, *stop;

	for (stop = p + size - 1; !Sorted; stop--)
	for (Sorted = true, p1 = p, p2 = p + 1; p2 <= stop; p1 = p2++)
	if (!(strcmp(p1->NameOfItem, p2->NameOfItem) <= 0))
	{
		Sorted = false;
		PRICE temp = *p1;
		*p1 = *p2;
		*p2 = temp;

	}
}





void main()
{
	puts("\n\t\t Array of Item objects\n");

	PRICE ar[3];





	uint size = sizeof(ar) / sizeof(ar[0]);


	for (uint i = 0; i<size; i++)
	{
		cout << "\n Item #"<< i<<"\t";
		ar[i].NameOfItem = new char;
		cin >> ar[i].NameOfItem;
		cout << "\n Shop #" << i<< "\t";
		ar[i].NameOfShop = new char;
		cin >> ar[i].NameOfShop;
		cout << "\n Price #" << i << "\t";
		
		cin >> ar[i].Price;
	


	}
	Sort(ar, size);
	for (uint i = 0; i<size; i++)
		printf("\n%s,\t\t%d,\t\t%s", ar[i].NameOfItem, ar[i].Price,ar[i].NameOfShop);



	puts("\n\t\t get name of item");
	char *in;
	in = new char;
	cin >> in;
	cout << "Item " << in << " is from:";
	int k = 0;
	for (int i = 0; i < size; i++){
		if (strcmp(ar[i].NameOfItem, in) == 0){
			cout << ar[i].NameOfShop << " and costs "<< ar[i].Price;
			k++;
		}
	};
	if (k == 0){
		cout << "invalid Item";
	}





	int x;
	cin >> x;

}



