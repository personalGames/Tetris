/* 
 * File:   SquareAnimation.cpp
 * Author: dorian
 * 
 * Created on 9 de diciembre de 2014, 20:33
 */

#include <SFML/Graphics/RenderTarget.hpp>

#include "SquareAnimation.h"

SquareAnimation::SquareAnimation() : Square() {
    stateFrame = 0;
    animationFinished = false;
    animatedSprite=new AnimatedSprite();
    type=TypeSquare::SquareAnimation;
}

SquareAnimation::SquareAnimation(int posX, int posY) : Square(posX, posY) {
    stateFrame = 0;
    animationFinished = false;
    animatedSprite=new AnimatedSprite();
    type=TypeSquare::SquareAnimation;
}

SquareAnimation* SquareAnimation::clone() const {
    return new SquareAnimation(*this);
}

SquareAnimation::~SquareAnimation() {
    if (animatedSprite != nullptr) {
        delete animatedSprite;
    }
}

SquareAnimation::SquareAnimation(const Square& orig) : Square(orig) {
    stateFrame = 0;
    animationFinished = false;
}

void SquareAnimation::paint(sf::RenderWindow* pLienzo) {
    if (!animationFinished) {
        //calculo su posición en la matriz
        sizeImage.left = pointXBoard + x * sizeImage.width;
        sizeImage.top = pointYBoard + y * sizeImage.height;
        animatedSprite->setPosition(sizeImage.left, sizeImage.top);
        
        float scaleX = (sizeImage.width * 1.0) / (animatedSprite->getLocalBounds().width*1.0);
        float scaleY = (sizeImage.height * 1.0) / (animatedSprite->getLocalBounds().height*1.0);
        animatedSprite->setScale(0.5,0.5);

        //siguiente frame
        if (stateFrame < numFrames) {
            animatedSprite->setFrame(stateFrame, false);
            stateFrame++;
        } else {
            animationFinished = true;
        }
    }
    pLienzo->draw(*animatedSprite);
}

void SquareAnimation::setAnimation(Animation* animation) {
    numFrames = animation->getSize();
    animatedSprite->setPosition(0, 0);
    animatedSprite->play(*animation);
}

SquareAnimation::SquareAnimation(const SquareAnimation& orig) : Square(orig) {
    this->animatedSprite = orig.animatedSprite;
    this->stateFrame = 0;
    this->numFrames = orig.numFrames;
    this->animationFinished = false;
}