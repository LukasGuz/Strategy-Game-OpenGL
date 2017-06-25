//
//  GLTexture.h
//  StrategyGame
//
//  Created by Lukas Guz on 21.06.17.
//  Copyright (c) 2017 Lukas Guz. All rights reserved.
//

#ifndef StrategyGame_GLTexture_h
#define StrategyGame_GLTexture_h

#include <OpenGL/gl3.h>

struct GLTexture
{
    GLuint id;
    
    // save dimension of picture (optional)
    int width;
    int height;
};


#endif
