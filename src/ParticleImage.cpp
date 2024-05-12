#include "ParticleImage.h"

#include <iostream>

ParticleImage::ParticleImage(Particle* molecule) : molecule_(molecule){
  double heat_value = (molecule_->velocity_.Length()) / MAX_SPAWN_VELOCITY;
  QColor color = QColor((int)(255 * heat_value), 255, (int)(255 * (1 - heat_value)));
  setBrush(color);

  setRect(0, 0, molecule_->radius_ * 2, molecule_->radius_ * 2);

  setPos(molecule_->position_.x_ - molecule_->radius_, molecule_->position_.y_ - molecule_->radius_);
}

void ParticleImage::advance(int phase) {
  // 0 phase - calculations
  // 1 phase - render

  if (phase) {
    setPos(molecule_->position_.x_ - molecule_->radius_, molecule_->position_.y_ - molecule_->radius_);
    double heat_value = (molecule_->velocity_.Length()) / MAX_SPAWN_VELOCITY;
    heat_value = heat_value > 1 ? 1 : heat_value;
    QColor color = QColor((int)(255 * heat_value), 0, (int)(255 * (1 - heat_value)));
    setBrush(color);
  }
}