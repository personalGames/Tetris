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
    int yInitText = yWindow * 0.05;
    int xInitText = widhtMarginLeft * 0.20;

    textureTextNextShape=new sf::Text();
    textureTextNextShape->setFont(*(pantalla->getFont()));
    textureTextNextShape->setColor(sf::Color::White);
    textureTextNextShape->setString(L"Next Shape");
    textureTextNextShape->setCharacterSize(35);
    textureTextNextShape->setPosition(xInitText-(xInitText*0.5), yInitText);
    
    //calculate position of board for next shape
    meassureBoardNextShape.initBoardX = xInitText;
    meassureBoardNextShape.initBoardY = yInitText + textureTextNextShape->getLocalBounds().height * 1.8;
  
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
    int yInitText = (yWindow / 2) - yWindow * 0.1;
    int texW = textureTextPaused->getLocalBounds().width;
    int texH = textureTextPaused->getLocalBounds().height;
    
    textureTextPaused->setPosition(xInitText,yInitText);
    
    sizeRectanglePause.height = texH * 2;
    sizeRectanglePause.width = texW + (texW * 0.3);
    
    sizeRectanglePause.left = xInitText - (texW * 0.1);
    sizeRectanglePause.top = yInitText - (texH / 2);
}

void Painter::prepareTextGameOver(){
    
    textureTextGameOver= new sf::Text();
    textureTextGameOver->setFont(*(pantalla->getFont()));
    textureTextGameOver->setColor(sf::Color::White);
    textureTextGameOver->setString(L"¡Ha perdido! :(\n"
    "R para nueva partida");
    textureTextGameOver->setCharacterSize(55);
    
    
    int xWindow = pantalla->getWindow().width;
    int yWindow = pantalla->getWindow().height;
    int xInitText = (xWindow / 4);
    int yInitText = (yWindow / 2) - yWindow * 0.1;
    int texW = textureTextGameOver->getLocalBounds().width;
    int texH = textureTextGameOver->getLocalBounds().height;
    
    textureTextGameOver->setPosition(xInitText,yInitText);
    
    sizeRectangleGameOver.height = texH * 2;
    sizeRectangleGameOver.width = texW + (texW * 0.3);
    
    sizeRectangleGameOver.left = xInitText - (texW * 0.1);
    sizeRectangleGameOver.top = yInitText - (texH / 2);
}

void Painter::prepareTextInstructions(){
    textureTextInstructions = new sf::Text();
    textureTextInstructions->setFont(*(pantalla->getFont()));
    textureTextInstructions->setColor(sf::Color::White);
    textureTextInstructions->setString("P para pausar el juego\n"
            "ESC para salir del juego\n"
            "Espacio para girar la pieza\n"
            "Izq y Der para mover la pieza\n"
            "Abajo para bajar en uno la pieza");
    textureTextInstructions->setCharacterSize(18);
    
    int yInitText = 0;
    int xInitText = 0;
    int yWindow = pantalla->getWindow().height;
    xInitText = widhtMarginLeft * 0.1;
    yInitText = yWindow / 4 + yWindow / 2;
    textureTextInstructions->setPosition(xInitText,yInitText);
}

