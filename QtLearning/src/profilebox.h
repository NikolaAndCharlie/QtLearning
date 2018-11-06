#ifndef PROFILE_BOX_H_
#define PROFILE_BOX_H_

#include <QGraphicsItemGroup>
#include <QGraphicsTextItem>

class MainWindow;

class ProfileBox : public QGraphicsItemGroup
{
public:
	explicit ProfileBox(QGraphicsItem* item = nullptr);
	~ProfileBox()
	{
		
	}

	void init(QString name, MainWindow *window, QGraphicsScene* scene);
	QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
private:
 QGraphicsTextItem* name_tag_;
 MainWindow* m;
};

#endif
