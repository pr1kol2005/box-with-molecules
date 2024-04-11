#include "MainWidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent), ui_(new Ui::MainWidget)
{
  ui_->setupUi(this);

  scene_ = new QGraphicsScene(0, 0, BOX_WIDTH, BOX_HEIGHT, this);

  ui_->graphicsView->setScene(scene_);

  scene_->addRect(scene_->sceneRect());
  scene_->addItem(new ParticleImage(new Particle(Vector(0, 0), Vector(10, 10), 20, 1)));
  scene_->addItem(new ParticleImage(new Particle(Vector(800, 600), Vector(-10, -10), 20, 1)));

  timer_ = new QTimer(this);
  connect(timer_, SIGNAL(timeout()), scene_, SLOT(advance()));
  timer_->start(FPS);
}

MainWidget::~MainWidget()
{
  delete ui_;
  delete scene_;
  delete timer_;
}
