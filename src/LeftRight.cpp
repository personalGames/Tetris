/* 
 * File:   LeftRight.cpp
 * Author: dorian
 * 
 * Created on 13 de septiembre de 2014, 11:38
 */

#include "LeftRight.h"

LeftRight::LeftRight(TableBoard &board, Shape &shape, Direction direction)
: Command(), board(&board), shape(&shape) {
    this->direction = direction;
}

LeftRight::LeftRight(const LeftRight& orig) : Command(orig) {
    board = orig.board;
    shape = orig.shape;
    direction = orig.direction;
}

LeftRight::~LeftRight() {
}

void LeftRight::execute() {
    //if is alive and can fall
    if (isAlive() && shape->isCanFall()) {
        bool canMove = true;
        //set the value of the move depending of the direction
        int x = 1;
        if (getDirection() == Direction::LEFT) {
            x = -1;
        }
        //get the position of the squares if we move the shape
        vector<Square*> squares = shape->nextMove(x, 0);

        //for every square...
        for (int i = 0; i < shape->getNUMBER_OF_SQUARES() && canMove; i++) {
            //check the range
            if (squares[i]->getX() < 0
                    || squares[i]->getX() > board->getNumberColumns() - 1
                    || squares[i]->getY() < 0
                    || squares[i]->getY() > board->getNumberRows() - 1) {

                canMove = false;
            } else {
                //check if is filled by another square
                if (board->isFilled(shape, *(squares[i]))!= TypeSquare::NoSquare) {
                    canMove = false;
                }
            }
        }

        //if we can move, move it definitively
        if (canMove) {
            shape->move(x, 0);
            //update the board
            board->updateBoard();
        }
        
        std::for_each(squares.begin(), squares.end(), std::default_delete<Square>());

    }
    alive = false;
}
