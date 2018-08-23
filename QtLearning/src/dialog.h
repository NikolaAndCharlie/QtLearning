#ifndef _THREAD_H_
#define _THREAD_H_

#include <QThread>
#include <QDialog>
#include <QPushButton>
#include <QMutex>

class Thread :public QThread
{
  Q_OBJECT
public:
	Thread();

	void setMessage(const QString &message);
	void stop();
protected:
	void run();
private:
	QString m_messagestr;
	volatile bool stopped;
	QMutex mutex;
    
};


class Dialog :public QDialog
{
	Q_OBJECT
public:
	Dialog();
	~Dialog();
protected:
	void closeEvent(QCloseEvent* event);
private slots:
	void startOrStopThreadA();
	void startOrStopThreadB();


private:
  Thread threadA;
	Thread threadB;
	QPushButton* quitButton;
	QPushButton* threadAButton;
	QPushButton* threadBButton;
};


#endif
