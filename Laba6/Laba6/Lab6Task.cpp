//=======================================================================
//	������� �6. ������� �������. ������� �������. ����������� ������� �++.
//				��������� ����������.
//=======================================================================
#pragma once
#include "stdafx.h"
#include "Vector.h"
#include "MyString.h"
#include "Stack.h"
#include <vector>
#include <list>
#include <algorithm>
//#include "MyMan.h"

//============= ������ ������� ��� ������ � ������� ���������
template <class T> void pr(T& v, string s)
{
	cout<<"\n\n\t"<<s.c_str()<<"  # Sequence:\n";
	
	// �������� ������ ����������
	T::iterator p;
	int i;

	for (p = v.begin(), i=0;  p != v.end();  p++, i++)
		cout << endl << i+1 <<". "<< *p;
	cout << '\n';
}

template <class T>
void Swap(T& x, T& y)
{
	T* temp=new T();
	*temp = x;
	x = y;
	y = *temp;

}

void print(Vector &v){
	v.Out();
}
bool pred(Vector &v){
	if ((v.GetX() > 2)&&(v.GetY() > 2)){ return true; }
	return false;
}
bool pred2(Vector* v){
	if ((v->GetX() > 2) && (v->GetY() > 2)){ return true; }
	return false;
}
bool FirstM(string s){
	if (s[0]=='M'){ return true; }
	return false;
}

//----------------------------
string Fstr = "";

	bool FindStr(string s)
	{
		if (Fstr == s){ return true; }
		return false;
	}









