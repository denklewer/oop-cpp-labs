#pragma once
#include "Vector.h"
#include "Shape.h"
class Rect :
	public Shape
{
private:
	Vector ptLT, ptRB;
public:
	
	Rect(double left, double top,double right,double bottom);
	Rect();							// Default
	~Rect();
	Rect(Vector a, Vector b);
	Rect(const Rect &rect) { *this = rect; };
Rect Inflate(double d = 1);
Rect Inflate(double hight, double width);
Rect Inflate(double a, double b, double c, double d);
virtual void Out();

virtual void Move (Vector& v);

virtual double Area(); 
Rect& operator= (const Rect & r);


};

