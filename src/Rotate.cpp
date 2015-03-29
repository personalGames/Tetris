/* 
 * File:   Rotate.cpp
 * Author: dorian
 * 
 * Created on 20 de septiembre de 2014, 17:51
 */

#include "Rotate.h"

Rotate::Rotate(TableBoard &board, Shape &shape) : Command(), board(&board), shape(&shape) {
}

Rotate::Rotate(const Rotate& orig) : Command(orig) {
    board = orig.board;
    shape = orig.shape;
}

Rotate::~Rotate() {
}

void Rotate::execute() {
    //if is alive and can fall...
    if (isAlive() && shape->isCanFall()) {
        bool canMove = true;
        //get the result of rotating the shape (whitout really moving)
        vector<Square*> squares = shape->nextRotate();

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
            shape->rotate();
            //update the board
            board->updateBoard();
        }
        
        std::for_each(squares.begin(), squares.end(), std::default_delete<Square>());

    }
    alive = false;
}