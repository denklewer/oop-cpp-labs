#pragma once
#include "stdafx.h"
#include "Rect.h"


Rect::Rect()
{
	ptLT =  Vector(0, 0);
	ptRB = Vector(0, 0);
	decr(2);
	
	
}
Rect::Rect(double left, double top, double right, double bottom) {
	ptLT = Vector(left, top);
	ptRB = Vector(right, bottom);
	decr(2);

}
Rect::Rect(Vector a,Vector b) {
	ptLT = a;
	ptRB = b;
	decr(2);

}

Rect Rect::Inflate(double d ) {
	Vector temp(d, -d);
	ptRB =ptRB+temp;
	ptLT = ptLT + ((-1)*temp);
	return *this;
}
Rect Rect::Inflate(double hight, double width ) {
	Vector temp(hight, -width);
	ptRB = ptRB + temp;
	ptLT = ptLT + ((-1)*temp);
	return *this;
}
Rect Rect::Inflate(double up, double down,double left,double right) {
	Vector temp1(up, -left);
	Vector temp2(-down, right);
	ptRB = ptRB + temp2;
	ptLT = ptLT + temp1;
	return *this;
}

Rect inflate(double hight, double width);
Rect inflate(double a, double b, double c, double d);

void Rect::Out()
{

	cout << "\n Rect(" << ptLT.GetX() << ", " << ptLT.GetY() << ", " << ptRB.GetX() << ", " << ptRB.GetY() << ")";
}

void Rect::Move(Vector& v){
	ptLT = ptLT + v;
	ptRB = ptRB + v;
}

double Rect::Area(){
	return fabs(ptRB.GetX() - ptLT.GetX()) * fabs(ptLT.GetY() - ptRB.GetY());
}

Rect & Rect ::operator =(const Rect &r){
	if (this == &r)
		return *this;
	ptLT = Vector(r.ptLT);
	ptRB = Vector(r.ptRB);
	return *this;
}
Rect::~Rect(){
	
	
}