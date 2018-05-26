#include <QApplication>
#include "dialog.h"
int main(int argc,char* argv[])
{
    QApplication app(argc, argv);

    ExtendWidnow w;
    w.show();

    return app.exec();
}