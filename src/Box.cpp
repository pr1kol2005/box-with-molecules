#include "Box.h"
#include "constants.h"

Box::Box(int width, int height) : width_(width), height_(height) {
}

Vector Box::GetNormal(const Vector& pos) const {
  if (pos.x_ <= width_ / 2 && pos.x_ <= pos.y_ && pos.x_ <= (height_ - pos.y_)) {
    return LEFT_WALL_NORMAL;
  }
  else if (pos.x_ >= width_ / 2 && (width_ - pos.x_) <= pos.y_ && (width_ - pos.x_) <= (height_ - pos.y_)) {
    return RIGHT_WALL_NORMAL;
  }
  else if (pos.y_ <= height_ / 2 && pos.y_ <= pos.x_ && pos.y_ <= (width_ - pos.x_)) {
    return BOTTOM_WALL_NORMAL;
  }
  else if (pos.y_ >= height_ / 2 && (height_ - pos.y_) <= pos.x_ && (height_ - pos.y_) <= (width_ - pos.x_)) {
    return TOP_WALL_NORMAL;
  }
  return TOP_WALL_NORMAL;
}

bool Box::CheckCollision(const Particle& particle) {
  double gap = particle.radius_ + particle.velocity_.Length() * TIME_INTERVAL;
  return (particle.position_.x_ < gap) || (particle.position_.y_ < gap) ||
         ((width_ - particle.position_.x_) < gap) || ((height_ - particle.position_.x_) < gap);
};