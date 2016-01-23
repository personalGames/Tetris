/* 
 * File:   Game.h
 * Author: dorian
 *
 * Created on 13 de septiembre de 2014, 10:30
 */

#ifndef GAME_H
#define	GAME_H

#include <stdlib.h> //NULL
#include <stdio.h> //srand y rand
#include <time.h>       /* time */
#include <vector>
#include <map>
#include "MeassureMargin.h"
#include "Score.h"
#include <sstream>
#include <string> // this should be already included in <sstream>
#include "ImagesManager.h"
#include "ImportsShapes.h"
#include "Painter.h"
#include "TitleScene.h"

#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


//TODO: reorganizar
#include "Shape.h"
#include "Shapes.h"
#include "Timer.h"
#include "TableBoard.h"
#include "Window.h"
#include "ImportsShapes.h"
#include "Command.h"
#include "Fall.h"
#include "LeftRight.h"
#include "FallToGround.h"
#include "Rotate.h"
#include "RemoveCompletedLines.h"
#include "FallEvent.h"
#include "TypeSquare.h"

#include <iostream>
    

    
using namespace std;

class Game{
public:
    Game();
    Game(const Game &orig);
    virtual ~Game();
    
    void startGame();
    
    inline bool isAnimation() const {
        return animation;
    }

    inline void setAnimation(bool animation) {
        this->animation = animation;
    }

    inline bool isPaused() const {
        return paused;
    }

    inline void setPaused(bool paused) {
        this->paused = paused;
    }
    


private:
    /**
     * The shape falling
     */
    Shape* shapeFalling;
    /**
     * The next shape ready
     */
    Shape* nextShape;
    /**
     * The board of the game
     */
    TableBoard board;
    /**
     * The score of the game
     */
    Score* score;
    /**
     * The window itself
     */
    Window pantalla;
    /**
     * Boolean which i can know if i must end the game
     */
    bool letsQuit;
    /**
     * If there is some animation rendering, stop the game until is finished
     */
    bool animation;
    /**
     * Pause the game
     */
    bool paused;
    
    bool gameOver;
    /**
     * 
     * @return 
     */
    Painter* painter;
    
    bool inTitle;
    TitleScene title;
    
    sf::Music background;
    sf::SoundBuffer titleSoundBuffer;
    sf::Sound titleSound;
    sf::SoundBuffer gameOverBuffer;
    sf::Sound gameOverSound;
    
    
    
    /**
     * Position of new shapes
     */
    int xPosition;
    
    TableBoard meassureBoardNextShape;
    
    void setEventsGame();
    
    /**
     * listen to key event and react to the user actions
     * @param evento
     */
    void keyEvent(sf::Event &evento);
    /**
     * Get a new shape
     */
    void newShape();
    /**
     * Prepare the next shape
     */
    void nextShapeFall();
    
    void loadSounds();

    
    void logicGame();
    
    void paintProcessGame();
    
    void paintGameOver();
    
    void paintPauseMessage();
    
    void setNewSpecialShape();
    
    void resetGame();
    
    bool isGameOver() const {
        return gameOver;
    }

    void setGameOver(bool gameOver) {
        this->gameOver = gameOver;
    }

};


#endif	/* GAME_H */

