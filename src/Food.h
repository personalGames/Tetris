/* 
 * File:   Food.h
 * Author: dorian
 *
 * Created on 8 de diciembre de 2014, 23:50
 */

#ifndef FOOD_H
#define	FOOD_H

#include "Command.h"
#include "Shape.h"
#include "TableBoard.h"
#include "Timer.h"
#include "EventManager.h"
#include <unordered_map>
#include "TypeEvents.h"

class Food : public Command{
public:
    Food(TableBoard &board, Shape &shape);
    Food(TableBoard &board, Shape &shape, int time);
    Food(const Food& orig);
    virtual ~Food();
    
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
    int millisecondsFalling;
};

#endif	/* FOOD_H */

