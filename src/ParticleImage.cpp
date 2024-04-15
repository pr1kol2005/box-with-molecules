#include "ParticleImage.h"

ParticleImage::ParticleImage(Particle* molecule) : molecule_(molecule){
  QColor color = QColor(255, 255, 0);
  setBrush(color);

  setRect(0, 0, molecule_->radius_ * 2, molecule_->radius_ * 2);

  setPos(molecule_->position_.x_ - molecule_->radius_, molecule_->position_.y_ - molecule_->radius_);
}

void ParticleImage::advance(int phase) {
  // 0 phase - calculations
  // 1 phase - render

  if (phase) {
    setPos(molecule_->position_.x_ - molecule_->radius_, molecule_->position_.y_ - molecule_->radius_);
  }
}