#pragma once
#include "qgraphicsitem.h"
#include <QGraphicsSceneMouseEvent>
#include "counter.h"
class MyEllipse :
	public QGraphicsEllipseItem
{
public:
	MyEllipse(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = 0) : QGraphicsEllipseItem(x, y, w, h, parent){}


protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
	~MyEllipse();
};

