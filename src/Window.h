/* 
 * File:   Pantalla.h
 * Author: dorian
 *
 * Created on 10 de agosto de 2014, 19:36
 */

#ifndef WINDOW_H
#define	WINDOW_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Window {
public:
    Window();
    Window(const Window& orig);
    virtual ~Window();
    
    /**
     * Get the measure of the window
     * @return 
     */
    inline sf::IntRect getWindow() const {
        return window;
    }
    
    /**
     * Get the render where I draw
     * @return 
     */
    inline sf::RenderWindow* getRenderer() const {
        return renderer;
    }
    
    /**
     * Get the font of the game
     * @return 
     */
    inline sf::Font* getFont() const {
        return font;
    }

    void clear();
    void actualizar();
    /**
     * Draw the image on the window
     * @param imagen the image
     * @param destino size and position of the image in the window
     */
//    void copiarImagen(SDL_Texture* imagen, SDL_Rect destino);
    void copiarImagen(sf::Sprite &sprite);
    
private:
    /**
     * The measure of the window
     */
    sf::IntRect window;
    /**
     * Initialize everything
     */
    void inicializacion();
    /**
     * The render where I draw everything to be show in the window
     */
    sf::RenderWindow* renderer;
    /**
     * The font to write
     */
    sf::Font* font;
    /**
     * Initialize the fonts of the game
     */
    void initializationFonts();

};

#endif	/* PANTALLA_H */

