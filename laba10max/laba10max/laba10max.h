#ifndef LABA10MAX_H
#define LABA10MAX_H

#include <QtWidgets/QMainWindow>
#include "ui_laba10max.h"

class laba10max : public QMainWindow
{
	Q_OBJECT

public:
	laba10max(QWidget *parent = 0);
	~laba10max();

private:
	Ui::laba10maxClass ui;
};

#endif // LABA10MAX_H
