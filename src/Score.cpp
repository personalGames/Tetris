/* 
 * File:   Score.cpp
 * Author: dorian
 * 
 * Created on 21 de septiembre de 2014, 22:52
 */

#include "Score.h"
#include <cmath>
#include <SFML/Audio/Sound.hpp>

Score::Score() {
    score = 0;
    lines = 0;
    level = 1;
    linesNextLevel = 0;
    nextLevel = 0;
    calculateVelocity();
    
    if(levelUpSound.loadFromFile("resources/audio/SFX_LevelUp.ogg")){
        levelUp.setVolume(20);
        levelUp.setBuffer(levelUpSound);
    }
    
    if(wonderfulSound.loadFromFile("resources/audio/VO_WONDRFL.ogg")){
        wonderful.setVolume(100);
        wonderful.setBuffer(wonderfulSound);
    }
    
    if(amazingSound.loadFromFile("resources/audio/VO_AMAZING.ogg")){
        amazing.setVolume(100);
        amazing.setBuffer(amazingSound);
    }
}

Score::Score(const Score& orig) {
    score = orig.score;
    lines = orig.lines;
    level = orig.level;
    
    velocity=orig.velocity;
    
    calculateNextLevel();
}

Score::~Score() {
    
}


void Score::incrementLine(int x) {
    int plus;
    switch(x){
        case 1:
            plus=40;
            
            break;
        case 2:
            plus=100;
            break;
        case 3:
            plus=300;
            amazing.play();
            break;
        default:
            plus=1200;
            wonderful.play();
            break;
    }
    lines+=x;
    linesNextLevel+=x;
    
    score += plus * level;
    

    while (linesNextLevel >= 10) {
        level++;
        //sound!
        levelUp.play();
        //otras consecuencias, subir velocidad, dificultad...
        calculateVelocity();
        calculateNextLevel();
    }
}



void Score::calculateNextLevel() {
    linesNextLevel-=10;
}

void Score::calculateVelocity() {
    if(level>10){
        velocity= 100;
    }else{
        velocity = 100 * (11-level);
    }
}

