#include <QWidget>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>

#include <QTimer>

#include "Particle.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget {
  Q_OBJECT;

  Ui::MainWidget* ui_;
  QGraphicsScene* scene_;
  QTimer* timer_;


 public:
  explicit MainWidget(QWidget* parent = nullptr);
  ~MainWidget();
};

class ParticleImage : public QGraphicsEllipseItem {
 public:
  ParticleImage(Particle molecule);

  virtual void advance(int phase);
};