void Painter::prepareScores(){
    int xInitText=0;
    int yInitText=0;
    //calculate position of text score
    xInitText = (widhtMarginRight * 0.20) + board.widhtBoard + widhtMarginLeft;
    textureTextScore= new sf::Text();
    textureTextScore->setFont(*(pantalla->getFont()));
    textureTextScore->setColor(sf::Color::White);
    textureTextScore->setString(L"Score");
    textureTextScore->setCharacterSize(30);
    textureTextScore->setPosition(xInitText, yInitText+textureTextScore->getLocalBounds().height*1.5);
    yInitText=yInitText+textureTextScore->getLocalBounds().height*1.8;
    
    //calculate rectangle of score
    sizeRectangleScore.left = xInitText;
    sizeRectangleScore.top = yInitText + textureTextScore->getLocalBounds().height * 1.5;
    sizeRectangleScore.height = textureTextScore->getLocalBounds().height * 1.5;
    sizeRectangleScore.width = widhtMarginRight - (widhtMarginRight * 0.4);
    
    xInitScore = sizeRectangleScore.left + sizeRectangleScore.width * 0.1;
    yInitScore = sizeRectangleScore.top + sizeRectangleScore.height * 0.03;
    int separationBetweenSections = sizeRectangleScore.height + textureTextScore->getLocalBounds().height * 1.5;

    //calculate position of text Level
    yInitText = yInitText + separationBetweenSections;
    
    textureTextLevel= new sf::Text();
    textureTextLevel->setFont(*(pantalla->getFont()));
    textureTextLevel->setColor(sf::Color::White);
    textureTextLevel->setString(L"Level");
    textureTextLevel->setCharacterSize(30);
    textureTextLevel->setPosition(xInitText, yInitText + textureTextScore->getLocalBounds().height * 1.5);

    yInitText=yInitText+textureTextLevel->getLocalBounds().height*1.8;
    //calculate rectangle of level
    sizeRectangleLevel.left = xInitText;
    sizeRectangleLevel.top = yInitText + textureTextLevel->getLocalBounds().height * 1.5;
    sizeRectangleLevel.height = textureTextLevel->getLocalBounds().height*1.5;
    sizeRectangleLevel.width = widhtMarginRight - (widhtMarginRight * 0.4);
    
    xInitLevel = sizeRectangleLevel.left + sizeRectangleLevel.width * 0.1;
    yInitLevel = sizeRectangleLevel.top + sizeRectangleLevel.height * 0.03;


    //calculate position of text Lines
    yInitText = yInitText + separationBetweenSections;
    textureTextLines= new sf::Text();
    textureTextLines->setFont(*(pantalla->getFont()));
    textureTextLines->setColor(sf::Color::White);
    textureTextLines->setString(L"Lines");
    textureTextLines->setCharacterSize(30);
    textureTextLines->setPosition(xInitText, yInitText+textureTextScore->getLocalBounds().height*1.5);
    
    yInitText=yInitText+textureTextLines->getLocalBounds().height*1.8;
    //calculate rectangle of lines
    sizeRectangleLines.left = xInitText;
    sizeRectangleLines.top = yInitText + textureTextLines->getLocalBounds().height * 1.5;
    sizeRectangleLines.height = textureTextLines->getLocalBounds().height*1.5;
    sizeRectangleLines.width = widhtMarginRight - (widhtMarginRight * 0.4);
    
    

    xInitLines = sizeRectangleLines.left + sizeRectangleLines.width * 0.1;
    yInitLines = sizeRectangleLines.top + sizeRectangleLines.height * 0.03;
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
    texture->setPosition(xInitScore, yInitScore);
    
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
    texture->setPosition(xInitLevel, yInitLevel);
    
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
    texture->setPosition(xInitLines, yInitLines);
    
    pantalla->getRenderer()->draw(*texture);
    delete texture;
}

void Painter::paintRectangle(sf::IntRect &rect, sf::Color &color) {
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(rect.width, rect.height));
    rectangle.setOutlineThickness(1);
    rectangle.setPosition(rect.left,rect.top);
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
            sf::Vertex(sf::Vector2f(i * meassureBoardNextShape.widthCell + meassureBoardNextShape.initBoardX,
            meassureBoardNextShape.initBoardY)),
            sf::Vertex(sf::Vector2f(i * meassureBoardNextShape.widthCell + meassureBoardNextShape.initBoardX,
            yFinal))
        };
        pantalla->getRenderer()->draw(line, 2, sf::Lines);

    }

    for (int i = 0; i < numberRow + 1; i++) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(meassureBoardNextShape.initBoardX,
            i * meassureBoardNextShape.heigthCell + meassureBoardNextShape.initBoardY)),
            sf::Vertex(sf::Vector2f(xFinal,
            i * meassureBoardNextShape.heigthCell + meassureBoardNextShape.initBoardY))
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