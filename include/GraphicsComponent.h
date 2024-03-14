#pragma once

#include "Particle.h"
#include "Box.h"

#include <vector>
#include <iostream>

class GraphicsComponent {
 public:

  GraphicsComponent();

  void Render(const std::vector<Particle>& gas, const Box& box);
};