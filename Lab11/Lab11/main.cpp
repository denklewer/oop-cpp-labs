#include <QApplication> 
#include <QtWidgets>
#include "mytabledialog.h"

int main(int argc, char *argv[]) {
	
	QApplication a(argc, argv);

	MyTableDialog tab;
	tab.show();

return a.exec(); };
