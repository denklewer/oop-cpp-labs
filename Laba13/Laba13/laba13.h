#ifndef LABA13_H
#define LABA13_H
#include <QtWidgets/QApplication>
#include <qobject.h>
#include <QMainWindow>
#include <QWidget>
#include <QtWidgets>
#include <qlist.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsSceneEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPushButton>
#include "MyRect.h"
#include "MyEllipse.h"
#include "MyPolygon.h"





class Laba13 : public  QDialog
{
	Q_OBJECT

public:
	Laba13(QWidget *parent = 0);
	~Laba13();
	private slots:
	void btAddRectClicked() {


		MyRect *squa = new MyRect(0, 0, 115, 115);

		squa->setFlag(QGraphicsItem::ItemIsMovable);
		squa->setBrush(QColor(0, 190, 0));

		Myscene->addItem(squa);

	}
	void btAddEllipseClicked() {
		MyEllipse* ell = new MyEllipse(0, 0, 115, 115);
		ell->setFlag(QGraphicsItem::ItemIsMovable);
		ell->setBrush(QColor(0, 0, 150));

		Myscene->addItem(ell);
	}
	void btAddPolygonClicked() {

		QPolygonF Triangle;
		Triangle.append(QPointF(-70., 0));
		Triangle.append(QPointF(0., -70));
		Triangle.append(QPointF(70., 0));
		Triangle.append(QPointF(-70., 0));
		MyPolygon* pol = new MyPolygon(Triangle);

		pol->setFlag(QGraphicsItem::ItemIsMovable);
		pol->setBrush(QColor(110, 180, 150));
		Myscene->addItem(pol);
	}

private:
	QPushButton* btAddRec;
	QPushButton *btAddEllipse;
	QPushButton *btAddPoly;
	QGraphicsScene *Myscene;
	QGraphicsView *MyView;
	QGraphicsSceneMouseEvent  *MyEvent;
};

#endif // LABA13_H
