#include <QWidget>

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>

#include <QString>

#include <QTimer>

#include <QStandardItem>
#include <QStandardItemModel>

#include "ParticleImage.h"
#include "Simulation.h"
#include "constants.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget {
  Q_OBJECT;

  Ui::MainWidget *ui_;
  QGraphicsScene *scene_;
  QTimer *timer_;
  QTimer *value_timer_;
  Simulation simulation_;

public:
  explicit MainWidget(QWidget *parent, Simulation &simulation);
  ~MainWidget();

private slots:
  void ManageCollisions();
  void MoveParticles();
  void UpdateValues();
};
