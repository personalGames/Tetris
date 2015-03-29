/* 
 * File:   Bomb.h
 * Author: dorian
 *
 * Created on 8 de octubre de 2014, 17:19
 */

#ifndef BOMB_H
#define	BOMB_H

#include "Command.h"
#include "Shape.h"
#include "TableBoard.h"
#include "Timer.h"
#include "Score.h"
#include "SquareAnimation.h"
#include "Images.h"
#include "ImagesManager.h"

class Bomb : public Command{
public:
    Bomb(TableBoard &board, Shape &shape, Score& score);
    Bomb(TableBoard& board, Shape& shape, Score& score, int time);
    Bomb(const Bomb& orig);
    virtual ~Bomb();
    
    void execute();
    
private:
    /**
     * the board of the game
     */
    TableBoard* board;
    /**
     * the shape involucred
     */
    Shape* shape;
    /**
     * Timer to control the moment in which the shape will fall another
     * position in the board
     */
    Timer timer;
    /**
     * Time in milliseconds between one fall and another
     */
    Score* score;
    int millisecondsFalling;
    bool animation;
    AnimatedSprite* sprite;
    SpecialShape *shape2;
    
    vector<Square*> squaresExploded(int x, int y);
};

#endif	/* BOMB_H */

