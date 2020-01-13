#ifndef INITDB_H
#define INITDB_H
#include <QGraphicsItem>
#include <QtSql>
#include <QMessageBox>

	void addShape(QSqlQuery &q, int idShape, QString item, QString type, QString depends)
	{

		//q.prepare(QLatin1String("insert into Shapes(id, item, type ,depends) values(?, ?, ? ,?)"));

		//  q.addBindValue(idShape);
		q.addBindValue(item);
		q.addBindValue(type);

		q.addBindValue(depends);


	

		q.exec();
	}



	QSqlError initDb()
	{
		QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
		db.setDatabaseName(":memory:");

		if (!db.open())
			return db.lastError();

		QStringList tables = db.tables();
		if (tables.contains("Shapes", Qt::CaseInsensitive))

			return QSqlError();

		QSqlQuery q;
		if (!q.exec(QLatin1String("create table Shapes(id integer primary key, item myrectangle, type QString , depends QString,count integer)")))
			return q.lastError();

		//if (!q.prepare(QLatin1String("insert into Shapes(id, item, type ,depends) values(?, ?, ? ,?)")))
		//   return q.lastError();


		if (!q.prepare(QLatin1String("insert into Shapes(item, type, depends) values(?, ?, ?)")))
			return q.lastError();

		

		return QSqlError();
	}





#endif
