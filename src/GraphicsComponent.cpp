#include "GraphicsComponent.h"

GraphicsComponent::GraphicsComponent() = default;

void GraphicsComponent::Render(const std::vector<Particle>& gas,  const Box& box) {
  std::cout << gas[0].position.x << " ";
  std::cout << gas[0].position.y << " ; ";
  std::cout << gas[1].position.x << " ";
  std::cout << gas[1].position.y << std::endl;
}