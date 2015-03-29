/* 
 * File:   ImagesManager.h
 * Author: dorian
 *
 * Created on 26 de octubre de 2014, 18:16
 */

#ifndef IMAGESMANAGER_H
#define	IMAGESMANAGER_H

#include <unordered_map>
#include "HashEnum.h"
#include "Shapes.h"
#include "Images.h"
#include "ImportsShapes.h"
#include "Window.h"
#include <vector>
#include <string>
#include <iostream>
#include "AnimatedSprite.h"
#include "Animations.h"
#include "tinyxml2.h"

#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include "boost/progress.hpp"

namespace fs = boost::filesystem;

class ImagesManager {
public:
    static ImagesManager& getInstance(){
        static ImagesManager instance;
        return instance;
    }
    
    void loadImagesAnimations();
    sf::Texture* getImage(Images request);
    Animation* getAnimation(Animations request);
    
private:
    ImagesManager();
    ImagesManager(const ImagesManager& orig);
    virtual ~ImagesManager();
    
    void operator=(ImagesManager const&);
    
    void loadAnimations();
    void loadImages();
    void loadImagesFromFolder(Images image, std::string path);
    void loadAnimationsFromFolder(Animations animation, std::string path);

    bool loaded;
    
    /**
     * Map between the shapes and its images
     */
    std::unordered_map<std::string, sf::Texture> images;
    std::unordered_map<Images, std::vector<std::string>*, HashEnum> groupImages;
    std::unordered_map<std::string, Animation*> animations;
    std::unordered_map<Animations, std::vector<std::string>*, HashEnum> groupAnimations;
    
    Animation* readAnimation(std::string path, Animations animation);
};

#endif	/* IMAGESMANAGER_H */

