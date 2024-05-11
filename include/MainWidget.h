#include <QWidget>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>

#include <QString>

#include <QTimer>

#include <QStandardItem>
#include <QStandardItemModel>

#include "ParticleImage.h"
#include "constants.h"
#include "Simulation.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget {
  Q_OBJECT;

  Ui::MainWidget* ui_;
  QGraphicsScene* scene_;
  QTimer* timer_;
  Simulation simulation_;

 public:
  explicit MainWidget(QWidget* parent, Simulation& simulation);
  ~MainWidget();

 private slots:
  void ManageCollisions();
  void MoveParticles();
  void UpdateValues();
};
