#include "Simulation.h"
#include "MainWidget.h"

#include <QApplication>

int main(int argc, char* argv[]) {
  Box box(BOX_WIDTH, BOX_HEIGHT);
  std::vector<Particle> gas;
  Simulation simulation(gas, box);
  simulation.RandomSpawn();

  QApplication app(argc, argv);
  MainWidget window(nullptr, simulation);
  window.show();
  return app.exec();
}