#include "profilebox.h"
#include "mainwindow.h"
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QBrush>
#include <QPen>
#include <QFont>

ProfileBox::ProfileBox(QGraphicsItem* p)
{	
	QBrush brush(Qt::white);
	QPen pen(Qt::black);
	QFont font;
	font.setFamily("Arial");
	font.setPointSize(12);

	QGraphicsRectItem* rect_item = new QGraphicsRectItem();
	rect_item->setRect(0,0,90,100);
	rect_item->setBrush(brush);
	rect_item->setPen(pen);

	name_tag_ = new QGraphicsTextItem();
	name_tag_->setPlainText("");
	name_tag_->setFont(font);
	name_tag_->setPos(10,0);

	QGraphicsPixmapItem* pixmap_item = new QGraphicsPixmapItem();
	QPixmap pixmap(":rc//profile.ico");
	pixmap_item->setPixmap(pixmap);
	pixmap_item->setPos(15,30);

	this->addToGroup(rect_item);
	this->addToGroup(name_tag_);
	this->addToGroup(pixmap_item);

	this->setFlag(QGraphicsItem::ItemIsSelectable);
	this->setFlag(QGraphicsItem::ItemIsMovable);
	this->setFlag(QGraphicsItem::ItemSendsScenePositionChanges);

}

void ProfileBox::init(QString name, MainWindow * window, QGraphicsScene* scene)
{
	name_tag_->setPlainText(name);
	m = window;
	scene->addItem(this);
}

QVariant ProfileBox::itemChange(GraphicsItemChange change, const QVariant& value)
{
	if(change == QGraphicsItem::ItemPositionChange) {
		m->updateLines();
	}

	return QGraphicsItem::itemChange(change, value);
}