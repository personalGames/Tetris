#include "SpecialShape.h"
#include "SquareAnimation.h"

SpecialShape::SpecialShape() : SpecialShape(new Square()) {}

SpecialShape::SpecialShape(Square* example) : SpecialShape(example, 0) {}

SpecialShape::SpecialShape(Square* example, int state) : Shape() {
    numberSquares = NUMBER_OF_SQUARES;
    actualNumberSquares = numberSquares;
    this->state = 0;

    //create the vector of squares
    squares = vector<Square*>(NUMBER_OF_SQUARES);
    //create a square in this x,y position
    //first create the square with the given example
    Square* nextSquare = example->clone();
    //store the square
    squares[0] = nextSquare;

};

SpecialShape::SpecialShape(vector<Square*>& squares) {
    this->squares = squares;
    numberSquares = squares.size();
    actualNumberSquares = squares.size();
}

bool SpecialShape::isAnimationFinished() {
    bool finished=true;
    for(Square* square: squares){
        finished= finished & square->isAnimationFinished();
    }
    return finished;
}

void SpecialShape::remove() {
    actualNumberSquares = 0;
}

SpecialShape::~SpecialShape() {
    //dtor
}

SpecialShape::SpecialShape(const SpecialShape& other) : Shape(other) {
    state = other.state;
}

void SpecialShape::rotateShape(vector<Square*> &cloneSquares) {
    //it's the same position all the time
}

