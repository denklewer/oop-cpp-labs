#ifndef MYCLASS_H
#define MYCLASS_H

#include <QWidget>
class MyClass
{
private:
    QVector<QWidget*> kol;
    unsigned k;

public:
    MyClass(){
			
        kol = QVector<QWidget*>();
        k = 0;

    }
    void push(QWidget* ob) {
            kol.push_back(ob);
           k += 1;
        }
    ~MyClass(){}
        QWidget* pop(){
            return kol.at(k);
            k--;
        }
        unsigned Size() { return k+1; }

        QWidget* operator [] (unsigned index) {

            return kol.at(index);

        }
};

#endif // MYCLASS_H
