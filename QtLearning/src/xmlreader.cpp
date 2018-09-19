#include "xmlreader.h"
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpacerItem>
#include <QFrame>


EndingWidget::EndingWidget()
{
	setWindowFlag(Qt::FramelessWindowHint);
	setMinimumSize(200,300);
	this->setObjectName(tr("centerwidget"));
  this->setStyleSheet(tr("#centerwidget {border-image: url(:/images/12.png);}"));

	QLabel *userName_label = new QLabel(tr("UserName: "));
	QLabel *PassWord_label = new QLabel(tr("PassWord: "));

	QLineEdit* line1 = new QLineEdit;
	QLineEdit* line2 = new QLineEdit;

	QWidget* w = new QWidget;

	QFormLayout* label_line_layout = new QFormLayout;
	label_line_layout->addRow(userName_label, line1);
	label_line_layout->addRow(PassWord_label, line2);
  w->setLayout(label_line_layout);
	w->setObjectName(tr("fameFrame"));
	w->setStyleSheet(tr("#fameFrame {border: 1px solid rgb(24,103,155);\
	                                       border-radius: 15px;\
																				 background-color:white;}"));
//	QFrame * a_frame = new QFrame;
////	a_frame->setObjectName(tr("fameFrame"));
//	a_frame->setStyleSheet(tr("#fameFrame {border: 1px solid rgb(24,103,155);\
//	                                       border-radius: 15px;\
//																				 background-color:white;}"));
//	a_frame = qobject_cast<QFrame*>(label_line_layout);

	QPushButton* submit = new QPushButton(tr("Submit"));
	submit->setStyleSheet(tr("QPushButton {border: 1px solid rgb(24,103,155);\
	                                       border-radius: 15px;\
																				 background-color: rgb(124,203,255);\
																				 color: white;}"));
  
	submit->setMinimumSize(240,35);

	QHBoxLayout* h_layout = new QHBoxLayout;
	h_layout->addStretch();
	h_layout->addWidget(w);
//	h_layout->addLayout(label_line_layout);
	h_layout->addStretch();

	QHBoxLayout* h2_layout = new QHBoxLayout();
	h2_layout->addStretch();
	h2_layout->addWidget(submit);
	h2_layout->addStretch();

	QVBoxLayout* v1_layout = new QVBoxLayout;
	v1_layout->addStretch();
	v1_layout->addLayout(h_layout);
	v1_layout->addLayout(h2_layout);
	v1_layout->addStretch();

	this->setLayout(v1_layout);
}


EndingWidget::~EndingWidget()
{
	
}

