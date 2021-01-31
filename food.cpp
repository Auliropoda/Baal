#include "food.h"
#include <QGraphicsItem>
#include <QObject>
#include <mainwindow.h>

Food::Food(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    foodImage = new QPixmap(":hero/player/food.png");
}

QRectF Food::boundingRect() const
{
    return QRectF(0, 0, 16, 16);
}

void Food::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
     painter->drawPixmap(0, 0, 16, 16, *foodImage, 0, 0, 16, 16);
}


