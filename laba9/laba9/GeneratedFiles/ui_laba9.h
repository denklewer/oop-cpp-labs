/********************************************************************************
** Form generated from reading UI file 'laba9.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABA9_H
#define UI_LABA9_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_laba9Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *laba9Class)
    {
        if (laba9Class->objectName().isEmpty())
            laba9Class->setObjectName(QStringLiteral("laba9Class"));
        laba9Class->resize(600, 400);
        menuBar = new QMenuBar(laba9Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        laba9Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(laba9Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        laba9Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(laba9Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        laba9Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(laba9Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        laba9Class->setStatusBar(statusBar);

        retranslateUi(laba9Class);

        QMetaObject::connectSlotsByName(laba9Class);
    } // setupUi

    void retranslateUi(QMainWindow *laba9Class)
    {
        laba9Class->setWindowTitle(QApplication::translate("laba9Class", "laba9", 0));
    } // retranslateUi

};

namespace Ui {
    class laba9Class: public Ui_laba9Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABA9_H
