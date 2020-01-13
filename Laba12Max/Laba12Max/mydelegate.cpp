#include "mydelegate.h"


void MyDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{
	int data = index.data().toInt(); //если количество фигур > 0
	if (data)
	{
		//option.rect - хранит координаты и размер текущей ячейки
		//painter->drawRect(option.rect.x()+10, option.rect.y()+10, 10, 10);
		//TODO: нарисовать элементы в цикле, чтобы рисовать 1, 2 или 3 квадратика в зависимости от количества. Хотите можете задать цвет заливки фигур
		int raz = 0;
		if (data < 3) { raz = 1; }
		else { if (data < 10) { raz = 2; } else { raz = 3; } }

		for (int i = 1; i <= raz; i++) {
			//Рисование на основе типа фигуры:
			//Получение типа фигуры: для этого требуется получить всю строку через модель и проверить вторую колонку:

			QString type = index.model()->index(index.row(), 2).data().toString();
			if (type == "RECTANGLE")
			{
				painter->drawRect(option.rect.x() + 10 * i, option.rect.y() + 10, 10, 10);
				//для цикла +10 нужно заменить на какой-нибудь коэффициент зависящий от итерации в цикле, например:
				//option.rect.x()+i*10
			}
			else if (type == "CIRCLE")
			{
				painter->drawEllipse(option.rect.x() + 10 * i , option.rect.y() + 10, 10, 10);
			}
			else //TODO: Для треугольников
				//painter->drawRect(option.rect.x() + 10 * i + 3, option.rect.y() + 10, 10, 10); //Пока рисуем квадрат
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