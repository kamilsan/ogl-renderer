#pragma once

#include <vector>
#include <glad/glad.h>

#include "vertex.hpp"

class Mesh
{
public:
  Mesh(std::vector<Vertex> verticies, std::vector<unsigned int> indicies);
  Mesh(const Mesh& other) = delete;
  ~Mesh();

  void draw() const;
private:
  GLuint VAO_;
  GLuint VBO_;
  GLuint IBO_;
  int count_;
};