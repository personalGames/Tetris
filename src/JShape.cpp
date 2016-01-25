
#include "JShape.h"

constexpr const int JShape::COORDINATES[4][4][2];
constexpr const int JShape::INITIAL_COORDINATES[3][2];  
      
JShape::JShape() : JShape(Square()){}
JShape::JShape(Square example) : JShape(example,0){}
JShape::JShape(Square example, int state) : Shape() {
    numberSquares=NUMBER_OF_SQUARES;
    actualNumberSquares=numberSquares;
        this->state=0;
        state=state%NUMBER_OF_STATES;

        int numberSquaresAsigned=0;
        //create the vector of squares
        squares=vector<Square*>(NUMBER_OF_SQUARES);
        //for every coordinates..
        for (int i = 0; i < LENGTH_INITIAL_COORDINATES; i++) {
            for (int j = 0; j < LENGTH_INITIAL_COORDINATES_2; j++) {
                //if in the matrix indicates a square...
                if (INITIAL_COORDINATES[i][j] != 0) {
                    //create a square in this x,y position
                    //first create the square with the given example
                    Square* nextSquare=new Square(example);
                    //and then move the square to its position
                    nextSquare->incrementX(j);
                    nextSquare->incrementY(i);
                    //store the square
                    squares[numberSquaresAsigned]=nextSquare;
                    numberSquaresAsigned++;
                }
            }
        }
        
        //rotate the shape if the initial position differs
        while(this->state!=state){
            rotate();
        }
};





JShape::~JShape(){
    //dtor
}

JShape::JShape(const JShape& other):Shape(other) {
    state=other.state;
}


void JShape::rotateShape(vector<Square*> &cloneSquares) {
        state++;
        state=state%NUMBER_OF_STATES;

//        for every squares of the shape
        for (int i = 0; i < NUMBER_OF_SQUARES; i++) {
//            multiplier means that I have to minus or plus depending the state of the shape
//            get X point of the squares and plus the modifier of coordinates correspondent to that squares 
            cloneSquares[i]->setX(cloneSquares[i]->getX() + COORDINATES[state][i][0] );
//            get Y point of the squares and plus the modifier of coordinates correspondent to that squares
            cloneSquares[i]->setY(cloneSquares[i]->getY() + COORDINATES[state][i][1]);
        }
}
