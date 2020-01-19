#pragma once

#include <glad/glad.h>
#include <string>

class ShaderProgram
{
public:
  explicit ShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource);

  void use() const;
  GLuint getUniformLocation(const std::string& name) const;
private:
  GLuint program_;

  GLuint createCompiledShader(const char* source, unsigned int shaderType);
};