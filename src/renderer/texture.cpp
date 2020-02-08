#include "texture.hpp"

#include <stdexcept>

Texture::Texture(const char* filename)
{
  int width, height, n;
  unsigned char* pixels = stbi_load(filename, &width, &height, &n, 0);
  if(!pixels)
  {
    throw std::runtime_error("Failed to load texture!");
  }

  glGenTextures(1, &texture_);
  glBindTexture(GL_TEXTURE_2D, texture_);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);
  glGenerateMipmap(GL_TEXTURE_2D);

  stbi_image_free(pixels);
  glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture()
{
  glDeleteTextures(1, &texture_);
}

void Texture::bind() const
{
  glBindTexture(GL_TEXTURE_2D, texture_);
}
