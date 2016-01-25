/* 
 * File:   EmptySquare.h
 * Author: dorian
 *
 * Created on 25 de agosto de 2014, 19:31
 */

#ifndef EMPTYSQUARE_H
#define	EMPTYSQUARE_H

#include "Square.h"


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
 
	virtual void setImage(sf::Texture * image) {}


	virtual void paint(sf::RenderWindow* pLienzo) {}

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
    
private:

};

#endif	/* EMPTYSQUARE_H */

