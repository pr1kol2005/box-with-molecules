#include "Simulation.h"
#include "GraphicsComponent.h"

int main() {
  Box box(200, 200);

  std::vector<Particle> gas;

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      Particle molecule(Vector(10 * i, 10 * j), Vector(1, 1), 1, 1);
      gas.push_back(molecule);
    }
  }

  Simulation simulation(gas, box);
  GraphicsComponent graphics;
  
  for (size_t i = 0; i < 1000; i++) {
    graphics.Render(simulation.gas, box);
    simulation.ManageCollisions();
    simulation.MoveParticles(0.001);
  }
  return 0;
}