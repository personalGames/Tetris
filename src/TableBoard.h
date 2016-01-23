/* 
 * File:   TableBoard.h
 * Author: dorian
 *
 * Created on 15 de agosto de 2014, 12:10
 */

#ifndef TABLEBOARD_H
#define	TABLEBOARD_H

#include <SFML/Graphics.hpp>
#include "Shape.h"
#include "Command.h"
#include "MeassureBoard.h"
#include <vector>
#include <string>
#include <sstream>
#include "TypeSquare.h"

using namespace std;

class TableBoard {
public:

    TableBoard() {    }
    TableBoard(const sf::IntRect &window, int rows = DEFAULT_ROWS, int columns = DEFAULT_COLUMNS);
    TableBoard(const TableBoard &orig);
    virtual ~TableBoard();

    inline int getWidthCell() const {
        return meassureBoard.widthCell;
    }

    inline int getHeightCell() const {
        return meassureBoard.heigthCell;
    }

    inline int getInitX() const {
        return meassureBoard.initBoardX;
    }

    inline int getInitY() const {
        return meassureBoard.initBoardY;
    }

    inline int getEndX() const {
        return meassureBoard.initBoardX + meassureBoard.widhtBoard;
    }

    inline int getEndY() const {
        return meassureBoard.initBoardY + meassureBoard.heigthBoard;
    }

    inline int getNumberColumns() const {
        return numberColumns;
    }

    inline int getNumberRows() const {
        return numberRows;
    }

    inline BoardGrid getMeassureBoard() const {
        return meassureBoard;
    }
    
    inline int getWidthBoard() const {
        return meassureBoard.widhtBoard;
    }
    
    inline int getHeigthBoard() const {
        return meassureBoard.heigthBoard;
    }

    /**
     * Get the list of shapes
     * @return list of shapes
     */
    inline const list<Shape*>& getShapes() const{
        return shapes;
    }

    void clearAllShapes();

    /**
     * Add a shape to the board in the position specified by the shape.
     * Will not be added if the place of that shape is filled
     * @param shape the shape to add
     * @return  true if added
     */
    bool addShape(Shape* shape);

    inline void addCommand(Command* command) {
        commands.push_back(command);
    }


    /**
     * 
     * @param pLienzo
     */
    void drawLines(sf::RenderWindow* pLienzo);

    /**
     * Check if a determined square is filled by another square
     * @param square the square to check
     * @return true if the square is ocupied
     */
    inline TypeSquare isFilled(Square &square) {
        return table[square.getX()][ square.getY()];
    }

    /**
     * Check if a position of a shape has any square filled by another
     * @param shape the shape to check
     * @return true if some of the square from the shape is already filled by another,
     * false otherwise
     */
    TypeSquare isFilled(Shape* shape);

    /**
     * Check if a position of a shape has any square filled by another
     * Precondition: the coordinates are into the values of the board
     * @param shape the shape to check
     * @param original the original shape in which squares don't be take into account
     * @return true if some of the square from the shape is already filled by another,
     * false otherwise
     */
    TypeSquare isFilled(Shape* shape, Shape* original);

    /**
     * Check if a determined square is filled by another square
     * Precondition: the coordinates are into the values of the board
     * @param original the original shape in which squares don't be take into account
     * @param square the square to check
     * @return true if the square is ocupied
     */
    TypeSquare isFilled(Shape* original, Square &square);

    /**
     * Check if a determined square is filled by another square
     * Precondition: the coordinates are into the values of the board
     * @param x coordinate x
     * @param y coordinate y
     * @return true if the square is ocupied
     */
    inline TypeSquare isFilled(int x, int y) {
        return table[x][y];
    }

    void updateBoard();

    bool isSomethingFalling();

    void clearShapes();
    
    void executeShapes();
    
    void cleanCommandShapes();
    
    void executeCommands();
    
    void clearCommands();

    string toString();
    
    void paint(sf::RenderWindow* pLienzo);

private:
    static const int DEFAULT_ROWS = 20;
    static const int DEFAULT_COLUMNS = 10;
    int numberRows;
    int numberColumns;
    BoardGrid meassureBoard;

    /**
     * Table of the board, store 1 if there's any square on it, 0 otherwise
     */
    vector< vector<TypeSquare> > table;

    inline int getIndexTable(int row, int column) {
        return row * numberColumns + column;
    }

    /**
     * List of the shapes that is on the board
     */
    list<Shape*> shapes{};
    /**
     * List of more special shapes on the board
     */
    list<Shape*> specialShapes{};

    list<Command*> commands{};

    void initialiceParameters(const sf::IntRect &window, int rows, int columns);

};

#endif	/* TABLEBOARD_H */

