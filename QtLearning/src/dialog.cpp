#include "dialog.h"
#include <iostream>
#include <QHBoxLayout>
#include <QCloseEvent>
#include <QMutexLocker>

using namespace std;

Thread::Thread()
{
	stopped = false;
}

void Thread::setMessage(const QString& message)
{
	m_messagestr = message;
  cout << message.toStdString() <<endl;
}

void Thread::stop()
{
	QMutexLocker locker(&mutex);
	stopped = true;
}

void Thread::run()
{
 forever{
 QMutexLocker locker(&mutex);
	if(stopped)
	{
		stopped = false;
		break;
	}
  cerr<< qPrintable(m_messagestr)<<endl;
 }
 cout<<endl;
}

Dialog::Dialog()
{
	threadA.setMessage("A");
	threadB.setMessage("B");
	threadAButton = new QPushButton(tr("Start A Button"));
	threadBButton = new QPushButton(tr("Strat B Button"));

	quitButton = new QPushButton(tr("Quite"));
	quitButton->setDefault(true);
	
	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(threadAButton);
	layout->addWidget(threadBButton);
	layout->addWidget(quitButton);

	this->setLayout(layout);
	connect(threadAButton, SIGNAL(clicked()),this,SLOT(startOrStopThreadA()));
	connect(threadBButton, SIGNAL(clicked()),this, SLOT(startOrStopThreadB()));
	connect(quitButton,SIGNAL(clicked()),this, SLOT(close()));
}

Dialog::~Dialog()
{

}

void Dialog::closeEvent(QCloseEvent* event)
{
	threadB.stop();
	threadA.stop();
	threadA.wait();
	threadB.wait();

	event->accept();
}

void Dialog::startOrStopThreadA()
{
	if(threadA.isRunning())
	{
		threadA.stop();
		threadAButton->setText(tr("Strat A"));
	}
	else
	{
		threadA.start();
		threadAButton->setText(tr("Stop A"));
	}
}

void Dialog::startOrStopThreadB()
{
	if(threadB.isRunning())
	{
		threadB.stop();
		threadBButton->setText(tr("Start B"));
	}
	else
	{
		threadB.start();
		threadBButton->setText(tr("Stop B"));
	}
}