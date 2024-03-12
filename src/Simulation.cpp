#include "Simulation.h"

Simulation::Simulation(std::vector<Particle> gas, Box box) : gas(gas), box(box) {
}

void Simulation::AddParticle(const Particle& molecule) {
  gas.push_back(molecule);
}

void Simulation::RemoveLastParticle() {
  gas.pop_back();
}

void Simulation::Simulate() {
  // add simulation logic
}