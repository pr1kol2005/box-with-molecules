#include "Simulation.h"

#include <cmath>

Simulation::Simulation(std::vector<Particle> gas, Box box) : gas(gas), box(box) {
}

void Simulation::AddParticle(const Particle& molecule) {
  gas.emplace_back(molecule);
}

void Simulation::RemoveLastParticle() {
  gas.pop_back();
}

void Simulation::Simulate() {
  size_t size = gas.size();
  for (size_t i = 0; i < size; i++) {
    if (gas[i].CheckCollision(box)) {
      Vector v = gas[i].velocity;
      Vector n = box.GetNormal(gas[i].position);
      Vector t = Vector(std::pow(n.y, 2), std::pow(n.y, 2));
      gas[i].velocity = n * std::fabs(v.ScalarProduct(n)) + t * v.ScalarProduct(t);
    }
    for (size_t j = i + 1; j < size; j++) {
      if(gas[i].CheckCollision(gas[j])) {
        Vector n = gas[j].position - gas[i].position;
        Vector t = n.Normal();
        Vector v1 = gas[i].velocity;
        Vector v2 = gas[j].velocity;
        Vector v1_n = n * v1.ScalarProduct(n);
        Vector v2_n = n * v2.ScalarProduct(n);
        double m1 = gas[i].mass;
        double m2 = gas[j].mass;
        gas[i].velocity = t * v1.ScalarProduct(t) + (v1_n * (m1 - m2) + v2_n * 2 * m2) / (m1 + m2);
        gas[j].velocity = t * v2.ScalarProduct(t) + (v2_n * (m2 - m1) + v1_n * 2 * m1) / (m1 + m2);
      }
    }
  }
}