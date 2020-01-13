#include "mytriangle.h"

void MyTriangle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        this->~MyTriangle();
    }
    else {
        this->setZValue(Counter::getCount());
    }
}

MyTriangle::~MyTriangle()
{
	Counter::CountAll--;
	Counter::CountTriangle--;

}

