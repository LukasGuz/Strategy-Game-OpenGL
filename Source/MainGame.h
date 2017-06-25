//
//  MainGame.h
//  StrategyGame
//
//  Created by Lukas Guz on 18.06.17.
//  Copyright (c) 2017 Lukas Guz. All rights reserved.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef __StrategyGame__MainGame__
#define __StrategyGame__MainGame__

#include <SDL2/SDL.h>
//#include <OpenGL/OpenGL.h>
#include <OpenGL/gl3.h>

// allow  use of sprites:
#include "Sprites.h"
#include "GLSLProgram.h"
#include "GLTexture.h"



// status if game runs or stops/exit used by void gameLoop()
enum class GameState {PLAY, EXIT};

// main class to run and initalize the game
class MainGame
{
public:
    MainGame();             // konstructor
    ~MainGame();            // destructor
    
    void Run();             // function to run the game

private:
    
    void InitSystems();     // function to initilize basic systems like SDL and OpenGl
    void InitShaders();
    void gameLoop();        // handels the exit condition / checks the Gamestate
    void processInput();    // handel inputs
    void drawGame();        // render function
    
    SDL_Window* pwindow;    // instance of window, handel to window
    int pScreenWidth;       // window width
    int pScreenHeight;      // window height
    
    GameState pGameState;
    
    Sprite pSprite;         // test sprite
    
    // just for now:
    GLSLProgram pColorProgram;
    GLTexture pPlayerTexture;
    
    
    float ptime;
    
};




#endif /* defined(__StrategyGame__MainGame__) */
