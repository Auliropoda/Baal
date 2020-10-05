#include "player.h"



Player::Player(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    currentFrame = 0;
    playerImage = new QPixmap(":hero/player/golem_blind.png");

    playerTimer = new QTimer();
    connect(playerTimer, &QTimer::timeout, this, &Player::nextFrame);
    playerTimer->start(65);
}

QRectF Player::boundingRect() const
{
    return QRectF(0, 0, 720, 482);
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
    painter->drawPixmap(0, 0, *playerImage, currentFrame, 0, 720, 482);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Player::nextFrame()
{

    currentFrame += 722;
    if (currentFrame >=  8664)
        currentFrame = 0;
    this->update(0, 0, 720, 482);
}
