#include "mytabledialog.h"
#include <QTextCodec>
MyTableDialog::MyTableDialog(QWidget *parent)
	: QDialog(parent)
{
	this->resize(800, 300);
	this->setMinimumSize(800, 300);
	this->setMaximumSize(800, 300);
	TextBox = new QLineEdit(this);
	btSearch = new QPushButton("Search", this);
	btAdd = new QPushButton("Add Row", this);
	btReadFromFile = new QPushButton("Read From File", this);
	btSaveToFile = new QPushButton("Save to File", this);
  tableWidget = new QTableWidget(6, 6,this);
	spSelectedColumn = new QSpinBox(this);
	tableWidget->resize(600, 300);
	connect(tableWidget, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(refresh(QTableWidgetItem*)));
	


	TextBox->setGeometry(tableWidget->width() + 15, 15, width()-tableWidget->width()-30, TextBox->height());
	btSearch->setGeometry(TextBox->x() + TextBox->width()/2-btSearch->width()/2, TextBox->y() + TextBox->height() + 10, btSearch->width(), btSearch->height());
	spSelectedColumn->setGeometry(QRect((btSearch->pos() + QPoint(0, btSearch->height() + 10)), QSize(spSelectedColumn->width(), spSelectedColumn->height())));
	btAdd->setGeometry(QRect((spSelectedColumn->pos()+QPoint(0,spSelectedColumn->height()+10)), QSize(btAdd->width(), btAdd->height())));
	btReadFromFile->setGeometry(QRect((btAdd->pos() + QPoint(0, btAdd->height() + 10)), QSize(btReadFromFile->width(), btReadFromFile->height())));
	btSaveToFile->setGeometry(QRect((btReadFromFile->pos() + QPoint(0, btReadFromFile->height() + 10)), QSize(btSaveToFile->width(), btSaveToFile->height())));


	//Имя, Фамилия, Отчество, адрес, дата рождения, email, телефонные номера

		QHeaderView *mh = new QHeaderView(Qt::Horizontal);
		mh->setSectionsClickable(true);
		tableWidget->setHorizontalHeader(mh);
		QStringList headerLabels;
		headerLabels << "FirstName" << "LastName" << "Adress" << "Date"<<"Email"<<"Phone numbers";
		tableWidget->setHorizontalHeaderLabels(headerLabels);
		spSelectedColumn->setPrefix("Column: ");
		spSelectedColumn->setRange(1, 6);
		



	/*	tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked
			| QAbstractItemView::SelectedClicked);*/
		tableWidget->resizeColumnsToContents();
		connect(mh, SIGNAL(sectionClicked(int)), this, SLOT(sort(int)));
		connect(btAdd, SIGNAL(clicked()), this, SLOT(btAddClicked()));
		connect(btSearch, SIGNAL(clicked()), this, SLOT(btSearchClicked()));

		connect(btReadFromFile, SIGNAL(clicked()), this, SLOT(ReadFromFile()));
		connect(btSaveToFile, SIGNAL(clicked()), this, SLOT(WriteToFile()));


	TextBox->show();

	tableWidget->show();
	//tableWidget->setSortingEnabled(true);
}




void MyTableDialog::sort(int x)
{
	
	tableWidget->setSortingEnabled(true);
	tableWidget->sortByColumn(x);
	tableWidget->setSortingEnabled(false);
}



void MyTableDialog::refresh(QTableWidgetItem* x){

	QMessageBox msg(this);

	
		QRegExp rx;
		
	qDebug() << x->column();
	switch (x->column())
	{
	case 0:{
					 rx.setPattern("^[A-Za-zА-Яа-я]((\\w[^\\_])*([\\-\\s])?(\\w[^\\_])*[A-Za-zА-Яа-я])*$");
	
					 msg.setText("Input error of Firstname"); break;
	}
	case 1: {
						rx.setPattern("^[A-Za-zА-Яа-я]((\\w[^\\_])*([\\-\\s])?(\\w[^\\_])*[A-Za-zА-Яа-я])*$");
						msg.setText("Input error of Lastname"); break;

	}
	case 2: {
						rx.setPattern("\\w*");
						msg.setText("Input error of Adress"); break;

	}
	case 3: {
						rx.setPattern("^(([0-2]?[0-9])|([3][0-1]))(\\.|\\,)(([0]?[0-9])|([1][0-2]))(\\.|\\,)(([0-1]?[0-9]{1,3})|([2][0][0][0-9]))$");
						
						
						
						

						msg.setText("Input error of Date"); break;

	}
	case 4:{
					  rx.setPattern("\\w+@\\w+\\.\\w+");
					 msg.setText("Input error of email"); break;
	}

	case 5: {
						rx.setPattern("^((\\+)?\\d{1,3}\\s?((\\d{1,3})|(\\(\\d{1,3}\\)))\\s?\\d{1,3}[\\s\\-]?\\d{1,2}\\s?\\d{1,2}(\\,\\s?)?)+$");
						msg.setText("Input error of Phone Numbers"); break; 
	}
			}
	QString str = x->text();
	
	if (str.contains(rx)){
	
		
		//tableWidget->setItem( 1, 1, 0);
		
	}
	else  { 
	
	tableWidget->setItem(x->row(), x->column(), 0);
	
	msg.exec(); // call exec() to show the message

	}
	
	tableWidget->resizeColumnsToContents();
}
MyTableDialog::~MyTableDialog()
{

}
