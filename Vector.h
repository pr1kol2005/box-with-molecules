#pragma once

#include <cmath>

class Vector {
 public:
  double x;
  double y;

  Vector(double x1 = 0, double y1 = 0);

  Vector operator+(const Vector& other) const;

  Vector operator-(const Vector& other) const;

  Vector operator*(double scalar) const;

  Vector operator/(double scalar) const;

  double Length() const;
};