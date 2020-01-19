#pragma once

#include <cmath>
#include <iostream>

struct Vector
{
  Vector(): x(0), y(0), z(0) {}
  Vector(float x, float y, float z): x(x), y(y), z(z) {}

  inline float length() const { return std::sqrt(x*x + y*y + z*z); };
  inline float lengthSq() const { return x*x + y*y + z*z; };
  inline Vector normalize() const;
  inline float dot(const Vector& other) const { return x*other.x + y*other.y + z*other.z; };
  inline Vector cross(const Vector& other) const;

  inline Vector operator+(const Vector& other) const;
  inline Vector operator-(const Vector& other) const;
  inline Vector operator-() const;
  inline Vector operator*(float value) const;
  inline Vector operator/(float value) const;
  inline friend std::ostream& operator<<(std::ostream& os, const Vector& v);

  float x;
  float y;
  float z;
};

inline Vector Vector::normalize() const
{
  float len = length();
  if(len > -0.0001 && len < 0.0001)
    return Vector();
  return Vector(x / len, y / len, z / len);
}

inline Vector Vector::cross(const Vector& other) const
{
  return Vector(y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x);
}

inline Vector Vector::operator+(const Vector& other) const
{
  return Vector(x + other.x, y + other.y, z + other.z);
}

inline Vector Vector::operator-(const Vector& other) const
{
  return Vector(x - other.x, y - other.y, z - other.z);
}

inline Vector Vector::operator-() const
{
  return Vector(-x, -y, -z);
}

inline Vector Vector::operator*(float value) const
{
  return Vector(x * value, y * value, z * value);
}

inline Vector Vector::operator/(float value) const
{
  float inv = 1.0/value;
  return Vector(x * inv, y * inv, z * inv);
}


inline std::ostream& operator<<(std::ostream& os, const Vector& v)
{
  os << "[" << v.x << ", " << v.y << ", " << v.z << "]";
  return os;
}