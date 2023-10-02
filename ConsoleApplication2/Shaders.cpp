#include "Shaders.h"

Shaders::Shaders() : vertexShaderSquare(0), fragmentShaderSquare(0), shaderProgramSquare(0),
vertexShaderTriangle(0), fragmentShaderTriangle(0), shaderProgramTriangle(0) {
}

Shaders::~Shaders() {
    glDeleteShader(vertexShaderSquare);
    glDeleteShader(fragmentShaderSquare);
    glDeleteProgram(shaderProgramSquare);

    glDeleteShader(vertexShaderTriangle);
    glDeleteShader(fragmentShaderTriangle);
    glDeleteProgram(shaderProgramTriangle);
}

void Shaders::Initialize() {
    const char* vertex_shader_square =
        "#version 330\n"
        "layout(location=0) in vec3 vp;"
        "out vec3 fragPos;"
        "void main () {"
        "     gl_Position = vec4 (vp, 1.0);"
        "     fragPos = vp;"
        "}";

    const char* fragment_shader_square =
        "#version 330\n"
        "in vec3 fragPos;"
        "out vec4 frag_colour;"
        "void main () {"
        "     frag_colour = vec4 (fragPos, 1.0);"
        "}";

    const char* vertex_shader_triangle =
        "#version 330\n"
        "layout(location=0) in vec3 vp;"
        "out vec3 fragPos;"
        "void main () {"
        "     gl_Position = vec4 (vp, 1.0);"
        "     fragPos = vp;"
        "}";

    const char* fragment_shader_triangle =
        "#version 330\n"
        "in vec3 fragPos;"
        "out vec4 frag_colour;"
        "void main () {"
        "     frag_colour = vec4 (fragPos, 1.0);"
        "}";

    vertexShaderSquare = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderSquare, 1, &vertex_shader_square, 0);
    glCompileShader(vertexShaderSquare);

    fragmentShaderSquare = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderSquare, 1, &fragment_shader_square, 0);
    glCompileShader(fragmentShaderSquare);

    shaderProgramSquare = glCreateProgram();
    glAttachShader(shaderProgramSquare, fragmentShaderSquare);
    glAttachShader(shaderProgramSquare, vertexShaderSquare);
    glLinkProgram(shaderProgramSquare);

    vertexShaderTriangle = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderTriangle, 1, &vertex_shader_triangle, 0);
    glCompileShader(vertexShaderTriangle);

    fragmentShaderTriangle = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderTriangle, 1, &fragment_shader_triangle, 0);
    glCompileShader(fragmentShaderTriangle);

    shaderProgramTriangle = glCreateProgram();
    glAttachShader(shaderProgramTriangle, fragmentShaderTriangle);
    glAttachShader(shaderProgramTriangle, vertexShaderTriangle);
    glLinkProgram(shaderProgramTriangle);

    GLint status;
    glGetProgramiv(shaderProgramSquare, GL_LINK_STATUS, &status);
    if (status == GL_FALSE) {
        GLint infoLogLength;
        glGetProgramiv(shaderProgramSquare, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar* strInfoLog = new GLchar[infoLogLength + 1];
        glGetProgramInfoLog(shaderProgramSquare, infoLogLength, 0, strInfoLog);
        fprintf(stderr, "Linker failure (Square Shader): %s\n", strInfoLog);
        delete[] strInfoLog;
    }

    glGetProgramiv(shaderProgramTriangle, GL_LINK_STATUS, &status);
    if (status == GL_FALSE) {
        GLint infoLogLength;
        glGetProgramiv(shaderProgramTriangle, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar* strInfoLog = new GLchar[infoLogLength + 1];
        glGetProgramInfoLog(shaderProgramTriangle, infoLogLength, 0, strInfoLog);
        fprintf(stderr, "Linker failure (Triangle Shader): %s\n", strInfoLog);
        delete[] strInfoLog;
    }
}

GLuint Shaders::GetProgram() const {
    return shaderProgramSquare;
}