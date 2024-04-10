#include "Simulation.h"
#include "GraphicsComponent.h"
#include "MainWidget.h"

#include <QApplication>

int main(int argc, char* argv[]) {
  // Box box(200, 200);
  // std::vector<Particle> gas;
  // Simulation simulation(gas, box);
  // GraphicsComponent graphics;

  // simulation.AddParticle(Particle(Vector(90, 90), Vector(10, 10), 1, 1));
  // simulation.AddParticle(Particle(Vector(100, 100), Vector(-10, -10), 1, 1));
  // simulation.AddParticle(Particle(Vector(195, 100), Vector(10, 0), 1, 1));
  
  // for (size_t i = 0; i < 1000; i++) {
  //   graphics.Render(simulation.GetGas(), box);
  //   simulation.ManageCollisions();
  //   simulation.MoveParticles(0.001);
  // }

  QApplication a(argc, argv);
  MainWidget w;
  w.show();
  return a.exec();
}