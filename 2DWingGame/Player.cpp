#include "Player.h"
#include <QKeyEvent>
#include "Bullet.h"
#include <QGraphicsScene>
#include <Enemy.h>

#include <QDebug>
Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
  bulletsound = new QMediaPlayer();
  bulletsound->setMedia(QUrl("qrc:/sounds/grenade.mp3"));

  //set graphic
  setPixmap(QPixmap(":/images/plane2.png"));
  setPos(370,540);
}

void Player::keyPressEvent(QKeyEvent *event)
{
 if (event->key() == Qt::Key_Left){
     if (pos().x() > 0)
     setPos(x()-10,y());
 }
 else if (event->key() == Qt::Key_Right){
     if (pos().x() + 100 < 800)
     setPos(x()+10,y());
 }
// else if (event->key() == Qt::Key_Up){
//     setPos(x(),y()-10);
// }
// else if (event->key() == Qt::Key_Down){
//     setPos(x(),y()+10);
// }
 else if (event->key() == Qt::Key_Space){
     //create a bullet
     Bullet * bullet = new Bullet();
     bullet->setPos(x()+30,y()-25);
     scene()->addItem(bullet);

     //play bullet sound
     if (bulletsound->state() == QMediaPlayer::PlayingState){
         bulletsound->setPosition(0);
     }
     else if (bulletsound->state() == QMediaPlayer::StoppedState){
         bulletsound->play();
     }

 }
}

void Player::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
