#pragma once

#include <QStyledItemDelegate>
#include <QPainter>

class MyDelegate : public QStyledItemDelegate
{
	Q_OBJECT
	
public:
	MyDelegate(QWidget *parent = 0) : QStyledItemDelegate(parent) {}
	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;


};