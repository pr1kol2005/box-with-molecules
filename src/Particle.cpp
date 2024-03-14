#include "Particle.h"

Particle::Particle(const Vector& position, const Vector& velocity,
                   double radius, double mass) : position(position), velocity(velocity), radius(radius), mass(mass) {
};

Vector Particle::GetImpulse() {
  return velocity * mass;
};

void Particle::UpdatePosition(double timeStep) {
  position.x += velocity.x * timeStep;
  position.y += velocity.y * timeStep;
};

bool Particle::CheckCollision(const Particle& molecule) {
  double tolerance = 1e-2;
  return (position - molecule.position).Length() - radius - molecule.radius < tolerance;
};