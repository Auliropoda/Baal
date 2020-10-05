#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QGraphicsItem>

class Scene : public QObject, public QGraphicsItem
{
public:
    Scene(QObject *parent = nullptr);

private slots:

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;

    QPixmap *sceneImage;
    int currentFrame;
};

#endif // SCENE_H
