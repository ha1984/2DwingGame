#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> //random number function: rand() = really large int
#include <game.h>

#include <qDebug>

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // set random position
    int random_number = rand() % 700;
    setPos(random_number,0);
    // drew the rect
    //setRect(0,0,100,100);
    setPixmap(QPixmap(":/images/plane2.png"));
    setTransformOriginPoint(30,25);
    setRotation(180);

    // connect timer with bullet movement
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    // move bullet every 50ms
    timer->start(50);
}

void Enemy::move()
{
    // move enemy down
    setPos(x(),y()+5);
//    if (pos().y() + rect().height() > 700){
    if (pos().y() > 700){
        scene()->removeItem(this);
        game->health->decrease();
        delete this;

       //qDebug() << "enemy deleted";
    }
}
