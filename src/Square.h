/* 
 * File:   Square.h
 * Author: dorian
 *
 * Created on 15 de agosto de 2014, 15:22
 */

#ifndef SQUARE_H
#define	SQUARE_H

#include "MeassureBoard.h"
#include <SFML/Graphics.hpp>
#include "TypeSquare.h"

class Square {
public:
    Square();
    Square(int posX, int posY) : x(posX), y(posY) {
        type=TypeSquare::Square;
    }
    Square(const Square& orig);
    virtual ~Square(){
        //never free the image, is shared between squares and shapes
        
    }
    

    virtual void setGraphics(BoardGrid &board, sf::Texture *image);
    
    virtual void setImage(sf::Texture * image);
    
    inline int getX() const {
        return x;
    }

    virtual inline void setX(int x) {
        this->x = x;
    }

    inline int getY() const {
        return y;
    }
    
    inline bool isReadyToPaint(){
        return readyToPaint;
    }

    virtual inline void setY(int y) {
        this->y = y;
    }
    
    virtual inline void incrementX(int increment){
        this->x+=increment;
    }
    
    virtual inline void incrementY(int increment){
        this->y+=increment;
    }
    
    virtual void paint(sf::RenderWindow* pLienzo);

    virtual int compareTo(Square *o);

    BoardGrid getBoard(){
        return board;
    }
    
    virtual Square* clone() const;
    
    inline TypeSquare getType() const {
        return type;
    }

    void setType(TypeSquare type) {
        this->type = type;
    }
    
protected:
    BoardGrid board;
    int x;
    int y;
    int pointXBoard;
    int pointYBoard;
    sf::Texture *image;
    sf::IntRect sizeImage;
    bool readyToPaint;
    TypeSquare type;
    
    void setDataTableBoard(BoardGrid &board);
};

#endif	/* SQUARE_H */

