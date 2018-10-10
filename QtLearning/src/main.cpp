#include "xmlreader.h"
#include <QApplication>
#include <QHeaderView>
#include <QtWebEngineWidgets/QWebEngineView>
int main(int argc,char* argv[])
{
	QApplication app(argc, argv);
	
	//QWebEngineView* veiw = new QWebEngineView();
	//veiw->load(QUrl("http://www.baidu.com"));
	//veiw->show();

	EndingWidget w;
	w.show();

	return app.exec();
}