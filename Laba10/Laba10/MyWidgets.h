#pragma once
#include <QWidget>

class MyWidgets
{
private:
	QVector<QWidget*> coll;
	unsigned Count;
public:
	MyWidgets(int n){
		coll = QVector<QWidget*>(n);
		Count = n;
	}
	MyWidgets(){
		coll = QVector<QWidget*>();
		Count = 0;
	}
	void push(QWidget* ob) {
		coll.push_back(ob);
		Count += 1;
	}
	~MyWidgets(){}
	QWidget* pop(){
		return coll.at(Count);
		Count--;
	}
	unsigned Size() { return Count+1; }

	QWidget* operator [] (unsigned index) {
		
		return coll.at(index);

	}


};

