#pragma once
class Vector;
class Circle;
class Shape
{
private:
	static  int Count;


public:
	static Shape* shapes[1000];
	Shape();
	~Shape();
 static void PrintCount();
	virtual void Move (Vector& v)=0;
	virtual void Out()=0;
	 virtual double Area()=0; 
	 void NewObject(Shape* adress);
	 void DelObject(Shape* adress);
	 static int GetCount();
	 void decr(int n);
};

