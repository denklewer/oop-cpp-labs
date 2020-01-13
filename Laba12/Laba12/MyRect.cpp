#include "MyRect.h"


void MyRect::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (event->button() == Qt::RightButton)
	{
		this->~MyRect();
	}
	else {
		this->setZValue(Counter::getCount());
	}
}



MyRect::~MyRect()
{
}
