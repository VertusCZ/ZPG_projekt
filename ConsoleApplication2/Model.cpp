#include "Model.h"

Model::Model() : VBOs{ 0, 0 }, VAOs{ 0, 0 } {
}

Model::~Model() {
    for (GLuint& VBO : VBOs) {
        if (VBO != 0) {
            glDeleteBuffers(1, &VBO);
        }
    }
    for (GLuint& VAO : VAOs) {
        if (VAO != 0) {
            glDeleteVertexArrays(1, &VAO);
        }
    }
}

void Model::CreateGeometry() {
  
    float square[] = {
        0.1f, -0.4f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Lev� doln� vrchol
        0.1f, 0.4f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f,  // Lev� horn� vrchol
        0.8f, 0.4f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f,   // Prav� horn� vrchol
        0.8f, -0.4f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f   // Prav� doln� vrchol
    };


    float triangle[] = {
    -0.7f, 0.2f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, // Lev� doln� vrchol
    0.1f, 0.2f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,  // Prav� doln� vrchol
    -0.3f, 0.9f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f    // Vrchol naho�e
    };




    glGenBuffers(2, VBOs); 
    glGenVertexArrays(2, VAOs); 

    //square 
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(square), square, GL_STATIC_DRAW);

    glBindVertexArray(VAOs[0]);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (GLvoid*)0);

    //triangle 
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);

    glBindVertexArray(VAOs[1]);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (GLvoid*)0);
}

void Model::Render() {
   
    glBindVertexArray(VAOs[0]);
    glDrawArrays(GL_QUADS, 0, 4);

   
    glBindVertexArray(VAOs[1]);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
