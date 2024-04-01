#pragma once

#include "Vector.h"

class Particle {
  Vector position_;
  Vector velocity_;
  double radius_;
  double mass_;

 public:
  Particle(const Vector& position, const Vector& velocity, double radius, double mass);

  Vector GetImpulse();

  void UpdatePosition(double timeStep);

  bool CheckCollision(const Particle& molecule);

  friend class Box;
  friend class GraphicsComponent;
  friend class Simulation;
};