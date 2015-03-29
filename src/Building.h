/* 
 * File:   Building.h
 * Author: dorian
 *
 * Created on 26 de octubre de 2014, 18:11
 */

#ifndef BUILDING_H
#define	BUILDING_H

#include "Command.h"
#include "Shape.h"
#include "TableBoard.h"
#include "Timer.h"
#include "Score.h"
#include "SquareExplosion.h"
#include "ImagesManager.h"
#include "EventManager.h"

class Building :public Command, ResponseEvents {
public:
    Building(TableBoard &board, Score& score);
    Building(const Building& orig);
    virtual ~Building();
    
    void execute();
    void response(TypeEvents event, std::unordered_map<std::string, int> &arguments);
    
private:
    /**
     * the board of the game
     */
    TableBoard* board;
    /**
     * Timer to control the moment in which the shape will fall another
     * position in the board
     */
    Timer timer;
    Score* score;
    int millisecondsFalling;
    
    void moveSquares();
    
    void createSquares();
};

#endif	/* BUILDING_H */

