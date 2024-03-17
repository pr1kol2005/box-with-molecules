#pragma once

#include "Vector.h"
#include "Particle.h"

class Box {
  int width_;
  int height_;

public:
  Box(int width, int height);

  Vector GetNormal(const Vector& pos) const;

  bool CheckCollision(const Particle& particle);
};