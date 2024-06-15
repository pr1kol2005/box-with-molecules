#pragma once

#include "Particle.h"
#include "Vector.h"

class Box {
  int width_;
  int height_;

public:
  Box(int width, int height);

  Vector GetNormal(const Vector &pos) const;

  bool CheckCollision(const Particle &particle);

  bool OutOfBoundaries(const Particle &particle);
};