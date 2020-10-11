#include "Scene.h"

#include <QPainter>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsItem>

Scene::Scene(QObject *parent)
    : QObject(parent), QGraphicsItem()
{
    sceneImage = new QPixmap(":hero/player/Back_Ground.png");
    sX = 0.0;
    sY = 0.0;
}

QRectF Scene::boundingRect() const
{
    return QRectF(0, 0, 32.0, 32.0);
}

void Scene::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0.0, 0.0, 32.0, 32.0, *sceneImage, sX, sY, 32.0, 32.0);
}

void Scene::setSX(float i)
{
    sX = i;
}

void Scene::setSY(float i)
{
    sY = i;
}


