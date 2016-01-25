/* 
 * File:   TitleScene.cpp
 * Author: dorian
 * 
 * Created on 23 de enero de 2016, 16:17
 */

#include "TitleScene.h"
#include "ImagesManager.h"

TitleScene::TitleScene() {
    image=nullptr;
}

TitleScene::~TitleScene() {
}

void TitleScene::draw(sf::RenderWindow* renderer) {
    if (image != nullptr) {
        sf::Sprite* sprite = new sf::Sprite();
        sprite->setTexture(*image);
        sprite->setPosition(0,0);

        renderer->draw(*sprite);
        delete sprite;
    }else{
        image = ImagesManager::getInstance().getImage(Images::Title);
    }
}
