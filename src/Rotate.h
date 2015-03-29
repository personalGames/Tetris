/* 
 * File:   Rotate.h
 * Author: dorian
 *
 * Created on 20 de septiembre de 2014, 17:51
 * 
 * The action of a shape rotating once
 */

#ifndef ROTATE_H
#define	ROTATE_H

#include "Command.h"
#include "Shape.h"
#include "TableBoard.h"
#include <algorithm>
#include <memory>

class Rotate :public Command {
public:
    Rotate(TableBoard &board, Shape &shape);
    Rotate(const Rotate& orig);
    virtual ~Rotate();
    
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

#endif	/* ROTATE_H */

