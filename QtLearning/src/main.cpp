#include <QApplication>
#include <QSplashScreen>
#include "dialog.h"
#include <QFile>
#include <QIODevice>
#include <QDataStream>
#include <QTextStream>
#include <iostream>
#include <QSettings>

int main(int argc,char* argv[])
{
	QApplication app(argc, argv);
	QCoreApplication::setApplicationName("EIGHTAG");
	QCoreApplication::setOrganizationName("aaaa");
	QCoreApplication::setOrganizationDomain("simpretech.com");
	QSettings::setDefaultFormat(QSettings::IniFormat);
	QSettings::setPath(QSettings::IniFormat, QSettings::UserScope, QCoreApplication::applicationDirPath());


 //// QSettings setting("M","QtLearning");
  //QSettings::setDefaultFormat(QSettings::IniFormat);
	//QSettings::setPath(QSettings::IniFormat, QSettings::UserScope, QCoreApplication::applicationDirPath());
	//QSettings setting("C:/Users/Nikola/Desktop/1.ini",QSettings::IniFormat);
	QSettings setting;
	setting.setValue("iiii",QVariant::fromValue(2).toInt());
	setting.beginWriteArray("camera");

	for(int i = 0;i < 8; ++i) {
		setting.setArrayIndex(i);
		setting.setValue("Camera",QVariant::fromValue(i).toInt());
	}

	setting.endArray();
	QList<int> lists_;
	setting.beginReadArray("camera");
	for(int i = 0 ;i < 8 ;i++) {
		setting.setArrayIndex(i);
	  int aaa = setting.value("camera").toInt();
		std::cout<<"camera::"<<i <<" id:"<<aaa<<std::endl;
	}

	return app.exec();
}