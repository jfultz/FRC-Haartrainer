#include "ImageScene.h"
#include <QPainter>

ImageScene::ImageScene(QObject* parent) :
    QGraphicsScene(parent)
{

}

void ImageScene::drawBackground(QPainter * painter, const QRectF & rect)
{
    if (m_image.isNull())
    {
        QBrush brush(QColor("white"));
        painter->setBrush((brush));
        painter->drawRect(rect);
    }
    else
        painter->drawImage(rect, m_image);
}
