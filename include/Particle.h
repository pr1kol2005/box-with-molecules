#pragma once

#include "Vector.h"

class Particle {
 public:
  Vector position;
  Vector velocity;
  double radius;
  double mass;

  Particle(const Vector& position, const Vector& velocity, double radius, double mass);

  Vector GetImpulse();

  void UpdatePosition(double timeStep);

  bool CheckCollision(const Particle& molecule);
};