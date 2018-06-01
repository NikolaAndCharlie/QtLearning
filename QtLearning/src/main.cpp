#include <QApplication>
#include <QSplashScreen>
#include "dialog.h"




int main(int argc,char* argv[])
{
    QApplication app(argc, argv);
    QPixmap pix("C://Users/Nikola/Desktop/1.jpg");
    
    QSplashScreen* splash = new QSplashScreen(pix);
    splash->show();
    qApp->processEvents();
    splash->showMessage(QObject::tr("I am your father"));
    IconEditor w;
    w.show();
    delete splash;
    return app.exec();
}