#include "Box.h"

Box::Box(int width, int height) : width(width), height(height) {
}

Vector Box::GetNormal(const Vector& pos) const {
  if (pos.x <= width / 2 && pos.x <= pos.y && pos.x <= (height - pos.y)) {
    return Vector(1, 0);
  }
  else if (pos.x >= width / 2 && (width - pos.x) <= pos.y && (width - pos.x) <= (height - pos.y)) {
    return Vector(-1, 0);
  }
  else if (pos.y <= height / 2 && pos.y <= pos.x && pos.y <= (width - pos.x)) {
    return Vector(0, 1);
  }
  else if (pos.y >= height / 2 && (height - pos.y) <= pos.x && (height - pos.y) <= (width - pos.x)) {
    return Vector(0, -1);
  }
  return Vector(0, -1);
}

bool Box::CheckCollision(const Particle& particle) {
  double tolerance = particle.radius + 1e-2;
  return (particle.position.x < tolerance) || (particle.position.y < tolerance) ||
         ((width - particle.position.x) < tolerance) || ((height - particle.position.x) < tolerance);
};