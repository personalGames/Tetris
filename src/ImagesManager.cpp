/* 
 * File:   ImagesManager.cpp
 * Author: dorian
 * 
 * Created on 26 de octubre de 2014, 18:16
 */

#include "ImagesManager.h"
#include "tinyxml2.h"

#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include "boost/progress.hpp"
#include "ImportsShapes.h"
#include "Window.h"
#include <iostream>

namespace fs = boost::filesystem;

ImagesManager::ImagesManager() {
    loaded = false;
}

ImagesManager::~ImagesManager() {
}

void ImagesManager::loadImagesAnimations() {
    loadImages();
}

void ImagesManager::loadImages() {
    loadImagesFromFolder(Images::Square, "resources/images/squares");
    loadImagesFromFolder(Images::Title, "resources/images/title");
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
