#pragma once

#include "vector.hpp"

class Vertex
{
public:
  Vertex(const Vector& position, const Vector& color): position_(position), color_(color) {}

  inline const Vector& getPosition() const { return position_; }
  inline Vector& getPosition() { return position_; }
  inline void setPosition(const Vector& position) { position_ = position; }
  inline const Vector& getColor() const { return color_; }
  inline Vector& getColor() { return color_; }
  inline void setColor(const Vector& color) { color_ = color; }

private:
  Vector position_;
  Vector color_;
};