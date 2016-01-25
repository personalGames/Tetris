/*
 * File:   Pantalla.cpp
 * Author: dorian
 *
 * Created on 10 de agosto de 2014, 19:36
 */



#include "Window.h"
#include <math.h>
#include <cstdlib>

using namespace std;

Window::Window() {
    window.width = 1024;
    window.height= 768;

    inicializacion();
    initializationFonts();

}

Window::Window(const Window& orig) {
}

Window::~Window() {
}

void Window::actualizar() {
    // Mostramos la pantalla
    renderer->display();
}

void Window::clear() {
    renderer->clear(sf::Color(0,0,0));
}

void Window::copiarImagen(sf::Sprite &sprite){
    renderer->draw(sprite);
}

void Window::inicializacion() {
   renderer=new sf::RenderWindow(sf::VideoMode(window.width, window.height, 32), "Tetris");
   renderer->setVerticalSyncEnabled(true);
    this->clear();
}

void Window::initializationFonts() {
    font=new sf::Font;
    font->loadFromFile("resources/fonts/arial.ttf");
     
}