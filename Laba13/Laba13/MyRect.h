#pragma once
#include "qgraphicsitem.h"
#include <QGraphicsSceneMouseEvent>
#include "counter.h"
class MyRect :
	public QGraphicsRectItem
{
public:
	MyRect(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = 0) : QGraphicsRectItem(x, y, w, h, parent){
		
	}
protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
	~MyRect();
};

