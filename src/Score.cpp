/* 
 * File:   Score.cpp
 * Author: dorian
 * 
 * Created on 21 de septiembre de 2014, 22:52
 */

#include "Score.h"

Score::Score() {
    score = 0;
    lines = 0;
    level = 1;
    nextLevel = 0;
    velocity=1000;
    velocityBuilding=7000;
    calculateNextLevel();
}

Score::Score(const Score& orig) {
    score = orig.score;
    lines = orig.lines;
    level = orig.level;
    
    velocity=orig.velocity;
    velocityBuilding=orig.velocityBuilding;
    
    calculateNextLevel();
}

Score::~Score() {

}

void Score::explodedSquares(int numberSquares){
    score+=((numberSquares)*0.2)*4;
    score+=numberSquares*3;
}

void Score::incrementLine(int x) {
    int plus=((x-1)*0.2)*5;
    lines+=x;
    
    while (x > 0) {
        score += 10;
        x--;
    }
    
    score+=plus;

    while (score >= nextLevel) {
        level++;
        //otras consecuencias, subir velocidad, dificultad...
        calculateVelocity();
        calculateNextLevel();
    }
}



void Score::calculateNextLevel() {
    nextLevel = nextLevel + 10 * (level * 3);
}

void Score::calculateVelocity() {
    velocity=1000-(level*0.1);
    velocityBuilding=5000-(level*0.1);
}

