/* 
 * File:   EmptySquare.h
 * Author: dorian
 *
 * Created on 25 de agosto de 2014, 19:31
 */

#ifndef EMPTYSQUARE_H
#define	EMPTYSQUARE_H

#include "Square.h"
#include <SDL2/SDL.h>


class EmptySquare : public Square {
public:
    EmptySquare() : Square() {
        x=y=-10;
        type=TypeSquare::NoSquare;
    }
    EmptySquare(int x, int y) : Square(x,y){
        type=TypeSquare::NoSquare;
    }
    EmptySquare(const EmptySquare& orig) : Square(orig){
        x=-10;
        y=-10;
    }
    virtual ~EmptySquare(){}
    
    inline void setGraphics(SDL_Texture &image){}

    virtual inline void setImage(SDL_Texture &image) {
        
    }

    virtual inline void setX(int x) {
      
    }

    virtual inline void setY(int y) {
        
    }
    
    virtual inline void incrementX(int increment){
        
    }
    
    virtual inline void incrementY(int increment){
        
    }

    virtual int compareTo(Square o){
        return 1;
    }
    
    EmptySquare* clone() const {
        return new EmptySquare(*this);
    }
    
    void paint(SDL_Renderer* pLienzo){}
    
private:

};

#endif	/* EMPTYSQUARE_H */

