#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsScene>
#include <QGraphicsView>

#include "Scene.h"
#include "player.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void keyReleaseEvent(QKeyEvent*)override;

private:

    QGraphicsScene *scene;
    Scene *floor;
    Player *hero;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H