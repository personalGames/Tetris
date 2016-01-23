/* 
 * File:   RemoveCompletedLines.cpp
 * Author: dorian
 * 
 * Created on 20 de septiembre de 2014, 20:39
 */

#include "RemoveCompletedLines.h"

RemoveCompletedLines::RemoveCompletedLines(TableBoard& board, Score& score)
: Command(), board(&board), score(&score) {
    if(removeSoundBuffer.loadFromFile("resources/audio/SFX_SpecialLineClearTriple.ogg")){
        removeSound.setVolume(40);
        removeSound.setBuffer(removeSoundBuffer);
    }
}

RemoveCompletedLines::RemoveCompletedLines(const RemoveCompletedLines& orig) {
    board = orig.board;
    score = orig.score;
}

RemoveCompletedLines::~RemoveCompletedLines() {
}

void RemoveCompletedLines::execute() {
    bool lineFilled;
    //list of lines to be removed
    vector<int> linesFilled;

    //for every line of the board...
    for (int i = 0; i < board->getNumberRows(); i++) {
        lineFilled = true;
        //check every square of the line if is filled
        for (int j = 0; j < board->getNumberColumns() && lineFilled; j++) {
            //if one square is not filled... out
            if (board->isFilled(j, i)!=TypeSquare::Square) {
                lineFilled = false;
            }
        }
        //if the line is filled, add it to the list of line to be removed
        if (lineFilled) {
            linesFilled.push_back(i);
        }
    }

    if (linesFilled.size() > 0) {
        //remove the lines
        removeLines(linesFilled);
        //move every fixed squares of the board
        moveSquares(linesFilled);
        //clear posibly empty shapes from the board
        board->clearShapes();
        //update the board
        board->updateBoard();
        //update the score
        score->incrementLine(linesFilled.size());
        //remove sound
        removeSound.play();
    }
}

void RemoveCompletedLines::moveSquares(vector<int> &lines) {
    //get the number of rows of the board
    int numberRows = board->getNumberRows();
    //prepare a vector
    vector<int> positionMoves(numberRows);
    //prepare an iterator
    vector<int>::iterator it;
    int positions = 0;
    //for every row of the board...
    for (int i = 0; i < numberRows; i++) {
        //store the number of rows that the line will be moved down
        positionMoves[numberRows - i - 1] = positions;
        //if the line is one of the removed lines...
        it = find(lines.begin(), lines.end(), (numberRows - i - 1));
        if (it != lines.end()) {
            //every square above that line will fall down one more line
            positions++;
        }
    }
    //get the list of shapes of the board
    list<Shape*> shapes = board->getShapes();

    //for every shape....
    for (Shape* shape : shapes) {
        //get the squares of the shape
        vector<Square*> listSquares = shape->getSquares();

        //for every square, move what array says
        for (Square* square : listSquares) {
            if (square->getY() >= 0) {
                shape->incrementSquare(0, positionMoves[square->getY()], *square);
            }
        }
    }
}

void RemoveCompletedLines::removeLines(vector<int> &lines) {
    //get the shapes of the board
    list<Shape*> shapes = board->getShapes();

    //for every shape....
    for (Shape* shape : shapes) {
        //get the squares of the shape
        vector<Square*> listSquares = shape->getSquares();

        vector<int>::iterator it;
        //for every square, checks if is in the line to be removed
        for (unsigned int i = 0; i < listSquares.size(); i++) {
            Square* square=listSquares[i];
            it = find(lines.begin(), lines.end(), square->getY());
            if (it != lines.end()) {
                //remove the square
                shape->removeSquare(*square);
            }
        }
    }
}

bool RemoveCompletedLines::isAlive() const {
    return alive || removeSound.getStatus()==sf::Sound::Status::Playing;
}
