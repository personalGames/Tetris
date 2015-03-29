/* 
 * File:   Complaint.h
 * Author: dorian
 *
 * Created on 8 de diciembre de 2014, 23:08
 */

#ifndef COMPLAINT_H
#define	COMPLAINT_H

#include "Command.h"
#include "Shape.h"
#include "TableBoard.h"
#include "Timer.h"
#include "EventManager.h"
#include <unordered_map>
#include "TypeEvents.h"

class Complaint : public Command {
public:
    Complaint(TableBoard &board, Shape &shape);
    Complaint(TableBoard &board, Shape &shape, int time);
    Complaint(const Complaint& orig);
    virtual ~Complaint();
    
    void execute();
private:
    /**
     * the board of the game
     */
    TableBoard* board;
    /**
     * the shape involucred
     */
    Shape* shape;
    /**
     * Timer to control the moment in which the shape will fall another
     * position in the board
     */
    Timer timer;
    /**
     * Time in milliseconds between one fall and another
     */
    int millisecondsFalling;
};

#endif	/* COMPLAINT_H */

