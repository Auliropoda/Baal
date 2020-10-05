#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>


class Player : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = 0);

private slots:
    void nextFrame();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    QRectF boundingRect() const;

private:
    QTimer *playerTimer;      // Таймер для пролистывания изображения в QPixmap
    QPixmap *playerImage;   // В данный объект QPixamp будет помещён спрайт
    int currentFrame;   // Координата X, с которой начинает очередной кадр спрайта
};

#endif // PLAYER_H
