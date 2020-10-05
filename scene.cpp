#include "scene.h"

#include <QPainter>
#include <QDebug>

Scene::Scene(QObject *parent)
    : QObject(parent), QGraphicsItem()
{
    sceneImage = new QPixmap("D:/Game/Baal/panel_brown.png");
}

QRectF Scene::boundingRect() const
{
    return QRectF(-50, -50, 100, 100);
}

void Scene::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-50,-50, *sceneImage);
}
