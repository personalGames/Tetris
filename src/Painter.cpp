/* 
 * File:   Painter.cpp
 * Author: dorian
 * 
 * Created on 30 de octubre de 2014, 10:34
 */


#include "Painter.h"

Painter::Painter(Window &pantalla, BoardGrid board): pantalla(&pantalla), board(board) {
    
}

Painter::Painter(const Painter& orig) {
}

Painter::~Painter() {
}

void Painter::prepareBoardNextShape(){
    //get dimensions of the window
    meassureBoardNextShape = board;
    
    int yWindow = pantalla->getWindow().height;
    
    //calculate position of text next shape
    int yInitText = static_cast<int>(yWindow * 0.05);
    int xInitText = static_cast<int>(widhtMarginLeft * 0.20);

    textureTextNextShape=new sf::Text();
    textureTextNextShape->setFont(*(pantalla->getFont()));
    textureTextNextShape->setColor(sf::Color::White);
    textureTextNextShape->setString(L"Next Shape");
    textureTextNextShape->setCharacterSize(35);
    textureTextNextShape->setPosition(static_cast<float>(xInitText-(xInitText*0.5f)), static_cast<float>(yInitText));
    
    //calculate position of board for next shape
    meassureBoardNextShape.initBoardX = xInitText;
    meassureBoardNextShape.initBoardY = static_cast<int>(yInitText + textureTextNextShape->getLocalBounds().height * 1.8f);
  
}

void Painter::prepareTextPause(){
    textureTextPaused= new sf::Text();
    textureTextPaused->setFont(*(pantalla->getFont()));
    textureTextPaused->setColor(sf::Color::White);
    textureTextPaused->setString(L"Juego pausado\n"
            "Pulse P de nuevo para continuar");
    textureTextPaused->setCharacterSize(35);
    
    
    int xWindow = pantalla->getWindow().width;
    int yWindow = pantalla->getWindow().height;
    int xInitText = (xWindow / 4);
    int yInitText = static_cast<int>((yWindow / 2) - yWindow * 0.1);
    int texW = static_cast<int>(textureTextPaused->getLocalBounds().width);
    int texH = static_cast<int>(textureTextPaused->getLocalBounds().height);
    
    textureTextPaused->setPosition(static_cast<float>(xInitText), static_cast<float>(yInitText));
    
    sizeRectanglePause.height = texH * 2;
    sizeRectanglePause.width = static_cast<int>(texW + (texW * 0.3));
    
    sizeRectanglePause.left = static_cast<int>(xInitText - (texW * 0.1));
    sizeRectanglePause.top = static_cast<int>(yInitText - (texH / 2));
}

void Painter::prepareTextGameOver(){
    
    textureTextGameOver= new sf::Text();
    textureTextGameOver->setFont(*(pantalla->getFont()));
    textureTextGameOver->setColor(sf::Color::White);
    textureTextGameOver->setString(L"Ha perdido! :( \n");
    textureTextGameOver->setCharacterSize(55);
    
    
    int xWindow = pantalla->getWindow().width;
    int yWindow = pantalla->getWindow().height;
    int xInitText = (xWindow / 4);
    int yInitText = static_cast<int>((yWindow / 2) - yWindow * 0.1);
    int texW = static_cast<int>(textureTextGameOver->getLocalBounds().width);
    int texH = static_cast<int>(textureTextGameOver->getLocalBounds().height);
    
    textureTextGameOver->setPosition(static_cast<float>(xInitText), static_cast<float>(yInitText));
    
    sizeRectangleGameOver.height = texH * 2;
    sizeRectangleGameOver.width = static_cast<int>(texW + (texW * 0.3));
    
    sizeRectangleGameOver.left = static_cast<int>(xInitText - (texW * 0.1));
    sizeRectangleGameOver.top = static_cast<int>(yInitText - (texH / 2));
}

void Painter::prepareTextInstructions(){
    textureTextInstructions = new sf::Text();
    textureTextInstructions->setFont(*(pantalla->getFont()));
    textureTextInstructions->setColor(sf::Color::White);
    textureTextInstructions->setString("P para pausar el juego\n"
            "ESC para volver a inicio\n"
            "Espacio para girar la pieza\n"
            "Izq y Der para mover la pieza\n"
            "Abajo para bajar en uno la pieza");
    textureTextInstructions->setCharacterSize(18);
    
    int yInitText = 0;
    int xInitText = 0;
    int yWindow = pantalla->getWindow().height;
    xInitText = static_cast<int>(widhtMarginLeft * 0.1);
    yInitText = yWindow / 4 + yWindow / 2;
    textureTextInstructions->setPosition(static_cast<float>(xInitText), static_cast<float>(yInitText));
}

