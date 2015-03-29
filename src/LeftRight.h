/* 
 * File:   LeftRight.h
 * Author: dorian
 *
 * Created on 13 de septiembre de 2014, 11:38
 * 
 * The action of a shape moving one position to left or right
 */

#ifndef LEFTRIGHT_H
#define	LEFTRIGHT_H

#include "Command.h"
#include "Shape.h"
#include "TableBoard.h"
#include <memory>
#include <algorithm>

/**
 * Enumeration of the horizontal direction to move
 */
enum class Direction {LEFT, RIGHT}; 

class LeftRight : public Command{
public:
    /**
     * 
     * @param board the table of the game where the shape is falling
     * @param shape the shape
     * @param direction the horizontal direction to move
     */
    LeftRight(TableBoard &board, Shape &shape, Direction direction);
    LeftRight(const LeftRight& orig);
    virtual ~LeftRight();
    
    void execute();
    
    /**
     * Get the horizontal direction of the move
     * @return 
     */
    inline Direction getDirection(){
        return direction;
    }
    
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
     * direction of the move
     */
    Direction direction;

};

#endif	/* LEFTRIGHT_H */

