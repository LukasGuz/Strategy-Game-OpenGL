//
//  picoPNG.h
//  StrategyGame
//
//  Created by NOT by Lukas Guz on 21.06.17.
//  
//  picoPNG version 20101224
//  Copyright (c) 2005-2010 Lode Vandevenne

#ifndef __StrategyGame__picoPNG__
#define __StrategyGame__picoPNG__

#include <vector>

extern int decodePNG(std::vector<unsigned char>& out_image, unsigned long& image_width, unsigned long& image_height,
                     const unsigned char* in_png, size_t in_size, bool convert_to_rgba32);


#endif /* defined(__StrategyGame__picoPNG__) */
