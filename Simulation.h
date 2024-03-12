#pragma once

#include <vector>

#include "Box.h"
#include "Vector.h"
#include "Particle.h"

class Simulation {
 public:
  std::vector<Particle> gas;
  Box box;

  Simulation(std::vector<Particle> gas, Box box);
  
  void AddParticle(const Particle& molecule);

  void RemoveLastParticle();

  void Simulate();
};