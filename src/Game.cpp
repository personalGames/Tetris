
#include "Game.h"

Game::Game() {
    /* initialize random seed: */
    srand(time(NULL));
    letsQuit = false;
    shapeFalling = nullptr;
    nextShape = nullptr;
    board = TableBoard(pantalla.getWindow(), 20, 10);
    score = Score();
    ImagesManager::getInstance().loadImagesAnimations();
    
    
    setEventsGame();
    
    paintedGameOver=false;
    paintedPause = false;
    paused = false;
    gameOver = false;
    animation = false;
    painter=new Painter(pantalla, board.getMeassureBoard());
    painter->prepareInterface();
    //position where new shapes will appear
    xPosition = (int) board.getNumberColumns() / 2;
    xPosition -= 1;
    special=false;
}

Game::Game(const Game &orig) {
    /* initialize random seed: */
    srand(time(NULL));
    letsQuit = orig.letsQuit;
    shapeFalling = orig.shapeFalling;
    nextShape = orig.nextShape;
    board = orig.board;
    score = orig.score;
    ImagesManager::getInstance().loadImagesAnimations();
    setEventsGame();
    paintedPause = orig.paintedPause;
    paintedGameOver=orig.paintedGameOver;
    paused = orig.paused;
    gameOver = orig.gameOver;
    animation = orig.animation;
    painter=orig.painter;
    //position where new shapes will appear
    xPosition = orig.xPosition;
    special=orig.special;
}

Game::~Game() {
}

void Game::setEventsGame(){
    Command* comando= new RemoveCompletedLines(board, score);
    board.addCommand(comando);
    building =new Building(board,score);
}

void Game::startGame() {
    sf::Event evento;
    //preparo next shape
    nextShapeFall();
    //preparo timer
    Timer timer{};
    timer.start();
    //preparo shape
    newShape();
    while (!letsQuit) {
        if (isPaused()) {
            paintPauseMessage();
        } else if (isGameOver()) {
            paintGameOver();
        } else {
            //limpio la pantalla
            pantalla.clear();
            if (!isAnimation()) {
                logicGame();
            }
            paintProcessGame();
        }
        //Consultamos los eventos
        while (pantalla.getRenderer()->pollEvent(evento)) {
            keyEvent(evento);
        }

        //lanzo nuevo shape si necesario
        newShape();

        /**
         * 60 frames por segundo
         * 1/60 *100 salen a unos 16 milisegundos para cada frame
         * Si no cumple el tiempo, espera un poco
         */
        if (timer.delta() < 16) {
            sf::sleep(sf::milliseconds(16 - timer.delta()));
        }
        timer.reset();
    }
}

void Game::resetGame() {
    delete shapeFalling;
    delete nextShape;
    
    shapeFalling = nullptr;
    nextShape = nullptr;
    board = TableBoard(pantalla.getWindow(), 20, 10);
    score = Score();
    setEventsGame();
    paintedPause = false;
    paused = false;
    gameOver = false;
    animation = false;
    //preparo next shape
    nextShapeFall();
}

void Game::logicGame() {
    //ejecuto los comandos de la board
    board.executeCommands();
    board.clearCommands();
    
    //ejecuto y limpio comandos del shape cayendo
    shapeFalling->executeCommands();
    shapeFalling->clearCommandsFinished();
    
    //ejecuto y limpio los del resto del board si hubiera
    board.executeShapes();
    board.executeSpecialShapes();
    
    //construyo...
    building->execute();
    
    //borro shapes del board que ya estén totalmente eliminados
    board.clearAllShapes();
    board.cleanCommandShapes();
    
}

void Game::keyEvent(sf::Event &evento) {
    if (evento.type == sf::Event::Closed) { // Si es de salida
        letsQuit = true;
        return;
    }
    if (evento.type == sf::Event::KeyPressed) {
        sf::Keyboard::Key key = evento.key.code;
        Command* command = nullptr;
        switch (key) {
            case sf::Keyboard::P:
                setPaused(!isPaused());
                break;

            case sf::Keyboard::R:
                if (isGameOver()) {
                    resetGame();
                }
                break;

            case sf::Keyboard::Left:
                if (isPaused()) {
                    return;
                }
                command = new LeftRight(board, *shapeFalling, Direction::LEFT);
                shapeFalling->addCommand(command);
                break;

            case sf::Keyboard::Right:
                if (isPaused()) {
                    return;
                }
                command = new LeftRight(board, *shapeFalling, Direction::RIGHT);
                shapeFalling->addCommand(command);
                break;

            case sf::Keyboard::Down:
                if (isPaused()) {
                    return;
                }
                command = new FallEvent(board, *shapeFalling);
                shapeFalling->addCommand(command);
                break;

            case sf::Keyboard::Space:
                if (isPaused()) {
                    return;
                }
                command = new Rotate(board, *shapeFalling);
                shapeFalling->addCommand(command);
                break;

            case sf::Keyboard::Escape:
                exit(0);
                
            default:
                return;

        }
    }
}

