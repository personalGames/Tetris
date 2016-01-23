/* 
 * File:   RemoveCompletedLines.h
 * Author: dorian
 *
 * Created on 20 de septiembre de 2014, 20:39
 * 
 * An action in which the command search for completed lines and remove it
 */

#ifndef REMOVECOMPLETEDLINES_H
#define	REMOVECOMPLETEDLINES_H

#include "Command.h"
#include "Score.h"
#include "TypeSquare.h"
#include "Shape.h"
#include "TableBoard.h"
#include <vector>
#include <algorithm>

class RemoveCompletedLines : public Command {
public:
    RemoveCompletedLines(TableBoard &board, Score& score);
    RemoveCompletedLines(const RemoveCompletedLines& orig);
    virtual ~RemoveCompletedLines();
    
    bool isAlive() const;
    void execute();
private:
    /**
     * the board of the game
     */
    TableBoard* board;
    /**
     * A pointer to the score of the game
     */
    Score* score;
    
    /**
     * Move down the squares above the removed lines
     * @param lines
     */
    void moveSquares(vector<int> &lines);
    /**
     * Remove the lines
     * @param lines a vector of the lines of the board to be removed
     */
    void removeLines(vector<int> &lines);
    
    
    sf::SoundBuffer removeSoundBuffer;
    sf::Sound removeSound;
    
};

#endif	/* REMOVECOMPLETEDLINES_H */

