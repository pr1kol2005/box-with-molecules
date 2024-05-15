#pragma once

#include <cmath>

class Vector {
  double x_;
  double y_;

public:
  Vector(double x, double y);

  Vector operator+(const Vector &other) const;

  Vector operator-(const Vector &other) const;

  Vector operator*(double scalar) const;

  Vector operator/(double scalar) const;

  Vector &operator+=(const Vector &other);

  Vector &operator-=(const Vector &other);

  Vector &operator*=(double scalar);

  Vector &operator/=(double scalar);

  double Length() const;

  Vector Normal() const;

  double CrossProduct(const Vector &other) const;

  double ScalarProduct(const Vector &other) const;

  friend class Box;
  friend class GraphicsComponent;
  friend class Particle;
  friend class Simulation;
  friend class ParticleImage;
  friend class MainWidget;
};