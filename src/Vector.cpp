#include "../Vector.h"

Vector::Vector(double x1 = 0, double y1 = 0) : x(x1), y(y1) {
};

Vector Vector::operator+(const Vector& other) const {
  return Vector(x + other.x, y + other.y);
};

Vector Vector::operator-(const Vector& other) const {
  return Vector(x - other.x, y - other.y);
};

Vector Vector::operator*(double scalar) const {
  return Vector(x * scalar, y * scalar);
};

Vector Vector::operator/(double scalar) const {
  return Vector(x / scalar, y / scalar);
};

double Vector::Length() const {
  return sqrt(x * x + y * y);
};