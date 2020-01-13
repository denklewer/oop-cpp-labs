#pragma once
#include "stdafx.h"
#include "Vector.h"

//int Vector::Count = 0;
Vector::Vector (double c1, double c2)
{
	x=c1;   y=c2;
	//Count += 1;
	
}

Vector::Vector ()
{
	x = y = 0.;
//Count += 1;

}
//Vector::~Vector(){ Count = Count - 1; }
void Vector::Out()
{
	cout << "\nVector:  x = " << x << ",  y = " << y;
}

//void Vector::PrintCount(){ cout << "\n Now there are " << Count << " vectors";  }
double Vector::GetX()
{
	return x;
}
double Vector::GetY()
{
	return y;
}

//====== ��������������� �������� =====//
Vector& Vector::operator= (const Vector &v)	// ����������
{
	if (this == &v) // �������� ����, �� ���������  ������ ��������  � ��, ������� �������� ��������� �� ���� � ��� �� ������
		return *this;
	x = v.x;
	y = v.y;
	return *this;
}
Vector Vector::operator+ (const Vector& v)	// ��������
{
	
	Vector temp;
		temp.x = x + v.x;
		temp.y = y + v.y;
	return temp;
}
double Vector::operator! ()	// ������ ������
{
	return sqrt(x*x + y*y);
}
/*bool Vector::operator== (Vector & v)   // ��������� �� ������
{
	double temp1 = !v;
	double temp2 = !(*this);
	if (fabs(temp1 - temp2) < DBL_EPSILON) { return true; }

	return false;
} */
bool Vector::operator> (Vector & v)	// ���������
{
	if (!(*this) > !v) { return true; }

	return false;
}
bool Vector::operator< (Vector & v)	// ���������
{
	if (x<v.x) { return true; }
	else if (fabs(x - v.x) < DBL_EPSILON) {
		if (y < v.y) { return true; }
		else { return false; }
	}

	return false;
}



bool Vector::operator== (Vector & v)	// ��������� ��������������
{
	if ((fabs(x - v.x) < DBL_EPSILON)) { if((fabs(y - v.y) < DBL_EPSILON)) { return true; } }

	return false;
}

bool Vector::operator== (Vector  v)	// ��������� ��������������
{
	if ((fabs(x - v.x) < DBL_EPSILON)) { if ((fabs(y - v.y) < DBL_EPSILON)) { return true; } }

	return false;
}

Vector operator * (double d, Vector v) {
	Vector temp;
	temp.x = d*v.x;
	temp.y = d*v.y;
	return temp;
}
Vector Vector::operator* (const double d)	// ��������� �� ������
{
	Vector temp;
	temp.x = x*d;
	temp.y = y*d;

	return temp ;
}
double Vector::operator* (const Vector& v)	// ��������� ������������
{

	
	
	return (x * v.x + y * v.y);
	

}
void Vector::Move(Vector& v){
	x = x + v.x;
	y = y + v.y;
}
double Vector::Area(){
	return 0;
}
Vector::~Vector(){
	
}