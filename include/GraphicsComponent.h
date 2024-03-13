#pragma once

#include "Particle.h"
#include "Box.h"

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <vector>

class GraphicsComponent {
 public:

  GraphicsComponent();

  void Render(const std::vector<Particle>& gas, const Box& box);
};