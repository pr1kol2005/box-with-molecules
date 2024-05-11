#include "Simulation.h"

#include <cmath>
#include <iostream>
#include <random>

Simulation::Simulation(std::vector<Particle>& gas, Box& box) : gas_(gas), box_(box) {
  ResetThermodynamicValues();
  grid_.reserve(GRID_HEIGHT + 1);
  for (size_t i = 0; i <= GRID_HEIGHT; i++) {
    grid_.emplace_back(std::vector<Particle*>(GRID_WIDTH + 1, nullptr));
  }
}

void Simulation::RandomSpawn() {
  std::srand(std::time(0));

  for (int i = 0; i < PARTICLE_SPAWN_NUMBER; i++) {
    AddParticle(Particle(Vector(PARTICLE_SIZE + (1 + (std::rand() % (GRID_WIDTH - 1))) * 2 * PARTICLE_SIZE,
                                PARTICLE_SIZE + (1 + (std::rand() % (GRID_HEIGHT - 1))) * 2 * PARTICLE_SIZE),
                         Vector(MAX_SPAWN_VELOCITY - std::rand() % (2 * MAX_SPAWN_VELOCITY),
                                MAX_SPAWN_VELOCITY - std::rand() % (2 * MAX_SPAWN_VELOCITY)),
                         PARTICLE_SIZE, 1));                                
  }
}

void Simulation::ResetThermodynamicValues() {
  p_ = 0;
  v_avg_ = 0;
  E_avg_ = 0;
  kT_ = 0;
}

std::vector<Particle>& Simulation::GetGas() {
  return gas_;
}

void Simulation::AddParticle(const Particle& molecule) {
  gas_.emplace_back(molecule);
}

void Simulation::RemoveParticle() {
  gas_.pop_back();
}

void Simulation::BoxCollision(Particle* curr) {
  Vector v = curr->velocity_;
  Vector p = curr->GetImpulse();
  Vector n = box_.GetNormal(curr->position_);
  Vector t = Vector(std::pow(n.y_, 2), std::pow(n.x_, 2));
  curr->velocity_ = n * std::fabs(v.ScalarProduct(n)) + t * v.ScalarProduct(t);

  double dp_n = 2 * std::fabs(p.ScalarProduct(n));
  p_ += dp_n;
}

void Simulation::ParticleCollision(Particle* curr, Particle* other) {
  Vector n = (other->position_ - curr->position_) / (other->position_ - curr->position_).Length();
  Vector t = n.Normal();
  Vector v1 = curr->velocity_;
  Vector v2 = other->velocity_;
  Vector v1_n = n * v1.ScalarProduct(n);
  Vector v2_n = n * v2.ScalarProduct(n);
  double m1 = curr->mass_;
  double m2 = other->mass_;
  if ((v2_n - v1_n).ScalarProduct(other->position_ - curr->position_) <= 0) {
    curr->velocity_ = AbsolutelyElasticCollision(t, v1, v1_n, v2_n, m1, m2);
    other->velocity_ = AbsolutelyElasticCollision(t, v2, v2_n, v1_n, m2, m1);
  }
}

void Simulation::ManageCollisionsLinear() {
  for (size_t i = 0; i <= GRID_HEIGHT; ++i) {
    grid_[i].assign(GRID_WIDTH + 1, nullptr);
  }

  for (size_t i = 0; i < gas_.size(); ++i) {
    int x = std::abs((int)(gas_[i].position_.x_ / GRID_CELL_SIZE) % GRID_WIDTH);
    int y = std::abs((int)(gas_[i].position_.y_ / GRID_CELL_SIZE) % GRID_HEIGHT);
    grid_[y][x] = &gas_[i];
  }

  int dy_arr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dx_arr[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  for (size_t i = 0; i <= GRID_HEIGHT; ++i) {
    for (size_t j = 0; j <= GRID_WIDTH; ++j) {
      Particle* curr = grid_[i][j];
      if (curr == nullptr) {
        continue;
      }

      if (box_.CheckCollision(*curr)) {
        BoxCollision(curr);
      }

      for (int k = 0; k < 8; k++) {
        int dy = dy_arr[k];
        int dx = dx_arr[k];
        if (0 <= i + dy && i + dy <= GRID_HEIGHT && 0 <= j + dx && j + dx <= GRID_WIDTH) {
          Particle* other = grid_[i + dy][j + dx];
          if (other && curr->CheckCollision(*other)) {
            ParticleCollision(curr, other);
          }
        }
      }
    }
  }
}

void Simulation::ManageCollisionsSquared() {
  size_t size = gas_.size();
  for (size_t i = 0; i < size; i++) {
    if (box_.CheckCollision(gas_[i])) {
      BoxCollision(&gas_[i]);
    }
    for (size_t j = i + 1; j < size; j++) {
      if(gas_[i].CheckCollision(gas_[j])) {
        ParticleCollision(&gas_[i], &gas_[j]);
      }
    }
  }
}

void Simulation::MoveParticles(double time_step) {
  for (size_t i = 0; i < gas_.size(); i++) {
    gas_[i].UpdatePosition(time_step);
    v_avg_ += gas_[i].velocity_.Length();
    E_avg_ += gas_[i].mass_ * gas_[i].velocity_.Length() * gas_[i].velocity_.Length() / 2;
  }
}

Vector AbsolutelyElasticCollision(const Vector& t, const Vector& v1, const Vector& v1_n, const Vector& v2_n, double m1, double m2) {
  return t * v1.ScalarProduct(t) + (v1_n * (m1 - m2) + v2_n * 2 * m2) / (m1 + m2);
}