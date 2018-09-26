#ifndef ENDING_WINDOW_H_
#define ENDING_WINDOW_H_

#include <QWidget>
#include <QtCharts/QChartView>
#include <QMessageBox>
#include <QFileDialog>
#include <QPainter>

class EndingWidget : public QWidget
{
 Q_OBJECT
public:
	EndingWidget();
	~EndingWidget();

	void paintEvent(QPaintEvent * event);
	void paintImage(QString filename, int x ,int y);
protected:
private:
	bool canDraw;
	QPixmap* pix;
	QSize imageSize;
	QSize drawSize;
	QPoint drawPos;
	QLabel* image_label;
private slots:
 void browserClicked();
 void SaveClicked();
 void ScaleValueChanged(int v);
 void HorValueChanged(int v);
 void VerValueChanged(int v);

};





#endif
