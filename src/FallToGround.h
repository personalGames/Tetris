/* 
 * File:   FallToGround.h
 * Author: dorian
 *
 * Created on 14 de septiembre de 2014, 16:24
 * 
 * The action of a shape falling until it reach the end
 */

#ifndef FALLTOGROUND_H
#define	FALLTOGROUND_H

#include "Command.h"
#include "Shape.h"
#include "TableBoard.h"
#include "Timer.h"
#include <algorithm>
#include <memory>

class FallToGround : public Command{
public:
    /**
     * 
     * @param board the table of the game where the shape is falling
     * @param shape the shape
     */
    FallToGround(TableBoard &board, Shape &shape);
    FallToGround(const FallToGround& orig);
    virtual ~FallToGround();
    
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

};


#endif	/* FALLTOGROUND_H */

