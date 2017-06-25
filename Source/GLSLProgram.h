//
//  GLSLProgram.h
//  StrategyGame
//
//  Created by Lukas Guz on 19.06.17.
//  Copyright (c) 2017 Lukas Guz. All rights reserved.
//

#ifndef __StrategyGame__GLSLProgram__
#define __StrategyGame__GLSLProgram__

#include <string>
#include <OpenGL/gl3.h>

class GLSLProgram
{
public:
    // konstructor:
    GLSLProgram();
    // destructor:
    ~GLSLProgram();
    
    //compile Shaders
    void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilepath);
    
    //link shaders in program
    void linkShaders();
    
    void addAtrribute(const std::string& attributeName);
    
    //
    GLint getUniformLocation(const std::string& uniformName);
    
    // use GL-Programm
    void use();
    // un use GL-Program
    void unUse();
    
private:
    
    int pNumAttributes;
    
    // id to shader program
    GLuint pProgramID;
   
    GLuint pvertexShaderID;
    GLuint pfragmentShaderID;

    void compileShader(const std::string& filePath, GLuint id);
    
    
    
    
};


















#endif /* defined(__StrategyGame__GLSLProgram__) */
