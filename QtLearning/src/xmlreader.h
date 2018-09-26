#ifndef ENDING_WINDOW_H_
#define ENDING_WINDOW_H_

#include <QWidget>
#include <QtCharts/QChartView>


class EndingWidget : public QWidget
{
 Q_OBJECT
public:
	EndingWidget();
	~EndingWidget();
protected:
  void resizeEvent(QResizeEvent* event);
private:
	QtCharts::QChartView* chartViewBar;
	QtCharts::QChartView* chartViewPie;
	QtCharts::QChartView* chartViewLine;

};





#endif
