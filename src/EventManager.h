/* 
 * File:   EventManager.h
 * Author: dorian
 *
 * Created on 8 de diciembre de 2014, 22:36
 */

#ifndef EVENTMANAGER_H
#define	EVENTMANAGER_H

#include <unordered_map>
#include "HashEnum.h"
#include <list>
#include "TypeEvents.h"
#include "ResponseEvents.h"

class EventManager {
public:
    static EventManager& getInstance(){
        static EventManager instance;
        return instance;
    }
    
    void addListener(TypeEvents event, ResponseEvents *object);
    void event(TypeEvents event, std::unordered_map<std::string, int> *arguments);
    
private:
    EventManager();
    EventManager(const EventManager& orig);
    virtual ~EventManager();
    
    std::unordered_map<TypeEvents, std::list<ResponseEvents*>* ,HashEnum> registers;
};

#endif	/* EVENTMANAGER_H */

