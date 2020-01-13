#ifndef MYTRIANGLE_H
#define MYTRIANGLE_H


#pragma once
#include "qgraphicsitem.h"
#include <QGraphicsSceneMouseEvent>
#include "counter.h"
class MyTriangle :
    public QGraphicsPolygonItem
{
public:
    MyTriangle(QPolygonF polik,int newid, QGraphicsItem *parent = 0) : QGraphicsPolygonItem(polik,parent){
			id = newid;
			
            }
		int getId(){
			return id;

		}



protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    ~MyTriangle();
private :
	int id;

};



#endif // MYTRIANGLE_H
