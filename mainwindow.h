#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>

#include "Scene.h"
#include "player.h"
#include "food.h"
#include "enemy.h"

const int MAXSCORE = 5;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

     bool eventFilter(QObject *object, QEvent* event) override;
     void setRim();
     void setWall();

public slots:
     void slotDeleteFood(QGraphicsItem * item);
     void slotCreateFood();

private:
    QGraphicsScene *scene;
    Scene *floor;
    Scene *ground;
    Player *hero;
    Food *food = new Food();

    QVector<Enemy*> vectorEnemy;

    QTimer *timerFood;

    QList<QGraphicsItem *> foods;
    int score = 0;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
