#include "MainWidget.h"
#include "ui_mainwidget.h"

#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>

MainWidget::MainWidget(QWidget *parent, Simulation &simulation)
    : QWidget(parent), ui_(new Ui::MainWidget), simulation_(simulation), update_iteration_(0) {
  ui_->setupUi(this);

  resize(BOX_WIDTH + 100, BOX_HEIGHT + 100);

  scene_ = new QGraphicsScene(0, 0, BOX_WIDTH, BOX_HEIGHT, this);

  ui_->graphicsView->setScene(scene_);

  scene_->addRect(scene_->sceneRect());

  for (size_t i = 0; i < simulation.gas_.size(); i++) {
    scene_->addItem(new ParticleImage(&simulation_.gas_[i]));
  }

  ui_->label_1->setText(QString("N = ") +
                        QString::number(PARTICLE_SPAWN_NUMBER));

  ui_->label_2->setText(QString("V - b = ") +
      QString::number(simulation_.V_ - simulation_.b_));

  timer_ = new QTimer(this);
  value_timer_ = new QTimer(this);
  connect(timer_, SIGNAL(timeout()), this, SLOT(ManageCollisions()));
  connect(timer_, SIGNAL(timeout()), this, SLOT(MoveParticles()));
  connect(timer_, SIGNAL(timeout()), scene_, SLOT(advance()));
  connect(value_timer_, SIGNAL(timeout()), this, SLOT(UpdateValues()));
  timer_->start(FPS);
  value_timer_->start(VALUE_UPDATE_INTERVAL);
}

// able to choose: linear — O(M) / squared — O(N^2)
// M — number of grid cells, N — number of particles
// linear collision check is less precise
void MainWidget::ManageCollisions() {
  if (GRID_HEIGHT * GRID_WIDTH * 100 <
      PARTICLE_SPAWN_NUMBER * PARTICLE_SPAWN_NUMBER) {
    simulation_.ManageCollisionsLinear();
  } else {
    simulation_.ManageCollisionsSquared();
  }
}

void MainWidget::MoveParticles() { simulation_.MoveParticles(TIME_INTERVAL); }

void MainWidget::UpdateValues() {
  simulation_.p_ /=
      (TIME_INTERVAL * (VALUE_UPDATE_INTERVAL / FPS) *
                        (2 * (BOX_HEIGHT + BOX_WIDTH)));
  simulation_.v_avg_ /= (PARTICLE_SPAWN_NUMBER * VALUE_UPDATE_INTERVAL / FPS);
  simulation_.E_ /= (VALUE_UPDATE_INTERVAL / FPS);
  simulation_.kT_ = (simulation_.E_ / PARTICLE_SPAWN_NUMBER);

  ui_->label_3->setText(QString("p = ") + QString::number(simulation_.p_));
  ui_->label_4->setText(QString("<v> = ") +
                        QString::number(simulation_.v_avg_));
  ui_->label_5->setText(QString("E = ") +
                        QString::number(simulation_.E_));
  ui_->label_6->setText(QString("kT = ") + QString::number(simulation_.kT_));
  ui_->label_7->setText(QString("P(V - b) / NkT = ") + QString::number(simulation_.p_ * (simulation_.V_ - simulation_.b_) / (PARTICLE_SPAWN_NUMBER * simulation_.kT_)));
  

  std::ofstream file;
  file.open("data/vpv.txt", std::ios::app);
  if (file.is_open()) {
    if (update_iteration_ == 0) {
      std::time_t now = std::time(0);
      file << "________________________________________\n" << std::ctime(&now);
      file << "N = " << PARTICLE_SPAWN_NUMBER << ", V = " << simulation_.V_ << ", b = " << simulation_.b_ << ", delta_t = " << VALUE_UPDATE_INTERVAL << '\n';
    }
    for (auto& particle : simulation_.gas_) {
      file << particle.GetImpulse().Length() << ' ';
    }
    file << '\n';
    update_iteration_++;
    file.close();
  } else {
    std::cerr << "Unable to open file";
  }

  simulation_.ResetThermodynamicValues();
}

MainWidget::~MainWidget() {
  delete ui_;
  delete scene_;
  delete timer_;
  delete value_timer_;
}
