#include "Simulation.h"
#include "MainWidget.h"

#include <random>
#include <QApplication>

int main(int argc, char* argv[]) {
  Box box(BOX_WIDTH, BOX_HEIGHT);
  std::vector<Particle> gas;
  Simulation simulation(gas, box);
  std::srand(std::time(0));

  for (int i = 0; i < PARTICLE_SPAWN_NUMBER; i++) {
    simulation.AddParticle(Particle(Vector(PARTICLE_SIZE + (1 + (std::rand() % (GRID_WIDTH - 1))) * 2 * PARTICLE_SIZE,
                                           PARTICLE_SIZE + (1 + (std::rand() % (GRID_HEIGHT - 1))) * 2 * PARTICLE_SIZE),
                                    Vector(MAX_SPAWN_VELOCITY - std::rand() % (2 * MAX_SPAWN_VELOCITY),
                                           MAX_SPAWN_VELOCITY - std::rand() % (2 * MAX_SPAWN_VELOCITY)),
                                    PARTICLE_SIZE, 1));                                
  }

  QApplication app(argc, argv);
  MainWidget window(nullptr, simulation);
  window.show();
  return app.exec();
}