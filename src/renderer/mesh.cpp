#include "mesh.hpp"

Mesh::Mesh(std::vector<float> verticies, std::vector<unsigned int> indicies)
{
  glGenBuffers(1, &VBO_);
  glGenBuffers(1, &IBO_);
  glGenVertexArrays(1, &VAO_);

  glBindVertexArray(VAO_);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO_);

  glBufferData(GL_ARRAY_BUFFER, verticies.size()*sizeof(float), 
    verticies.data(), GL_STATIC_DRAW);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies.size()*sizeof(unsigned int), 
    indicies.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

  glEnableVertexAttribArray(0);
  glBindVertexArray(0);

  count_ = indicies.size();
}

Mesh::~Mesh()
{
  glDeleteBuffers(1, &VBO_);
  glDeleteBuffers(1, &IBO_);
  glDeleteVertexArrays(1, &VAO_);
}

void Mesh::draw() const
{
  glBindVertexArray(VAO_);
  glDrawElements(GL_TRIANGLES, count_, GL_UNSIGNED_INT, 0);
  glBindVertexArray(0);
}