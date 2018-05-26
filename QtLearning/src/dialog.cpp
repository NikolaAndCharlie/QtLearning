#include "dialog.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

ExtendWidnow::ExtendWidnow()
{
    CreateExtendWindow();
 //   setFixedSize(300, 400);
    QWidget* firstWidget = new QWidget(this);
    m_fristLabel = new QLabel(tr("F"));
    m_moreButton = new QPushButton(tr("More"));
    connect(m_moreButton, SIGNAL(clicked(bool)), this, SLOT(ShowOrHideExtendWindow(bool)));
    QHBoxLayout* fristLayout = new QHBoxLayout;
    fristLayout->addWidget(m_fristLabel);
    fristLayout->addWidget(m_moreButton);
    firstWidget->setLayout(fristLayout);
    
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addWidget(firstWidget);

    mainLayout->addWidget(m_extendWidget);
}

ExtendWidnow::~ExtendWidnow()
{
    
}

void ExtendWidnow::CreateExtendWindow()
{
    m_extendWidget = new QWidget;
    QHBoxLayout* secondLayout = new QHBoxLayout;
    m_secondLabel = new QLabel(tr("W"));
    secondLayout->addWidget(m_secondLabel);
    m_extendWidget->setLayout(secondLayout);
    m_extendWidget->hide();
}

void ExtendWidnow::SetUi()
{
    
}

void ExtendWidnow::ShowOrHideExtendWindow(bool n)
{
    if(m_extendWidget->isHidden())
    {
        m_extendWidget->show();
    }
    else
    {
        m_extendWidget->hide();
    }
}
