#include "triangle.h"


void Triangle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        this->~MyPolygon();
    }
    else {
        this->setZValue(Counter::getCount());
    }
}


Triangle::~Triangle()
{

}

