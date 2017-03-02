#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"

#include <qDebug>

extern Game * game; //external global object game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // drew the bullet
    //setRect(0,-51,10,50);
   QPixmap mypix (":/images/small.png");
   setPixmap(mypix);



    // connect timer with bullet movement
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    // move bullet every 50ms
    timer->start(50);
}

void Bullet::move()
{
    // if bullet collides with item, delete it
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i=0; i < colliding_items.size(); ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //increase score
            game->score->increase();
            //delete memory
            delete colliding_items[i];
            delete this;
            return;
    }
    // move bullet up
    setPos(x(),y()-10);
    // if (pos().y() + rect().height() < 0){
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;

       // qDebug() << "bullet deleted";
    }
}
