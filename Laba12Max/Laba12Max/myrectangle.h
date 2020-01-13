#ifndef RECTANGLE_H
#define RECTANGLE_H

#pragma once
#include "qgraphicsitem.h"
#include <QGraphicsSceneMouseEvent>
#include "counter.h"
class myRectangle :
        public QGraphicsRectItem
{
public:
    myRectangle(qreal x, qreal y, qreal w, qreal h,int newid, QGraphicsItem *parent = 0) : QGraphicsRectItem(x, y, w, h, parent){
			id = newid;
			
        }
		int getId(){
			return id;
		}

		
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

    ~myRectangle();
private:
	int id;
	
};

#endif // RECTANGLE_H
