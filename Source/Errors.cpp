//
//  Errors.cpp
//  StrategyGame
//
//  Created by Lukas Guz on 20.06.17.
//  Copyright (c) 2017 Lukas Guz. All rights reserved.
//

#include "Errors.h"

#include <cstdlib>
#include <iostream>
#include <SDL2/SDL.h>


// checks for errors and quits game
void fatalError(std::string errorString){
    std::cout << errorString << std::endl;
    std::cout << "Enter any key to quit...";
    int tmp;
    std::cin >> tmp;
    SDL_Quit();
    exit(69);
}