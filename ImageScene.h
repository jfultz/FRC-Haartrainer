#ifndef IMAGESCENE_H
#define IMAGESCENE_H

#include <QGraphicsScene>
#include <QImage>

class ImageScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit ImageScene(QObject* parent = 0);
    virtual ~ImageScene() { };

    virtual void drawBackground(QPainter * painter, const QRectF & rect);

    void setImage(QImage& image) { m_image = image; update(); };

private:
    QImage m_image;
    QRect m_trainingRectangle;
};

#endif // IMAGESCENE_H
