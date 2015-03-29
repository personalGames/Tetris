/* 
 * File:   SquareAnimation.h
 * Author: dorian
 *
 * Created on 9 de diciembre de 2014, 20:33
 */

#ifndef SQUAREANIMATION_H
#define	SQUAREANIMATION_H

#include "Animation.h"
#include "AnimatedSprite.h"
#include "Square.h"

class SquareAnimation : public Square {
public:
    SquareAnimation();
    SquareAnimation(int posX, int posY);
    SquareAnimation(const Square& orig);
    SquareAnimation(const SquareAnimation& orig);
    
    virtual ~SquareAnimation();
    
    void setAnimation(Animation *animation);
    inline AnimatedSprite* getAnimationSprite(){
        return animatedSprite;
    }
    inline bool IsAnimationFinished() const {
        return animationFinished;
    }

    inline int GetNumFrames() const {
        return numFrames;
    }

    SquareAnimation* clone() const;
    virtual void paint(sf::RenderWindow* pLienzo);
    
private:
    int stateFrame, numFrames;
    bool animationFinished;
    AnimatedSprite* animatedSprite;
};

#endif	/* SQUAREANIMATION_H */

