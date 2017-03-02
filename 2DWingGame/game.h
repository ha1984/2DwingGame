#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include "Player.h"
#include "Score.h"
#include "Health.h"

class Game: public QGraphicsScene,public QGraphicsView {
public:
    Game();

    QGraphicsScene * scene;
    Player player;
    Score * score;
    Health * health;
};

#endif // GAME_H
