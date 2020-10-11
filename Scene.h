#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QGraphicsItem>

class Scene : public QObject, public QGraphicsItem
{
public:
    Scene(QObject *parent = nullptr);
    void setSX(float i = 0);
    void setSY(float i = 0);

private slots:

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;

    QPixmap *sceneImage;
    QGraphicsScene *sceneOne;
    int currentFrame;
    float sY;
    float sX;
};

#endif // SCENE_H
