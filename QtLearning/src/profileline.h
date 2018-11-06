#ifndef  PROFILE_LINE_H_
#define PROFILE_LINE_H_

#include <QWidget>
#include <QPen>
#include <QGraphicsItem>

class ProfileLine : public QGraphicsLineItem
{
public:
	ProfileLine(QGraphicsItem* p = nullptr);
	void initLine(QGraphicsItem* start, QGraphicsItem* end);
	void updateLine();

	QGraphicsItem* startBox;
	QGraphicsItem* endBox;
private:

};




#endif
