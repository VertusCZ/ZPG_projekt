#pragma once

#include <GL/glew.h>

class Model {
public:
    Model();
    ~Model();
    void CreateGeometry();
    void Render();

private:
    GLuint VBOs[2];
    GLuint VAOs[2]; 
};
