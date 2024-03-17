#include "Simulation.h"

#include <cmath>
#include <iostream>

Simulation::Simulation(std::vector<Particle>& gas, Box& box) : gas_(gas), box_(box) {
}

std::vector<Particle>& Simulation::GetGas(){
  return gas_;
}

void Simulation::AddParticle(const Particle& molecule) {
  gas_.emplace_back(molecule);
}

void Simulation::RemoveParticle() {
  gas_.pop_back();
}

void Simulation::ManageCollisions() {
  size_t size = gas_.size();
  for (size_t i = 0; i < size; i++) {
    if (box_.CheckCollision(gas_[i])) {
      Vector v = gas_[i].velocity_;
      Vector n = box_.GetNormal(gas_[i].position_);
      Vector t = Vector(std::pow(n.y_, 2), std::pow(n.x_, 2));
      gas_[i].velocity_ = n * std::fabs(v.ScalarProduct(n)) + t * v.ScalarProduct(t);
    }
    for (size_t j = i + 1; j < size; j++) {
      if(gas_[i].CheckCollision(gas_[j])) {
        Vector n = (gas_[j].position_ - gas_[i].position_) / (gas_[j].position_ - gas_[i].position_).Length();
        Vector t = n.Normal();
        Vector v1 = gas_[i].velocity_;
        Vector v2 = gas_[j].velocity_;
        Vector v1_n = n * v1.ScalarProduct(n);
        Vector v2_n = n * v2.ScalarProduct(n);
        double m1 = gas_[i].mass_;
        double m2 = gas_[j].mass_;
        gas_[i].velocity_ = t * v1.ScalarProduct(t) + (v1_n * (m1 - m2) + v2_n * 2 * m2) / (m1 + m2);
        gas_[j].velocity_ = t * v2.ScalarProduct(t) + (v2_n * (m2 - m1) + v1_n * 2 * m1) / (m1 + m2);
      }
    }
  }
}

void Simulation::MoveParticles(double timeStep) {
  for (size_t i = 0; i < gas_.size(); i++) {
    gas_[i].UpdatePosition(timeStep);
  }
}