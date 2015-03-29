/* 
 * File:   FallToGround.cpp
 * Author: dorian
 * 
 * Created on 14 de septiembre de 2014, 16:24
 */

#include "FallToGround.h"

FallToGround::FallToGround(TableBoard& board, Shape& shape) : Command(), board(&board), shape(&shape) {
}

FallToGround::FallToGround(const FallToGround& orig) : Command(orig) {
    board=orig.board;
    shape=orig.shape;
}

FallToGround::~FallToGround() {
}

void FallToGround::execute() {
    //while the command
    while (isAlive()) {
        bool canMove = true;
        //get the position of the squares if we move the shape
        vector<Square*> squares = shape->nextMove(0, 1);

        //if the shape can fall...
        if (shape->isCanFall()) {
            //for every square...
            for (int i = 0; i < shape->getNUMBER_OF_SQUARES() && canMove; i++) {
                //check the range, if is still inside the board
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
                shape->move(0, 1);
                //update the board with the new position
                board->updateBoard();
            }else{
                shape->setCanFall(false);
            }
            std::for_each(squares.begin(), squares.end(), std::default_delete<Square>());
        } else {
            //if the shape can't fall, is dead
            alive = false;
        }

    }
}