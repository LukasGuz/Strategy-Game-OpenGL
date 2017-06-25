//
//  GLSLProgram.cpp
//  StrategyGame
//
//  Created by Lukas Guz on 19.06.17.
//  Copyright (c) 2017 Lukas Guz. All rights reserved.
//

#include "GLSLProgram.h"
#include "Errors.h"

#include <fstream>
#include <vector>


// konstructor
GLSLProgram::GLSLProgram() : pNumAttributes(0), pProgramID(0), pvertexShaderID(0), pfragmentShaderID(0)  // initialization list
{
    
}
// destructor
GLSLProgram::~GLSLProgram()
{
    
}

//compile Shaders
void GLSLProgram::compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilepath)
{
    //Vertex and fragment shaders are successfully compiled.
    //Now time to link them together into a program.
    //Get a program object.
    pProgramID = glCreateProgram();
    
    pvertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    
    if (pvertexShaderID == 0)
    {
        fatalError("Vertex shader failed to be created!");   // calles Error function in Errors.cpp
    }
    
    pfragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    
    if (pfragmentShaderID == 0)
    {
        fatalError("Fragment shader failed to be created!");   // calles Error function in Errors.cpp
    }
    
    compileShader(vertexShaderFilePath, pvertexShaderID);
    compileShader(fragmentShaderFilepath, pfragmentShaderID);
}

//link shaders in program
void GLSLProgram::linkShaders()
{
    //Attach our shaders to our program
    glAttachShader(pProgramID, pvertexShaderID);
    glAttachShader(pProgramID, pfragmentShaderID);
    
    //Link our program
    glLinkProgram(pProgramID);
    
    // Error handeling:
    
    //Note the different functions here: glGetProgram* instead of glGetShader*.
    GLint isLinked = 0;
    glGetProgramiv(pProgramID, GL_LINK_STATUS, (int *)&isLinked);
    if(isLinked == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetProgramiv(pProgramID, GL_INFO_LOG_LENGTH, &maxLength);
        
        //The maxLength includes the NULL character
        std::vector<char> infoLog(maxLength);
        glGetProgramInfoLog(pProgramID, maxLength, &maxLength, &infoLog[0]);
        
        //We don't need the program anymore.
        glDeleteProgram(pProgramID);
        //Don't leak shaders either.
        glDeleteShader(pvertexShaderID);
        glDeleteShader(pvertexShaderID);
        
        //std::printf("%s\n", &(errorLog[0]));
        fatalError("Shader failed to link!");
    }
    
    //Always detach shaders after a successful link.
    glDetachShader(pProgramID, pvertexShaderID);
    glDetachShader(pProgramID, pfragmentShaderID);
    glDeleteShader(pvertexShaderID);
    glDeleteShader(pfragmentShaderID);
}

void GLSLProgram::addAtrribute(const std::string& attributeName)
{
    glBindAttribLocation(pProgramID, pNumAttributes++, attributeName.c_str());
}

// get the uniform location
GLint GLSLProgram::getUniformLocation(const std::string& uniformName)
{
    GLint location = glGetUniformLocation(pProgramID, uniformName.c_str());
    
    if (location == GL_INVALID_INDEX)
    {
        fatalError("Uniform" + uniformName + "not found in shader!");
    }
    return location;
}

void GLSLProgram::use()
{
    glUseProgram(pProgramID);
    for (int i = 0; i < pNumAttributes; i++) {
        glEnableVertexAttribArray(i);
    }
}
void GLSLProgram::unUse()
{
    glUseProgram(0);
    for (int i = 0; i < pNumAttributes; i++) {
        glDisableVertexAttribArray(i);
    }
}

void GLSLProgram::compileShader(const std::string& filePath, GLuint id)
{
    std::ifstream vertexFile(filePath);
    if (vertexFile.fail()) {
        perror(filePath.c_str());
        fatalError("Failed to open" + filePath);
    }
    
    std::string fileContents = "";
    std::string line;
    
    while (std::getline(vertexFile, line)) {
        fileContents +=line + "\n";
    }
    
    vertexFile.close();
    
    const char* contentsPtr = fileContents.c_str();
    glShaderSource(id, 1, &contentsPtr, nullptr);
    
    glCompileShader(id);
    
    GLint success = 0;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    
    if (success == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);
        
        std::vector<char> errorLog(maxLength);
        glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);
        
        glDeleteShader(id);
        
        std::printf("%s\n", &errorLog[0]);
        fatalError("Shader"+ filePath + "failed to compile");
    }
}



































