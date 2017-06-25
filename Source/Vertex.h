//
//  Vertex.h
//  StrategyGame
//
//  Created by Lukas Guz on 21.06.17.
//  Copyright (c) 2017 Lukas Guz. All rights reserved.
//


#ifndef StrategyGame_Vertex_h
#define StrategyGame_Vertex_h


#include <OpenGL/gl3.h>

struct Position
{
    float x;
    float y;
} position;

struct Color
{
    GLubyte r;
    GLubyte g;
    GLubyte b;
    GLubyte a;
} color;

struct UV
{
    float u;
    float v;
};

struct Vertex
{
    Position position;
    
    Color color;
    
    // UV texture mapping
    UV uv;
    
    void setPosition(float x, float y)
    {
        position.x = x;
        position.y = y;
    }
    
    void setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a)
    {
        color.r = r;
        color.g = g;
        color.b = b;
        color.a = a;
    }
    
    void setUV(float u, float v)
    {
        uv.u = u;
        uv.v = v;
    }
};




#endif
