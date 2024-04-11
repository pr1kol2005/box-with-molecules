#include <QWidget>

#include <QGraphicsItem>

#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>


#include "Particle.h"
#include "constants.h"

class ParticleImage : public QGraphicsEllipseItem {
  Particle* molecule_;

 public:
  ParticleImage(Particle* molecule);

  virtual void advance(int phase);
};