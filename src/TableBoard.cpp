/*
 * File:   TableBoard.cpp
 * Author: dorian
 *
 * Created on 15 de agosto de 2014, 12:10
 */

#include "TableBoard.h"

#include <iostream>

TableBoard::TableBoard(const sf::IntRect &window, int rows, int columns) :
table(columns, vector<TypeSquare>(rows, TypeSquare::NoSquare)) {
    initialiceParameters(window, rows, columns);
}

TableBoard::TableBoard(const TableBoard &orig) {
    numberColumns = orig.numberColumns;
    numberRows = orig.numberRows;
    table = orig.table;
    meassureBoard = orig.meassureBoard;
}

TableBoard::~TableBoard() {
}

void TableBoard::initialiceParameters(const sf::IntRect &window, int rows, int columns) {
    numberColumns = columns;
    numberRows = rows;

    //establezco la altura
    meassureBoard.heigthBoard = window.height - static_cast<int>(window.height * 0.10);

    //establezco la anchura
    meassureBoard.widhtBoard = meassureBoard.heigthBoard / 2;
    if (meassureBoard.widhtBoard >= (window.width - static_cast<int>(window.width * 0.10))) {
        meassureBoard.widhtBoard = window.width - static_cast<int>(window.width * 0.10);
    } else if (meassureBoard.widhtBoard < static_cast<int>(meassureBoard.widhtBoard * 0.60)) {
        meassureBoard.widhtBoard = static_cast<int>(window.width * 0.60);
    }

    //tamaño de una celda
    meassureBoard.widthCell = meassureBoard.widhtBoard / columns;
    meassureBoard.heigthCell = meassureBoard.heigthBoard / rows;

    //marcando la zona de la tabla real con las medidas de las celdas
    int anchoLibre = window.width - meassureBoard.widhtBoard;
    //inicio x
    meassureBoard.initBoardX = anchoLibre / 2;
    //ancho real de la tabla
    meassureBoard.widhtBoard = meassureBoard.widthCell * columns;
    //inicio y
    meassureBoard.initBoardY = static_cast<int>(meassureBoard.heigthBoard * 0.05);
    //altura real de la tabla
    meassureBoard.heigthBoard = rows * meassureBoard.heigthCell;
}

void TableBoard::drawLines(sf::RenderWindow* pLienzo) {
    int yFinal = meassureBoard.initBoardY + meassureBoard.heigthBoard;
    int xFinal = meassureBoard.initBoardX + meassureBoard.widhtBoard;

    for (int i = 0; i < numberColumns + 1; i++) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(static_cast<float>(i * meassureBoard.widthCell + meassureBoard.initBoardX),
									static_cast<float>(meassureBoard.initBoardY))),
            sf::Vertex(sf::Vector2f(static_cast<float>(i * meassureBoard.widthCell + meassureBoard.initBoardX),
				static_cast<float>(yFinal)))
        };
        pLienzo->draw(line, 2, sf::Lines);
    }

    for (int i = 0; i < numberRows + 1; i++) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(static_cast<float>(meassureBoard.initBoardX),
						static_cast<float>(i * meassureBoard.heigthCell + meassureBoard.initBoardY))),
            sf::Vertex(sf::Vector2f(static_cast<float>(xFinal),
				static_cast<float>(i * meassureBoard.heigthCell + meassureBoard.initBoardY)))
        };
        pLienzo->draw(line, 2, sf::Lines);
    }
}

bool TableBoard::addShape(Shape* shape) {
    if (isFilled(shape)==TypeSquare::NoSquare ) {
        shapes.push_back(shape);
        int index = 0;
        vector<Square*> squares = shape->getSquares();
        while (index < shape->getNUMBER_OF_SQUARES()) {
            table[squares[index]->getX()][squares[index]->getY()] = squares[index]->getType();
            index++;
        }
        return true;
    } else {
        return false;
    }
}

/**
 * Check if a position of a shape has any square filled by another
 * @param shape the shape to check
 * @return true if some of the square from the shape is already filled by another,
 * false otherwise
 */
TypeSquare TableBoard::isFilled(Shape* shape) {
    TypeSquare result = TypeSquare::NoSquare;
    //checking every square...
    int index = 0;
    vector<Square*> squares = shape->getSquares();
    while (index < shape->getNUMBER_OF_SQUARES() && result==TypeSquare::NoSquare ) {
        result = isFilled(*(squares[index]));
        index++;
    }
    return result;
}

