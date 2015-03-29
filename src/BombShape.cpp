#include "BombShape.h"
#include <iostream>
#include "SquareExplosion.h"

BombShape::BombShape() : BombShape(Square()) {
}

BombShape::BombShape(Square example) : BombShape(example, 0) {
}

BombShape::BombShape(Square example, int state) : Shape() {
    numberSquares = NUMBER_OF_SQUARES;
    actualNumberSquares = numberSquares;
    this->state = 0;

    int numberSquaresAsigned = 0;
    //create the vector of squares
    squares = vector<Square*>(NUMBER_OF_SQUARES);
    //create a square in this x,y position
    //first create the square with the given example
    Square* nextSquare = new Square(example);
    //store the square
    squares[numberSquaresAsigned] = nextSquare;
    numberSquaresAsigned++;

};

BombShape::BombShape(vector<Square*>& squares) {
    this->squares = squares;
    numberSquares = squares.size();
    actualNumberSquares = squares.size();
}

bool BombShape::isAnimationFinished() {
    return squares[0]->isAnimationFinished();
}

void BombShape::remove() {
    actualNumberSquares = 0;
}

BombShape::~BombShape() {
    //dtor
}

BombShape::BombShape(const BombShape& other) : Shape(other) {
    state = other.state;
}

void BombShape::rotateShape(vector<Square*> &cloneSquares) {
    //it's the same position all the time
}

