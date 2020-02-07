#include "camera.hpp"

Camera::Camera(const Vector& position, const Vector& forward, const Vector& up): 
  position_(position)
{
  forward_ = forward.normalize();
  up_ = up.normalize();
  calculateAngles();
  calculateVectors();
}

void Camera::setPosition(const Vector& position)
{
  position_ = position;
}

void Camera::setForward(const Vector& forward)
{
  forward_ = forward.normalize();
  calculateAngles();
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

void Camera::rotateX(float amt)
{
  pitch_ += amt;
  calculateForwardFromAngles();
  calculateVectors();
}

void Camera::rotateY(float amt)
{
  yaw_ += amt;
  calculateForwardFromAngles();
  calculateVectors();
}

void Camera::move(Camera::CameraDirection direction, float amt)
{
  switch(direction)
  {
    case CameraDirection::Forward:
      position_ += forward_ * amt;
      break;
    case CameraDirection::Back:
      position_ -= forward_ * amt;
      break;
    case CameraDirection::Right:
      position_ += right_ * amt;
      break;
    case CameraDirection::Left:
      position_ -= right_ * amt;
      break;
  }
}

const Vector& Camera::getForward() const
{
  return forward_;
}

const Vector& Camera::getRight() const
{
  return right_;
}

const Vector& Camera::getUp() const
{
  return up_;
}

void Camera::calculateAngles()
{
  pitch_ = std::asin(forward_.y);
  yaw_ = std::atan2(forward_.z, forward_.x);
}

void Camera::calculateForwardFromAngles()
{
  float sinY = std::sin(yaw_);
  float cosY = std::cos(yaw_);
  float sinP = std::sin(pitch_);
  float cosP = std::cos(pitch_);

  forward_ = Vector(cosY*cosP, sinP, sinY*cosP).normalize();
}

void Camera::calculateVectors()
{
  up_ = Vector(0, 1, 0);
  right_ = up_.normalize().cross(forward_).normalize();
  up_ = forward_.cross(right_).normalize();  
}