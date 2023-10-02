#pragma once

#include <GL/glew.h>
#include <stdio.h>

class Shaders {
public:
    Shaders();
    ~Shaders();
    void Initialize();
    GLuint GetProgram() const;
 

private:
    GLuint vertexShaderSquare;
    GLuint fragmentShaderSquare;
    GLuint shaderProgramSquare;

    GLuint vertexShaderTriangle;
    GLuint fragmentShaderTriangle;
    GLuint shaderProgramTriangle;
};