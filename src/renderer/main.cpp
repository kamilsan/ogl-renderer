#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "window.hpp"
#include "shaderProgram.hpp"
#include "mesh.hpp"

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

void onResize(GLFWwindow*, int width, int height)
{
  glViewport(0, 0, width, height);
}

int main()
{
  Window window{"OpenGL", WINDOW_WIDTH, WINDOW_HEIGHT};
  window.setResizeCallback(onResize);

  std::ifstream vsFile("vertexShader.vs.glsl");
  std::stringstream vsStream;
  vsStream << vsFile.rdbuf();
  vsFile.close();

  std::ifstream fsFile("fragmentShader.fs.glsl");
  std::stringstream fsStream;
  fsStream << fsFile.rdbuf();
  fsFile.close();

  try
  {
    ShaderProgram shaderProgram(vsStream.str().c_str(), fsStream.str().c_str());
    Mesh squere({-0.5, -0.5, 0.0, -0.5, 0.5, 0.0, 0.5, 0.5, 0.0, 0.5, -0.5, 0.0}, 
      {0, 1, 2, 2, 3, 0});

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    while(window.isRunning())
    {
      glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      shaderProgram.use();
      squere.draw();

      window.update();
    }
  }
  catch(std::runtime_error& err)
  {
    std::cout << "ERROR: " << err.what() << std::endl;
  }

  return 0;
}