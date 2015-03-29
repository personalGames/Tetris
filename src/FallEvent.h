/* 
 * File:   FallEvent.h
 * Author: dorian
 *
 * Created on 21 de septiembre de 2014, 12:11
 * 
 * The action of a shape falling once
 */

#ifndef FALLEVENT_H
#define	FALLEVENT_H

#include "Command.h"
#include "Shape.h"
#include "TableBoard.h"
#include <algorithm>
#include <memory>

class FallEvent : public Command{
public:
    /**
     * 
     * @param board the table of the game where the shape is falling
     * @param shape the shape
     */
    FallEvent(TableBoard &board, Shape &shape);
    FallEvent(const FallEvent& orig);
    virtual ~FallEvent();
    
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

#endif	/* FALLEVENT_H */

