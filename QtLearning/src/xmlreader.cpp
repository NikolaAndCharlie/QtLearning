#include "xmlreader.h"
#include <QUrl>

EndingWidget::EndingWidget()
{  
   setUi();
   webview = new QWebEngineView(this->centralWidget());
	 webview->load(QUrl("http://www.baidu.com"));


}

EndingWidget::~EndingWidget()
{

}

void EndingWidget::setUi()
{
  this->setMinimumSize(800,600);
	QWidget * w  = new QWidget;
	w->setMinimumSize(400,400);
	this->setCentralWidget(w);
}