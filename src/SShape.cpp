#include "SShape.h"

constexpr const int SShape::COORDINATES[4][2];
constexpr const int SShape::INITIAL_COORDINATES[3][2];

SShape::SShape() : SShape(Square()) {
}

SShape::SShape(Square example) : SShape(example, 0) {
}

SShape::SShape(Square example, int state) : Shape() {
    numberSquares = NUMBER_OF_SQUARES;
    actualNumberSquares = numberSquares;
    this->state = 0;
    state = state % NUMBER_OF_STATES;

    int numberSquaresAsigned = 0;
    //create the vector of squares
    squares = vector<Square*>(NUMBER_OF_SQUARES);
    //for every coordinates..
    for (int i = 0; i < LENGTH_INITIAL_COORDINATES; i++) {
        for (int j = 0; j < LENGTH_INITIAL_COORDINATES_2; j++) {
            //if in the matrix indicates a square...
            if (INITIAL_COORDINATES[i][j] != 0) {
                //create a square in this x,y position
                //first create the square with the given example
                Square* nextSquare = new Square(example);
                //and then move the square to its position
                nextSquare->incrementX(j);
                nextSquare->incrementY(i);
                //store the square
                squares[numberSquaresAsigned] = nextSquare;
                numberSquaresAsigned++;
            }
        }
    }

    //rotate the shape if the initial position differs
    while (this->state != state) {
        rotate();
    }
};

SShape::~SShape() {
    //dtor
}

SShape::SShape(const SShape& other) : Shape(other) {
    state = other.state;
}

void SShape::rotateShape(vector<Square*> &cloneSquares) {
    state++;
    state = state % NUMBER_OF_STATES;

    int multiplier = 1;

    if (state == 0) {
        multiplier = -1;
    }

    //for every squares of the shape
    for (int i = 0; i < NUMBER_OF_SQUARES; i++) {
        //multiplier means that I have to minus or plus depending the state of the shape
        //get X point of the squares and plus the modifier of coordinates correspondent to that squares
        cloneSquares[i]->setX(cloneSquares[i]->getX() + COORDINATES[i][0] * multiplier);
        //get Y point of the squares and plus the modifier of coordinates correspondent to that squares
        cloneSquares[i]->setY(cloneSquares[i]->getY() + COORDINATES[i][1] * multiplier);
    }
}

