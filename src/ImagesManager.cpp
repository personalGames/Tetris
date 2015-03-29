/* 
 * File:   ImagesManager.cpp
 * Author: dorian
 * 
 * Created on 26 de octubre de 2014, 18:16
 */

#include "ImagesManager.h"

#include <iostream>

ImagesManager::ImagesManager() {
    loaded = false;
}

ImagesManager::~ImagesManager() {
}

void ImagesManager::loadImagesAnimations() {
    loadImages();
    loadAnimations();
}

void ImagesManager::loadImages() {
    loadImagesFromFolder(Images::Square, "resources/images/squares");
    loadImagesFromFolder(Images::Bomb, "resources/images/bomb");
    loadImagesFromFolder(Images::Maze, "resources/images/pick");
    loadImagesFromFolder(Images::Complaint, "resources/images/others");
    loadImagesFromFolder(Images::Food, "resources/images/food");

    loaded = true;
}

void ImagesManager::loadImagesFromFolder(Images image, std::string path) {
    std::vector<std::string> *vectorImages = new std::vector<std::string>();

    if (!boost::filesystem::exists(path)) {
        return;
    }

    boost::filesystem::directory_iterator end_iter;
    if (boost::filesystem::is_directory(path)) {
        for (boost::filesystem::directory_iterator dir_itr(path); dir_itr != end_iter; ++dir_itr) {
            try {
                boost::filesystem::file_status status = dir_itr->status();
                if (fs::is_directory(status)) {
                    continue;

                } else if (fs::is_regular_file(status)) {
                    std::string pathFilename = dir_itr->path().string();
                    images[pathFilename] = *new sf::Texture;
                    images[pathFilename].loadFromFile(pathFilename);
                    vectorImages->push_back(pathFilename);

                }
            } catch (const std::exception &ex) {
                std::cout << dir_itr->path().filename() << " " << ex.what() << std::endl;
            }
        }
    }

    groupImages[image] = vectorImages;

}

sf::Texture * ImagesManager::getImage(Images request) {
    std::vector<std::string>* alternatives = groupImages[request];
    int size = alternatives->size();
    int azar = (rand() % size);
    std::string azarImage = alternatives->at(azar);
    return &images[azarImage];
}

Animation* ImagesManager::getAnimation(Animations request) {
    std::vector<std::string>* alternatives = groupAnimations[request];
    int size = alternatives->size();
    int azar = (rand() % size);
    std::string azarAnimation = alternatives->at(azar);
    return animations[azarAnimation];
}

void ImagesManager::loadAnimations() {
    loadAnimationsFromFolder(Animations::Explosion, "resources/animations/explosions");
    loadAnimationsFromFolder(Animations::Animal, "resources/animations/animals");
}

void ImagesManager::loadAnimationsFromFolder(Animations animation, std::string path) {
    std::vector<std::string> *vectorAnimations = new std::vector<std::string>();

    if (!boost::filesystem::exists(path)) {
        return;
    }

    boost::filesystem::directory_iterator end_iter;
    if (boost::filesystem::is_directory(path)) {
        for (boost::filesystem::directory_iterator dir_itr(path); dir_itr != end_iter; ++dir_itr) {
            try {
                boost::filesystem::file_status status = dir_itr->status();
                if (fs::is_directory(status)) {
                    continue;

                } else if (fs::is_regular_file(status)) {
                    std::string pathFilename = dir_itr->path().string();
                    animations[pathFilename] = readAnimation(pathFilename, animation);
                    vectorAnimations->push_back(pathFilename);

                }
            } catch (const std::exception &ex) {
                std::cout << dir_itr->path().filename() << " " << ex.what() << std::endl;
            }
        }
    }

    groupAnimations[animation] = vectorAnimations;
}

Animation* ImagesManager::readAnimation(std::string path, Animations animation) {
    int num_frames;
    int size_x;
    int size_y;
    int num_columns;
    int num_rows;
    const char* path_char = path.c_str();

    tinyxml2::XMLDocument doc;
    doc.LoadFile(path_char);
    tinyxml2::XMLElement* root = doc.FirstChildElement();

    std::cout<<path<<std::endl;
    tinyxml2::XMLElement* element = root->FirstChildElement("num_frames");
    element->QueryIntAttribute("v", &num_frames);

    element = root->FirstChildElement("size_frame");
    element->QueryIntAttribute("x", &size_x);
    element->QueryIntAttribute("y", &size_y);
    
    element = root->FirstChildElement("num_columns");
    element->QueryIntAttribute("v", &num_columns);
    
    element = root->FirstChildElement("num_rows");
    element->QueryIntAttribute("v", &num_rows);

    element = root->FirstChildElement("image");
    std::string pathImage= element->Attribute("v");
    
    Animation* animationLoaded=new Animation();
    sf::Texture* image = new sf::Texture;
    image->loadFromFile(pathImage);
    animationLoaded->setSpriteSheet(*image);
    
    for(int y=0; y<num_rows; y++){
        for(int x=0; x<num_columns; x++){
            animationLoaded->addFrame(sf::IntRect(x*size_x,y*size_y,size_x,size_y));
        }
    }

    return animationLoaded;
}

