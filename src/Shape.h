/* 
 * File:   Shape.h
 * Author: dorian
 *
 * Created on 25 de agosto de 2014, 19:30
 */

#ifndef SHAPE_H
#define	SHAPE_H

#include "Square.h"
#include "EmptySquare.h"
#include <vector>
#include <list>
#include "Command.h"

using namespace std;

class Shape {
public:
    Shape();
    Shape(const Shape& orig);
    virtual ~Shape();
    

    inline bool isCanFall() const {
        return canFall;
    }

    inline void setCanFall(bool canFall) {
        this->canFall = canFall;
    }

    inline const vector<Square*>& getSquares() const {
        return squares;
    }

    inline int getNumberSquares() const {
        return numberSquares;
    }
    
    inline int getActualNumberSquares() const{
        return actualNumberSquares;
    }
    
    /**
     * Remove a squares of the shape
     * @param squareTarget a squares with the same position of the squares want to remove
     */
    void removeSquare(Square &squareTarget);
    
    /**
     * Remove a squares of the shape
     * @param x coordinate x of the squares
     * @param y coordinate y of the squares
     */
    inline void removeSquare(int x, int y){
        Square temp=*(new Square(x,y));
        removeSquare(temp);
    }
    
    /**
     * Move the shape a position determined by its velocity
     * The parameter determine if the move is temporal or definitively
     * giving a copy of the squaress or not
     * @param cloneSquares 
     */
    void moveShape(vector<Square*> &cloneSquares, int x, int y);
    
    /**
     * Move the shape
     */
    inline void move(int x, int y) {
        moveShape(squares,x,y);
    }
    
    /**
     * Get an array of the squaress with the new position if we move the shape
     * with the actual determined velocity. don't really move the shape
     * @return a copy of the squaress with the updated positions if we move the shape
     */
    vector<Square*> nextMove(int x, int y);
   
    
    /**
     * Rotate the shape
     */
    inline void rotate(){
        rotateShape(squares);
    }
    
    /**
     * Get an array of the squaress with the new position if we rotate the shape.
     * Don't really rotate the shape
     * @return a copy of the squaress with the updated positions
     */
    vector<Square*> nextRotate();
    
    /**
     * Increment the given square of the shape by the given amount
     * @param x
     * @param y
     * @param square
     */
    void incrementSquare(int x, int y, Square& square);
    /**
     * Increment the squares of the shape by the given amount
     * @param x
     * @param y
     */
    void incrementSquare(int x, int y);
    
    
    /**
     * Check if the given square is the same as a square from this shape
     * @param square the square to check
     * @return true if have a square with 
     */
    bool hasSquare(Square &square);
    
    /**
     * Paint the shape on the given surface
     * @param pLienzo
     */
    virtual void paint(sf::RenderWindow *pLienzo);
    
    
    virtual int getState()=0;
    virtual int getNUMBER_OF_STATES()=0;
    virtual int getNUMBER_OF_SQUARES()=0;
    
    /**
     * Add an asociated command
     * @param command the command asociated
     */
    inline void addCommand(Command* command){
        commands.push_back(command);
    }
    
    /**
     * Ejecute every command asociate to the shape
     */
    void executeCommands();
    /**
     * Clear from the list every dead command
     */
    void clearCommandsFinished();
    
    /**
     * Set the necesary data to be draw
     * @param board the measure of the board
     * @param image the image of the squares
     */
    void setGraphics(BoardGrid &board, sf::Texture *image);
    
    
    
protected:
    /**
     * Squares that compose the shape
     */
    vector<Square*> squares;
    bool canFall;
    int numberSquares;
    /**
     * Number of non-empty squares
     */
    int actualNumberSquares;
    /**
     * The state of the shape that indicate the position of rotation of the shape
     */
    int state;
    /**
     * list of commands asociated to this shape
     */
    list<Command*> commands;
    
    /**
     * Rotate the shape
     * The parameter determine if the move is temporal or definitively
     * giving a copy of the squaress or not
     * @param cloneSquares 
     */
     virtual void rotateShape(vector<Square*> &cloneSquares)=0;
     
     vector<Square*> cloneSquares(vector<Square*> original);
    
};

#endif	/* SHAPE_H */

