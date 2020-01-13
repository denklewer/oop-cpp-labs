#include "lab12.h"
#include "initdb.h"

#include <QtSql>

// ÏÎ×ÒÈ ÐÀÁÎ×Àß ÂÅÐÑÈß
Lab12::Lab12(QWidget *parent)
    : QDialog(parent)
{
	shapeTable = new QTableView(this);
	 x = 0;
	 y = 0;
	 count = 0;
    if (!QSqlDatabase::drivers().contains("QSQLITE"))
        QMessageBox::critical(this, "Unable to load database", "This demo needs the SQLITE driver");


    // initialize the database
    QSqlError err = initDb();


	


    if (err.type() != QSqlError::NoError) {
        QMessageBox Msg(this);
        Msg.setText(err.text());
Msg.exec();
        return;
    }

    // Create the data model
    model = new QSqlRelationalTableModel(shapeTable);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setTable("Shapes");

    // Set the localized header captions

    model->setHeaderData(model->fieldIndex("id"), Qt::Horizontal, tr("ID"));
    model->setHeaderData(model->fieldIndex("type"), Qt::Horizontal, tr("Type"));
    model->setHeaderData(model->fieldIndex("depends"), Qt::Horizontal, tr("Depends"));

    // Populate the model
    if (!model->select()) {
        QMessageBox Msg(this);
Msg.setText(model->lastError().text());
Msg.exec();
        return;
    }
    // Set the model and hide the ID column
  
    shapeTable->setModel(model);
		
   // ui.bookTable->setItemDelegate(new BookDelegate(ui.bookTable));
    //ui.bookTable->setColumnHidden(model->fieldIndex("id"), true);
    shapeTable->setSelectionMode(QAbstractItemView::SingleSelection);



   shapeTable->setCurrentIndex(model->index(0, 0));
	 Lines = QList<QGraphicsLineItem*>();
	 
	
	
        this->resize(1200, 600);
      btAddEllipse = new QPushButton("Add Ellipse",this);
        btAddPoly = new QPushButton("Add Polygon",this);
        btAddRec = new QPushButton("Add Rectangle",this);
        Myscene = new QGraphicsScene(this);
				btAddDepend = new QPushButton("Add Depend", this);
				cbCir = new QRadioButton("Circles", this);
				cbRect = new QRadioButton("Rectangles", this);
				cbTri = new QRadioButton("Triangles", this);
				cbAll = new QRadioButton("All", this);
				ldX = new QLineEdit(this);
				ldY = new QLineEdit(this);
				btDelDepend = new QPushButton("Dell Depend", this);
					connect(btAddEllipse, SIGNAL(clicked()), this, SLOT(btAddEllipseClicked()));
        connect(btAddPoly, SIGNAL(clicked()), this, SLOT(btAddPolygonClicked()));
        connect(btAddRec, SIGNAL(clicked()), this, SLOT(btAddRectClicked()));
				connect(cbCir, SIGNAL(clicked()), this, SLOT(cbCirChecked()));
				connect(cbRect, SIGNAL(clicked()), this, SLOT(cbRectChecked()));
				connect(cbTri, SIGNAL(clicked()), this, SLOT(cbTriChecked()));
				connect(cbAll, SIGNAL(clicked()), this, SLOT(cbAllChecked()));
				connect(btAddDepend, SIGNAL(clicked()), this, SLOT(btAddDependClicked()));
				connect(btDelDepend, SIGNAL(clicked()), this, SLOT(btDelDependClicked()));
        btAddEllipse->setGeometry(this->width() - btAddEllipse->width() - 30, 15, btAddEllipse->width(), btAddEllipse->height());
        btAddPoly->setGeometry(this->width() - btAddEllipse->width() - 30, btAddEllipse->y() + btAddEllipse->height() + 15, btAddEllipse->width(), btAddEllipse->height());
        btAddRec->setGeometry(this->width() - btAddEllipse->width() - 30, btAddPoly->y() + btAddPoly->height() + 15, btAddEllipse->width(), btAddEllipse->height());
				btAddDepend->setGeometry(this->width() - btAddEllipse->width() - 30, btAddRec->y() + btAddRec->height() + 15, btAddEllipse->width(), btAddEllipse->height());
				cbCir->setGeometry(this->width() - cbCir->width() - 30, btAddDepend->y() + btAddDepend->height() + 15,cbCir->width(),cbCir->height());
				cbRect->setGeometry(this->width() - cbCir->width() - 30, cbCir->y() + cbCir->height() + 15, cbRect->width(), cbRect->height());
				cbTri->setGeometry(this->width() - cbCir->width() - 30, cbRect->y() + cbRect->height() + 15, cbTri->width(), cbTri->height());
				cbAll->setGeometry(this->width() - cbCir->width() - 30, cbTri->y() + cbTri->height() + 15, cbAll->width(), cbAll->height());
				ldX->setGeometry(this->width() - cbCir->width() - 30, cbAll->y() + cbAll->height() + 15, ldX->width(), ldX->height());
				ldY->setGeometry(this->width() - cbCir->width() - 30, ldX->y() + ldX->height() + 15, ldY->width(), ldY->height());
				btDelDepend->setGeometry(this->width() - btAddEllipse->width() - 30, ldY->y() + ldY->height() + 15, btDelDepend->width(), btDelDepend->height());
				MyView = new QGraphicsView(Myscene,this);
        MyView->resize(this->width()*2/5, this->height());
        MyView->show();
        shapeTable->resize(MyView->size());
        shapeTable->setGeometry(MyView->width(),0,shapeTable->width(),shapeTable->height());
				MyDelegate *delegate = new MyDelegate;

				shapeTable->setItemDelegateForColumn(4, delegate);
        shapeTable->show();

		

}

