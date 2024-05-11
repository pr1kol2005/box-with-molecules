#include "MainWidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent, Simulation& simulation) : QWidget(parent), ui_(new Ui::MainWidget), simulation_(simulation)
{
  ui_->setupUi(this);

  resize(BOX_WIDTH + 100, BOX_HEIGHT + 100);

  scene_ = new QGraphicsScene(0, 0, BOX_WIDTH, BOX_HEIGHT, this);

  ui_->graphicsView->setScene(scene_);

  scene_->addRect(scene_->sceneRect());

  for (size_t i = 0; i < simulation.gas_.size(); i++) {
    scene_->addItem(new ParticleImage(simulation_.gas_.data() + i));
  }

  ui_->label_1->setText(QString("N = ") + QString::number(PARTICLE_SPAWN_NUMBER));

  ui_->label_2->setText(QString("V = ") + QString::number(BOX_WIDTH * BOX_HEIGHT * (2 * PARTICLE_SIZE)));

  timer_ = new QTimer(this);
  connect(timer_, SIGNAL(timeout()), this, SLOT(ManageCollisions()));
  connect(timer_, SIGNAL(timeout()), this, SLOT(MoveParticles()));
  connect(timer_, SIGNAL(timeout()), scene_, SLOT(advance()));
  connect(timer_, SIGNAL(timeout()), this, SLOT(UpdateValues()));
  timer_->start(FPS);
}

// able to choose: linear — O(M) / squared — O(N^2)
// M — number of grid cells, N — number of particles
// linear collision check is less precise
void MainWidget::ManageCollisions() {
  if (GRID_HEIGHT * GRID_WIDTH * 10 < PARTICLE_SPAWN_NUMBER * PARTICLE_SPAWN_NUMBER) {
    simulation_.ManageCollisionsLinear();
  } else {
  simulation_.ManageCollisionsSquared();
  }
}

void MainWidget::MoveParticles() {
  simulation_.MoveParticles(TIME_INTERVAL);
}

void MainWidget::UpdateValues() {
  ui_->label_3->setText(QString("p = ") + QString::number(simulation_.p_));
  ui_->label_4->setText(QString("<v> = ") + QString::number(simulation_.v_avg_));
  ui_->label_5->setText(QString("<E> = ") + QString::number(simulation_.E_avg_));
  ui_->label_6->setText(QString("kT = ") + QString::number(simulation_.kT_));
}

MainWidget::~MainWidget()
{
  delete ui_;
  delete scene_;
  delete timer_;
}
