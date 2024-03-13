#pragma once

#include "Vector.h"
#include "Particle.h"

class Box {
 public:
  int width;
  int height;

  Box(int width, int height);

  Vector GetNormal(const Vector& pos) const;

  bool CheckCollision(const Particle& particle);
};