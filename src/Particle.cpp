#include "Particle.h"
#include "constants.h"

Particle::Particle(const Vector& position, const Vector& velocity,
                   double radius, double mass) : position_(position), velocity_(velocity), radius_(radius), mass_(mass) {
};

Vector Particle::GetImpulse() {
  return velocity_ * mass_;
};

void Particle::UpdatePosition(double timeStep) {
  position_.x_ += velocity_.x_ * timeStep;
  position_.y_ += velocity_.y_ * timeStep;
};

bool Particle::CheckCollision(const Particle& molecule) {
  double gap = radius_ + molecule.radius_ + TIME_INTERVAL * (velocity_.Length() + molecule.velocity_.Length());
  return (position_ - molecule.position_).Length() < gap;
};