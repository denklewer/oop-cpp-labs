#ifndef TRIANGLE_H
#define TRIANGLE_H

#pragma once
#include "qgraphicsitem.h"
#include <QGraphicsSceneMouseEvent>
#include "counter.h"
class Triangle:
        public QGraphicsPolygonItem
{
public:

    Triangle(QPolygonF polik, QGraphicsItem *parent = 0) : QGraphicsPolygonItem(polik){

                }
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    ~Triangle();
};

#endif // TRIANGLE_H
