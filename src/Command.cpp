#include "Command.h"

Command::Command(): alive(true){
}

Command::Command(const Command& orig){
    alive=orig.alive;
}

Command::~Command(){}
