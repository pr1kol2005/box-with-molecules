#include "Simulation.h"

#include <cmath>
#include <iostream>

Simulation::Simulation(std::vector<Particle>& gas, Box& box) : gas_(gas), box_(box) {
  grid_ = new std::vector<Particle*>*[GRID_WIDTH + 2];
  for (size_t i = 0; i < GRID_WIDTH + 2; i++) {
    grid_[i] = new std::vector<Particle*>[GRID_HEIGHT + 2];
    for (size_t j = 0; j < GRID_HEIGHT + 2; j++) {
      grid_[i][j] = std::vector<Particle *>(1);
    }
  }
}

Simulation::~Simulation() {
  for (size_t i = 0; i < GRID_WIDTH + 2; i++) {
    delete[] grid_[i];
  }
  delete[] grid_;
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

Vector AbsolutelyElasticCollision(const Vector& t, const Vector& v1, const Vector& v1_n, const Vector& v2_n, double m1, double m2) {
  return t * v1.ScalarProduct(t) + (v1_n * (m1 - m2) + v2_n * 2 * m2) / (m1 + m2);
}

// void Simulation::ManageCollisions() {
//   for (int i = 1; i <= GRID_WIDTH; ++i) {
//     for (int j = 1; j <= GRID_HEIGHT; ++j) {
//       grid_[i][j].clear();
//     }
//   }

//   for (int i = 0; i < gas_.size(); ++i) {
//     int x = (int)(gas_[i].position_.x_ / (PARTICLE_SIZE * 2)) + 1;
//     int y = (int)(gas_[i].position_.y_ / (PARTICLE_SIZE * 2)) + 1;
//     grid_[x][y].push_back(&gas_[i]);
//   }
// }

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
        if ((v2_n - v1_n).ScalarProduct(gas_[j].position_ - gas_[i].position_) <= 0) {
          gas_[i].velocity_ = AbsolutelyElasticCollision(t, v1, v1_n, v2_n, m1, m2);
          gas_[j].velocity_ = AbsolutelyElasticCollision(t, v2, v2_n, v1_n, m2, m1);
        }
      }
    }
  }
}

void Simulation::MoveParticles(double timeStep) {
  for (size_t i = 0; i < gas_.size(); i++) {
    gas_[i].UpdatePosition(timeStep);
  }
}