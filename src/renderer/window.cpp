#include "window.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdexcept>

Window::Window(const char* title, unsigned int width, unsigned int height): 
  width_(width), height_(height), running_(false)
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_OPENGL_CORE_PROFILE);

  window_ = glfwCreateWindow(width, height, title, NULL, NULL);

  if(window_ == NULL)
  {
    glfwTerminate();
    throw std::runtime_error("Failed to create GLFW window!");
  }
  glfwMakeContextCurrent(window_);

  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    glfwTerminate();
    throw std::runtime_error("Failed to initialize GLAD!");
  }

  running_ = true;
}

Window::~Window()
{
  glfwDestroyWindow(window_);
  glfwTerminate();
}

void Window::update()
{
  if(!glfwWindowShouldClose(window_))
  {
    glfwSwapBuffers(window_);
    glfwPollEvents();
  }
  else
    running_ = false;
}

void Window::setResizeCallback(void(*cb)(GLFWwindow*, int, int))
{
  glfwSetFramebufferSizeCallback(window_, cb);
}

unsigned int Window::getWidth() const
{
  return width_;
}

unsigned int Window::getHeight() const
{
  return height_;
}

bool Window::isRunning() const
{
  return running_;
}
