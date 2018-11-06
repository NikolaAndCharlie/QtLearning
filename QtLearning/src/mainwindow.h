#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include "profileline.h"
#include<QWidget>
#include<QGraphicsScene>
#include <QList>

class MainWindow : public QWidget
{
	Q_OBJECT
public:
	MainWindow();
	~MainWindow() {}

	void updateLines();
	void keyReleaseEvent(QKeyEvent* e);
private:
	void setUi();

private slots:
	void addOneItem();
	void selectionChanged();
private:
	QGraphicsScene* scene_;
	QList<ProfileLine*> lines_;
};




#endif
