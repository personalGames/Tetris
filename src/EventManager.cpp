/* 
 * File:   EventManager.cpp
 * Author: dorian
 * 
 * Created on 8 de diciembre de 2014, 22:36
 */

#include "EventManager.h"
#include "ResponseEvents.h"

EventManager::EventManager() {
}

EventManager::EventManager(const EventManager& orig) {
}

EventManager::~EventManager() {
}

void EventManager::addListener(TypeEvents event, ResponseEvents *object){
    std::list<ResponseEvents*> *observers=registers[event];
    if (observers==nullptr){
        observers=new std::list<ResponseEvents*>();
        registers[event]=observers;
    }
    
    observers->push_back(object);
}

void EventManager::event(TypeEvents event, std::unordered_map<std::string, int> *arguments){
    std::list<ResponseEvents*> *observers=registers[event];
    if (observers==nullptr){
        observers=new std::list<ResponseEvents*>();
        registers[event]=observers;
    }
    
    std::list<ResponseEvents*>::const_iterator iterator;
    for (iterator = observers->begin(); iterator != observers->end(); ++iterator) {
        (*iterator)->response(event, *arguments);
    }
    
    delete arguments;
}