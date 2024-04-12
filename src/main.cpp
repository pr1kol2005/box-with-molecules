#include "Simulation.h"
#include "MainWidget.h"

#include <random>
#include <QApplication>

int main(int argc, char* argv[]) {
  Box box(BOX_WIDTH, BOX_HEIGHT);
  std::vector<Particle> gas;
  Simulation simulation(gas, box);

  for (int i = 0; i < PARTICLE_NUMBER; i++) {
    simulation.AddParticle(Particle(Vector(PARTICLE_SIZE + (1 + ( std::rand() % (BOX_WIDTH / (2 * PARTICLE_SIZE) - 1))) * 2 * PARTICLE_SIZE,
                                           PARTICLE_SIZE + (1 + ( std::rand() % (BOX_HEIGHT / (2 * PARTICLE_SIZE) - 1))) * 2 * PARTICLE_SIZE),
                                    Vector(std::rand() % MAX_SPAWN_VELOCITY, std::rand() % MAX_SPAWN_VELOCITY), PARTICLE_SIZE, 1));
  }

  QApplication a(argc, argv);
  MainWidget w(nullptr, simulation);
  w.show();
  return a.exec();
}