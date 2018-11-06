#include "mainwindow.h"
#include "profilebox.h"
#include "profileline.h"
#include <QLayout>
#include <QPushButton>
#include <QGraphicsView>
#include <QInputDialog>


MainWindow::MainWindow()
{
	setUi();

}

void MainWindow::updateLines()
{
   if(lines_.size() > 0) {
	   for(int i = 0 ; i < lines_.size() ; ++i) {
		   lines_.at(i)->updateLine();
	   }
   }
}

void MainWindow::keyReleaseEvent(QKeyEvent* e)
{
	if(e->key() == Qt::Key_Delete) {
		if(scene_->selectedItems().size() > 0) {
			QGraphicsItem* item = scene_->selectedItems().at(0);
			scene_->removeItem(item);

			for(int i = lines_.size() -1; i >= 0; --i) {
				ProfileLine* line = lines_.at(i);
				if(line->startBox == item || line->endBox == item) {
					lines_.removeAt(i);
					scene_->removeItem(line);
					delete line;
				}
			}

			 delete item;
		}
	}
}

void MainWindow::setUi()
{
	QVBoxLayout* main_layout = new QVBoxLayout;

	QGraphicsView* view = new QGraphicsView;
	view->setInteractive(true);
	QPushButton* add_one_pushbutton = new QPushButton(tr("Add One"));
	main_layout->addWidget(view,8);
	main_layout->addWidget(add_one_pushbutton,2);

	this->setLayout(main_layout);
	this->setFixedSize(1000,600);

	scene_ = new QGraphicsScene(this);
	view->setScene(scene_);

	connect(scene_, &QGraphicsScene::selectionChanged, this, &MainWindow::selectionChanged);
	connect(add_one_pushbutton, &QPushButton::clicked, this, &MainWindow::addOneItem);
	ProfileBox* box = new ProfileBox();
	box->init("Nikola", this, scene_);
}

void MainWindow::addOneItem()
{
	bool ok;
	QString name = QInputDialog::getText(this, tr("Employee name"), tr("Please bababab"), QLineEdit::Normal, "Nikola", &ok);

	if(ok && !name.isEmpty()) {
		ProfileBox* box = new ProfileBox();
		box->init(name, this, scene_);

		if(scene_->selectedItems().size() > 0) {
			ProfileLine* line = new ProfileLine;
			line->initLine(box, scene_->selectedItems().at(0));
			scene_->addItem(line);
		  lines_.push_back(line);
		}
	}
}

void MainWindow::selectionChanged()
{

}