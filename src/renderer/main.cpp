#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cmath>

#include "window.hpp"
#include "shaderProgram.hpp"
#include "mesh.hpp"
#include "matrix.hpp"
#include "vertex.hpp"
#include "camera.hpp"
#include "texture.hpp"

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

void onResize(GLFWwindow*, int width, int height)
{
  glViewport(0, 0, width, height);
}

void input(Window& window, Camera& camera)
{
  const float movementSpeed = 0.06f;
  const float rotationSpeed = 0.02f;
  
  if(glfwGetKey(window.getWindowPtr(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
    window.close();
  
  if(glfwGetKey(window.getWindowPtr(), GLFW_KEY_W) == GLFW_PRESS)
    camera.move(Camera::CameraDirection::Forward, movementSpeed);
  else if(glfwGetKey(window.getWindowPtr(), GLFW_KEY_S) == GLFW_PRESS)
    camera.move(Camera::CameraDirection::Back, movementSpeed);
  else if(glfwGetKey(window.getWindowPtr(), GLFW_KEY_A) == GLFW_PRESS)
    camera.move(Camera::CameraDirection::Left, movementSpeed);
  else if(glfwGetKey(window.getWindowPtr(), GLFW_KEY_D) == GLFW_PRESS)
    camera.move(Camera::CameraDirection::Right, movementSpeed);
  
  if(glfwGetKey(window.getWindowPtr(), GLFW_KEY_UP) == GLFW_PRESS)
    camera.rotateX(rotationSpeed);
  else if(glfwGetKey(window.getWindowPtr(), GLFW_KEY_DOWN) == GLFW_PRESS)
    camera.rotateX(-rotationSpeed);
  else if(glfwGetKey(window.getWindowPtr(), GLFW_KEY_LEFT) == GLFW_PRESS)
    camera.rotateY(rotationSpeed);
  else if(glfwGetKey(window.getWindowPtr(), GLFW_KEY_RIGHT) == GLFW_PRESS)
    camera.rotateY(-rotationSpeed);
}

int main()
{
  Window window{"OpenGL", WINDOW_WIDTH, WINDOW_HEIGHT};
  window.setResizeCallback(onResize);

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  glFrontFace(GL_CW);
  glCullFace(GL_BACK);

  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

  try
  {
    ShaderProgram shaderProgram("vertexShader.vs.glsl", "fragmentShader.fs.glsl");
    
    Mesh cube({Vertex({-1.0, -1.0, -1.0}, {0, 0}), // front
               Vertex({-1.0, 1.0, -1.0}, {0, 1}),
               Vertex({1.0, 1.0, -1.0}, {1, 1}),
               Vertex({1.0, -1.0, -1.0}, {1, 0}),

               Vertex({1.0, -1.0, -1.0}, {0, 0}), // right
               Vertex({1.0, 1.0, -1.0}, {0, 1}),
               Vertex({1.0, 1.0, 1.0}, {1, 1}),
               Vertex({1.0, -1.0, 1.0}, {1, 0}), 

               Vertex({1.0, -1.0, 1.0}, {0, 0}), // back
               Vertex({1.0, 1.0, 1.0}, {0, 1}),
               Vertex({-1.0, 1.0, 1.0}, {1, 1}),
               Vertex({-1.0, -1.0, 1.0}, {1, 0}),

               Vertex({-1.0, -1.0, 1.0}, {0, 0}), // left
               Vertex({-1.0, 1.0, 1.0}, {0, 1}),
               Vertex({-1.0, 1.0, -1.0}, {1, 1}),
               Vertex({-1.0, -1.0, -1.0}, {1, 0}),

               Vertex({-1.0, 1.0, -1.0}, {0, 0}), // top
               Vertex({-1.0, 1.0, 1.0}, {0, 1}),
               Vertex({1.0, 1.0, 1.0}, {1, 1}),
               Vertex({1.0, 1.0, -1.0}, {1, 0}),

               Vertex({-1.0, -1.0, 1.0}, {0, 0}), // bottom
               Vertex({-1.0, -1.0, -1.0}, {0, 1}),
               Vertex({1.0, -1.0, -1.0}, {1, 1}),
               Vertex({1.0, -1.0, 1.0}, {1, 0}),
              }, 
              { 0, 1, 2, 2, 3, 0,
                4, 5, 6, 6, 7, 4,
                8, 9, 10, 10, 11, 8,
                12, 13, 14, 14, 15, 12,
                16, 17, 18, 18, 19, 16,
                20, 21, 22, 22, 23, 20
              });

    try
    {
      Texture crateTexture{"res/crate.jpg"};

      Camera camera{Vector3{0, 0, -3}, Vector3{0, 0, 1}, Vector3{0, 1, 0}};
      
      shaderProgram.use();
      auto mmLoc = shaderProgram.getUniformLocation("modelMatrix");
      auto vmLoc = shaderProgram.getUniformLocation("viewMatrix");
      auto pmLoc = shaderProgram.getUniformLocation("projectionMatrix");

      auto diffuseLoc = shaderProgram.getUniformLocation("diffuse");
      glUniform1i(diffuseLoc, 0);

      float aspectRatio = (float)window.getWidth() / window.getHeight();
      Matrix projectionMatrix = Matrix::initPerspective(M_PI / 2, aspectRatio, 0.1, 1000);

      glUniformMatrix4fv(pmLoc, 1, GL_TRUE, projectionMatrix.getData());

      float angle = M_PI / 2;
      while(window.isRunning())
      {
        input(window, camera);
        
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUniformMatrix4fv(vmLoc, 1, GL_TRUE, camera.getViewMatrix().getData());

        Matrix modelMatrix = Matrix::initRotation(angle, angle / 2, 0);
        glUniformMatrix4fv(mmLoc, 1, GL_TRUE, modelMatrix.getData());
        crateTexture.bind();
        cube.draw();

        window.update();

        angle += 0.015;
      }
    }
    catch(std::exception& ex)
    {
      std::cout << ex.what() << "\n";
    }
  }
  catch(std::runtime_error& err)
  {
    std::cout << "ERROR: " << err.what() << std::endl;
  }

  return 0;
}