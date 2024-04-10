#include "MainWidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent), ui_(new Ui::MainWidget)
{
  ui_->setupUi(this);

  scene_ = new QGraphicsScene(0, 0, 800, 600, this);

  ui_->graphicsView->setScene(scene_);

  scene_->addRect(scene_->sceneRect());
  scene_->addItem(new ParticleImage(Particle(Vector(90, 90), Vector(10, 10), 1, 1)));

  timer_ = new QTimer(this);
  connect(timer_, SIGNAL(timeout()), scene_, SLOT(advance()));
  timer_->start(1000 / 1);
}

MainWidget::~MainWidget()
{
  delete ui_;
  delete scene_;
  delete timer_;
}
