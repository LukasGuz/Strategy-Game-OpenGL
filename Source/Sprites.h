//
//  Sprites.h
//  StrategyGame
//
//  Created by Lukas Guz on 18.06.17.
//  Copyright (c) 2017 Lukas Guz. All rights reserved.
//

#ifndef __StrategyGame__Sprites__
#define __StrategyGame__Sprites__

#include <OpenGL/gl3.h>


class Sprite
{
public:
    Sprite();
    ~Sprite();
    
    // initilize the sprite-functions
    void initSprite(float x, float y, float width, float height);
    
    // draws the Sprites
    void drawSprite();

private:
    float pX;                       // x-koordinate
    float pY;                       // y-koordinate
    float pWidth;                   // width
    float pHeight;                  // height
    
    GLuint pVboID;                  // vertext buffer-object needed for glew (GLuint = "GL-" unsigned int, but is guaranteed to be 32 bit)
};









#endif /* defined(__StrategyGame__Sprites__) */