void Lab12::btAddRectClicked(){
	QSqlQuery qu;

	if (!qu.prepare(QLatin1String("insert into Shapes(item, type, depends) values(?, ?, ?)")))
	{
		QMessageBox Msg(this);
	
		Msg.setText(qu.lastError().text());
		Msg.exec();
	}
	QString str = "Rectangle #";
	QString str2;
	int newid = Counter::getCountR();
	str += str2.setNum(newid);
	
	addShape(qu, 1, str, "RECTANGLE", QString());
	model->select();
	count++;
	x = x + (-1) ^ count * 50;
	y = y + 50;
	myRectangle *squa = new myRectangle(x, y, 50, 50, Counter::getCountAll());
	
	//squa->setFlag(QGraphicsItem::ItemIsMovable);
	squa->setBrush(QColor(0, 190, 0));
	//squa->setFlag(QGraphicsItem::ItemIsMovable);
	Myscene->addItem(squa);
	ListOfRects[squa->getId()] = squa;
	ListOfItems[squa->getId()]=squa;

	model->setFilter("type='RECTANGLE'");
	for (int i = 0; i < model->rowCount(); i++){
		QSqlRecord record = model->record(i);

		int k = (record.value("id").toInt());
		model->setData(model->index(i, 4), newid);


	}
	
	
	model->submitAll();
	model->setFilter("");
	//refresh();






}

void Lab12::btAddEllipseClicked() {
	QSqlQuery qu;

	if (!qu.prepare(QLatin1String("insert into Shapes(item, type, depends) values(?, ?, ?)")))
	{
		QMessageBox Msg(this);
		Msg.setText(qu.lastError().text());
		Msg.exec();
	}

	QString str = "Ellipse #";
	QString str2;
	int newid = Counter::getCountC();
	str += str2.setNum(newid);
	addShape(qu, 1, str, "CIRCLE", QString());

	model->select();


	count++;
	x = x + (-1) ^ count * 50;
	y = y + 50;
	Circle* ell = new Circle(x, y, 50, 50, Counter::getCountAll());
  ell->setBrush(QColor(0, 0, 150));
	//ell->setFlag(QGraphicsItem::ItemIsMovable);
	ListOfItems[ell->getId()]=ell;
	ListOfRects[ell->getId()] = new QGraphicsRectItem(ell->rect());

	

	Myscene->addItem(ell);
	model->setFilter("type='CIRCLE'");
	for (int i = 0; i < model->rowCount(); i++){
		QSqlRecord record = model->record(i);

		int k = (record.value("id").toInt());
		model->setData(model->index(i, 4), newid);


	}
	model->submitAll();
	model->setFilter("");
	//refresh();



}
void Lab12::btAddPolygonClicked() {
	QSqlQuery qu;
	if (!qu.prepare(QLatin1String("insert into Shapes(item, type, depends) values(?, ?, ?)")))
	{
		QMessageBox Msg(this);
		Msg.setText(qu.lastError().text());
		Msg.exec();
	}
	QString str = "Triangle #";
	QString str2;
	int newid = Counter::getCountT();
	str += str2.setNum(newid);
	addShape(qu, 1, str, "TRIANGLE", QString());
	model->select();
	count++;
	x = x + (-1) ^ count * 50;
	y = y + 50;
	QPolygonF Triangle;
	Triangle.append(QPointF(x, y));
	Triangle.append(QPointF(x+50, y));
	Triangle.append(QPointF(x, y+50));
	Triangle.append(QPointF(x, y));
		MyTriangle* pol = new MyTriangle(Triangle,Counter::getCountAll());
//	pol->setFlag(QGraphicsItem::ItemIsMovable);
	pol->setBrush(QColor(100, 100, 150));
	Myscene->addItem(pol);
	ListOfItems[pol->getId()]=pol;
	ListOfRects[pol->getId()] = new QGraphicsRectItem(pol->boundingRect());
	Myscene->addItem(pol);

	model->setFilter("type='TRIANGLE'");
	for (int i = 0; i < model->rowCount(); i++){
		QSqlRecord record = model->record(i);

		int k = (record.value("id").toInt());
		model->setData(model->index(i, 4), newid);


	}
	model->submitAll();
	model->setFilter("");
	//refresh();
}
void Lab12::cbRectChecked(){
	model->setFilter("type = 'TRIANGLE'");
	model->select();
	hideDep();
	for (int i = 0; i < model->rowCount(); i++){
		QSqlRecord record = model->record(i);
		ListOfItems[(record.value("id").toInt())]->hide();
	}
	model->setFilter("type = 'CIRCLE'");
	model->select();
	hideDep();
	for (int i = 0; i < model->rowCount(); i++){
		QSqlRecord record = model->record(i);
		ListOfItems[(record.value("id").toInt())]->hide();
	}


	
			model->setFilter("type = 'RECTANGLE'");
			model->select();
			readDep();
			for (int i = 0; i < model->rowCount(); i++){
				QSqlRecord record = model->record(i);
				ListOfItems[(record.value("id").toInt())]->show();
			}
			refresh();

}

