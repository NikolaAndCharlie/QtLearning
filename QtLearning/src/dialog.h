#ifndef _INCONEDITE_
#define _INCONEDITE_

#include <QColor>
#include <QImage>
#include <QWidget>


class QRubberBand;
class QPoint;
class IconEditor:public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor penColor READ penColor WRITE setPenColor);
    Q_PROPERTY(QImage iconImage READ iconImage WRITE setIconImage);
    Q_PROPERTY(int zoomFactor READ zoomFactor WRITE setZoomFactor);

public:
    IconEditor(QWidget *parent = 0);
     
    void setPenColor(const QColor &newColor);
    QColor penColor() const { return curColor; }
    void setZoomFactor(int newZoom);
    int zoomFactor() const { return zoom; }
    void setIconImage(const QImage& newImage);
    QImage iconImage()  const { return image; }
    QSize sizeHint() const;
private:
    void SetImagePixel(const QPoint& pos, bool opaque);
    QRect pixelRect(int i, int j) const;
    QColor curColor;
    QImage image;
    int zoom;
    QRubberBand* m_rectBand;
    QPoint m_origin;
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent* event);

};






#endif