void main()
{

	//===========================================================
	// ������� �������
	//===========================================================
	// �������� ������ ������� ������������ ���� ���������� - Swap().
	// ��������� ����������������� ���������� ������� � �������
	// ������������ ���� ���������.





	{
		int i = 1, j = -1;
		Swap(i, j);

		double a = 0.5, b = -5.5;
		Swap(a, b);

		Vector u(1, 2), w(-3, -4);
		Swap(u, w);

		// ���� �� ���������� ������� ����� MyString � ���������� ������,
		// �� ��������� �������� ���� ������ �������� ���������.
		
		MyString s1 ("Your fault"), s2 ("My forgiveness");
		Swap (s1, s2);
	}
	//===========================================================
	// ������� �������
	//===========================================================
	// �������� ������ ������ MyStack ��� �������� ��������� ������ ���� T.
	// � �������� ������ ��� ����� ����� ���� ������ ������.
	// ��� ������� ������������� ������� ����� ����� ���� �����������
	// ��������-��������� �������
	// ������������� ���������� �� ������ �������� "Push" � "Pop","GetSize" � "Capacity"
	// �������������� - ����� ���� ����� �� ������� (operator[]).
	// ��� ����, ����� ������������� ���������� ���������� ���� �������� 
	// ������� ������������ �������������� ��������.
	

	Stack <int> st1(5);
	Stack <double> st2(5);
	Stack <Vector> st3(5);
	
	// � ������� ������� MyStack �������� ���� ���������� ���� int, �����
	// ���� ���������� ���� double �, �������, ���� �� ���������� ���� Vector 
	// ���� �� ����������� ��� ������ ��� ��������� ����������,
	// �� ��������� �������� ������ ��������
	try
	{
		cout << "\tTest MyStack\n";
		Stack <int> stack(3);

		cout << "\nInteger Stack capacity: " << stack.Capacity();

		stack.Push(1);
		stack.Push(2);
		stack.Push(3);
		
		cout << "\nInteger Stack has: " << stack.GetSize() << " elements";

//	stack.Push(4);	// ����� ������ ���� "���������" ����������

		cout << "\nInteger Stack pops: " << stack.Pop();
		cout << "\nInteger Stack pops: " << stack.Pop();
		
		cout << "\nInteger Stack has: " << stack.GetSize() << " elements";
		stack.Pop();
	//	stack.Pop();		// ����� ������ ���� "���������" ����������
		stack.Push(2);
		
	//	int i = stack[3];	// ����� ������ ���� "���������" ����������
		
		Stack<Vector> ptStack(5);
		
		cout << "\nVector Stack capacity: " << ptStack.Capacity();
		
		ptStack.Push(Vector(1,1));
		ptStack.Push(Vector(2,2));
		
		cout << "\nVector Stack pops: ";
		// ����������� ����� ������ Vector ��� ������ ��������
		ptStack.Pop().Out();
		
		cout << "\nVector Stack has: " << ptStack.GetSize() << " elements";
	}
	catch (StackOverflow)
	{
		cout << "\nStack overflow";
	}
	catch (StackUnderflow)
	{
		cout << "\nStack underflow";
	}
	catch (StackOutOfRange o)
	{
		o.Out();
	}

	stop;

	//=======================================================================
	// ���������� ����������� ����������. ������������������ ���� vector
	//=======================================================================
	
	// �������� ������ ������ ����� �����. ������� ��� ������ � ������� ������ size(),
	// � ������� ������ push_back() ��������� ������ ������-���� ����������.
	// �������� ����� ������ ������� � �������� �������� ��� ���������.
	// � �������� ������ � �������� �� ������ ����� ���������� ������� �����������
	// ��������� (size()) ������ ����������� ��������� ���������� ��������� (max_size()),
	// � ����� ����������������� ������ (capacity()).
	unsigned i=0;
	vector<int> v;
	int n = v.size(); //0
	v.push_back(-1);  
	v.push_back(-2);
	n = v.size();  // 2
	n = v.capacity();// 2
	n = v.max_size(); // 1073741823
		
	// ��� ��� �� ����� ����� �������� ������������������, �� �������������
	// ������� ������ ������� ��� ������ ������ ����������.
	// ��������������� ���� ������ �������� (pr), ������� �������� ����
	// ����������� ��� ��� ������ ������ �������

	pr (v, "Vector of ints");
	
	// ���������� ������ ����������� ��� �������� ������� ������������
	// � ��������� �������� � 2 �������� � ����������� (222.).
	// �������� ��������� �������. ����� ������� ������ ������� � ��� ����������
	// (����� - resize()) � ����� �������� ���������.
	
	vector<double> vd(2);
	vd.push_back(222.); 
	vd.push_back(1.3);
	pr (vd, "Vector of doubles");
	n = vd.size(); //4
	n = vd.capacity(); //4
	n = vd.max_size(); // 536870911
	vd.resize( 4);
	vd.push_back(22.);
	vd.push_back(1.0);
	pr (vd, "After resize");
	n = vd.size(); //6
	n = vd.capacity();//6
	n = vd.max_size(); // 536870911
	stop;
	// ��������� ����� at(), � ����� �������� ������ [], �������� ��������
	// ��������� ��������� ������� � ��������� ���������.
	vd.at(0) = 2.5;
	vd[1] = 3.9;


	pr (vd, "After at");
	stop;
	// �������� ������ ������������, ������� �������� ������ �������������.
	vector < double>wd = vd;
	stop;

	pr (wd, "Copy");
	
	// �������� ������, ������� �������� ����� ������������ ������������������
	vector<double> ud;
	ud.assign(&wd[0], &wd[2]);
	pr (ud, "Copy part");

	stop;
	// �������� ������ ������������, ������� �������� ������ ����� �������� �������.
	double ar[] = { 0., 1., 2., 3., 4., 5. };


	vector<double> va(ar+1, ar + 5);
pr (va, "Copy part of array");
stop;
	// �������� ������ ��������, ������� �������� ������ ����� ������� ������
	char s[] = "Array is a succession of chars";
	  
	vector<char> vc(s, s + 10);
	pr (vc, "Copy part of c-style string");

	// �������� ������ ��������� ���� Vector � ���������������
	// ��� �������� � ������������ (1,1).
	vector<Vector> vv;
	vv.push_back(Vector(1, 1));
		
	
	cout << "\n\nvector of Vectors\n";
	for (i = 0; i < vv.size(); i++)
	{
		vv[i].Out();
	}
	stop;
	// �������� ������ ���������� �� Vector � ��������������� ��� ��������
	// �������� ������ Vector
	
	vector<Vector*> vp;

	cout << "\n\nvector of pointers to Vector\n";
	vp.push_back(new Vector(1, 2));
	vp.push_back(new Vector(3, 4));
	for ( i = 0; i < vp.size(); i++)
	{vp[i]->Out(); }
	stop;
	// ��������� ������������ ������� assign � ���������
	// ������������ = ��� ����������� ���� vector.
	vp.assign(10, new Vector(1, 2));

	cout << "\n\nAfter assign\n";
	for ( i=0;  i < vp.size();  i++)
		vp[i]->Out();
	stop;
	// ������������ ����� ������ ���������� �� Vector � ��������������� ��� 
	// � ������� ������ ������ assign
	vector<Vector*> vpNew;
	vpNew.assign(&vp[0], &vp[4]);
	
	cout << "\n\nNew vector after assign\n";
for (i=0;  i < vpNew.size();  i++)
		vpNew[i]->Out();

stop;
	// �� ���� ������� vector �������� ���������� ������ �
	// ��������� ��� ���������� ������� ���������.
	// ������ ������� - ������������� �������
	// ������ ������� - ����������� �������

	
	//========= ����������� �������
	vector <vector<double>> vdd(6);
	unsigned j=0;
		for ( i=0;  i < vdd.size();  i++)
		vdd[i] = vector<double>(i+1, double(i));
	
cout << "\n\n\tTest vector of vector<double>\n";
	for ( i=0;  i < vdd.size();  i++)
	{
		cout << endl;
		for (j=0;  j < vdd[i].size();  j++)
			cout << vdd[i][j] << "  ";
	}	
  
	stop;

	//===================================
	// ���������� �������� � ������������
	//===================================
	//3�. ��������� �������� ������� � ���������� ��������� ������������������.
	//��������� ������� ������������������. ������������ ��������
	//��������� ����� ������������������ ��������� ������ - assign().


	//�������� � ������������������ ������ �� ��������� char. ������ -
	//�� �������.
	vector<char> vch(4);
	for ( i = 0; i < vch.size(); i++){
		vch[i] = i+48;
}

	//�������� � ������������������ ������ �� ��������� char. ������ -
	//�� �������.
	char cMas[] = "1234567";



	//�������� �������� ������� �������� ������� ( front() )
	cout << "\n first element is : "<< vch.front();

	//�������� �������� ���������� �������� ������� ( back() )
	cout << "\n last element is : " << vch.back();

	//�������� ������ �������
	cout << "\n size of vector is : " << vch.size();

	//��������� ������� ����� �������� �� �������� ������� cMas.
	vch = vector<char>(cMas, cMas+5);

	//��������� ������ �������, ������ � ��������� ��������.
	cout << "\n now first element is : " << vch.front();
	cout << "\n now last element is : " << vch.back();
	cout << "\n  now size of vector is : " << vch.size();
	stop;


	//3�. ������ � ������������ ��������� ������� � ��������� - at()
	//� ��� �������� - []
	//�������� �������������������� ������ �� 8 ��������� char - vChar2.
	vector<char> vChar2(8);
	for ( i = 0; i < vChar2.size(); i = i + 2){
		vChar2.at(i) = vch[i / 2];
	}
	char str2[] = "KUKU";
	for ( i = 1; i < vChar2.size(); i = i + 2){
		vChar2[i] = str2[i/2];
	}

	//� ������� at() ��������� ������ ��������� ������� ��������
	//��������� vChar1 �� ����������� �������,
	//� � ������� [] ��������� �������� ��������� ������� vChar2 ��������
	//������� {'K','U','K','U'}.

	
	  stop;
	//	vChar2.at(9) = 0;  ����������
//		vChar2[9] = 0;  ���� ���������

	//���������� "�����" �� ������� ������� � ������� at() �
	//� ������� []. �������� ��������: ��� ���������� ���
	//������� ��������� � ��������������� �������� � ����� �������

  
	stop;

	//3�.�������� � ����� ������� vChar2  - ����� Z (push_back()). ���
	vChar2.push_back('Z');


	//���������� ��������� ������ �� ����� �� � �������� (pop_back())
	vChar2.pop_back();
  
	stop;

	//3�. �������-�������� �������� ������������������ insert() - erase()
	//������� ������������������ - clear()



	//�������� ����� ������ ��������� ������� vChar2 ����� 'W'
	for (i = 0; i <  vChar2.size(); i = i + 2){
		vChar2.insert(vChar2.begin()+i, 'W');
	}
	stop;
	//�������� ����� 5-�� ��������� ������� vChar2 3 ����� 'X'
	vChar2.insert(vChar2.begin() + 4, 3, 'X');
	stop;
	//�������� ����� 2-�� ��������� ������� vChar2 � �������� ��
	//������ �������� ������� "aaabbbccc"
	char str[] = "aaabbbccc";
		vChar2.insert(vChar2.begin() + 1, str + 3, str + 6);
		stop;
	//������� c ������� �� ������� �������� vChar2
		vChar2.erase(vChar2.begin(), vChar2.begin() + 9);
  
	stop;

	//���������� ��� �������� ������������������ - clear()
	vChar2.clear();

	stop;

	//�������� ����������� �������

	stop;

///////////////////////////////////////////////////////////////////

	//������� 4. ������. ��������, ����������� ��� �������.
	//�������� ��� ������ ������ �� ��������� Vector - ptList1 �
	//ptList2
	list<Vector> ptList1;
	list<Vector> ptList2;
		

	//��������� ��� ������ ���������� � ������� ������� push_back(),
	//push_front, insrert()
	ptList1.push_back(Vector(1,1));
	ptList1.push_front(Vector(2, 1));
	ptList2.insert(ptList2.begin(), ptList1.begin(),ptList1.end());
	ptList1.insert(++ptList1.begin(), ptList2.begin(), ptList2.end());
	stop;
	//������������ ������ - sort().
	ptList1.sort();
	ptList2.sort();
	//���������: ��� ����, ����� �������� ����������, � ������ Vector
	//������ ���� ������������� �������� "<"

  
	stop;

	//���������� ��������������� ������ - merge(). ����������: ���
	//��� ���� ���������� �� ������ �������.
	ptList1.merge(ptList2);   // ����������

	stop;

	//���������� �������� �� ������ - remove()
	//��������� �� ������ ������� � ������������ ���������.
	//���������: ��� ����� ���������� ����� ��������������
	//� ������ Vector �������� "=="
	ptList1.remove(Vector(2, 1));

	stop;

///////////////////////////////////////////////////////////////////

	//������� 5. ����������� ���������.���������� ������������ ����
	// <algorithm>
	//5�. �������� �� ����� �������� ptList1 �� �����������
	//������� � ������� ��������� for_each()
	
	 
	for_each(ptList1.begin(), ptList1.end(),print );


	stop;

	//5�.� ������� ��������� find() ������� �������� �� ������� Vector �
	//������������ ���������. � ������� ��������� find_if() �������
	//�������� �� �������, ��������������� ������������� �������, 
	//��������, ��� ���������� ����� ������ ���� ������ 2.
	//���������: �������� �������-��������, ������� ��������� �������
	//� ���������� boolean-�������� (�������� ����� ���� ��� ����������
	//��������, ��� � ������� ������)

	ptList1.push_back(Vector(2, 1));
	ptList1.push_back(Vector(3, 4));
	Vector b;
	b=*find(ptList1.begin(), ptList1.end(), Vector(2, 1));
	cout << "\nUsing function find()\n";
	b.Out();
	cout << "\nUsing function find_if()\n";
	b = *find_if(ptList1.begin(), ptList1.end(), pred);
	b.Out();
	  stop;

	//�������� ������ �� ���������� �� ������� Vector. � ������� 
	//��������� find_if() � ��������� (����� ������������ �������� - 
	//����� ������ Vector, ������������ � ���������� �������) ������� �
	//������������������ �������, ��������������� �������

		list<Vector*> ptList3;
		ptList3.push_back(new Vector(1, 1));
		ptList3.push_back(new Vector(1, 2));
		ptList3.push_back(new Vector(1, 3));
		ptList3.push_back(new Vector(2, 1));
		ptList3.push_back(new Vector(5, 7));
		ptList3.push_back(new Vector(1, 4));
		cout << "\n 2.Using function find_if()\n";
		Vector* res;
		res = *find_if(ptList3.begin(), ptList3.end(), pred2);
		res->Out();
	  stop;

	//5�. �������� ������ ��������� Vector. ��������� ������
	//����������. � ������� ��������� replace() �������� �������
	//� ������������ ��������� ����� ���������. � ������� ���������
	//replace_if() �������� �������, ��������������� ������-����
	//������� �� ������������ ��������. ���������: �������
	//�������� ����������.

		list<Vector> ptList4;
		ptList4.push_back( Vector(1, 1));
		ptList4.push_back( Vector(1, 2));
		ptList4.push_back( Vector(1, 3));
		ptList4.push_back( Vector(2, 1));
		ptList4.push_back( Vector(5, 7));
		ptList4.push_back( Vector(1, 4));

		replace(ptList4.begin(), ptList4.end(), Vector(2, 1), Vector(3, 3));
  //������������ �������� ��������� ������
		replace_if(ptList4.begin(), ptList4.end(), pred, Vector(2, 2));
  
	stop;


	//5�. �������� ������ ����� (string). � ������� ��������� count()
	//���������� ���������� ���������� �����. � ������� ���������
	//count_if() ���������� ���������� �����, ������������ � ��������
	//�����
	vector<string> vs;
	vs.push_back("Mama");
	vs.push_back("Papa");
	vs.push_back("Mama");
	vs.push_back("Brother");
	vs.push_back("Brother");
	vs.push_back("Sister");
	vs.push_back("Mama");
	int rez = 0;
	rez= count(vs.begin(), vs.end(), "Mama");
	rez=count_if(vs.begin(), vs.end(), FirstM);
	//5�. � ������� ��������� count_if() ���������� ���������� �����,
	//������� ��������� � �������� �������. ���������: ������ ����
	//�������-�������
	Fstr = "Brother";
	rez = count_if(vs.begin(), vs.end(),FindStr);

	stop;

	cout <<"\n\n";
}