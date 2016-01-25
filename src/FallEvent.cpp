/* 
 * File:   FallEvent.cpp
 * Author: dorian
 * 
 * Created on 21 de septiembre de 2014, 12:11
 */

#include "FallEvent.h"

FallEvent::FallEvent(TableBoard& board, Shape& shape) 
                : Command(), board(&board), shape(&shape) {
}

FallEvent::FallEvent(const FallEvent& orig) {
    board = orig.board;
    shape = orig.shape;
}

FallEvent::~FallEvent() {
    
}

void FallEvent::execute(){
    //if is alive and the shape can fall
    if (isAlive() && shape->isCanFall()) {
        bool canMove = true;
        //get the position of the squares if we move the shape
        vector<Square*> squares = shape->nextMove(0, 1);

        //for every square...
        int number = shape->getNUMBER_OF_SQUARES();
        for (int i = 0; i < number && canMove; i++) {
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
        }
        
        std::for_each(squares.begin(), squares.end(), std::default_delete<Square>());

    }
    //even if we move or not the shape, this command execute once, so
    //always is not alive at the end
    alive = false;
}

