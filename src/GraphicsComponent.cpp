#include "GraphicsComponent.h"

GraphicsComponent::GraphicsComponent() = default;

void GraphicsComponent::Render(const std::vector<Particle>& gas,  const Box& box) {
  for (size_t i = 0; i < gas.size(); i++) {
    std::cout << gas[i].position_.x_ << " ";
    if (i == gas.size() - 1) {
      std::cout << gas[i].position_.y_ << std::endl;
    } else {
      std::cout << gas[i].position_.y_ << " ; ";
    }
  }
}