void Lab12::cbCirChecked(){
	model->setFilter("type = 'RECTANGLE'");
	model->select();
	hideDep();
	for (int i = 0; i < model->rowCount(); i++){
		QSqlRecord record = model->record(i);
		ListOfItems[(record.value("id").toInt())]->hide();
	}
	model->setFilter("type = 'TRIANGLE'");
	model->select();
	hideDep();
	for (int i = 0; i < model->rowCount(); i++){
		QSqlRecord record = model->record(i);
		ListOfItems[(record.value("id").toInt())]->hide();
	}

			model->setFilter("type = 'CIRCLE'");
			model->select();
			readDep();
			for (int i = 0; i < model->rowCount(); i++){
				QSqlRecord record = model->record(i);
				ListOfItems[(record.value("id").toInt())]->show();
			}
			refresh();

}
void Lab12::cbTriChecked(){
	model->setFilter("type = 'RECTANGLE'");
	model->select();
	hideDep();
	for (int i = 0; i < model->rowCount(); i++){
		QSqlRecord record = model->record(i);
		ListOfItems[(record.value("id").toInt())]->hide();
	}
	model->setFilter("type = 'CIRCLE'");
	model->select();
	hideDep();
	for (int i = 0; i < model->rowCount(); i++){
		QSqlRecord record = model->record(i);
		ListOfItems[(record.value("id").toInt())]->hide();
	}
			model->setFilter("type = 'TRIANGLE'");
		
	model->select();
	readDep();
	for (int i = 0; i < model->rowCount(); i++){
		QSqlRecord record = model->record(i);
		ListOfItems[(record.value("id").toInt())]->show();
	}
	refresh();
}
void Lab12::cbAllChecked(){
	

	model->setFilter("");
	
	model->select();
	readDep();
	for (int i = 0; i < model->rowCount(); i++){
		QSqlRecord record = model->record(i);
		ListOfItems[(record.value("id").toInt())]->show();
	}
	refresh();
}
void Lab12::btAddDependClicked(){
	int x = ldX->text().toInt();
	int y = ldY->text().toInt();
	Depends[x][y] = true;
	Depends[y][x] = true;




	refresh();

}
void Lab12::btDelDependClicked(){
	int x = ldX->text().toInt();
	int y = ldY->text().toInt();
	Depends[x][y] = false;
	Depends[y][x] = false;
	 
	QString tmp = "id = ";
	QString str;
	tmp += str.setNum(x);
	model->setFilter(str);

	refresh();

}
void Lab12::refresh(){
	for (int i = 0; i < Lines.count(); i++){
		Myscene->removeItem(Lines.at(i));
	}


	for (int i = 0; i < model->rowCount(); i++){
		QSqlRecord record = model->record(i);
		QString str;
		int k = (record.value("id").toInt());
		QString newList="";
		for (int n = 0; n < model->rowCount(); n++){
			QSqlRecord record2 = model->record(n);
			int j = record2.value("id").toInt();
			
			if (Depends[k][j]) {
				str.setNum(j);
				if (newList.length()>0) {
					newList += ", ";
					newList += str;
				}
				else { newList += str; }
					QLineF linef = QLineF(ListOfRects[k]->rect().center(), ListOfRects[j]->rect().center());
					QGraphicsLineItem* line = new QGraphicsLineItem(linef, ListOfItems[k]);
						line->setPen(QPen(QColor(30, 30, 30)));
					Myscene->addItem(line);
					Lines.push_back(line);
			
				
			}
		}
		model->setData(model->index(i,3), newList);
	}

	model->submitAll();

}
void Lab12::readDep(){
	for (int i = 0; i < model->rowCount(); i++){
		QSqlRecord record = model->record(i);
	
		int k = (record.value("id").toInt());
		QString newList = "";
		QString str = record.value("depends").toString();
		QStringList mas = str.split(",");

		for (int n = 0; n < mas.count(); n++){
			Depends[k][ mas[n].toInt()] = true;
			Depends[mas[n].toInt()][k ] = true;
	}
	
	}

}
void Lab12::hideDep(){
	for (int i = 0; i < model->rowCount(); i++){
		QSqlRecord record = model->record(i);
		
		int k = (record.value("id").toInt());
		QString newList = "";
		QString str = record.value("depends").toString();
		QStringList mas = str.split(",");

		for (int n = 0; n < mas.count(); n++){
			Depends[k][mas[n].toInt()] = false;
			Depends[mas[n].toInt()][k] = false;
		}

	}

}

Lab12::~Lab12()
{

}
