#ifndef ENDING_WINDOW_H_
#define ENDING_WINDOW_H_

#include <QtWebEngineWidgets/QtWebEngineWidgets>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QMainWindow>
#include <QWidget>
class EndingWidget : public QMainWindow
{
 Q_OBJECT
public:
	EndingWidget();
	~EndingWidget();

protected:

private:
  QWebEngineView* webview;

	void setUi();
private slots:


};





#endif
