/* 
 * File:   ZShape.h
 * Author: dorian
 *
 * Created on 30 de agosto de 2014, 15:39
 */

#ifndef ZSHAPE_H
#define	ZSHAPE_H

#include "Square.h"
#include "EmptySquare.h"
#include "Shape.h"

class ZShape : public Shape {

public:
    ZShape();
    ZShape(Square example);
    ZShape(Square example, int state);
    
    ZShape(const ZShape& orig);
    virtual ~ZShape();
    
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
        return NUMBER_OF_SQUARES;
    } 
    
    /**
     * Rotate the given squares
     * @param cloneSquares the squares to rotate
     */
    void rotateShape(vector<Square*> &cloneSquares);
    
    
private:
    /**
     * Number of states of the 
     */
    static const int NUMBER_OF_STATES=2;
    /**
     * The number of squaress of this shape
     */
    static const int NUMBER_OF_SQUARES=4;
    
    /**
     * Coordinates to make the shape
     * Just a matrix with ougths and ones where a one indicates a shape 
     * in the position of the matrix
     */
    constexpr const static int INITIAL_COORDINATES[3][2]={{0,1},{1,1},{1,0}};
    const static int LENGTH_INITIAL_COORDINATES=3;
    const static int LENGTH_INITIAL_COORDINATES_2=2;
    /**
     * Coordinates of the shape
     */
    constexpr const static int COORDINATES[4][2]={{-1,1},
                                                {1,1},
                                                {0,0},
                                                {2,0}}; 
    

};

#endif	/* ZSHAPE_H */

