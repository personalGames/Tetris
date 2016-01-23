/*
 * File:   Shape.cpp
 * Author: dorian
 *
 * Created on 25 de agosto de 2014, 19:30
 */

#include "Shape.h"

Shape::Shape() {
    canFall = true;
}

Shape::Shape(const Shape& orig) {
    squares = orig.squares;
    canFall = orig.canFall;
    numberSquares = orig.numberSquares;
    actualNumberSquares = orig.actualNumberSquares;
}

Shape::~Shape() {
    for (int i = 0; i < squares.size(); i++) {
        delete squares[i];
    }
    squares.clear();

    for (Command *command : commands) {
        delete command;
    }
    commands.clear();
}

void Shape::removeSquare(Square &squareTarget) {
    bool found = false;
    //iterate over the squares of the shape
    for (int i = 0; i < numberSquares && !found; i++) {
        Square* s = squares[i];
        if ((s->compareTo(&squareTarget)) == 0) {
            //delete de square
            delete squares[i];
            //create a null square
            EmptySquare* s = new EmptySquare();
            squares[i] = s;
            found = true;
        }
    }
    if (found) {
        actualNumberSquares--;
    }
}

void Shape::incrementSquare(int x, int y, Square& square) {
    bool found = false;
    //iterate over the squares of the shape
    for (int i = 0; i < numberSquares && !found; i++) {
        if (squares[i]->compareTo(&square) == 0) {
            //create a null squares
            squares[i]->incrementX(x);
            squares[i]->incrementY(y);
            found = true;
        }
    }
}

void Shape::incrementSquare(int x, int y) {
    //iterate over the squares of the shape
    for (int i = 0; i < numberSquares; i++) {
        //create a null squares
        squares[i]->incrementX(x);
        squares[i]->incrementY(y);
    }
}

void Shape::moveShape(vector<Square*> &cloneSquares, int x, int y) {
    int i = 0;
    while (i < numberSquares) {
        cloneSquares[i]->incrementX(x);
        cloneSquares[i]->incrementY(y);

        i++;
    }

}

vector<Square*> Shape::nextMove(int x, int y) {
    //make a copy to not really moving the squares
    vector<Square*> clone = cloneSquares(squares); //(squares);
    //get the next move
    moveShape(clone, x, y);
    //return the modified squares
    return clone;
}

vector<Square*> Shape::nextRotate() {
    //make a copy to not really moving the squares
    vector<Square*> clone = cloneSquares(squares);

    //store the state
    int previousState = state;
    //get the next rotate
    rotateShape(clone);
    //restore the state
    state = previousState;
    //return the modified squares
    return clone;
}

vector<Square*> Shape::cloneSquares(vector<Square*> original) {
    vector<Square*> clone(original.size());
    for (int i = 0; i < original.size(); i++) {
        clone[i] = original[i]->clone();
    }
    return clone;
}

bool Shape::hasSquare(Square &square) {
    bool result = false;
    for (int i = 0; (i < numberSquares) & (!result); i++) {
        if (squares[i]->compareTo(&square) == 0) {
            result = true;
        }
    }
    return result;
}

void Shape::paint(sf::RenderWindow* pLienzo) {
    int i = 0;
    //paint every square
    while (i < numberSquares) {
        squares[i]->paint(pLienzo);
        i++;
    }
}

void Shape::executeCommands() {
    for (list<Command*>::iterator it = commands.begin(); it != commands.end(); ++it) {
        (*it)->execute();
    }
}

void Shape::clearCommandsFinished() {
    for (list<Command*>::iterator it = commands.begin(); it != commands.end();) {
        if ((*it)->isAlive() != true) {
            Command* command = (*it);
            it = commands.erase(it);
            delete command;
        } else {
            ++it;
        }
    }
}

void Shape::setGraphics(BoardGrid &board, sf::Texture *image) {
    int i = 0;
    //set the data to every square
    while (i < numberSquares) {
        squares[i]->setGraphics(board, image);
        i++;
    }
}