#include "mesh.hpp"

Mesh::Mesh(std::vector<Vertex> verticies, std::vector<unsigned int> indicies)
{
  std::vector<float> vboData;
  for(auto vertex : verticies)
  {
    vboData.push_back(vertex.getPosition().x);
    vboData.push_back(vertex.getPosition().y);
    vboData.push_back(vertex.getPosition().z);
    vboData.push_back(vertex.getTexCoord().x);
    vboData.push_back(vertex.getTexCoord().y);
  }

  glGenBuffers(1, &VBO_);
  glGenBuffers(1, &IBO_);
  glGenVertexArrays(1, &VAO_);

  glBindVertexArray(VAO_);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO_);

  glBufferData(GL_ARRAY_BUFFER, vboData.size()*sizeof(float), 
    vboData.data(), GL_STATIC_DRAW);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies.size()*sizeof(unsigned int), 
    indicies.data(), GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)));
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  
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