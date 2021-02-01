#include "mainwindow.h"
#include "ui_mainwindow.h"


#include "enemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <cmath>
#include <QMessageBox>

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
    hero->m_player->play();

    vectorEnemy = QVector<Enemy*>(1);

    for(int i = 0; i < vectorEnemy.size(); ++i)
    {
        vectorEnemy[i] = new Enemy();
        vectorEnemy[i]->setPos(qrand()%550+150, qrand()%550+150);
        vectorEnemy[i]->setDX(3);
        scene->addItem(vectorEnemy[i]);
    }


    timerFood = new QTimer();
    connect(timerFood, &QTimer::timeout, this, &MainWindow::slotCreateFood);
    timerFood->start(3000);
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
            auto items = scene->collidingItems(hero);
            for (const auto &it : items)
            {
                if (it->type() == 1)
                {
                    hero->setDX(-2);
                    hero->move();
                }
                else if(typeid (*it) == typeid (*food))
                {
                    slotDeleteFood(it);
                } else if(typeid (*it) == typeid (*vectorEnemy[0]))
                {
                    QMessageBox::warning(this,"Внимание","Вы проиграли");
                }
            }

            for(int i = 0; i < vectorEnemy.size(); ++i)
            {
                vectorEnemy[i]->setEnemyCurrentAnimation(1);
                vectorEnemy[i]->move();

                auto enemyItems = scene->collidingItems(vectorEnemy[i]);
                for(const auto &it : enemyItems)
                {
                    if (it->type() == 1)
                    {
                        vectorEnemy[i]->setDX(vectorEnemy[i]->getDX()*(-1));
                        vectorEnemy[i]->move();
                    }
                }
            }
        }
        if(keyEvent->key() == Qt::Key_A) //2
        {
            hero->setSY(192);
            hero->setDX(-2);
            hero->setDY(0);
            hero->setCurrentAnimationState(1);
            hero->move();

            auto items = scene->collidingItems(hero);
            for (const auto &it : items)
            {
                if (it->type() == 1)
                {
                    hero->setDX(+2);
                    hero->move();
                }
                else if(typeid (*it) == typeid (*food))
                {
                    slotDeleteFood(it);
                }  
            }

            for(int i = 0; i < vectorEnemy.size(); ++i)
            {
                vectorEnemy[i]->setEnemyCurrentAnimation(1);
                vectorEnemy[i]->move();

                auto enemyItems = scene->collidingItems(vectorEnemy[i]);
                for(const auto &it : enemyItems)
                {
                    if (it->type() == 1)
                    {
                        vectorEnemy[i]->setDX(vectorEnemy[i]->getDX()*(-1));
                        vectorEnemy[i]->move();
                    }
                }
            }
        }
        if(keyEvent->key() == Qt::Key_W) //3
        {
            hero->setSY(64);
            hero->setDX(0);
            hero->setDY(-2);
            hero->setCurrentAnimationState(3);
            hero->move();
            auto items = scene->collidingItems(hero);
            for (const auto &it : items)
            {
                if (it->type() == 1)
                {
                    hero->setDY(+2);
                    hero->move();
                }
                else if(typeid (*it) == typeid (*food))
                {
                    slotDeleteFood(it);
                }
            }

            for(int i = 0; i < vectorEnemy.size(); ++i)
            {
                vectorEnemy[i]->setEnemyCurrentAnimation(1);
                vectorEnemy[i]->move();

                auto enemyItems = scene->collidingItems(vectorEnemy[i]);
                for(const auto &it : enemyItems)
                {
                    if (it->type() == 1)
                    {
                        vectorEnemy[i]->setDX(vectorEnemy[i]->getDX()*(-1));
                        vectorEnemy[i]->move();
                    }
                }
            }
        }

        if(keyEvent->key() == Qt::Key_S) //4
        {
            hero->setSY(0);
            hero->setDX(0);
            hero->setDY(2);
            hero->setCurrentAnimationState(4);
            hero->move();
            auto items = scene->collidingItems(hero);
            for (const auto &it : items)
            {
                if (it->type() == 1)
                {
                    hero->setDY(-2);
                    hero->move();
                }
                else if(typeid (*it) == typeid (*food))
                {
                    slotDeleteFood(it);
                }
            }

            for(int i = 0; i < vectorEnemy.size(); ++i)
            {
                vectorEnemy[i]->setEnemyCurrentAnimation(1);
                vectorEnemy[i]->move();

                auto enemyItems = scene->collidingItems(vectorEnemy[i]);
                for(const auto &it : enemyItems)
                {
                    if (it->type() == 1)
                    {
                        vectorEnemy[i]->setDX(vectorEnemy[i]->getDX()*(-1));
                        vectorEnemy[i]->move();
                    }
                }
            }
        }
    }

    if(event->type() == QEvent::KeyRelease)
    {
        auto keyEvent = static_cast<QKeyEvent *>(event);
        if(keyEvent->key() == Qt::Key_D || keyEvent->key() == Qt::Key_A
                || keyEvent->key() == Qt::Key_S || keyEvent->key() == Qt::Key_W)
        {
            hero->stop();

            for(int i = 0; i < vectorEnemy.size(); ++i)
            vectorEnemy[i]->stop();
        }
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
    floor->setPos(32, 32);
    floor->itemType = "floor";
    scene->addItem(std::move(floor));

    floor = new Scene();
    floor->setSX(231.0);
    floor->setSY(33.0);
    floor->setPos(736, 32);
    floor->itemType = "floor";
    scene->addItem(std::move(floor));

    floor = new Scene();
    floor->setSX(33.0);
    floor->setSY(132.0);
    floor->setPos(32, 736);
    floor->itemType = "floor";
    scene->addItem(std::move(floor));

    floor = new Scene();
    floor->setSX(231.0);
    floor->setSY(132.0);
    floor->setPos(736, 736);
    floor->itemType = "floor";
    scene->addItem(std::move(floor));

//upWall
    for(int i = 64; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(66);
        floor->setSY(33.0);
        floor->setPos(i, 32);
        floor->itemType = "floor";
        scene->addItem(std::move(floor));
    }

    for(int i = 96; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(99);
        floor->setSY(33.0);
        floor->setPos(i, 32);
        floor->itemType = "floor";
        scene->addItem(std::move(floor));
    }

    for(int i = 128; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(132);
        floor->setSY(33.0);
        floor->setPos(i, 32);
        floor->itemType = "floor";
        scene->addItem(std::move(floor));
    }

    for(int i = 160; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(165);
        floor->setSY(33.0);
        floor->setPos(i, 32);
        floor->itemType = "floor";
        scene->addItem(std::move(floor));
    }

    for(int i = 192; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(198);
        floor->setSY(33.0);
        floor->setPos(i, 32);
        floor->itemType = "floor";
        scene->addItem(std::move(floor));
    }
//

//LeftWall
    for (int i = 64; i <736; i+=64)
    {
        floor = new Scene();
        floor->setSX(33);
        floor->setSY(66);
        floor->setPos(32, i);
        floor->itemType = "floor";
        scene->addItem(std::move(floor));
    }

    for (int i = 96; i <736; i+=64)
    {
        floor = new Scene();
        floor->setSX(33);
        floor->setSY(99);
        floor->setPos(32, i);
        floor->itemType = "floor";
        scene->addItem(std::move(floor));
    }
//

//RightWall
    for (int i = 64; i <736; i+=64)
    {
        floor = new Scene();
        floor->setSX(231);
        floor->setSY(66);
        floor->setPos(736, i);
        floor->itemType = "floor";
        scene->addItem(std::move(floor));
    }

    for (int i = 96; i <736; i+=64)
    {
        floor = new Scene();
        floor->setSX(231);
        floor->setSY(99);
        floor->setPos(736, i);
        floor->itemType = "floor";
        scene->addItem(std::move(floor));
    }
//DawnWall
    for(int i = 64; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(66);
        floor->setSY(132);
        floor->setPos(i, 736);
        floor->itemType = "floor";
        scene->addItem(std::move(floor));
    }

    for(int i = 96; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(99);
        floor->setSY(132);
        floor->setPos(i, 736);
        floor->itemType = "floor";
        scene->addItem(std::move(floor));
    }

    for(int i = 128; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(132);
        floor->setSY(132);
        floor->setPos(i, 736);
        floor->itemType = "floor";
        scene->addItem(std::move(floor));
    }

    for(int i = 160; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(165);
        floor->setSY(132);
        floor->setPos(i, 736);
        floor->itemType = "floor";
        scene->addItem(std::move(floor));
    }

    for(int i = 192; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(198);
        floor->setSY(132);
        floor->setPos(i, 736);
        floor->itemType = "floor";
        scene->addItem(std::move(floor));
    }
//

//UpCalums
    for(int i = 64; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(66);
        floor->setSY(66);
        floor->setPos(i, 64);
        floor->itemType = "floor";
        scene->addItem(std::move(floor));
    }
    for(int i = 96; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(99);
        floor->setSY(66);
        floor->setPos(i, 64);
        floor->itemType = "floor";
        scene->addItem(std::move(floor));
    }

    for(int i = 128; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(132);
        floor->setSY(66);
        floor->setPos(i, 64);
        floor->itemType = "floor";
        scene->addItem(std::move(floor));
    }

    for(int i = 160; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(165);
        floor->setSY(66);
        floor->setPos(i, 64);
        floor->itemType = "floor";
        scene->addItem(std::move(floor));
    }

    for(int i = 192; i < 736; i+=160)
    {
        floor = new Scene();
        floor->setSX(198);
        floor->setSY(66);
        floor->setPos(i, 64);
        floor->itemType = "floor";
        scene->addItem(std::move(floor));
    }
//

//Ground
    for(int i = 64; i < 736; i+=32)
        for(int j = 96; j < 736; j+=32)
    {
        floor = new Scene();
        floor->setSX(66);
        floor->setSY(198);
        floor->setPos(i, j);
        floor->itemType = "ground";
        scene->addItem(std::move(floor));
    }

    for(int i = 64; i < 736; i+=32)
    {
        floor = new Scene();
        floor->setSX(99);
        floor->setSY(198-33);
        floor->setPos(i, 736);
        floor->itemType = "ground";
        scene->addItem(std::move(floor));
    }
    for(int i = 64; i < 736; i+=32)
    {
        floor = new Scene();
        floor->setSX(99);
        floor->setSY(198-33);
        floor->setPos(i, 738);
        floor->itemType = "ground";
        scene->addItem(std::move(floor));
    }

    for(int i = 64; i < 736; i+=32)
    {
        floor = new Scene();
        floor->setSX(99);
        floor->setSY(198-33);
        floor->setPos(i, 740);
        floor->itemType = "ground";
        scene->addItem(std::move(floor));
    }

}

void MainWindow::slotCreateFood()
{
    double foodX = -1.0;
    double foodY = -1.0;
    food = new Food();
    do
    {
        foodX = qrand()%600+100;
        foodY = qrand()%600+100;
    }while(abs(foodX - hero->pos().x()) < 68 && abs(foodY - hero->pos().y()) < 68);

    food->setPos(foodX, foodY);
    scene->addItem(std::move(food));
    foods.append(food);
}

void MainWindow::slotDeleteFood(QGraphicsItem * item)
{
    foreach (QGraphicsItem *food, foods)
    {
            if(food == item)
            {
                scene->removeItem(food);
                foods.removeOne(item);
                delete food;
                ui->lcdNumber->display(++score);
            }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


