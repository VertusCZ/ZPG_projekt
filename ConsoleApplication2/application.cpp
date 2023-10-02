#include "Application.h"
#include "Callback.h"

Application::Application(int width, int height, const std::string& title)
    : windowWidth(width), windowHeight(height), windowTitle(title) {}

void Application::Run() {
    InitializeGLFW();
    CreateWindow();
    InitializeGLEW();
    InitializeOpenGLState();
    InitializeShaders();
    CreateGeometry(); 

    while (!glfwWindowShouldClose(window)) {
        Render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    CleanUp();
}

Application::~Application() {
    CleanUp();
}

void Application::InitializeGLFW() {
    glfwSetErrorCallback(Callback::error_callback);
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3\n");
        exit(EXIT_FAILURE);
    }
}

void Application::CreateWindow() {
    window = glfwCreateWindow(windowWidth, windowHeight, windowTitle.c_str(), nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

   
    glfwSetKeyCallback(window, Callback::key_callback);
    glfwSetWindowSizeCallback(window, Callback::window_size_callback);
    glfwSetCursorPosCallback(window, Callback::cursor_callback);
    glfwSetMouseButtonCallback(window, Callback::button_callback);
}

void Application::InitializeGLEW() {
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "ERROR: Failed to initialize GLEW\n");
        exit(EXIT_FAILURE);
    }
}

void Application::InitializeOpenGLState() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Application::InitializeShaders() {
    shaders.Initialize(); 
}

void Application::CreateGeometry() {
    model.CreateGeometry(); 
}

void Application::Render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(shaders.GetProgram()); 
    model.Render();  
}


void Application::CleanUp() {
    glDeleteProgram(shaders.GetProgram());
    glfwDestroyWindow(window);
    glfwTerminate();
}
