//
//  MainGame.cpp
//  StrategyGame
//
//  Created by Lukas Guz on 18.06.17.
//  Copyright (c) 2017 Lukas Guz. All rights reserved.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "MainGame.h"
#include "Errors.h"
#include "ImageLoader.h"


#include <iostream>
#include <string>

// konstructor
MainGame::MainGame() :
    ptime(0),
    pScreenWidth(1024),
    pScreenHeight(768),
    pwindow(nullptr),
    pGameState(GameState::PLAY)
{
    
}

// destructor
MainGame::~MainGame()
{
    
}


// function to run the game -> run InitSystems
void MainGame::Run()
{
    // initalize
    InitSystems();
    
    // initilaize use of sprites (see Sprites.h/cpp) temporary
    pSprite.initSprite(-1.0f, -1.0f, 2.0f, 2.0f);
    
    pPlayerTexture = ImageLoader::loadPNG("/Users/LukasGuz/Programmieren/Projects/StrategyGame/StrategyGame/Textures/jimmyJump_pack/PNG/CharacterRight_Standing.png");
    
    // run or exit game
    gameLoop();
}

// function to initilize basic systems like SDL and OpenGl
void MainGame::InitSystems()
{
    // initalize SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    
    pwindow = SDL_CreateWindow("Strategy Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, pScreenWidth, pScreenHeight, SDL_WINDOW_OPENGL);
    if (pwindow == nullptr)
    {
        fatalError("SDL Window could not be created!");
    }
    
    // contexts for opengl :
    
    // for mac
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    
    // make GLContext and search for errors
    SDL_GLContext glContext = SDL_GL_CreateContext(pwindow);
    if (glContext == nullptr) {
        fatalError("SDL_GL context could not be created!");
    }
    
    GLuint vertexArrayID;
    glGenVertexArrays(1, &vertexArrayID);
    glBindVertexArray(vertexArrayID);
    
    
    
    
    // initilize glew and search for errors                     // not for mac
    //GLenum error = glewInit();
    //if (error != GLEW_OK) {
    //    fatalError("Could not initilazid glew");
    //}
    
    // back to normal:
    
    // tells SDL to doublebuffer (sets two window so no flicker)
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    
    // set background color (needed everytime GL_COLOR_BUFFER_BIT is somehow called)
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    
    InitShaders();
    
}

// game continues or stops
void MainGame::gameLoop()
{
    // run game till gamestate = Exit and start to get inputs by calling function
    while (pGameState != GameState::EXIT)
    {                           // works until game closed:
        processInput();         // handels input
        ptime += 0.01;
        drawGame();             // draws game
    }
}

void MainGame::InitShaders(){
    pColorProgram.compileShaders("/Users/LukasGuz/Programmieren/Projects/StrategyGame/StrategyGame/Shaders/colorShading.vert", "/Users/LukasGuz/Programmieren/Projects/StrategyGame/StrategyGame/Shaders/colorShading.frag");
    pColorProgram.addAtrribute("vertexPosition");
    pColorProgram.addAtrribute("vertexColor");
    pColorProgram.addAtrribute("vertexUV");
    pColorProgram.linkShaders();
}


// handel inputs(Events) and prozess them
void MainGame::processInput()
{
    SDL_Event evnt;                     // variable for events ( 1 = pending; 2 = none available)

    // process inputs
    while (SDL_PollEvent(&evnt))        // while event true (=1)
    {
        switch (evnt.type) {
            case SDL_QUIT:
                pGameState = GameState::EXIT;
                break;
            case SDL_MOUSEMOTION:
                std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
                break;
            default:
                break;
        }
    }

}

// render code/function
void MainGame::drawGame()
{

    glClearDepth(1.0);                                      // tells OpenGl the depth (not so important to know)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // clears the screen each time the picture will drawn (Color_Buffer "whats drawn by game"| ... )
    
    
    
    // use the shader:
    pColorProgram.use();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, pPlayerTexture.id);
    GLint textureLocation = pColorProgram.getUniformLocation("mySampler");
    glUniform1i(textureLocation, 0);
    
    //GLuint timeLocation = pColorProgram.getUniformLocation("time");
    //glUniform1f(timeLocation, ptime);
    
    
    // draw sprites
    pSprite.drawSprite();
    
    // unuseShader:
    glBindTexture(GL_TEXTURE_2D, 0);
    pColorProgram.unUse();
    
   // swaps the buffer and draw everything on screen
    SDL_GL_SwapWindow(pwindow);
    
}































