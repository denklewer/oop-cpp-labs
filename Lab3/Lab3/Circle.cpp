#pragma once
#include "stdafx.h"
#include "Circle.h"


Circle::Circle()
{
	R = 0;
	ptCntr = Vector(0, 0);
	decr(1);
	

}

Circle::Circle(double p1, double p2, double d){
	ptCntr = Vector(p1, p2);
		R = d;
		decr(1);
	
}
Circle::Circle(Vector a, double d){
	ptCntr = a;
	R = d;
	
	
}


void Circle::Out()
{
	cout << "\nCircle: (" << ptCntr.GetX() << "," << ptCntr.GetY() << "," << R << ")";
}


Circle::~Circle()
{

	
}


void Circle::Move(Vector& v){
	ptCntr = ptCntr + v;
	
}
double Circle::Area(){
	return (3.14159*R*R);

}
Circle & Circle ::operator =(const Circle &c){
	if (this == &c)
		return *this;
	ptCntr = Vector(c.ptCntr);
	R = c.R;

	return *this;
}