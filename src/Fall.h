/* 
 * File:   Fall.h
 * Author: dorian
 *
 * Created on 31 de agosto de 2014, 21:10
 * 
 * The action of a shape falling
 */

#ifndef FALL_H
#define	FALL_H

#include "Command.h"
#include "Shape.h"
#include "TableBoard.h"
#include "Timer.h"
#include <algorithm>
#include <memory>

class Fall : public Command{
public:
    /**
     * 
     * @param board the table of the game where the shape is falling
     * @param shape the shape
     */
    Fall(TableBoard &board, Shape &shape);
    Fall(TableBoard& board, Shape& shape, int time);
    Fall(const Fall& orig);
    virtual ~Fall();
    
    /**
     * Overwriting the virtual method
     */
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

#endif	/* FALL_H */

