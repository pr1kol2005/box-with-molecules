#include "MainWidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent), ui_(new Ui::MainWidget)
{
  ui_->setupUi(this);
  scene_ = new QGraphicsScene(0, 0, 800, 600, this);
  ui_->graphicsView->setScene(scene_);
  scene_->addRect(scene_->sceneRect());
}

MainWidget::~MainWidget()
{
  delete ui_;
  delete scene_;
}
