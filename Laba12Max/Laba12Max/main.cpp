#include "lab12.h"
#include <QtWidgets/QApplication>
#include <qobject.h>
#include <QMainWindow>
#include <QWidget>
#include <QtWidgets>
#include <qlist.h>
#include <QEvent>
#include <QMouseEvent>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsSceneEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QgraphicsEllipseItem>
#include <QGraphicsPolygonItem>
#include <QPushButton>
#include <QTransform>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lab12 w;
    w.show();

    return a.exec();
}
