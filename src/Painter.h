/* 
 * File:   Painter.h
 * Author: dorian
 *
 * Created on 30 de octubre de 2014, 10:34
 */

#ifndef PAINTER_H
#define	PAINTER_H

#include "MeassureBoard.h"
#include "TableBoard.h"
#include "MeassureBoard.h"
#include "Score.h"
#include "Window.h"
#include <sstream>
#include <SFML/Graphics.hpp>
#include <string> // this should be already included in <sstream>

class Painter {
public:
    Painter(Window &pantalla, BoardGrid board);
    Painter(const Painter& orig);
    virtual ~Painter();
    
    void prepareInterface();
    
    void paintPauseMessage();
    void paintGameOver();
    
    void paintScore(Score &score);
    void paintLevel(Score &score);
    void paintLines(Score &score);
    void paintBoardNext();
    void paintInterface(Score &score);
    
    inline BoardGrid getMeassureBoardNextShape() const {
        return meassureBoardNextShape;
    }
    
private:
    Window* pantalla;
    BoardGrid board;
    
    //position where score will be draw
    int xInitScore;
    int yInitScore;
    
    //position where the number of lines will be draw
    int xInitLines;
    int yInitLines;
    
    //position where level will be draw
    int xInitLevel;
    int yInitLevel;
    
    int widhtMarginRight;
    int widhtMarginLeft;
    
    /**
     * Position board next shape
     */
    BoardGrid meassureBoardNextShape;
    
    /**
     * Textures ("images") of the text that will be draw
     */
    sf::Text* textureTextScore;
    sf::Text* textureTextLevel;
    sf::Text* textureTextLines;
    sf::Text* textureTextPaused;
    sf::Text* textureTextInstructions;
    sf::Text* textureTextGameOver;
    sf::Text* textureTextNextShape;
    
    /**
     * Sizes and positions where the level, score and lines removed will be
     * draw
     */
    sf::IntRect sizeRectangleLevel;
    sf::IntRect sizeRectangleScore;
    sf::IntRect sizeRectangleLines;
    sf::IntRect sizeRectanglePause;
    sf::IntRect sizeRectangleGameOver;
    
    /**
     * Paint a rectangle with the given size and position
     * @param rect
     */
    void paintRectangle(sf::IntRect &rect, sf::Color &color);
    
    void prepareTextInstructions();
    void prepareTextGameOver();
    void prepareTextPause();
    void prepareBoardNextShape();
    void prepareScores();
    
    
};

#endif	/* PAINTER_H */

