#include "ParticleImage.h"

ParticleImage::ParticleImage(Particle molecule) {
  QColor color = QColor(255, 255 , 0);
  setBrush(color);
  setRect(0, 0, 50, 50);
  setPos(100, 100);
}

void ParticleImage::advance(int phase) {
  // 0 phase - calculations
  // 1 phase - render

  if (phase) {
    setPos(rand() % 600, rand() % 600);
  }
}

ParticleImage::~ParticleImage() {
  delete molecule_;
}