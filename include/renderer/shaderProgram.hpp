#pragma once

#include <glad/glad.h>

class ShaderProgram
{
public:
  explicit ShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource);

  void use();
private:
  GLuint program_;

  GLuint createCompiledShader(const char* source, unsigned int shaderType);
};