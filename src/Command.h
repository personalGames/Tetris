/* 
 * File:   Command.h
 * Author: dorian
 *
 * Created on 30 de agosto de 2014, 19:21
 */

#ifndef COMMAND_H
#define	COMMAND_H

/**
 * Represent an action and/or command
 * This is the base class
 */
class Command {
public:
    Command();
    Command(const Command& orig);
    virtual ~Command();
    
    /**
     * Execute the action
     */
    virtual void execute()=0;
    
    /**
     * If an action or command has been executed, the command is "dead"
     * @return true if can execute, false if has already been executed
     */
    inline virtual bool isAlive() const{
        return alive;
    }
    
protected:
    /**
     * Tell if the command is "alive" and can be executed or 
     * has already been executed and it's done
     */
    bool alive;
};

#endif	/* COMMAND_H */