void Painter::prepareScores(){
    int xInitText=0;
    int yInitText=0;
    //calculate position of text score
    xInitText = static_cast<int>((widhtMarginRight * 0.20) + board.widhtBoard + widhtMarginLeft);
    textureTextScore= new sf::Text();
    textureTextScore->setFont(*(pantalla->getFont()));
    textureTextScore->setColor(sf::Color::White);
    textureTextScore->setString(L"Score");
    textureTextScore->setCharacterSize(30);
    textureTextScore->setPosition(static_cast<float>(xInitText), static_cast<float>(yInitText+textureTextScore->getLocalBounds().height*1.5f));
    yInitText=static_cast<int>(yInitText+textureTextScore->getLocalBounds().height*1.8);
    
    //calculate rectangle of score
    sizeRectangleScore.left = xInitText;
    sizeRectangleScore.top = static_cast<int>(yInitText + textureTextScore->getLocalBounds().height * 1.5);
    sizeRectangleScore.height = static_cast<int>(textureTextScore->getLocalBounds().height * 1.5);
    sizeRectangleScore.width = static_cast<int>(widhtMarginRight - (widhtMarginRight * 0.4));
    
    xInitScore = static_cast<int>(sizeRectangleScore.left + sizeRectangleScore.width * 0.1);
    yInitScore = static_cast<int>(sizeRectangleScore.top + sizeRectangleScore.height * 0.03);
    int separationBetweenSections = static_cast<int>(sizeRectangleScore.height + textureTextScore->getLocalBounds().height * 1.5);

    //calculate position of text Level
    yInitText = yInitText + separationBetweenSections;
    
    textureTextLevel= new sf::Text();
    textureTextLevel->setFont(*(pantalla->getFont()));
    textureTextLevel->setColor(sf::Color::White);
    textureTextLevel->setString(L"Level");
    textureTextLevel->setCharacterSize(30);
    textureTextLevel->setPosition(static_cast<float>(xInitText), static_cast<float>(yInitText + textureTextScore->getLocalBounds().height * 1.5f));

    yInitText= static_cast<int>(yInitText+textureTextLevel->getLocalBounds().height*1.8);
    //calculate rectangle of level
    sizeRectangleLevel.left = xInitText;
    sizeRectangleLevel.top = static_cast<int>(yInitText + textureTextLevel->getLocalBounds().height * 1.5);
    sizeRectangleLevel.height = static_cast<int>(textureTextLevel->getLocalBounds().height*1.5);
    sizeRectangleLevel.width = static_cast<int>(widhtMarginRight - (widhtMarginRight * 0.4));
    
    xInitLevel = static_cast<int>(sizeRectangleLevel.left + sizeRectangleLevel.width * 0.1);
    yInitLevel = static_cast<int>(sizeRectangleLevel.top + sizeRectangleLevel.height * 0.03);


    //calculate position of text Lines
    yInitText = yInitText + separationBetweenSections;
    textureTextLines= new sf::Text();
    textureTextLines->setFont(*(pantalla->getFont()));
    textureTextLines->setColor(sf::Color::White);
    textureTextLines->setString(L"Lines");
    textureTextLines->setCharacterSize(30);
    textureTextLines->setPosition(static_cast<float>(xInitText), yInitText+textureTextScore->getLocalBounds().height*1.5f);
    
    yInitText= static_cast<int>(yInitText+textureTextLines->getLocalBounds().height*1.8);
    //calculate rectangle of lines
    sizeRectangleLines.left = xInitText;
    sizeRectangleLines.top = static_cast<int>(yInitText + textureTextLines->getLocalBounds().height * 1.5);
    sizeRectangleLines.height = static_cast<int>(textureTextLines->getLocalBounds().height*1.5);
    sizeRectangleLines.width = static_cast<int>(widhtMarginRight - (widhtMarginRight * 0.4));
    
    

    xInitLines = static_cast<int>(sizeRectangleLines.left + sizeRectangleLines.width * 0.1);
    yInitLines = static_cast<int>(sizeRectangleLines.top + sizeRectangleLines.height * 0.03);
}

void Painter::prepareInterface(){
    int xWindow = pantalla->getWindow().width;
    //calculate the width of the margins
    widhtMarginRight = xWindow - (board.widhtBoard + board.initBoardX);
    widhtMarginLeft = xWindow - (widhtMarginRight + board.widhtBoard);
    
    prepareBoardNextShape();
    prepareScores();
    prepareTextGameOver();
    prepareTextInstructions();
    prepareTextPause();
}


