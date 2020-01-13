#ifndef MYTABLEDIALOG_H
#define MYTABLEDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include <QRegExp>
#include <QtDebug>
class MyTableDialog : public QDialog
{
	Q_OBJECT

public:
	MyTableDialog(QWidget*parrent = 0);


	~MyTableDialog();
	private slots:
	void sort(int x);
	void refresh(QTableWidgetItem* x);
	void btAddClicked() {
		tableWidget->setRowCount(tableWidget->rowCount() + 1);
	}
	void btSearchClicked() {

		int row_count = tableWidget->rowCount();

		QString search = TextBox->text();

		int search_column = spSelectedColumn->value()-1;
		int res = -1;

		for (int i = 0; i < row_count; i++)
		{
			if (tableWidget->item(i, search_column) != nullptr){

				if (tableWidget->item(i, search_column)->text() == search)
				{

					res = tableWidget->item(i, search_column)->row();
					QMessageBox msg(this);
					msg.setText("Founded");
					msg.exec(); // call exec() to show the message
					break;
				}
			}

		}
		if (res > -1)
		{

		tableWidget->selectRow(res);
		/*	tableWidget->item(res, search_column)->setSelected(true);*/
		tableWidget->scrollToItem(tableWidget->itemAt(search_column, res));
		}
		else {
			QMessageBox msg(this);
			msg.setText("Can't Find");
			msg.exec(); // call exec() to show the message
		}

	}
	void ReadFromFile() {

		int column_count = tableWidget->columnCount();
     QString myFil = ("NoteBook.txt");
		QFile Mfile(myFil);
		
		QString Str;
		int row = -1;
		if (Mfile.open(QIODevice::ReadOnly | QIODevice::Text)) //QFile::Text - построчное чтение
		{
			
			QTextStream in(&Mfile);
			while (!in.atEnd()) //Пока не конец файла
			{
				row++;
				if (row > tableWidget->rowCount()-1){
					tableWidget->setRowCount(row +1);
				}
				in>>Str;
				if (!(Str.isEmpty()))
				{
					QStringList lst = Str.split("|"); //Разбивается на элементы до знака |
					
					for (int i = 0; i < column_count ; i++)
						tableWidget->setItem(row, i,new QTableWidgetItem(lst[i]));	
				}
			}
		}

	}


	void WriteToFile() {
		int column_count = tableWidget->columnCount();
		int row_count = tableWidget->rowCount();
		QString fileName = QFileDialog::getSaveFileName(this,
			tr("Save Address Book"), "",
			tr("Address Book (*.txt);;All Files (*)"));

		if (fileName.isEmpty())
			return;
		else {
			QFile file(fileName);
			if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
				QMessageBox::information(this, tr("Unable to open file"),
					file.errorString());
				return;
			}
			QTextStream out(&file);
		
			for (int j = 0; j < row_count; j++){
				for (int i = 0; i < column_count; i++){
					if (tableWidget->item(j, i) != nullptr) {
						out << tableWidget->item(j, i)->text() << "|";
					}
					else  { out << " |"; }
				}

				out << endl;
			}
		}
	




	}


private:

	QLineEdit *TextBox;
	QSpinBox *spSelectedColumn;
	QPushButton *btSearch;
	QPushButton *btAdd;
	QPushButton *btReadFromFile;
	QPushButton *btSaveToFile;
	QTableWidget *tableWidget;
	
};

#endif // MYTABLEDIALOG_H
