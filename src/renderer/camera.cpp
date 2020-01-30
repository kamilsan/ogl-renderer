#include "camera.hpp"

Camera::Camera(const Vector& position, const Vector& forward, const Vector& up): position_(position)
{
  forward_ = forward.normalize();
  up_ = up.normalize();
  calculateVectors();
}

void Camera::setPosition(const Vector& position)
{
  position_ = position;
}

void Camera::setForward(const Vector& forward)
{
  forward_ = forward.normalize();
  calculateVectors();
}

Matrix Camera::getViewMatrix() const
{
  Matrix cameraTranslation({1, 0, 0, -position_.x,
                            0, 1, 0, -position_.y,
                            0, 0, 1, -position_.z,
                            0, 0, 0, 1});
  Matrix cameraRotation({right_.x, right_.y, right_.z, 0,
                        up_.x, up_.y, up_.z, 0,
                        forward_.x, forward_.y, forward_.z, 0,
                        0, 0, 0, 1});

  return cameraRotation * cameraTranslation;
}

void Camera::calculateVectors()
{
  right_ = up_.normalize().cross(forward_).normalize();
  up_ = forward_.cross(right_).normalize();
}