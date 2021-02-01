#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

#include <QMediaPlayer>
#include <QMediaPlaylist>

class Player : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = 0);
    void setCurrentAnimationState(int i);

    void move();
    void stop();

    void setDX(int i);
    void setDY(int i);
    void setSX(int i);
    void setSY(int i);

    bool collide;

    QMediaPlayer * m_player;
    QMediaPlaylist * m_playlist;

private slots:
    void nextFrame();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    QRectF boundingRect() const;
    QPainterPath shape() const;

private:
    QTimer *playerTimer;      // Таймер для пролистывания изображения в QPixmap
    QPixmap *playerImage;   // В данный объект QPixamp будет помещён спрайт
    int currentFrame;   // Координата X, с которой начинает очередной кадр спрайта
    /* 0 - stop; 1 - moveLeft; 2 - moveRight; 3 - moveUp; 4 - move Down */
    int currentAnimationState;
    int dX;
    int dY;
    int sY;
    int sX;

signals:
    void signalCheckItem(QGraphicsItem *item);
};

#endif // PLAYER_H
