//
//  ImageLoader.h
//  StrategyGame
//
//  Created by Lukas Guz on 21.06.17.
//  Copyright (c) 2017 Lukas Guz. All rights reserved.
//

#ifndef __StrategyGame__ImageLoader__
#define __StrategyGame__ImageLoader__

#include <string>

#include "GLTexture.h"

class ImageLoader
{
public:
   static GLTexture loadPNG(std::string filePath);
};





#endif /* defined(__StrategyGame__ImageLoader__) */