/**
 * Check if a position of a shape has any square filled by another
 * Precondition: the coordinates are into the values of the board
 * @param shape the shape to check
 * @param original the original shape in which squares don't be take into account
 * @return true if some of the square from the shape is already filled by another,
 * false otherwise
 */
TypeSquare TableBoard::isFilled(Shape* shape, Shape* original) {
    TypeSquare result = TypeSquare::NoSquare;
    //checking every square...
    int index = 0;
    vector<Square*> squares = shape->getSquares();
    while (index < shape->getNUMBER_OF_SQUARES() && result == TypeSquare::NoSquare) {
        if (original->hasSquare(*(squares[index]))) {
            result = isFilled(*(squares[index]));
        }
        index++;
    }
    return result;
}

TypeSquare TableBoard::isFilled(Shape* original, Square& square) {
    if (original->hasSquare(square)) {
        return TypeSquare::NoSquare;
    } else {
        return isFilled(square);
    }
}

void TableBoard::updateBoard() {
    for (int i = 0; i < numberColumns; i++) {
        for (int j = 0; j < numberRows; j++) {
            table[i][j] = TypeSquare::NoSquare;
        }
    }

    for (list<Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++) {
        vector<Square*> squares = (*it)->getSquares();
        int indexSquare = 0;
        while (indexSquare < (*it)->getNUMBER_OF_SQUARES()) {
            Square actual = *(squares[indexSquare]);
            if (actual.getY() >= 0 && actual.getX() >= 0) {
                table[actual.getX()][ actual.getY()] = actual.getType();
            }
            indexSquare++;
        }
    }
}

bool TableBoard::isSomethingFalling() {
    bool result = false;
    for (list<Shape*>::iterator it = shapes.begin(); ((it != shapes.end()) & !result); it++) {
        result |= (*it)->isCanFall();
    }
    return result;
}

void TableBoard::clearShapes() {
    for (list<Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++) {
        Shape* actualShape = (*it);
        if (actualShape->getActualNumberSquares() == 0) {
            it = shapes.erase(it);
            delete actualShape;
        }
    }
}

void TableBoard::clearAllShapes() {
    clearShapes();
    for (list<Shape*>::iterator it = specialShapes.begin(); it != specialShapes.end(); it++) {
        Shape* actualShape = (*it);
        if (actualShape->getActualNumberSquares() == 0) {
            it = specialShapes.erase(it);
            delete actualShape;
        }
    }
}

void TableBoard::executeShapes() {
    for (list<Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++) {
        Shape* actualShape = (*it);
        actualShape->executeCommands();
    }
}

void TableBoard::cleanCommandShapes() {
    for (list<Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++) {
        Shape* actualShape = (*it);
        actualShape->clearCommandsFinished();
    }

    for (list<Shape*>::iterator it = specialShapes.begin(); it != specialShapes.end(); it++) {
        Shape* actualShape = (*it);
        actualShape->clearCommandsFinished();
    }
}

void TableBoard::executeCommands() {
    for (list<Command*>::iterator it = commands.begin(); it != commands.end(); it++) {
        Command* actual = (*it);
        actual->execute();
    }
}

void TableBoard::clearCommands() {
    for (list<Command*>::iterator it = commands.begin(); it != commands.end(); it++) {
        Command* actual = (*it);
        if (!actual->isAlive()) {
            it = commands.erase(it);
            delete actual;
        }
    }
}

string TableBoard::toString() {
    std::stringstream result;
    for (int y = 0; y < numberRows; y++) {
        for (int x = 0; x < numberColumns; x++) {
            result << "[";
            if (table[x][y] == TypeSquare::NoSquare) {
                result << " ";
            } else {
                result << "X";
            }
            result << "]";
        }
        result << endl;
    }
    result << endl;
    return result.str();
}

void TableBoard::paint(sf::RenderWindow* pLienzo) {
    for (list<Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++) {
        (*it)->paint(pLienzo);
    }
    for (list<Shape*>::iterator it = specialShapes.begin(); it != specialShapes.end(); it++) {
        (*it)->paint(pLienzo);
    }
}