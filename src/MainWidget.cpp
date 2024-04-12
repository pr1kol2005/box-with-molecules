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

  timer_ = new QTimer(this);
  connect(timer_, SIGNAL(timeout()), this, SLOT(ManageCollisions()));
  connect(timer_, SIGNAL(timeout()), this, SLOT(MoveParticles()));
  connect(timer_, SIGNAL(timeout()), scene_, SLOT(advance()));
  timer_->start(FPS);
}

void MainWidget::ManageCollisions() {
  simulation_.ManageCollisions();
}

void MainWidget::MoveParticles() {
  simulation_.MoveParticles(TIME_INTERVAL);
}

MainWidget::~MainWidget()
{
  delete ui_;
  delete scene_;
  delete timer_;
}
