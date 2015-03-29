/* 
 * File:   MeassureBoard.h
 * Author: dorian
 *
 * Created on 31 de agosto de 2014, 12:11
 */

#ifndef MEASSUREBOARD_H
#define	MEASSUREBOARD_H

/**
 * Measure of the board of the game
 */
struct Board {
    //width and heigth of one cell of the board
    int heigthCell;
    int widthCell;

    //points where the cell board will be drawed
    int initBoardX;
    int initBoardY;

    //width and height of the board
    int heigthBoard;
    int widhtBoard;
};

#endif	/* MEASSUREBOARD_H */

