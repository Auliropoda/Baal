#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->installEventFilter(this);
    ui->setupUi(this);
    //this->resize(800, 800);

    scene = new QGraphicsScene(0, 0, 800, 800, this);

    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(scene);

    //scene->addLine(0,300,600,300,QPen(Qt::black));   // Добавляем горизонтальную линию через центр
    //scene->addLine(300,0,300,600,QPen(Qt::black));   // Добавляем вертикальную линию через центр

    setRim();
    setWall();


    hero = new Player();
    scene->addItem(hero);
    hero->setPos(300, 300);
}

bool MainWindow::eventFilter(QObject *object, QEvent* event)
{
    if(event->type() == QEvent::KeyPress)
    {
        auto keyEvent = static_cast<QKeyEvent *>(event);
        if(keyEvent->key() == Qt::Key_D) //1
        {
            hero->setSY(128);
            hero->setDX(2);
            hero->setDY(0);
            hero->setCurrentAnimationState(2);
            hero->move();
            if(!scene->collidingItems(hero).isEmpty())
            {
                        hero->setDX(-2);
                        hero->move();
            }
        }
        if(keyEvent->key() == Qt::Key_A) //2
        {
            hero->setSY(192);
            hero->setDX(-2);
            hero->setDY(0);
            hero->setCurrentAnimationState(1);
            hero->move();

            if(!scene->collidingItems(hero).isEmpty())
            {
                        hero->setDX(+2);
                        hero->move();
            }
        }
        if(keyEvent->key() == Qt::Key_W) //3
        {
            hero->setSY(64);
            hero->setDX(0);
            hero->setDY(-2);
            hero->setCurrentAnimationState(3);
            hero->move();

            if(!scene->collidingItems(hero).isEmpty())
            {
                        hero->setDY(+2);
                        hero->move();
            }
        }
        if(keyEvent->key() == Qt::Key_S) //4
        {
            hero->setSY(0);
            hero->setDX(0);
            hero->setDY(2);
            hero->setCurrentAnimationState(4);
            hero->move();
            if(!scene->collidingItems(hero).isEmpty())
            {
                        hero->setDY(-2);
                        hero->move();
            }
        }
    }

    if(event->type() == QEvent::KeyRelease)
    {
        auto keyEvent = static_cast<QKeyEvent *>(event);
        if(keyEvent->key() == Qt::Key_D || keyEvent->key() == Qt::Key_A
                || keyEvent->key() == Qt::Key_S || keyEvent->key() == Qt::Key_W)
            hero->stop();
    }
}

void MainWindow::setRim()
{

    for (int i = 0; i < 800; i+=32)
    {
        floor = new Scene();
        scene->addItem(floor);
        floor->setPos(i, 0);
    }

    for (int j = 32; j < 800; j+=32)
    {
    floor = new Scene();
    scene->addItem(floor);
    floor->setPos(0, j);
    }

    for (int i = 32; i < 800; i+=32)
    {
    floor = new Scene();
    scene->addItem(floor);
    floor->setPos(i,800-32);
    }

    for (int j = 32; j < 800; j+=32)
    {
        floor = new Scene();
        scene->addItem(floor);
        floor->setPos(768, j);
    }
}

