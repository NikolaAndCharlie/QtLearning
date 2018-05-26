#ifndef DIALOG_H_
#define DIALOG_H_
#include <QObject>
#include <QDialog>

class QPushButton;
class QLineEdit;
class QLabel;
class QHBoxLayout;
class QLayout;
class QWidget;

class ExtendWidnow : public QDialog
{
    Q_OBJECT
public:
    ExtendWidnow();
    ~ExtendWidnow();
private:
    void CreateExtendWindow();
    void SetUi();

    QLabel* m_fristLabel;
    QPushButton* m_moreButton;
    QLabel* m_secondLabel;
    QWidget* m_extendWidget;

    private slots:
    void ShowOrHideExtendWindow(bool n);
};





#endif
