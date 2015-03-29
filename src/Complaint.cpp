/* 
 * File:   Complaint.cpp
 * Author: dorian
 * 
 * Created on 8 de diciembre de 2014, 23:08
 */

#include "Complaint.h"

Complaint::Complaint(TableBoard& board, Shape& shape): Complaint(board,shape,1000) {
}

Complaint::Complaint(TableBoard& board, Shape& shape, int time) : Command(), board(&board), shape(&shape) {
    //start the timer
    timer.start();
    //set the initial time between fallings
    millisecondsFalling = time;
}

Complaint::Complaint(const Complaint& orig) {
    timer=orig.timer;
    millisecondsFalling=orig.millisecondsFalling;
    board=orig.board;
    shape=orig.shape;
}

Complaint::~Complaint() {
}

void Complaint::execute() {
    //if still alive and is time of another falling...
    if (isAlive() && timer.delta() >= millisecondsFalling) {
        //restart the timer
        timer.reset();
        bool canMove = true;
        
        //if the shape can fall...
        if (shape->isCanFall()) {
            //get the position of the squares if we move the shape
            vector<Square*> squares = shape->nextMove(0, 1);
            int number=shape->getNUMBER_OF_SQUARES();
            //for every square...
            for (int i = 0; i < number && canMove; i++) {
                //check the range, if is still inside the board
                if (squares[i]->getX() < 0
                        || squares[i]->getX() > board->getNumberColumns() - 1
                        || squares[i]->getY() < 0
                        || squares[i]->getY() > board->getNumberRows() - 1) {
                    
                    canMove = false;

                } else {
                    //check if is filled by another square
                    if (board->isFilled(shape, *(squares[i]))!=TypeSquare::NoSquare) {
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
                //if we can't move the shape, it can fall anymore
                shape->setCanFall(false);
                //set the event for the building
                std::unordered_map<std::string, int> *arguments=new std::unordered_map<std::string, int>();
                
                arguments->insert (std::make_pair<std::string,int>("time",10000));
                EventManager::getInstance().event(TypeEvents::stopBuilding, arguments);
            }
            //delete the squares used
            std::for_each(squares.begin(), squares.end(), std::default_delete<Square>());
        } else {
            //if the shape can't fall, the command is not alive anymore
            alive = false;
        }

    }
}