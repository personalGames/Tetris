/* 
 * File:   Square.h
 * Author: dorian
 *
 * Created on 15 de agosto de 2014, 15:22
 */

#ifndef SQUAREEXPLOSION_H
#define	SQUAREEXPLOSION_H

#include "Square.h"
#include "AnimatedSprite.h"
#include <iostream>

class SquareExplosion : public Square {
public:
    SquareExplosion() : Square(){
        stateFrame=0;
        animationFinished=false;
    }
    SquareExplosion(int posX, int posY) : Square(posX,posY) {
        stateFrame=0;
        animationFinished=false;
    }
    
    SquareExplosion(const SquareExplosion& orig);
    
    SquareExplosion(const Square& orig): Square(orig){
        stateFrame=0;
        animationFinished=false;
    }
    virtual ~SquareExplosion(){
        //never free the image, is shared between squares and shapes
        
    }
    
    bool isAnimationFinished() const {
        return animationFinished;
    }


    void setFramesAnimation(int numFrames, int row, int column, int width, int height);
    virtual void paint(sf::RenderWindow* pLienzo);
    
    SquareExplosion* clone() const;
    
    private:
        int stateFrame;
        int numFrames;
        int row;
        int column;
        int width;
        int height;
        bool animationFinished;
        
        Animation walkingAnimationDown;
        AnimatedSprite animatedSprite;
};

#endif	/* SQUARE_H */

