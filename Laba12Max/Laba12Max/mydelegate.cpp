#include "mydelegate.h"


void MyDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{
	int data = index.data().toInt(); //���� ���������� ����� > 0
	if (data)
	{
		//option.rect - ������ ���������� � ������ ������� ������
		//painter->drawRect(option.rect.x()+10, option.rect.y()+10, 10, 10);
		//TODO: ���������� �������� � �����, ����� �������� 1, 2 ��� 3 ���������� � ����������� �� ����������. ������ ������ ������ ���� ������� �����
		int raz = 0;
		if (data < 3) { raz = 1; }
		else { if (data < 10) { raz = 2; } else { raz = 3; } }

		for (int i = 1; i <= raz; i++) {
			//��������� �� ������ ���� ������:
			//��������� ���� ������: ��� ����� ��������� �������� ��� ������ ����� ������ � ��������� ������ �������:

			QString type = index.model()->index(index.row(), 2).data().toString();
			if (type == "RECTANGLE")
			{
				painter->drawRect(option.rect.x() + 10 * i, option.rect.y() + 10, 10, 10);
				//��� ����� +10 ����� �������� �� �����-������ ����������� ��������� �� �������� � �����, ��������:
				//option.rect.x()+i*10
			}
			else if (type == "CIRCLE")
			{
				painter->drawEllipse(option.rect.x() + 10 * i , option.rect.y() + 10, 10, 10);
			}
			else //TODO: ��� �������������
				//painter->drawRect(option.rect.x() + 10 * i + 3, option.rect.y() + 10, 10, 10); //���� ������ �������
			{
			QPolygonF Triangle;
			Triangle.append(QPointF(option.rect.x() + 10 * i, option.rect.y() + 10));
			Triangle.append(QPointF(option.rect.x() + 10 * i + 10, option.rect.y() + 10));
			Triangle.append(QPointF(option.rect.x() + 10 * i, option.rect.y() + 10 + 10));
			Triangle.append(QPointF(option.rect.x() + 10 * i, option.rect.y() + 10));
			painter->drawPolygon(Triangle);
		}
		}
		}
	else
		QStyledItemDelegate::paint(painter, option, index);
	}