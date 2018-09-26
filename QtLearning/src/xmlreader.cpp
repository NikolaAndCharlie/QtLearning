#include "xmlreader.h"
#include <QGridLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QLabel>
#include <QSplitter>
#include <QSlider>
#include <QFormLayout>
#include <QCoreApplication>


EndingWidget::EndingWidget()
            : canDraw(false)
{
	this->setFixedSize(400,300);
	QHBoxLayout* frist_layout = new QHBoxLayout;
	
	//image_label = new QLabel;
	//image_label->setFixedSize(150,150);
	//image_label->setStyleSheet("background-color: black;");
	
	//frist_layout->addStretch();
	//frist_layout->addWidget(image_label);
	//frist_layout->addStretch();

	QLabel* scale_label = new QLabel(tr("Scale"));
	QLabel* horizontal_label = new QLabel(tr("Horizontal"));
	QLabel* vertical_label = new QLabel(tr("Vertical"));
	
	QSlider* scale_slider = new QSlider(Qt::Horizontal);
	connect(scale_slider, &QSlider::valueChanged, this, &EndingWidget::ScaleValueChanged);
	QSlider* horizontal_slide = new QSlider(Qt::Horizontal);
	connect(horizontal_slide, &QSlider::valueChanged, this, &EndingWidget::HorValueChanged);
	QSlider* vertical_slide = new QSlider(Qt::Horizontal);
	connect(vertical_slide, &QSlider::valueChanged, this, &EndingWidget::VerValueChanged);

	QFormLayout* mide_layout = new QFormLayout;
	mide_layout->addRow(scale_label, scale_slider);
	mide_layout->addRow(horizontal_label, horizontal_slide);
	mide_layout->addRow(vertical_label, vertical_slide);

	QPushButton* browser_button = new QPushButton(tr("Browse"));
	connect(browser_button, &QPushButton::clicked, this, &EndingWidget::browserClicked);
	QPushButton* Save_button = new QPushButton(tr("Save"));
	connect(Save_button, &QPushButton::clicked, this, &EndingWidget::SaveClicked);

	QHBoxLayout* button_layout = new QHBoxLayout;
	button_layout->addWidget(browser_button);
	button_layout->addWidget(Save_button);

	QVBoxLayout* main_layout = new QVBoxLayout;
	main_layout->addLayout(frist_layout);
	main_layout->setStretchFactor(frist_layout,6);
	main_layout->addLayout(mide_layout);
	main_layout->setStretchFactor(mide_layout,3);
	main_layout->addLayout(button_layout);
	main_layout->addLayout(button_layout,1); 

	this->setLayout(main_layout);
}


EndingWidget::~EndingWidget()
{

}

void EndingWidget::paintEvent(QPaintEvent* event)
{
	if (canDraw) {
		paintImage("",125, 11);
	}
}

void EndingWidget::paintImage(QString filename, int x, int y)
{
	QPainter painter;
	QImage saveImage(150,150, QImage::Format_RGB16);

	if(!filename.isEmpty()) {
		painter.begin(&saveImage);
	}
	else {
		painter.begin(this);
	}

	if(!pix->isNull()) {
		painter.setClipRect(x, y , 300, 300);
		painter.fillRect(QRect(x,y, 150, 150), Qt::SolidPattern);
		painter.drawPixmap(x - drawPos.x(), y - drawPos.y(), drawSize.width(), drawSize.height(), *pix);
	}

	painter.end();

	if(filename != "") {
		saveImage.save(filename);
		QMessageBox::information(this, tr("Success"), tr("Image has been successfully saved!"));
	}

}

void EndingWidget::browserClicked()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Open Image"),"C://Users//Nikola//Desktop",tr("Image Files (*.jpg *.jpeg)"));

	if(!filename.isEmpty()) {
	   QPixmap* newPix = new QPixmap(filename);

		 if(!newPix->isNull()) {
			 if(newPix->width() < 150 || newPix->height() < 150) {
				 
				 QMessageBox::warning(this, tr("Inivalid Size"), tr("Image size too samll .please\
				  use an image larger than 150x150."));
					return ;
			 }

			 pix = newPix;
			 imageSize = pix->size();
			 drawSize = pix->size();

			 canDraw = true;
		 }
		 else {
			 canDraw = false;

			 QMessageBox::warning(this, tr("Invalid Image"), tr("Invalid or corrupted file. please try\
			 again with another image file."));
		 }
	}
	
}

void EndingWidget::SaveClicked()
{
   if(canDraw) {
	   if(!pix->isNull()) {
		   paintImage(QCoreApplication::applicationDirPath() + "/image.jpg",0,0);
	   }
   }
}

void EndingWidget::ScaleValueChanged(int value)
{
   drawSize = imageSize * value / 100;
	 update();
}

void EndingWidget::HorValueChanged(int v)
{
	drawPos.setX(v * drawSize.width() / 100 * 0.5);
	update();
}

void EndingWidget::VerValueChanged(int v)
{
	drawPos.setY(v * drawSize.height() / 100 * 0.5);
	update();
}