#include "../Box.h"

Box::Box(int width = 0, int height = 0) : width(width), height(height) {
}

Vector Box::GetNormal(const Vector& pos) const {
  if (pos.x <= width / 2 && pos.x <= pos.y && pos.x <= (height - pos.y)) {
    return Vector(1, 0);
  }
  else if (pos.x > width / 2 && (width - pos.x) <= pos.y && (width - pos.x) <= (height - pos.y)) {
    return Vector(-1, 0);
  }
  else if (pos.y <= height / 2 && pos.y <= pos.x && pos.y <= (width - pos.x)) {
    return Vector(0, 1);
  }
  else if (pos.y > height / 2 && (height - pos.y) <= pos.x && (height - pos.y) <= (width - pos.x)) {
    return Vector(0, -1);
  }
}