/* 
 * File:   Rotate.cpp
 * Author: dorian
 * 
 * Created on 20 de septiembre de 2014, 17:51
 */

#include "Rotate.h"

Rotate::Rotate(TableBoard &board, Shape &shape) : Command(), board(&board), shape(&shape) {
    if(notRotatedBuffer.loadFromFile("resources/audio/SFX_PieceRotateFail.ogg")){
        notRotatedSound.setVolume(35);
        notRotatedSound.setBuffer(notRotatedBuffer);
    }
    if(rotatedBuffer.loadFromFile("resources/audio/SFX_PieceRotateLR.ogg")){
        rotatedSound.setVolume(35);
        rotatedSound.setBuffer(rotatedBuffer);
    }
}

Rotate::Rotate(const Rotate& orig) : Command(orig) {
    board = orig.board;
    shape = orig.shape;
}

Rotate::~Rotate() {
}

void Rotate::execute() {
    //if is alive and can fall...
    if (alive && shape->isCanFall()) {
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
            rotatedSound.play();
            shape->rotate();
            //update the board
            board->updateBoard();
        }else{
            notRotatedSound.play();
        }
        
        std::for_each(squares.begin(), squares.end(), std::default_delete<Square>());

    }
    alive = false;
}

bool Rotate::isAlive() const {
    return alive || rotatedSound.getStatus()==sf::Sound::Status::Playing || notRotatedSound.getStatus()==sf::Sound::Status::Playing;
}