

#pragma once
#include <QApplication>
#include <QtWidgets>
#include "MyWidgets.h"
#include <QLabel>






//QSlider, QScrollbar, QSpinBox


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

QLabel * label =new QLabel("123");
label ->setWindowTitle("Label");

QLabel * labeltest = new QLabel("all is ok");

MyWidgets wid=MyWidgets();
wid.push(label);

QSlider* sl = new QSlider();
sl->move(100, 20);
sl->setWindowTitle("Slider");
QScrollBar * scb = new QScrollBar();
scb->move(0, 20);
scb->setWindowTitle("ScrollBar");
QSpinBox * spinbox = new QSpinBox();
spinbox->setWindowTitle("Spin");
spinbox->move(200, 20);
wid.push(sl);
wid.push(scb);
wid.push(spinbox);

	for (int i = 0; i<wid.Size()-1; i++)
	for (int j = 0; j<wid.Size()-1; j++)
	{
		if (wid[i]->metaObject()->className() == QString("QLabel"))
	
			QObject::connect(wid[j], SIGNAL(valueChanged(int)), wid[i], SLOT(setNum(int)));
		else QObject::connect(wid[i], SIGNAL(valueChanged(int)), wid[j], SLOT(setValue(int)));
	}
	
	wid[0]->show();
	wid[1]->show();
	wid[2]->show();
	wid[3]->show();

	return a.exec();
}
