#ifndef LAB9_H
#define LAB9_H

#include <QtWidgets/QMainWindow>
#include "ui_lab9.h"

class lab9 : public QMainWindow
{
	Q_OBJECT

public:
	lab9(QWidget *parent = 0);
	~lab9();

private:
	Ui::lab9Class ui;
};

#endif // LAB9_H