void MainWindow::setWall()
{
    floor = new Scene();
    floor->setSX(33.0);
    floor->setSY(33.0);
    scene->addItem(floor);
    floor->setPos(32, 32);

    floor = new Scene();
    floor->setSX(231.0);
    floor->setSY(33.0);
    scene->addItem(floor);
    floor->setPos(736, 32);

    floor = new Scene();
    floor->setSX(33.0);
    floor->setSY(132.0);
    scene->addItem(floor);
    floor->setPos(32, 736);

    floor = new Scene();
    floor->setSX(231.0);
    floor->setSY(132.0);
    scene->addItem(floor);
    floor->setPos(736, 736);

//upWall
    for(int i = 64; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(66);
        floor->setSY(33.0);
        scene->addItem(floor);
        floor->setPos(i, 32);
    }

    for(int i = 96; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(99);
        floor->setSY(33.0);
        scene->addItem(floor);
        floor->setPos(i, 32);
    }

    for(int i = 128; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(132);
        floor->setSY(33.0);
        scene->addItem(floor);
        floor->setPos(i, 32);
    }

    for(int i = 160; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(165);
        floor->setSY(33.0);
        scene->addItem(floor);
        floor->setPos(i, 32);
    }

    for(int i = 192; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(198);
        floor->setSY(33.0);
        scene->addItem(floor);
        floor->setPos(i, 32);
    }
//

//LeftWall
    for (int i = 64; i <736; i+=64)
    {
        floor = new Scene();
        floor->setSX(33);
        floor->setSY(66);
        scene->addItem(floor);
        floor->setPos(32, i);
    }

    for (int i = 96; i <736; i+=64)
    {
        floor = new Scene();
        floor->setSX(33);
        floor->setSY(99);
        scene->addItem(floor);
        floor->setPos(32, i);
    }
//

//RightWall
    for (int i = 64; i <736; i+=64)
    {
        floor = new Scene();
        floor->setSX(231);
        floor->setSY(66);
        scene->addItem(floor);
        floor->setPos(736, i);
    }

    for (int i = 96; i <736; i+=64)
    {
        floor = new Scene();
        floor->setSX(231);
        floor->setSY(99);
        scene->addItem(floor);
        floor->setPos(736, i);
    }
//DawnWall
    for(int i = 64; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(66);
        floor->setSY(132);
        scene->addItem(floor);
        floor->setPos(i, 736);
    }

    for(int i = 96; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(99);
        floor->setSY(132);
        scene->addItem(floor);
        floor->setPos(i, 736);
    }

    for(int i = 128; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(132);
        floor->setSY(132);
        scene->addItem(floor);
        floor->setPos(i, 736);
    }

    for(int i = 160; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(165);
        floor->setSY(132);
        scene->addItem(floor);
        floor->setPos(i, 736);
    }

    for(int i = 192; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(198);
        floor->setSY(132);
        scene->addItem(floor);
        floor->setPos(i, 736);
    }
//

//UpCalums
    for(int i = 64; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(66);
        floor->setSY(66);
        scene->addItem(floor);
        floor->setPos(i, 64);
    }
    for(int i = 96; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(99);
        floor->setSY(66);
        scene->addItem(floor);
        floor->setPos(i, 64);
    }

    for(int i = 128; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(132);
        floor->setSY(66);
        scene->addItem(floor);
        floor->setPos(i, 64);
    }

    for(int i = 160; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(165);
        floor->setSY(66);
        scene->addItem(floor);
        floor->setPos(i, 64);
    }

    for(int i = 192; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(198);
        floor->setSY(66);
        scene->addItem(floor);
        floor->setPos(i, 64);
    }
//

//Ground
    /*for(int i = 64; i < 736; i+=32)
        for(int j = 96; j < 736; j+=32)
    {
        floor = new Scene();
        floor->setSX(66);
        floor->setSY(198);
        scene->addItem(floor);
        floor->setPos(i, j);
    }

    /*for(int i = 64; i < 736; i+=32)
    {
        floor = new Scene();
        floor->setSX(99);
        floor->setSY(198-33);
        scene->addItem(floor);
        floor->setPos(i, 736);
    }
    for(int i = 64; i < 736; i+=32)
    {
        floor = new Scene();
        floor->setSX(99);
        floor->setSY(198-33);
        scene->addItem(floor);
        floor->setPos(i, 738);
    }

    for(int i = 64; i < 736; i+=32)
    {
        floor = new Scene();
        floor->setSX(99);
        floor->setSY(198-33);
        scene->addItem(floor);
        floor->setPos(i, 740);
    }*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

