#include "OShape.h"

constexpr const int OShape::INITIAL_COORDINATES[2][2];  
      
OShape::OShape() : OShape(Square()){}
OShape::OShape(Square example) : OShape(example,0){}
OShape::OShape(Square example, int state) : Shape() {
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





OShape::~OShape(){
    //dtor
}

OShape::OShape(const OShape& other):Shape(other){
    state=other.state;
}


void OShape::rotateShape(vector<Square*> &cloneSquares) {
        //it's the same position all the time
}

