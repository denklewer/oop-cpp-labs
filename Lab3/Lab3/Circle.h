#pragma once
#include "Shape.h"
#include "Vector.h"
class Circle :
	public Shape
{
private:
	Vector ptCntr; 
	double R;
public:
	Circle();
	Circle(double p1,double p2, double d);
	Circle(Vector a, double d);
	Circle(const Circle &circ) { *this = circ; };
	~Circle();
	virtual void Move(Vector& v);
	virtual void Out();
	 virtual	double Area();
	 Circle& operator= (const Circle & c);

};

