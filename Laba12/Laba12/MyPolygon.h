#pragma once
#include "qgraphicsitem.h"
#include <QGraphicsSceneMouseEvent>
#include "counter.h"
class MyPolygon :
	public QGraphicsPolygonItem
{
public:
	MyPolygon(QPolygonF polik, QGraphicsItem *parent = 0) : QGraphicsPolygonItem(polik){

			}



protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
	~MyPolygon();
};

