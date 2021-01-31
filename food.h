#ifndef FOOD_H
#define FOOD_H


#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QTimer>

class Food : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Food(QObject *parent = 0);
    virtual ~Food(){};

signals:

public slots:


protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QPixmap *foodImage;
};

#endif // FOOD_H
