#ifndef LAB12_H
#define LAB12_H
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
#include "myrectangle.h"
#include "mytriangle.h"
#include "circle.h"
#include <QtSql>
#include <QPixmap>
#include "mydelegate.h";
#include <QSqlRelationalDelegate>
#include <QItemDelegate>
//#include "initdb.h"

// ÏÎ×ÒÈ ÐÀÁÎ×Àß ÂÅÐÑÈß





class Lab12 : public QDialog
{
    Q_OBJECT

public:
    Lab12(QWidget *parent = 0);
    ~Lab12();
private slots:
void btAddRectClicked(); 
  
void btAddEllipseClicked();
void btAddPolygonClicked();
void cbRectChecked();
void cbCirChecked();
void cbTriChecked();
void cbAllChecked();
void btAddDependClicked();
void refresh();
void btDelDependClicked();
void readDep();
void hideDep();
private:
    QPushButton* btAddRec;
 QPushButton *btAddEllipse;
    QPushButton *btAddPoly;
    QGraphicsScene *Myscene;
    QGraphicsView *MyView;
    QGraphicsSceneMouseEvent  *MyEvent;
    QSqlRelationalTableModel *model;
    QTableView* shapeTable;
		QPushButton *btAddDepend;
		QPushButton *btDelDepend;
		QLineEdit *ldX;
		QLineEdit *ldY;
		QRadioButton *cbRect;
		QRadioButton *cbCir;
		QRadioButton *cbTri;
		QRadioButton *cbAll;
		QGraphicsItem *ListOfItems[512];
		QGraphicsRectItem* ListOfRects[512];
		bool Depends[512][512];
		
		QList<QGraphicsLineItem *>Lines;
		QList<int> ids;
		qint32 x;
		qint32 y;
		qint32 count;
};

#endif // LAB12_H
