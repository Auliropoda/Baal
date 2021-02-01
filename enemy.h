#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

const int ENEMYSPEED = 1;
class Enemy : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Enemy(QObject *parent = 0);
    virtual ~Enemy(){};

    void move();
    void stop();

    void setEnemyCurrentAnimation(int i);

    void setDX(int i);
    void setDY(int i);
    void setSX(int i);
    void setSY(int i);
    int getDX();

signals:

private slots:
    void nextFrame();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QPixmap *enemyImage;
    QTimer *enemyTimer;

    int enemyFrame;
    int enemyCurrentAnimation;

    int sY;
    int dX;
    int dY;
    int sX;
};

#endif // ENEMY_H

