#include "ParticleImage.h"

ParticleImage::ParticleImage(Particle* molecule) : molecule_(molecule){
  QColor color = QColor(255, 255, 0);
  setBrush(color);

  setRect(0, 0, molecule_->radius_, molecule_->radius_);

  setPos(molecule_->position_.x_, molecule_->position_.y_);
}

void ParticleImage::advance(int phase) {
  // 0 phase - calculations
  // 1 phase - render

  if (phase) {
    moveBy(molecule_->velocity_.x_ * TIME_INTERVAL, molecule_->velocity_.y_ * TIME_INTERVAL);
  }
}

ParticleImage::~ParticleImage() {
  delete molecule_;
}