//
//  Sprites.cpp
//  StrategyGame
//
//  Created by Lukas Guz on 18.06.17.
//  Copyright (c) 2017 Lukas Guz. All rights reserved.
//

#include "Sprites.h"
#include "Vertex.h"

#include <cstddef>

Sprite::Sprite()
{
    pVboID = 0;                         // vertex buffer always zero at the beginning
}


Sprite::~Sprite()
{
  // if Sprite is destroyed free the vertex buffer and free the vram
    if (pVboID != 0) {
        glDeleteBuffers(1, & pVboID);
    }
}

void Sprite::initSprite(float x, float y, float width, float height)
{
    pX = x;
    pY = y;
    pWidth = width;
    pHeight = height;
    
    // create vertex buffer
    if (pVboID == 0)                        // at the beginning always zero -> see Kontructor
    {
        glGenBuffers(1, &pVboID);           // at beginning create buffer (vertex buffer gets the id of this buffer here created)
    }
    
    
    // this vertex will hold our vertex data
    // create space for vertesies for screen koordinates
    Vertex vertexData[6];

    //first triangle
    vertexData[0].setPosition(x + width,y + height);
    vertexData[0].setUV(1.0f, 1.0f);
    
    vertexData[1].setPosition(x, y + height);
    vertexData[1].setUV(0.0f, 1.0f);
    
    vertexData[2].setPosition(x, y);
    vertexData[2].setUV(0.0f, 0.0f);
    
    //second triangle
    
    vertexData[3].setPosition(x, y);
    vertexData[3].setUV(0.0f, 0.0f);
    
    vertexData[4].setPosition(x + width, y);
    vertexData[4].setUV(1.0f, 0.0f);
    
    vertexData[5].setPosition(x + width, y + height);
    vertexData[5].setUV(1.0f, 1.0f);
    
    for (int i=0; i < 6; i++)
    {
        vertexData[i].setColor(255, 0, 255, 255);
    }
    
    // top left corner of vertex gets blue
    vertexData[1].setColor(0, 0, 255, 255);
 
    // botton right corner of vertex gets green
    vertexData[4].setColor(0, 255, 0, 255);
    
    
    // bind the buffer
    glBindBuffer(GL_ARRAY_BUFFER, pVboID);
    // upload the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
    
    
    // unbind the buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
}

// draws the sprites
void Sprite::drawSprite()
{
    //bind the buffer object
    glBindBuffer(GL_ARRAY_BUFFER, pVboID);
    
    // tell opengl that want to use the first attribute array. only use
    // now because only using positions
    glEnableVertexAttribArray(0);
    
    // this is the position attribute pointer
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, position));
    // this is the color attribute pointer
    glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*) offsetof(Vertex, color));
    // this is the UV attribute pointer
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color) );
    
    // actual drawing (6 vertices to the screen)
    glDrawArrays(GL_TRIANGLES, 0, 6);
    
    
    // end drawing
    
    // disable the vertex attrib. array this is not optional
    glDisableVertexAttribArray(0);
    // unbind the VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
























