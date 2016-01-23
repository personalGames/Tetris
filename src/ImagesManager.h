/* 
 * File:   ImagesManager.h
 * Author: dorian
 *
 * Created on 26 de octubre de 2014, 18:16
 */

#ifndef IMAGESMANAGER_H
#define	IMAGESMANAGER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "HashEnum.h"
#include "Shapes.h"
#include "Images.h"

#include <vector>
#include <string>



class ImagesManager {
public:
    static ImagesManager& getInstance(){
        static ImagesManager instance;
        return instance;
    }
    
    void loadImagesAnimations();
    sf::Texture* getImage(Images request);
    
private:
    ImagesManager();
    ImagesManager(const ImagesManager& orig);
    virtual ~ImagesManager();
    
    void operator=(ImagesManager const&);
    
    void loadImages();
    void loadImagesFromFolder(Images image, std::string path);

    bool loaded;
    
    /**
     * Map between the shapes and its images
     */
    std::unordered_map<std::string, sf::Texture> images;
    std::unordered_map<Images, std::vector<std::string>*, HashEnum> groupImages;
    
};

#endif	/* IMAGESMANAGER_H */

