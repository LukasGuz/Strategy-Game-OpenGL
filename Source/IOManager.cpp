//
//  IOManager.cpp
//  StrategyGame
//
//  Created by Lukas Guz on 21.06.17.
//  Copyright (c) 2017 Lukas Guz. All rights reserved.
//

#include "IOManager.h"

#include <fstream>

bool IOManager::readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer)
{
    std::ifstream file(filePath, std::ios::binary);
    if (file.fail())
    {
        perror(filePath.c_str());
        return false;
    }
    // seek to the end of file
    file.seekg(0, std::ios::end);
    
    // get the file size
    int fileSize = file.tellg();
    file.seekg(0, std::ios::beg);
    
    // reduce the file size by any header bytes that might be present
    fileSize -= file.tellg();
    
    buffer.resize(fileSize);
    file.read((char*)&(buffer[0]), fileSize);
    file.close();
    
    return true;
}