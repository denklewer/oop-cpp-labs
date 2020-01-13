#include "circle.h"

void Circle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        this->~Circle();
    }
    else {
        this->setZValue(Counter::getCount());
    }
}

Circle::~Circle()
{

}

