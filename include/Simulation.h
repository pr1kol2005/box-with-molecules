#pragma once

#include <vector>

#include "Box.h"
#include "Vector.h"
#include "Particle.h"

#include "constants.h"

class Simulation {
  std::vector<Particle> gas_;
  Box box_;
  std::vector<std::vector<Particle*>> grid_;

 public:
  Simulation(std::vector<Particle>& gas, Box& box);

  ~Simulation() = default;

  void RandomSpawn();

  std::vector<Particle>& GetGas();
  
  void AddParticle(const Particle& molecule);

  void RemoveParticle();

  void BoxCollision(Particle* curr);

  void ParticleCollision(Particle* curr, Particle* other);
  
  void ManageCollisionsLinear();

  void ManageCollisionsSquared();

  void MoveParticles(double timeStep);

  friend class MainWidget;
};

Vector AbsolutelyElasticCollision(const Vector& t, const Vector& v1, const Vector& v1_n, const Vector& v2_n, double m1, double m2);