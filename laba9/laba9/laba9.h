#ifndef LABA9_H
#define LABA9_H

#include <QtWidgets/QMainWindow>
#include "ui_laba9.h"

class laba9 : public QMainWindow
{
	Q_OBJECT

public:
	laba9(QWidget *parent = 0);
	~laba9();

private:
	Ui::laba9Class ui;
};

#endif // LABA9_H
