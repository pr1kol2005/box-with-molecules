#include <gtest/gtest.h>
#include <vector>

#include "Box.h"
#include "Particle.h"
#include "Simulation.h"
#include "Vector.h"
#include "constants.h"

TEST(VectorTestCase, VectorTest) {
  Vector v1(1, 0);
  Vector v2(0, 1);
  EXPECT_EQ(v1.CrossProduct(v2), 1);
  EXPECT_EQ(v1.ScalarProduct(v2), 0);
}

TEST(BoxTestCase, BoxTest) {
  Box box(100, 100);
  Vector v(25, 0);
  Particle p(Vector(5, 5), Vector(0, 0), 5, 228);

  EXPECT_EQ(box.GetNormal(v), Vector(0, 1));
  EXPECT_TRUE(box.CheckCollision(p));
}

TEST(ParticleTestCase, ParticleTest) {
  Particle p1(Vector(5, 5), Vector(0, 0), 5, 228);
  Particle p2(Vector(25, 5), Vector(-1, 0), 5, 228);
  p2.UpdatePosition(10);

  EXPECT_TRUE(p1.CheckCollision(p2));
}

TEST(SimulationTestCase, SimulationTest) {
  Box box(BOX_WIDTH, BOX_HEIGHT);
  std::vector<Particle> gas;
  Simulation sim(gas, box);
  sim.RandomSpawn();

  if (PARTICLE_SIZE * PARTICLE_SIZE * PARTICLE_SPAWN_NUMBER <=
      BOX_HEIGHT * BOX_WIDTH) {
    for (size_t i = 0; i < gas.size(); i++) {
      for (size_t j = i + 1; j < gas.size(); j++) {
        EXPECT_FALSE(gas[i].CheckCollision(gas[j]));
      }
    }
  }

  Particle p1(Vector(25, 5), Vector(0, 0), 5, 1);
  Particle p2(Vector(25, 15), Vector(0, -1), 5, 1);
  sim.ParticleCollision(&p1, &p2);

  EXPECT_EQ(p1.GetImpulse(), Vector(0, -1));
  EXPECT_EQ(p2.GetImpulse(), Vector(0, 0));

  sim.BoxCollision(&p1);

  EXPECT_EQ(p1.GetImpulse(), Vector(0, 1));
}