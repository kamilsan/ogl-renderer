#pragma once

#include <glad/glad.h>
#include "stb_image.h"

class Texture
{
public:
  Texture(const char* filename);
  ~Texture();

  void bind() const;
private:
  GLuint texture_;
};