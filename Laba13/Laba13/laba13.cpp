#include "laba13.h"

Laba13::Laba13(QWidget *parent)
: QDialog(parent)
{
	this->resize(600, 600);
	btAddEllipse = new QPushButton("Add Ellipse", this);
	btAddPoly = new QPushButton("Add Polygon", this);
	btAddRec = new QPushButton("Add Rectangle", this);
	Myscene = new QGraphicsScene(this);
	connect(btAddEllipse, SIGNAL(clicked()), this, SLOT(btAddEllipseClicked()));
	connect(btAddPoly, SIGNAL(clicked()), this, SLOT(btAddPolygonClicked()));
	connect(btAddRec, SIGNAL(clicked()), this, SLOT(btAddRectClicked()));

	btAddEllipse->setGeometry(this->width() - btAddEllipse->width() - 30, 15, btAddEllipse->width(), btAddEllipse->height());
	btAddPoly->setGeometry(this->width() - btAddEllipse->width() - 30, btAddEllipse->y() + btAddEllipse->height() + 15, btAddEllipse->width(), btAddEllipse->height());
	btAddRec->setGeometry(this->width() - btAddEllipse->width() - 30, btAddPoly->y() + btAddPoly->height() + 15, btAddEllipse->width(), btAddEllipse->height());
	MyView = new QGraphicsView(Myscene, this);
	MyView->resize(this->width() * 2 / 3, this->height());
	MyView->show();


}

Laba13::~Laba13()
{

}
