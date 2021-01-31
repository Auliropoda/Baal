#include "player.h"

#include <QGraphicsItem>

Player::Player(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    currentFrame = 0;
    currentAnimationState = 0;
    collide = false;
    dX = 0;
    dY = 0;
    sY = 0;

    playerImage = new QPixmap(":hero/player/Baal_Move.png");

    playerTimer = new QTimer();
    connect(playerTimer, &QTimer::timeout, this, &Player::nextFrame);
    playerTimer->start(120);
}

QRectF Player::boundingRect() const
{
    return QRectF(0, 0, 64, 64);
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    /* В отрисовщике графического объекта отрисовываем спрайт
     * Разберём все параметры данной функции
     * Первых два аргумента - это координат X и Y куда помещается QPixmap
     * Третий аргумент - это указатель на QPixmap
     * 4 и 5 аргументы - Координаты в В изображении QPixmap, откуда будет отображаться изображение
     * Задавая координату X с помощью перемнной currentFrame мы будем как бы передвигать камеру
     * по спрайту
     * и последние два аргумента - это ширина и высота отображаем части изображение, то есть кадра
     * */
    if(currentAnimationState != 0)
    painter->drawPixmap(0, 0, 64, 64, *playerImage, currentFrame, sY, 64, 64);
    else
    {
        currentFrame  = 0;
        painter->drawPixmap(0, 0, 64, 64, *playerImage, currentFrame, sY, 64, 64);
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Player::nextFrame()
{

    currentFrame += 64;
    if (currentFrame >= 256)
        currentFrame = 0;
    this->update(0, 0, 64, 64);
}

void Player::setCurrentAnimationState(int i)
{
    currentAnimationState = i;
}

void Player::setDX(int i)
{
    dX = i;
}

void Player::setSY(int i)
{
    sY = i;
}

void Player::setSX(int i)
{
    sX = i;
}

void Player::setDY(int i)
{
    dY = i;
}

void Player::move()
{
     setPos(pos().x() + dX, pos().y()+ dY);
}

void Player::stop()
{
    currentAnimationState = 0;
}

QPainterPath Player::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}


