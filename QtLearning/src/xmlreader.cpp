#include "xmlreader.h"
#include <QGridLayout>
#include <QChart>
#include <QBarSet>
#include <QChartView>
#include <QBarSeries>
#include <QLineSeries>
#include <QPieSeries>
#include <QBarCategoryAxis>



using namespace QtCharts;

EndingWidget::EndingWidget()
{


	QBarSet* set0 = new QBarSet(tr("Jane"));
	QBarSet* set1 = new QBarSet(tr("John"));
	QBarSet* set2 = new QBarSet(tr("Axel"));
	QBarSet* set3 = new QBarSet(tr("Mary"));
	QBarSet* set4 = new QBarSet(tr("Samntha"));

	*set0 << 10 << 20 << 30 << 40 << 50 << 60;
	*set1 << 50 << 70 << 40 << 45 << 80 << 70;
	*set2 << 30 << 50 << 80 << 13 << 80 << 50;
	*set3 << 50 << 60 << 70 << 30 << 40 << 25;
	*set4 << 90 << 70 << 50 << 30 << 16 << 42;


	QBarSeries* seriesBar = new QBarSeries();
	seriesBar->append(set0);
	seriesBar->append(set1);
	seriesBar->append(set2);
	seriesBar->append(set3);
	seriesBar->append(set4);

	QChart *charBar = new QChart();

	charBar->addSeries(seriesBar);
	charBar->setTitle("student  performance");
	charBar->setAnimationOptions(QChart::SeriesAnimations);

	QStringList categories; 
	categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
	
	QBarCategoryAxis* axis = new QBarCategoryAxis();
	axis->append(categories);
	charBar->createDefaultAxes();
	charBar->setAxisX(axis, seriesBar);

	QWidget* chart1 = new QWidget;

	chartViewBar = new QChartView(charBar);
	chartViewBar->setRenderHint(QPainter::Antialiasing);
	chartViewBar->setParent(chart1);


	QPieSeries* seriesPie = new QPieSeries();
	seriesPie->append("Jane",10);
	seriesPie->append("Joe",20);
	seriesPie->append("Andy",30);
	seriesPie->append("Barbara",40);
	seriesPie->append("Janson",50);

	QPieSlice* slice = seriesPie->slices().at(1);

	slice->setExploded();
	slice->setLabelVisible();
	slice->setPen(QPen(Qt::darkGreen, 2));
	slice->setBrush(Qt::green);

	QChart * chartPie = new QChart;
	chartPie->addSeries(seriesPie);

	QWidget* chart2 = new QWidget;

	chartPie->setTitle(tr("Student Performance"));
	chartViewPie = new QChartView(chartPie);
	chartViewPie->setRenderHint(QPainter::Antialiasing);
	chartViewPie->setParent(chart2);


	QLineSeries* seriesLine = new QLineSeries;

	seriesLine->append(0,6);
	seriesLine->append(2,4);
	seriesLine->append(3,8);
	seriesLine->append(7,4);
	seriesLine->append(10,5);
	seriesLine->append(11,10);
	seriesLine->append(13,3);
	seriesLine->append(17,6);
	seriesLine->append(18,3);
	seriesLine->append(20,2);

	QChart* chartLine = new QChart();
	chartLine->addSeries(seriesLine);
	chartLine->createDefaultAxes();
	chartLine->setTitle("Students Performance");


	QWidget* chart3 = new QWidget;
	chartViewLine = new QChartView(chartLine);
	chartViewLine->setRenderHint(QPainter::Antialiasing);
	chartViewLine->setParent(chart3);


	QGridLayout* mainLayout = new QGridLayout;
	mainLayout->addWidget(chart1,0,0);
	mainLayout->addWidget(chart2,0,1);
	mainLayout->addWidget(chart3,0,2);

	this->setMinimumSize(900,700);
	this->setLayout(mainLayout);

}


EndingWidget::~EndingWidget()
{
	
}

void EndingWidget::resizeEvent(QResizeEvent* event)
{
		QWidget::resizeEvent(event);
		chartViewLine->resize(chartViewLine->parentWidget()->size());
		chartViewBar->resize(chartViewBar->parentWidget()->size());
		chartViewPie->resize(chartViewPie->parentWidget()->size());
}
