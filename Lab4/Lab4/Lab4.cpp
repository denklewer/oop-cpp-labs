// Lab4.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#pragma once
#include "stdafx.h"
#include <windows.h>

#include "Tree.h"
#include "Word.h"
#include <fstream>
#include <cstdlib>
#include <string>
void main()
{
	
	bool flag;
	setlocale(LC_ALL, "Russian");

	
	Tree* tree = new Tree();
	TreeItem::SetRule(false);
	Word x (4, "Four", "Chetire");
///*	tree->Insert(x);*/
	tree->Insert(new Word(2, "Two", "Dwa"));
	tree->Insert(new Word(6, "Six", "Shesti"));
	tree->Insert(new Word(1, "One", "Odin"));
	tree->Insert(new Word(3, "Three", "Tri"));
	//tree->Insert(new TreeItem(4, "Four"));
	//tree->Insert(new TreeItem(2, "Two"));
	//tree->Insert(new TreeItem(6, "Six"));
	//tree->Insert(new TreeItem(1, "One"));
	//tree->Insert(new TreeItem(3, "Three"));



	long a;
	String s;



	









char in=0;

	for (int i = 0; in != 'q'; i++){
		tree->Print();
		cout << "\n �������� ���� �� �������: \n 1.������� ����� �������  \n 2.�������� ������� � ������� \n 3.������� ������� �� ������� �� �����(���� �� �����) \n 4.������� ������� �� ������� �� ����������� �������� (���� �� ��������)\n 5. ����� ����� �� �����.(����  �� �����)\n 6. ����� ����� �� ����������� ��������(���� �� ��������)\n 7. �������� ������� �� �����(������� �����)\n 8. �����\n"; 
		cin >> in;
		switch (in)
		{
		case '1':{ Tree* tree1 = new Tree(); 
			tree = tree1;
			cout << "\n ����������� �� �����/��������? (1/0):";
			cin >> flag;
			TreeItem::SetRule(flag); } continue;
		case '2': {cout << "\n ������� ���� ��������: "; 
			int id;
			cin >> id;
			cout << "\n ������� ����� �� ����������: "; 
			char* eng=new char[];
			cin >> eng; 

			cout << "\n ������� ����� �� �������:";
			char* rus = new char[];
			SetConsoleCP(1251);
			cin >> rus;
			SetConsoleCP(866);
			tree->Insert(new Word(id, String(eng), String(rus)));
			 } continue;
		case '3':{	cout << "\n ������� ���� ��������:";
			int n;
			cin >> n;


			TreeItem* tmptree = tree->LookUp(n);
			if (tmptree != 0) {
			tree->Delete(tree->LookUp(n));
			}
			else { cout << "\n ������� �� ������!!\n"; }
		} continue;
		case '4': {cout << "\n ������� ���������� �������� �����:";
			char* tmp=new char[];
			cin >> tmp;

			TreeItem* tmptree = tree->LookUp(String(tmp));
			delete tmp;
			if (tmptree != 0) {
			tree->DeleteByName(tmptree); 
			}
			else { cout << "\n ������� �� ������!!\n"; }
			} continue;
		
		case '5': {cout << "\n ������� ���� ��������:"; 
			int n;
			cin >> n; 
			TreeItem* tmp = tree->LookUp(n);
			if (tmp != 0) {
				cout << "\n ��������� �������:\t" << tmp->ToString().GetString() << "\n";
			}
			else { cout << "\n ������� �� ������!!\n"; }
		}; continue;
		case '6':{cout << "\n ������� ���������� �������� �����:";
			char* tmpStr=new char[];
			cin >> tmpStr;
			TreeItem* tmp = tree->LookUp(String(tmpStr));
			delete tmpStr;
			if (tmp != 0) {
			cout << "\n ��������� �������:\t" << tmp->ToString().GetString() << "\n"; 
			}
			else { cout << "\n ������� �� ������!!\n"; }
		}; continue;
		case '7':{cout << "\n ������� ��� �����:";
			char* tmpStr=new char[];
			cin >> tmpStr;
			Tree* tree1 = new Tree();
			cout << "\n ����������� �� �����/��������? (1/0):";
			cin >> flag;
			TreeItem::SetRule(flag);
			ifstream infile(tmpStr);     // ������ ������ �����
			delete tmpStr;
			if (!infile.is_open()) {
				cout << "File not open!" << endl;

			}
			string id, english, russian;
			while (!getline(infile, id, ' ').eof()) {

				getline(infile, english, ' ');

				getline(infile, russian);
				int intId =atoi(id.c_str());
				char* newEnglish = (char*)english.c_str();
				char* newRussian = (char*)russian.c_str();
				tree1->Insert(new Word( intId, String(newEnglish), String(newRussian)));
			
			}                            // ����� ������ �����
			tree = tree1;
			}; continue;
		case '8': break;

		default: cout << "����� �� ������ ������\n";
			break;
		}

	}

	stop;
}
