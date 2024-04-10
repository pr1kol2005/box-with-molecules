#include <QWidget>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>

#include <QTimer>

#include "Particle.h"

class ParticleImage : public QGraphicsEllipseItem {
  Particle* molecule_;

 public:
  ParticleImage(Particle molecule);

  ~ParticleImage();

  virtual void advance(int phase);
};