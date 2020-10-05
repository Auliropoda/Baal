#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(800, 800);

    scene = new QGraphicsScene(0, 0, 600, 600, this);

    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(scene);

    //scene->addLine(0,300,600,300,QPen(Qt::black));   // Добавляем горизонтальную линию через центр
    //scene->addLine(300,0,300,600,QPen(Qt::black));   // Добавляем вертикальную линию через центр

    for (int i = 50; i < 650; i+=100)
        for(int j = 50; j < 650; j+=100)
    {
    floor = new Scene();
    scene->addItem(floor);
    floor->setPos(i, j);
    }

    hero = new Player();
    scene->addItem(hero);
    hero->setPos(-50, 0);
}

void MainWindow::keyReleaseEvent(QKeyEvent *apEvent)
{

}

MainWindow::~MainWindow()
{
    delete ui;
}

