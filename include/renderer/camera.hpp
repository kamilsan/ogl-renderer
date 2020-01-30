#pragma once

#include "vector.hpp"
#include "matrix.hpp"

class Camera
{
public:
  Camera(const Vector& position, const Vector& forward, const Vector& up);

  void setPosition(const Vector& position);
  void setForward(const Vector& forward);

  Matrix getViewMatrix() const;
private:
  void calculateVectors();

  Vector position_;
  Vector forward_;
  Vector up_;
  Vector right_;
};