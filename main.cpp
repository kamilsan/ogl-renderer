#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "window.hpp"
#include "shaderProgram.hpp"

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

int main()
{
  Window window{"OpenGL", WINDOW_WIDTH, WINDOW_HEIGHT};

  std::ifstream vsFile("vertexShader.vs");
  std::stringstream vsStream;
  vsStream << vsFile.rdbuf();
  vsFile.close();

  std::ifstream fsFile("fragmentShader.fs");
  std::stringstream fsStream;
  fsStream << fsFile.rdbuf();
  fsFile.close();

  ShaderProgram shaderProgram(vsStream.str().c_str(), fsStream.str().c_str());

  GLuint VBO, VAO;
  glGenBuffers(1, &VBO);
  glGenVertexArrays(1, &VAO);

  float vertices[] = {
    -0.5, -0.5, 0.0,
    0.5, -0.5, 0.0,
    0, 0.5, 0.0
  };

  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glBindVertexArray(0);

  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

  while(window.isRunning())
  {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    shaderProgram.use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    window.update();
  }

  return 0;
}