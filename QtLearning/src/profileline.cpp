#include "profileline.h"

ProfileLine::ProfileLine(QGraphicsItem* p) : QGraphicsLineItem(p)
{
	QPen pen(Qt::black);
	pen.setWidth(2);
	this->setPen(pen);

	this->setZValue(-999);
}

void ProfileLine::initLine(QGraphicsItem* start, QGraphicsItem* end)
{
	startBox = start;
	endBox = end;

	updateLine();
}

void ProfileLine::updateLine()
{
	if(startBox != nullptr && endBox != nullptr) {
		this->setLine(startBox->pos().x() + startBox->boundingRect().width() / 2,
		 startBox->pos().y() + startBox->boundingRect().height() / 2, 
		 endBox->pos().x() + endBox->boundingRect().width() / 2, 
		 endBox->pos().y() + endBox->boundingRect().height() / 2
		);


	}
}