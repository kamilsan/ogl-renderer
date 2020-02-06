#pragma once

#include "vector.hpp"
#include "matrix.hpp"

class Camera
{
public:
  enum class CameraDirection { Forward, Back, Right, Left };

  Camera(const Vector& position, const Vector& forward, const Vector& up);

  void setPosition(const Vector& position);
  void setForward(const Vector& forward);

  void rotateX(float amt);
  void rotateY(float amt);
  void move(CameraDirection direction, float amt);

  const Vector& getForward() const;
  const Vector& getRight() const;
  const Vector& getUp() const;

  Matrix getViewMatrix() const;
private:
  void calculateForwardFromAngles();
  void calculateAngles();
  void calculateVectors();

  Vector position_;
  Vector forward_;
  Vector up_;
  Vector right_;
  float yaw_;
  float pitch_;
};