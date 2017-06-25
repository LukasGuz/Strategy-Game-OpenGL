//
//  ImageLoader.cpp
//  StrategyGame
//
//  Created by Lukas Guz on 21.06.17.
//  Copyright (c) 2017 Lukas Guz. All rights reserved.
//

#include "ImageLoader.h"
#include "picoPNG.h"
#include "IOManager.h"
#include "Errors.h"


GLTexture ImageLoader::loadPNG(std::string filePath)
{
    GLTexture texture = {};
    
    
    std::vector<unsigned char> in;
    std::vector<unsigned char> out;
    
    unsigned long width, heigth;
    
    
    if (IOManager::readFileToBuffer(filePath, in) == false)
    {
        fatalError("Failed to laod PNG file to buffer!");
    }
    
    
    int errorCode = decodePNG(out, width, heigth, &(in[0]), in.size(),0);
    if (errorCode != 0) {
        fatalError("Decode PNG failed with error:" + std::to_string(errorCode));
    }
    
    glGenTextures(1, &(texture.id));
    
    glBindTexture(GL_TEXTURE_2D, texture.id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, heigth, 0, GL_RGBA, GL_UNSIGNED_BYTE, &(out[0]) );
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    glGenerateMipmap(GL_TEXTURE_2D);
    
    glBindTexture(GL_TEXTURE_2D, 0);
    
    texture.width = width;
    texture.height = heigth;
    
    return texture;
    
}














