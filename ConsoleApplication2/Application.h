#pragma once

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Model.h"
#include "Shaders.h"

class Application {
public:
    Application(int width, int height, const std::string& title);
    ~Application();
    void Run();

private:
    void InitializeGLFW();
    void CreateWindow();
    void InitializeGLEW();
    void InitializeOpenGLState();
    void InitializeShaders();
    void CreateGeometry();
    void Render();
    void CleanUp();

    int windowWidth;
    int windowHeight;
    Shaders shaders;
    std::string windowTitle;
    GLFWwindow* window;
    GLuint shaderProgram;
    Model model; 
   
};