void Painter::paintScore(Score &score) {
    //get the score
    int actualScore = score.getScore();
    //convert to a string
    string convertedScore;
    ostringstream convert;
    convert << actualScore;
    convertedScore = convert.str();
    
    sf::Text* texture;
    texture = new sf::Text();
    texture->setFont(*(pantalla->getFont()));
    texture->setColor(sf::Color::White);
    texture->setString(convertedScore);
    texture->setCharacterSize(30);
    texture->setPosition(static_cast<float>(xInitScore), static_cast<float>(yInitScore));
    
    pantalla->getRenderer()->draw(*texture);
    delete texture;
}

void Painter::paintLevel(Score &score) {
    //get the score
    int actualLevel = score.getLevel();
    //convert to a string
    string convertedLevel;
    ostringstream convert;
    convert << actualLevel;
    convertedLevel = convert.str();
    
    sf::Text* texture;
    texture = new sf::Text();
    texture->setFont(*(pantalla->getFont()));
    texture->setColor(sf::Color::White);
    texture->setString(convertedLevel);
    texture->setCharacterSize(30);
    texture->setPosition(static_cast<float>(xInitLevel), static_cast<float>(yInitLevel));
    
    pantalla->getRenderer()->draw(*texture);
    delete texture;
}

void Painter::paintLines(Score &score) {
    //get the score
    int actualLines = score.getLines();
    //convert to a string
    string convertedLines;
    ostringstream convert;
    convert << actualLines;
    convertedLines = convert.str();
    
    sf::Text* texture;
    texture = new sf::Text();
    texture->setFont(*(pantalla->getFont()));
    texture->setColor(sf::Color::White);
    texture->setString(convertedLines);
    texture->setCharacterSize(30);
    texture->setPosition(static_cast<float>(xInitLines), static_cast<float>(yInitLines));
    
    pantalla->getRenderer()->draw(*texture);
    delete texture;
}

void Painter::paintRectangle(sf::IntRect &rect, sf::Color &color) {
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(static_cast<float>(rect.width), static_cast<float>(rect.height)));
    rectangle.setOutlineThickness(1);
    rectangle.setPosition(static_cast<float>(rect.left), static_cast<float>(rect.top));
    rectangle.setFillColor(color);
    
    pantalla->getRenderer()->draw(rectangle);
}

void Painter::paintBoardNext() {
    int numberColumn = 4;
    int numberRow = 6;

    int yFinal = meassureBoardNextShape.initBoardY + meassureBoardNextShape.heigthCell*numberRow;
    int xFinal = meassureBoardNextShape.initBoardX + meassureBoardNextShape.widthCell*numberColumn;

    for (int i = 0; i < numberColumn + 1; i++) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(static_cast<float>(i * meassureBoardNextShape.widthCell + meassureBoardNextShape.initBoardX),
									static_cast<float>(meassureBoardNextShape.initBoardY))),
            sf::Vertex(sf::Vector2f(static_cast<float>(i * meassureBoardNextShape.widthCell + meassureBoardNextShape.initBoardX),
				static_cast<float>(yFinal)))
        };
        pantalla->getRenderer()->draw(line, 2, sf::Lines);

    }

    for (int i = 0; i < numberRow + 1; i++) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(static_cast<float>(meassureBoardNextShape.initBoardX),
				static_cast<float>(i * meassureBoardNextShape.heigthCell + meassureBoardNextShape.initBoardY))),
            sf::Vertex(sf::Vector2f(static_cast<float>(xFinal),
				static_cast<float>(i * meassureBoardNextShape.heigthCell + meassureBoardNextShape.initBoardY)))
        };
        pantalla->getRenderer()->draw(line, 2, sf::Lines);
    }
}

void Painter::paintInterface(Score &score) {
    pantalla->getRenderer()->draw(*textureTextInstructions);
    pantalla->getRenderer()->draw(*textureTextNextShape);
    pantalla->getRenderer()->draw(*textureTextScore);
    pantalla->getRenderer()->draw(*textureTextLines);
    pantalla->getRenderer()->draw(*textureTextLevel);
    sf::Color *color=new sf::Color(0, 0, 153, 235);
    paintRectangle(sizeRectangleScore, *color);
    paintRectangle(sizeRectangleLevel, *color);
    paintRectangle(sizeRectangleLines, *color);
    paintBoardNext();
    paintScore(score);
    paintLevel(score);
    paintLines(score);
    delete color;
}

void Painter::paintGameOver() {
    sf::Color* color=new sf::Color(60,60,60,245);
    paintRectangle(sizeRectangleGameOver,*color);
    pantalla->getRenderer()->draw(*textureTextGameOver);
}

void Painter::paintPauseMessage() {
    sf::Color* color=new sf::Color(60,60,60,245);
    paintRectangle(sizeRectanglePause,*color);
    pantalla->getRenderer()->draw(*textureTextPaused);
}