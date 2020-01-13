#pragma once
#include "Shape.h"
class Vector :
	public Shape




{
private:
	double x, y;	// ���������� ������� �� ���������
//static  int Count;
   public:
		
		
	//========== ��� ������������
	Vector (double c1, double c2);
	Vector ();							// Default
	~Vector();
	Vector(const Vector &vect) { *this = vect; 	 };
	double GetX();
	double GetY();
	//====== ��������������� �������� =====//
	Vector& operator= (const Vector& v);	// ����������
	Vector operator+ (const Vector& v);
double operator! ();
bool  operator > ( Vector& v);
bool operator== ( Vector& v);  

virtual	void Out();

		Vector operator* (const double d);
		friend Vector operator*(double d, Vector v);
		double operator* (const Vector& v);
		//static void PrintCount();

		virtual void Move(Vector& v);
		
		virtual double Area();



};
