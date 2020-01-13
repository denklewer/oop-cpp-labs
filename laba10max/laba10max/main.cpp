#pragma once
#include <QApplication>
#include <QtWidgets>

#include <QLabel>

#include "myclass.h"





int main(int argc, char *argv[]){
    QApplication a(argc, argv);
		QLabel * lb = new QLabel();
QLabel * label =new QLabel("123",lb);

label->setWindowTitle("Label");



MyClass obj=MyClass();
obj.push(label);

QSlider* sl = new QSlider(lb);


sl->setWindowTitle("Slider");
QScrollBar * scb = new QScrollBar(lb);

scb->setWindowTitle("ScrollBar");
QSpinBox * spinbox = new QSpinBox(lb);
spinbox->setWindowTitle("SpinBox");

obj.push(sl);
obj.push(scb);
obj.push(spinbox);

    for (int i = 0; i<obj.Size()-1; i++){


    for (int j = 0; j<obj.Size()-1; j++)
    {
        if (obj[i]->metaObject()->className() == QString("QLabel"))

            QObject::connect(obj[j], SIGNAL(valueChanged(int)), obj[i], SLOT(setNum(int)));
        else QObject::connect(obj[i], SIGNAL(valueChanged(int)), obj[j], SLOT(setValue(int)));
    }
}
		lb->show();
    obj[0]->show();
    obj[1]->show();
    obj[2]->show();
    obj[3]->show();

    return a.exec();
}
