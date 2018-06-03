#include <QtWidgets>
#include "dialog.h"
#include <QRubberBand>

IconEditor::IconEditor(QWidget *parent)
          :QWidget(parent)
{
 //   setAttribute(Qt::WA_StaticContents);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    zoom = 8;
    curColor = Qt::black;
    image = QImage(32, 32, QImage::Format_ARGB32);
    image.fill(qRgba(0, 0, 0, 0));
}

QSize IconEditor::sizeHint() const
{
    QSize size = zoom * image.size();
    if(zoom > 3)
    {
        size += QSize(1, 1);
    }


    return size;
}


void IconEditor::setPenColor(const QColor& newColor)
{
    curColor = newColor;
}

void IconEditor::setIconImage(const QImage& newImage)
{
    if(newImage  != image)
    {
        image = newImage.convertToFormat(QImage::Format_ARGB32);
        update();
        updateGeometry();
    }
}



void IconEditor::setZoomFactor(int newZoom)
{
    if(newZoom < 1)
    {
        newZoom = 1;
    }
   
    if(newZoom != zoom)
    {
        zoom = newZoom;
        update();
        updateGeometry();
    }
}


void IconEditor::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    if(zoom >= 3)
    {
        painter.setPen(palette().foreground().color());
        for(int i = 0;i <= image.width(); ++i)
        {
            painter.drawLine(zoom*i, 0, zoom*i, zoom * image.height());
        }

        for(int j = 0;j <= image.height(); j++)
        {
            painter.drawLine(0, zoom * j, zoom * image.width(), zoom * j);
        }
    }

    for(int i = 0;i < image.width(); ++i)
    {
        for(int j = 0;j <= image.height(); ++j)
        {
            QRect rect = pixelRect(i, j);
            if(!event->region().intersected(rect).isEmpty())
            {
                QColor color = QColor::fromRgba(image.pixel(i,j));
                if(color.alpha() < 255)
                {
                    painter.fillRect(rect, Qt::white);
                }

                painter.fillRect(rect, color);
            }
        }
    }
}



QRect IconEditor::pixelRect(int i, int j) const
{
    if(zoom > 3)
    {
        return QRect(zoom * i + 1, zoom * j + 1, zoom - 1, zoom - 1);
    }
    else
    {
        return QRect(zoom * i, zoom * j, zoom, zoom);
    }
}


void IconEditor::mousePressEvent(QMouseEvent* event)
{
    if(event->button()  == Qt::LeftButton)
    {
        SetImagePixel(event->pos(), true);
    }
    else if(event->button() == Qt::RightButton)
    {
        SetImagePixel(event->pos(), false);
    }
    m_origin = event->pos();
    m_rectBand = new QRubberBand(QRubberBand::Rectangle, this);
    if(!m_rectBand)
    {
    }
    m_rectBand->setGeometry(QRect(m_origin,QSize()));
    m_rectBand->show();
}


void IconEditor::mouseMoveEvent(QMouseEvent* event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        SetImagePixel(event->pos(), true);
    }
    else if(event->buttons() & Qt::RightButton)
    {
        SetImagePixel(event->pos(), false);
    }

    m_rectBand->setGeometry(QRect(m_origin, event->pos()).normalized());

}

void IconEditor::mouseReleaseEvent(QMouseEvent* event)
{
    m_rectBand->hide();
}

void IconEditor::SetImagePixel(const QPoint& pos, bool opaque)
{
    int i = pos.x() / zoom;
    int j = pos.y() / zoom;
    if(image.rect().contains(i,j))
    {
        if(opaque)
        {
            image.setPixel(i, j, penColor().rgba());
        }
        else
        {
            image.setPixel(i, j, qRgba(0, 0, 0, 0));
        }
    }

    update(pixelRect(i, j));
}

