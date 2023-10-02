#pragma once

#include <GLFW/glfw3.h>
#include<stdio.h>

class Callback {
public:
    static float currentRotation;
    static float rotationStep;
    static void error_callback(int error, const char* description);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void window_focus_callback(GLFWwindow* window, int focused) { printf("window_focus_callback \n"); }
    static void window_iconify_callback(GLFWwindow* window, int iconified) { printf("window_iconify_callback \n"); }
    static void window_size_callback(GLFWwindow* window, int width, int height);
    static void cursor_callback(GLFWwindow* window, double x, double y);
    static void button_callback(GLFWwindow* window, int button, int action, int mode);
};
