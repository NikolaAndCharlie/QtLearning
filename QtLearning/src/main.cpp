#include "xmlreader.h"
#include <QApplication>
#include <QHeaderView>

int main(int argc,char* argv[])
{
	QApplication app(argc, argv);
	

	EndingWidget w;
	w.show();

	return app.exec();
}