#include <QWidget>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>

#include <QTimer>

#include "Particle.h"
#include "constants.h"

class ParticleImage : public QGraphicsEllipseItem {
  Particle* molecule_;

 public:
  ParticleImage(Particle* molecule);

  virtual void advance(int phase);
};