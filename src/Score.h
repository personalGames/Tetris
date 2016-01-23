/* 
 * File:   Score.h
 * Author: dorian
 *
 * Created on 21 de septiembre de 2014, 22:52
 */

#ifndef SCORE_H
#define	SCORE_H

#include <iostream>
#include <SFML/Audio.hpp>

class Score {
public:
    Score();
    Score(const Score& orig);
    virtual ~Score();
    
    inline void incrementLine(){
        incrementLine(1);
    }
    
    void incrementLine(int x);
    inline int getScore() const{
        return score;
    }
    inline int getLines() const{
        return lines;
    }
    inline int getLevel() const{
        return level;
    }
    
    inline int getVelocity() const{
        return velocity;
    }
    
private:
    int score;
    int lines;
    int linesNextLevel;
    int level;
    int nextLevel;
    int velocity;
    
    sf::SoundBuffer levelUpSound;
    sf::Sound levelUp;
    
    sf::SoundBuffer amazingSound;
    sf::Sound amazing;
    
    sf::SoundBuffer wonderfulSound;
    sf::Sound wonderful;
    
    inline void incrementLevel(int x){
        level+=x;
    }
    
    inline void incrementLevel(){
        level++;
    }
    void calculateVelocity();
    void calculateNextLevel();
};

#endif	/* SCORE_H */

