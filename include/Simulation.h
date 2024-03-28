#pragma once

#include <vector>

#include "Box.h"
#include "Vector.h"
#include "Particle.h"

class Simulation {
  std::vector<Particle> gas_;
  Box box_;

 public:
  Simulation(std::vector<Particle>& gas, Box& box);

  std::vector<Particle>& GetGas();
  
  void AddParticle(const Particle& molecule);

  void RemoveParticle();
  
  void ManageCollisions();

  void MoveParticles(double timeStep);
};

Vector AbsolutelyElasticCollision(const Vector& t, const Vector& v1, const Vector& v1_n, const Vector& v2_n, double m1, double m2);