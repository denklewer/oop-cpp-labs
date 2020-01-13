#pragma once
#include "stdafx.h"
#include "Shape.h"


int Shape::Count=0;
Shape* Shape::shapes[1000];
Shape::Shape()
{
	NewObject(this);
}


Shape::~Shape()
{
	DelObject(this);
}
void Shape::NewObject(Shape* adress){
	if (Count < 999){
		shapes[Count] = adress;
		Count = Count + 1;
	}
}
void Shape::DelObject(Shape* adress){
	for (int i = 0; i < Count; i++)
	{
		if (adress == shapes[i]){
			for (int j = i; j < (Count-1); j++)
			{
				shapes[j] = shapes[j + 1];
			}
			break;
		}
		
	}
	Count--;
}


void Shape::PrintCount(){
	cout << "\n Now there are " << Count << " objects";
}
int Shape::GetCount(){ return Count; }
void Shape::decr(int n){ Count = Count - n;
}