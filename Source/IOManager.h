//
//  IOManager.h
//  StrategyGame
//
//  Created by Lukas Guz on 21.06.17.
//  Copyright (c) 2017 Lukas Guz. All rights reserved.
//

#ifndef __StrategyGame__IOManager__
#define __StrategyGame__IOManager__

#include <vector>

class IOManager
{
public:
    static bool readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer);
    
};













#endif /* defined(__StrategyGame__IOManager__) */
