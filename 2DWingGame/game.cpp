#include <QTimer>
#include <QGraphicsScene>
#include "Player.h"
#include <QGraphicsView>
#include "game.h"
#include <QMediaPlayer>
#include <QImage>
#include <QtCore>
#include <QTreeView>


Game::Game()
{
    //    MainWindow w;
    //    w.show();

        // create a scene
        QGraphicsScene * scene = new QGraphicsScene();
        //create background
        //scene->setBackgroundBrush(QBrush(QImage("qrc:/images/rot.png")));
        scene->setBackgroundBrush(Qt::green);

        // create rectangular item in the scene
        Player * player = new Player();
        //player->setRect(0,0,100,100);

        // add item to scene
        scene->addItem(player);

        //create a score
        score = new Score();
        scene->addItem(score);

        //create a health
        health = new Health();
        health->setPos(health->x(),health->y()+25);
        scene->addItem(health);


        //make rect focusable
        player->setFlag(QGraphicsItem::ItemIsFocusable);
        player->setFocus();



        // add a view
        QGraphicsView * view = new QGraphicsView(scene);



        //fix size of scene

        view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        //make view visible

       view->show();
       view->setFixedSize(800,600);
       scene->setSceneRect(0,0,800,600);

       //pos of player
       //player->setPos(view->width()/2,view->height() - player->rect().height());

       //spawn enemies every 2 secs
       QTimer * timer = new QTimer();
       QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
       timer->start(2000);

       //QMediaPlayer * music = new QMediaPlayer();
      // music->setMedia(QUrl("qrc:/sounds/war.mp3"));
      // music->play();
}