void Game::paintProcessGame() {
    //pinto los shapes
    shapeFalling->paint(pantalla.getRenderer());
    nextShape->paint(pantalla.getRenderer());
    //pinto los shapes del tablero
    board.paint(pantalla.getRenderer());

    //pinto las lineas del tablero
    board.drawLines(pantalla.getRenderer());
    //pinto la interfaz
    painter->paintInterface(score);
    //actualizo la pantalla
    pantalla.actualizar();
}

void Game::paintGameOver() {
    if (!isPaintedGameOver()) {
        painter->paintGameOver();
        setPaintedGameOver(true);

        //actualizo la pantalla
        pantalla.actualizar();
    }
}

void Game::paintPauseMessage() {
    if (!isPaintedPause()) {
        painter->paintPauseMessage();
        setPaintedPause(true);

        //actualizo la pantalla
        pantalla.actualizar();
    }
}

void Game::newShape() {
    //if needed of a shape...
    if (shapeFalling == nullptr || shapeFalling->isCanFall() == false) {
        //if the last shape was not null, store in the game board
        if (shapeFalling != nullptr && special==false) {
            board.addShape(shapeFalling);
        }

        int azar = ((rand() % 100));
        if (azar < 40) {
            special=true;
            setNewSpecialShape();
        } else {
            special=false;
            //get the next shape
            shapeFalling = nextShape;
            //random a state for the shape and rotate it
            int initialState = rand() % 20;
            initialState = initialState % shapeFalling->getNUMBER_OF_STATES();
            while (initialState > 0) {
                shapeFalling->rotate();
                initialState--;
            }


            //set the right graphics for the shape
            Board meassureBoard = board.getMeassureBoard();
            shapeFalling->setGraphics(meassureBoard, nullptr);
            //undo the position of the square when was created in nextShapeFall())
            shapeFalling->incrementSquare(xPosition - 2 + 2, -1);
            //check if have space 
            if (board.isFilled(shapeFalling)!=TypeSquare::NoSquare) {
                //end of game
                setGameOver(true);
            }

            //prepare the next shape
            nextShapeFall();
            //create the command that moves the shape to the ground
            Command* command = new Fall(board, *shapeFalling, score.getVelocity());
            shapeFalling->addCommand(command);
        }
    }

}

void Game::nextShapeFall() {
    //square example
    Square* square = new Square(1, 1);
    //get a random shape
    Shapes shapeSelected = static_cast<Shapes> ((rand() % 100) % NUMBER_SHAPES);
    //set the graphics to the square
    sf::Texture* image = ImagesManager::getInstance().getImage(Images::Square);
    Board meassureBoardNextShape=painter->getMeassureBoardNextShape();
    square->setGraphics(meassureBoardNextShape, image);
    
    switch (shapeSelected) {
        case Shapes::O:
            nextShape = new OShape(*square);
            break;
        case Shapes::T:
            nextShape = new TShape(*square);
            break;
        case Shapes::L:
            nextShape = new LShape(*square);
            break;
        case Shapes::Z:
            nextShape = new ZShape(*square);
            break;
        case Shapes::S:
            nextShape = new SShape(*square);
            break;
        case Shapes::I:
            nextShape = new IShape(*square);
            break;
        case Shapes::J:
            nextShape = new JShape(*square);
            break;
        case Shapes::Special:
            nextShapeFall();
            break;
    }
    delete square;
}

void Game::setNewSpecialShape() {
    //square example
    Square* square = new Square(1, 1);
    //set the right graphics for the shape
    Board meassureBoard = board.getMeassureBoard();
    
    int azar = ((rand() % 4));
    sf::Texture* image=ImagesManager::getInstance().getImage(Images::Bomb);
    Command* command;
    switch(azar){
        case 0:
            image=ImagesManager::getInstance().getImage(Images::Bomb);
            break;
        case 1:
            image=ImagesManager::getInstance().getImage(Images::Complaint);
            break;
        case 2:
            image=ImagesManager::getInstance().getImage(Images::Maze);
            break;
        case 3:
            image=ImagesManager::getInstance().getImage(Images::Food);
            break;
    }
    
    square->setGraphics(meassureBoard, image);
    shapeFalling=new SpecialShape(square);
    //recoloco el shape al centro
    shapeFalling->incrementSquare(xPosition -2 +2, -1);
    
    switch(azar){
        case 0:
            command = new Bomb(board, *shapeFalling, score, score.getVelocity());
            break;
        case 1:
            command = new Complaint(board, *shapeFalling, score.getVelocity());
            break;
        case 2:
            command = new Bomb(board, *shapeFalling, score, score.getVelocity());
            break;
        case 3:
            command = new Food(board, *shapeFalling, score.getVelocity());
            break;
    }
    
    shapeFalling->addCommand(command);
    
    delete square;
    
    //check if have space 
    TypeSquare typeColision=board.isFilled(shapeFalling);
    if (typeColision!=TypeSquare::NoSquare) {
        //end of game
        setGameOver(true);
    }
}