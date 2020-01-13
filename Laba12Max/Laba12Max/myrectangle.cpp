#include "myrectangle.h"



void myRectangle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        this->~myRectangle();
    }
    else {
        this->setZValue(Counter::getCount());
    }
}

myRectangle::~myRectangle()
{

}

