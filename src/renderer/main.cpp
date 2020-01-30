#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>

#include "window.hpp"
#include "shaderProgram.hpp"
#include "mesh.hpp"
#include "matrix.hpp"
#include "vertex.hpp"
#include "camera.hpp"

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
    Mesh triangle({Vertex{{-1.0, -1.0, 0.0}, {1.0, 0.0, 0.0}}, 
                   Vertex{{0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}}, 
                   Vertex{{1.0, -1.0, 0.0}, {0.0, 0.0, 1.0}}}, 
                   {0, 1, 2});
  
    Mesh quad({Vertex{{-1.0, -1.0, 0.0}, {0.09, 0.455, 0.5176}}, 
                   Vertex{{-1.0, 1.0, 0.0}, {0.09, 0.455, 0.5176}}, 
                   Vertex{{1.0, 1.0, 0.0}, {0.09, 0.455, 0.5176}}, 
                   Vertex{{1.0, -1.0, 0.0}, {0.09, 0.455, 0.5176}}},
                   {0, 1, 2, 2, 3, 0});

    Camera camera{Vector{0, 0, -3}, Vector{0, 0, 1}, Vector{0, 1, 0}};
    
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    shaderProgram.use();
    auto mmLoc = shaderProgram.getUniformLocation("modelMatrix");
    auto vmLoc = shaderProgram.getUniformLocation("viewMatrix");
    auto pmLoc = shaderProgram.getUniformLocation("projectionMatrix");

    float aspectRatio = (float)window.getWidth() / window.getHeight();
    Matrix projectionMatrix = Matrix::initPerspective(M_PI / 2, aspectRatio, 0.1, 1000);

    glUniformMatrix4fv(pmLoc, 1, GL_TRUE, projectionMatrix.getData());

    float angle = M_PI/2;
    while(window.isRunning())
    {
      glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      Vector cameraPos = {3.0f * cos(angle), 0, 3.0f * sin(angle)};
      camera.setPosition(cameraPos);
      camera.setForward(-cameraPos);
      glUniformMatrix4fv(vmLoc, 1, GL_TRUE, camera.getViewMatrix().getData());
      glUniformMatrix4fv(mmLoc, 1, GL_TRUE, Matrix::initIdentity().getData());

      glUniformMatrix4fv(mmLoc, 1, GL_TRUE, Matrix::initTranslation(1.25, 0, 0).getData());
      triangle.draw();

      glUniformMatrix4fv(mmLoc, 1, GL_TRUE, Matrix::initTranslation(-1.25, 0, 0).getData());
      quad.draw();

      window.update();

      angle += 0.015;
    }
  }
  catch(std::runtime_error& err)
  {
    std::cout << "ERROR: " << err.what() << std::endl;
  }

  return 0;
}