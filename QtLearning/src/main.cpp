#include <QApplication>
#include <QSplashScreen>
#include <QFile>
#include <QIODevice>
#include <QDataStream>
#include <QTextStream>
#include <iostream>
#include <QSettings>
#include "mainwindow.h"

int main(int argc,char* argv[])
{
	QApplication app(argc, argv);

	MainWindow w;
	w.show();

	return app.exec();
}
