/* 
 * File:   mainTestShapes.cpp
 * Author: dorian
 *
 * Created on 12 de septiembre de 2014, 16:56
 */

//#include "../include/shape/Shape.h"
//#include "../include/elements/Square.h"
//#include "../include/game/TableBoard.h"
//#include "../include/game/Window.h"
//
//#include "../include/shape/IShape.h"
//#include "../include/shape/OShape.h"
//#include "../include/shape/LShape.h"
//#include "../include/shape/JShape.h"
//#include "../include/shape/SShape.h"
//#include "../include/shape/ZShape.h"
//#include "../include/shape/TShape.h"

/*
 * 
 */
//int main(int argc, char** argv) {
//    Window pantalla;
//    SDL_Event evento;
//    TableBoard board((pantalla.getWindow()));
//    
//    
//    SDL_Texture* image = IMG_LoadTexture(pantalla.getPantalla(), 
//            "resources/images/blue_bold.png");
//    
////    creo una celda, le paso datos de table y que él se pinte
//    Square* square=new Square();
//
//    square=new Square();
//    Board meassureBoard=board.getMeassureBoard();
//    square->setGraphics(meassureBoard, image);
//    square->setX(0);
//    square->setY(0);
//
//    Shape* shape=new LShape(*square);
//    shape->paint(pantalla.getPantalla());
//    
//    square->setX(2);
//    square->setY(3);
//    shape=new LShape(*square);
//    shape->rotate();
//    shape->paint(pantalla.getPantalla());
//    
//    square->setX(4);
//    square->setY(6);
//    shape=new LShape(*square);
//    shape->rotate();
//    shape->rotate();
//    shape->paint(pantalla.getPantalla());
//    
//    square->setX(6);
//    square->setY(10);
//    shape=new LShape(*square);
//    shape->rotate();shape->rotate();
//    shape->rotate();
//    shape->paint(pantalla.getPantalla());
//    
//    
//    
//    image = IMG_LoadTexture(pantalla.getPantalla(), 
//            "resources/images/green_bold.png");
//    square->setGraphics(meassureBoard,image);
//    square->setX(2);
//    square->setY(13);
//    shape=new IShape(*square);
//    shape->paint(pantalla.getPantalla());
//    
//    
//    square->setX(7);
//    square->setY(0);
//    shape=new IShape(*square);
//    shape->rotate();
//    shape->paint(pantalla.getPantalla());
//    
//    square->setX(8);
//    square->setY(3);
//    shape=new JShape(*square);
//    shape->paint(pantalla.getPantalla());
//    
//    square->setX(7);
//    square->setY(17);
//    shape=new JShape(*square);
//    shape->rotate();
//    shape->paint(pantalla.getPantalla());
//    
//    
//    square->setX(6);
//    square->setY(13);
//    shape=new JShape(*square);
//    shape->rotate();shape->rotate();
//    shape->paint(pantalla.getPantalla());
//    
//    
//    square->setX(6);
//    square->setY(7);
//    shape=new JShape(*square);
//    shape->rotate();shape->rotate();shape->rotate();
//    shape->paint(pantalla.getPantalla());
//    
//    
//    
//    image = IMG_LoadTexture(pantalla.getPantalla(), 
//            "resources/images/red_bold.png");
//    square->setGraphics(meassureBoard,image);
//    square->setX(1);
//    square->setY(9);
//    shape=new ZShape(*square);
//    shape->rotate();
//    shape->paint(pantalla.getPantalla());
//    
//    square->setX(0);
//    square->setY(6);
//    shape=new ZShape(*square);
//    shape->paint(pantalla.getPantalla());
//    
//    
//    square->setX(2);
//    square->setY(0);
//    shape=new OShape(*square);
//    shape->paint(pantalla.getPantalla());
//    
//    
//    image = IMG_LoadTexture(pantalla.getPantalla(), 
//            "resources/images/orange_bold.png");
//    square->setGraphics(meassureBoard,image);
//    square->setX(6);
//    square->setY(2);
//    shape=new SShape(*square);
//    shape->rotate();
//    shape->paint(pantalla.getPantalla());
//    
//    square->setX(0);
//    square->setY(17);
//    shape=new SShape(*square);
//    shape->paint(pantalla.getPantalla());
//    
//    
//    square->setX(3);
//    square->setY(18);
//    shape=new TShape(*square);
//    shape->paint(pantalla.getPantalla());
//    
//    square->setX(8);
//    square->setY(9);
//    shape=new TShape(*square);
//    shape->rotate();
//    shape->paint(pantalla.getPantalla());
//    
//    square->setX(4);
//    square->setY(13);
//    shape=new TShape(*square);
//    shape->rotate();shape->rotate();
//    shape->paint(pantalla.getPantalla());
//    
//    square->setX(-1);
//    square->setY(11);
//    shape=new TShape(*square);
//    shape->rotate();shape->rotate();shape->rotate();
//    shape->paint(pantalla.getPantalla());
//    
//    
//    
//    board.drawLines(pantalla.getPantalla());
//    pantalla.actualizar();
//
//    // Ahora mantenemos el resultado en pantalla
//    // Hasta pulsar escape
//    while (1 == 1) {
//        // Consultamos los eventos
//        while (SDL_PollEvent(&evento)) {
//            if (evento.type == SDL_KEYDOWN || evento.type == SDL_QUIT) { // Si es de salida
//                return 0;
//            }
//        }
//    }
//
//    return 0;
//}