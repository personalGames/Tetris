/*
 * File:   Square.cpp
 * Author: dorian
 *
 * Created on 15 de agosto de 2014, 15:22
 */

#include "Square.h"
#include <iostream>

Square::Square() {
    x = 0;
    y = 0;
    sizeImage = *(new sf::IntRect);
    sizeImage.height = 0;
    sizeImage.width = 0;
    image = nullptr;
    //    sprite=new sf::Sprite();
    pointXBoard = 0;
    pointYBoard = 0;
    readyToPaint = false;
}

Square::Square(const Square& orig) {
    sizeImage.height = orig.sizeImage.height;
    sizeImage.width = orig.sizeImage.width;

    pointXBoard = orig.pointXBoard;
    pointYBoard = orig.pointYBoard;
    //    sprite=new sf::Sprite();
    //    sf::Sprite* sprite2=orig.sprite;
    //    sf::Texture* texture=sprite2->getTexture();
    //    sprite->setTexture(*(orig.sprite->getTexture()));
    //    sprite->setScale(orig.sprite->getScale());
    image = orig.image;
    x = orig.getX();
    y = orig.getY();
    
    type=orig.type;
}

void Square::setDataTableBoard(Board &board) {
    this->board = board;
    sizeImage.height = board.heigthCell;
    sizeImage.width = board.widthCell;

    pointXBoard = board.initBoardX;
    pointYBoard = board.initBoardY;
}

void Square::paint(sf::RenderWindow* pLienzo) {
    if (image != nullptr) {
        sf::Sprite* sprite = new sf::Sprite();
        sprite->setTexture(*image);
        sprite->setPosition(pointXBoard + x * sizeImage.width,
                pointYBoard + y * sizeImage.height);
        float scaleX = (sizeImage.width * 1.0) / ((image->getSize().x)*1.0);
        float scaleY = (sizeImage.height * 1.0) / ((image->getSize().y)*1.0);
        sprite->setScale(scaleX, scaleY);

        pLienzo->draw(*sprite);
        delete sprite;
    }
//    if(sprite!=nullptr){
//        sprite->setPosition(pointXBoard + x * sizeImage.width,
//                pointYBoard + y * sizeImage.height);
//        pLienzo->draw(*sprite);
//    }
}

int Square::compareTo(Square *o) {
    return abs(this->x - o->getX()) + abs(this->y - o->getY());
}

void Square::setGraphics(Board &board, sf::Texture* image) {
    if (image != nullptr) {
        //lanzar excepcion? No.
        setImage(image);
    }
    setDataTableBoard(board);
    readyToPaint = true;
}

void Square::setImage(sf::Texture* image) {
    if (image != nullptr) {
        this->image = image;
//        sprite=new sf::Sprite();
//        sprite->setTexture(*image);
//        float scaleX=(sizeImage.width*1.0)/((image->getSize().x)*1.0);
//        float scaleY=(sizeImage.height*1.0)/((image->getSize().y)*1.0);
//        sprite->setScale(scaleX,scaleY);
    }
}

bool Square::isAnimationFinished() {
    return true;
}

Square* Square::clone() const {
    return new Square(*this);
}