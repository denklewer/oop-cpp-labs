#ifndef CIRCLE_H
#define CIRCLE_H
#pragma once
#include "qgraphicsitem.h"
#include <QGraphicsSceneMouseEvent>
#include "counter.h"
class Circle:
        public QGraphicsEllipseItem
{
public:
    Circle(qreal x, qreal y, qreal w, qreal h,int newid, QGraphicsItem *parent = 0): QGraphicsEllipseItem(x, y, w, h, parent){
			
			id = newid;
		
	
		}
    ~Circle();
		int getId(){
			return id;
		}
		
	
protected:
        virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
	int id;
	
};

#endif // CIRCLE_H
