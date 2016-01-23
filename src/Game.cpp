
#include "Game.h"

Game::Game() : title() {
    /* initialize random seed: */
    srand(time(NULL));
    score = nullptr;
    letsQuit = false;
    shapeFalling = nullptr;
    nextShape = nullptr;
    board = TableBoard(pantalla.getWindow(), 20, 10);
    if (score != nullptr) {
        delete score;
        score = nullptr;
    }
    score = new Score();
    ImagesManager::getInstance().loadImagesAnimations();

    setEventsGame();

    inTitle = true;
    paused = false;
    gameOver = false;
    animation = false;
    painter = new Painter(pantalla, board.getMeassureBoard());
    painter->prepareInterface();
    //position where new shapes will appear
    xPosition = (int) board.getNumberColumns() / 2;
    xPosition -= 1;

    //prepare music
    loadSounds();
}

void Game::loadSounds() {
    if (background.openFromFile("resources/audio/background.ogg")) {
        background.setVolume(10);
        background.setLoop(true);
    }

    if (titleSoundBuffer.loadFromFile("resources/audio/SFX_Splash.ogg")) {
        titleSound.setBuffer(titleSoundBuffer);
        titleSound.setVolume(25);
        titleSound.play();
    }
    if (gameOverBuffer.loadFromFile("resources/audio/SFX_GameOver.ogg")) {
        gameOverSound.setVolume(35);
        gameOverSound.setBuffer(gameOverBuffer);
    }
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
    paused = orig.paused;
    gameOver = orig.gameOver;
    animation = orig.animation;
    painter = orig.painter;
    //position where new shapes will appear
    xPosition = orig.xPosition;
}

Game::~Game() {
}

void Game::setEventsGame() {
    Command* comando = new RemoveCompletedLines(board, *score);
    board.addCommand(comando);
}

void Game::startGame() {
    sf::Event evento;
    //preparo next shape
    nextShapeFall();
    //preparo timer
    Timer timer{};
    Timer over{};
    timer.start();
    //preparo shape
    newShape();
    while (!letsQuit) {
        if (inTitle) {
            title.draw(pantalla.getRenderer());

        } else {
            //limpio la pantalla
            pantalla.clear();
            if (!isAnimation() && !(isPaused() || isGameOver())) {
                logicGame();
            }
            paintProcessGame();
        }

        if (isPaused()) {
            paintPauseMessage();
        } else if (isGameOver()) {
            if (!over.isRunning()) {
                over.start();
                background.stop();
                gameOverSound.play();
            } else if (over.delta() > 5000) {
                inTitle = true;
                gameOver = false;
                gameOverSound.stop();
                titleSound.play();
            }
            paintGameOver();
        }
        //actualizo la pantalla
        pantalla.actualizar();


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
        if (timer.delta() < 33) {
            sf::sleep(sf::milliseconds(33 - timer.delta()));
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
    if (score != nullptr) {
        delete score;
        score = nullptr;
    }
    score = new Score();
    setEventsGame();
    paused = false;
    gameOver = false;
    animation = false;
    //preparo next shape
    nextShapeFall();

    //start music
    titleSound.stop();
    background.play();
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
        if (inTitle && key != sf::Keyboard::Escape) {
            inTitle = false;
            resetGame();
            return;
        }
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
                if (inTitle) {
                    titleSound.stop();
                    exit(0);
                } else {
                    inTitle = true;
                    paused = false;
                    gameOver = false;
                    background.stop();
                    gameOverSound.stop();
                    titleSound.play();
                }

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
    painter->paintInterface(*score);

}

void Game::paintGameOver() {
    painter->paintGameOver();

    //actualizo la pantalla
    pantalla.actualizar();

}

void Game::paintPauseMessage() {
    painter->paintPauseMessage();

    //actualizo la pantalla
    pantalla.actualizar();

}

void Game::newShape() {
    //if needed of a shape...
    if (shapeFalling == nullptr || shapeFalling->isCanFall() == false) {
        //if the last shape was not null, store in the game board
        if (shapeFalling != nullptr) {
            board.addShape(shapeFalling);
        }

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
        BoardGrid meassureBoard = board.getMeassureBoard();
        shapeFalling->setGraphics(meassureBoard, nullptr);
        //undo the position of the square when was created in nextShapeFall())
        shapeFalling->incrementSquare(xPosition - 2 + 2, -1);
        //check if have space 
        if (board.isFilled(shapeFalling) != TypeSquare::NoSquare) {
            //end of game
            setGameOver(true);
        }

        //prepare the next shape
        nextShapeFall();
        //create the command that moves the shape to the ground
        Command* command = new Fall(board, *shapeFalling, score->getVelocity());
        shapeFalling->addCommand(command);

    }

}

void Game::nextShapeFall() {
    //square example
    Square* square = new Square(1, 1);
    //get a random shape
    Shapes shapeSelected = static_cast<Shapes> ((rand() % 100) % NUMBER_SHAPES);
    //set the graphics to the square
    sf::Texture* image = ImagesManager::getInstance().getImage(Images::Square);
    BoardGrid meassureBoardNextShape = painter->getMeassureBoardNextShape();
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
    }
    delete square;
}
