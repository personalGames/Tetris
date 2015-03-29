/* 
 * File:   OShape.h
 * Author: dorian
 *
 * Created on 30 de agosto de 2014, 15:00
 */

#ifndef SPECIAL_SHAPE_H
#define	SPECIAL_SHAPE_H

#include <SDL2/SDL_image.h>
#include "Square.h"
#include "EmptySquare.h"
#include "Shape.h"
#include "SquareExplosion.h"

class SpecialShape : public Shape {

public:
    SpecialShape();
    SpecialShape(Square* example);
    SpecialShape(Square* example, int state);
    SpecialShape(vector<Square*>& squares);
    
    SpecialShape(const SpecialShape& orig);
    virtual ~SpecialShape();
    
    /**
     * Get the actual state of the shape
     * @return the actual state
     */
    inline int getState() {
        return state;
    }

    /**
     * The total number of states of the shape
     * @return the number of states
     */
    inline int getNUMBER_OF_STATES() {
        return NUMBER_OF_STATES;
    }
    
    /**
     * Return the number of squaress of the shape.
     * Don't matter if the squares was removed.
     * @return number of squaress
     */
    inline int getNUMBER_OF_SQUARES() {
        return numberSquares;
    } 
    
    void remove();
    
    bool isAnimationFinished();
    
    /**
     * Rotate the given squares
     * @param cloneSquares the squares to rotate
     */
    void rotateShape(vector<Square*> &cloneSquares);
    
    
private:
    /**
     * Number of states of the 
     */
    static const int NUMBER_OF_STATES=1;
    /**
     * The number of squaress of this shape
     */
    static const int NUMBER_OF_SQUARES=1;
    
};


#endif	/* OSHAPE_H */

