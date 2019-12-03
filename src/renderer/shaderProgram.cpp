#include "shaderProgram.hpp"

#include <stdexcept>
#include <sstream>

ShaderProgram::ShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource)
{
  auto vertexShader = createCompiledShader(vertexShaderSource, GL_VERTEX_SHADER);
  auto fragmentShader = createCompiledShader(fragmentShaderSource, GL_FRAGMENT_SHADER);

  program_ = glCreateProgram();
  glAttachShader(program_, vertexShader);
  glAttachShader(program_, fragmentShader);
  glLinkProgram(program_);

  int result = 0;
  glGetProgramiv(program_, GL_LINK_STATUS, &result);
  if(!result) 
  {
    char infoLog[512];
    glGetProgramInfoLog(program_, 512, NULL, infoLog);
    std::stringstream errorMsgStream;
    errorMsgStream << "An error occured during linking shader program!" << std::endl << infoLog;
    throw std::runtime_error(errorMsgStream.str());
  }

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

void ShaderProgram::use()
{
  glUseProgram(program_);
}

GLuint ShaderProgram::createCompiledShader(const char* source, unsigned int shaderType)
{
  auto shader = glCreateShader(shaderType);
  glShaderSource(shader, 1, &source, NULL);
  glCompileShader(shader);

  char infoLog[512];
  int result = 0;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
  if(!result)
  {
    glGetShaderInfoLog(shader, 512, NULL, infoLog);
    std::stringstream errorMsgStream;
    errorMsgStream << "An error occured during shader compilation!" << std::endl << infoLog;
    throw std::runtime_error(errorMsgStream.str());
  }

  return shader;
}