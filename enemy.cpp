#include "enemy.h"

#include <QGraphicsItem>

Enemy::Enemy(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    enemyFrame = 0;
    enemyCurrentAnimation = 0;

    enemyImage = new QPixmap(":hero/player/enemy.png");

    enemyTimer = new QTimer();
    connect(enemyTimer, &QTimer::timeout, this, &Enemy::nextFrame);
    enemyTimer->start(120);
}

QRectF Enemy::boundingRect() const
{
    return QRectF(0, 0, 96, 128);
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        if(enemyCurrentAnimation != 0)
        painter->drawPixmap(0, 0, 96, 128, *enemyImage, enemyFrame, 512, 96, 128);
        else
        {
            enemyFrame = 0;
            painter->drawPixmap(0, 0, 96, 128, *enemyImage, enemyFrame, 512, 96, 128);
        }

        Q_UNUSED(option);
        Q_UNUSED(widget);
}

void Enemy::nextFrame()
{
    enemyFrame += 96;
    if (enemyFrame >= 768)
        enemyFrame = 0;
    this->update(0, 0, 96, 128);
}

void Enemy::move()
{
    setPos(pos().x() + dX, pos().y()+ dY);
}

void Enemy::stop()
{
    enemyCurrentAnimation = 0;
}

void Enemy::setDX(int i)
{
    dX = i;
}
void Enemy::setDY(int i)
{
    dY = i;
}
void Enemy::setSX(int i)
{
    sX = i;
}
void Enemy::setSY(int i)
{
    sY = i;
}

void Enemy::setEnemyCurrentAnimation(int i)
{
    enemyCurrentAnimation = i;
}

int Enemy::getDX()
{
    return dX;
}
