#include "MyPolygon.h"



void MyPolygon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (event->button() == Qt::RightButton)
	{
		this->~MyPolygon();
	}
	else {
		this->setZValue(Counter::getCount());
	}
}


MyPolygon::~MyPolygon()
{
}
