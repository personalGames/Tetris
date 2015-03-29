/* 
 * File:   Building.cpp
 * Author: dorian
 * 
 * Created on 26 de octubre de 2014, 18:11
 */

#include <algorithm>    // std::random_shuffle, sort
#include <vector>       // std::vector


#include "Building.h"

Building::Building(TableBoard &board, Score &score) : Command(), board(&board), score(&score) {
    //start the timer
    timer.start();
    //set the initial time between fallings
    millisecondsFalling = score.getVelocityBuilding();
    //register for events
    EventManager::getInstance().addListener(TypeEvents::stopBuilding, this);
}

Building::Building(const Building& orig) {
    timer = orig.timer;
    millisecondsFalling = orig.millisecondsFalling;
    board = orig.board;
}

Building::~Building() {
}

void Building::execute() {
    if (timer.delta() >= millisecondsFalling) {
        timer.reset();
        millisecondsFalling=score->getVelocityBuilding();
        moveSquares();
        createSquares();
        board->updateBoard();
    }
}

void Building::moveSquares() {
    //get the list of shapes of the board
    list<Shape*> shapes = board->getShapes();

    //for every shape....
    for (Shape* shape : shapes) {
        //get the squares of the shape
        vector<Square*> listSquares = shape->getSquares();

        //for every square, move what array says
        for (Square* square : listSquares) {
            if (square->getY() >= 0) {
                shape->incrementSquare(0, -1, *square);
            }
        }
    }
    board->updateBoard();
}

void Building::createSquares() {
    int numberColumns = board->getNumberColumns();
    int numberRows = board->getNumberRows();
    int blankSpaces = ((rand() % (numberColumns - 2))) + 1;
    vector<int> posibles(numberColumns);
    std::iota(posibles.begin(), posibles.end(), 0);
    std::random_shuffle(posibles.begin(), posibles.end());
    posibles.resize(blankSpaces);
    std::sort(posibles.rbegin(), posibles.rend());
    

    vector<Square*> line;
    int x=0;
    Board b=board->getMeassureBoard();
    for (x = 0; x < numberColumns; x++) {
        if (posibles.back() == x) {
            posibles.pop_back();
        } else {
            Square* square = new Square(x, numberRows-1);
            sf::Texture* image = ImagesManager::getInstance().getImage(Images::Square);
            square->setGraphics(b, image);
            line.push_back(square);
        }
    }
    Shape* special = new SpecialShape(line);
    board->addShape(special);
}

void Building::response(TypeEvents event, std::unordered_map<std::string, int> &arguments){
    switch(event){
        case TypeEvents::stopBuilding:
        {
                int timeStop=arguments["time"];
                millisecondsFalling+=timeStop;
        }
            break;
        default:
            break;
    }
}