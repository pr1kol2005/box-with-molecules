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