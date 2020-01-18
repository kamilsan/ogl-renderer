#pragma once

#include <vector>
#include <glad/glad.h>

class Mesh
{
public:
  Mesh(std::vector<float> verticies, std::vector<unsigned int> indicies);
  Mesh(const Mesh& other) = delete;
  ~Mesh();

  void draw() const;
private:
  GLuint VAO_;
  GLuint VBO_;
  GLuint IBO_;
  int count_;
};