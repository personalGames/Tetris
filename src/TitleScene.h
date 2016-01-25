/* 
 * File:   TitleScene.h
 * Author: dorian
 *
 * Created on 23 de enero de 2016, 16:17
 */

#ifndef TITLESCENE_H
#define	TITLESCENE_H

#include <SFML/Graphics.hpp>

class TitleScene {
public:
    TitleScene();
    virtual ~TitleScene();
    
    void draw(sf::RenderWindow* renderer);
private:
    sf::Texture *image;
};

#endif	/* TITLESCENE_H */

