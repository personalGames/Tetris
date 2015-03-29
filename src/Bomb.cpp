/* 
 * File:   Bomb.cpp
 * Author: dorian
 * 
 * Created on 8 de octubre de 2014, 17:19
 */

#include "Bomb.h"
#include <algorithm>
#include <memory>

Bomb::Bomb(TableBoard& board, Shape& shape, Score& score)
: Bomb(board, shape, score, 1000) {
}

Bomb::Bomb(TableBoard& board, Shape& shape, Score& score, int time)
: Command(), board(&board), shape(&shape), score(&score) {
    //start the timer
    timer.start();
    //set the initial time between fallings
    millisecondsFalling = time;
    shape2 = nullptr;
    animation = false;
}

Bomb::Bomb(const Bomb& orig) : Command(orig) {
    board = orig.board;
    shape = orig.shape;
}

Bomb::~Bomb() {
}

void Bomb::execute() {
    //if still alive and is time of another falling...
    if (isAlive() && timer.delta() >= millisecondsFalling) {
        //restart the timer
        timer.reset();
        bool canMove = true;

        //if the shape can fall...
        if (shape->isCanFall()) {
            if (animation && shape2 != nullptr) {
                // los frames son imagenes de 64x64
                // tres filas, un total de 22 frames
                if (shape2->isAnimationFinished()) {
                    shape->setCanFall(false);
                    shape2->remove();
                    alive = false;
                }
            } else {


                //get the position of the squares if we move the shape
                std::vector<Square*> squares = shape->nextMove(0, 1);
                int number = shape->getNUMBER_OF_SQUARES();
                //for every square...
                for (int i = 0; i < number && canMove; i++) {
                    //check the range, if is still inside the board
                    if (squares[i]->getX() < 0
                            || squares[i]->getX() > board->getNumberColumns() - 1
                            || squares[i]->getY() < 0
                            || squares[i]->getY() > board->getNumberRows() - 1) {

                        canMove = false;

                    } else {
                        //check if is filled by another square
                        if (board->isFilled(shape, *(squares[i])) !=TypeSquare::NoSquare) {
                            canMove = false;
                        }
                    }
                }


                //if we can move, move it definitively
                if (canMove) {
                    shape->move(0, 1);
                    //update the board with the new position
                    board->updateBoard();
                } else {
                    //if we can't move the shape, it can fall anymore, set the animation
                    //and the setCanFall later
                    animation = true;
                    //BOOMBB!!
                    //pillo la posición de la bomba
                    int x = squares[0]->getX();
                    int y = squares[0]->getY() - 1; //porque estos datos son del square movido
                    //preparo un vector de cuadrados que explotarán
                    
                    std::vector<Square*> squaresPaint = squaresExploded(x, y);
                    shape2 = new SpecialShape(squaresPaint);
                    board->addSpecialShape(*shape2);
                    shape->removeSquare(x, y);
                    //puntuación...
                    int number = squaresPaint.size() - 1;
                    score->explodedSquares(number);
                }


                std::for_each(squares.begin(), squares.end(), std::default_delete<Square>());
            }
        } else {
            //if the shape can't fall, the command is not alive anymore
            alive = false;
        }

    }
}

std::vector<Square*> Bomb::squaresExploded(int x, int y) {
    //pillo el listado de shapes
    std::list<Shape*> listShapes = board->getShapes();
    //preparo un vector de cuadrados que explotarán
    std::vector<Square*> squaresPaint;
    Animation* animation=ImagesManager::getInstance().getAnimation(Animations::Explosion);
    Board b = board->getMeassureBoard();
    int indexSquare = 1;
    SquareAnimation* empty = new SquareAnimation(x, y);
    empty->setGraphics(b, nullptr);
//    empty->setFramesAnimation(22, 3, 7, 64, 64);
    empty->setAnimation(animation);
    squaresPaint.push_back(empty);

    //para todos los shapes...
    for (std::list<Shape*>::iterator it = listShapes.begin();
            it != listShapes.end() && indexSquare != 9; it++) {
        //pillo sus cuadrados
        std::vector<Square*> squares = (*it)->getSquares();
        //vector<Square*> removeSquares;
        int index = 0;

        //compruebo cada cuadrado...
        while (index < (*it)->getNumberSquares()) {
            int differX = squares[index]->getX() - x;
            int differY = squares[index]->getY() - y;

            //si está cerca...
            if ((abs(differX) == 0 || abs(differX) == 1) && (abs(differY) == 0 || abs(differY) == 1)) {
                //creo el cuadrado explosion
                empty = new SquareAnimation(squares[index]->getX(), squares[index]->getY());
                empty->setGraphics(b, nullptr);
//                empty->setFramesAnimation(22, 3, 7, 64, 64);
                empty->setAnimation(animation);
                squaresPaint.push_back(empty);
                Square* s = squares[index];
                (*it)->removeSquare(*s);
                indexSquare++;

            }
            index++;
        }
    }
    return squaresPaint;
}

