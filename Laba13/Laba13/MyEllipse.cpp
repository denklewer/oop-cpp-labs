#include "MyEllipse.h"



void MyEllipse::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (event->button() == Qt::RightButton)
	{
		this->~MyEllipse();
	}
	else {
		this->setZValue(Counter::getCount());
	}
}


MyEllipse::~MyEllipse()
{
}
