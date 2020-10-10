#include "player.h"

#include <QGraphicsItem>

Player::Player(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    currentFrame = 0;
    dX = 0;
    playerImage.push_back(QPixmap(":hero/player/Baal.png"));
    playerImage.push_back(QPixmap(":hero/player/Baal_Walk.png"));
    playerImage.push_back(QPixmap(":hero/player/Baal_Walk_Left.png"));
    playerImage.push_back(QPixmap(":hero/player/Baal_Move.png"));

    currentAnimationState = 3;

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
    painter->drawPixmap(0, 0, 64, 64, playerImage[currentAnimationState], currentFrame, sY, 64, 64);

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

