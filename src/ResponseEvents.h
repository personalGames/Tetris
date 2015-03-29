/* 
 * File:   ResponseEvents.h
 * Author: dorian
 *
 * Created on 8 de diciembre de 2014, 22:41
 */

#ifndef RESPONSEEVENTS_H
#define	RESPONSEEVENTS_H

#include "TypeEvents.h"
#include <string>


class ResponseEvents {
public:
    virtual ~ResponseEvents(){}
    virtual void response(TypeEvents event, std::unordered_map<std::string, int> &arguments)=0;

};

#endif	/* RESPONSEEVENTS_H */

