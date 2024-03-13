#include "../Vector.h"

Vector::Vector(double x1 = 0, double y1 = 0) : x(x1), y(y1) {
}

Vector Vector::operator+(const Vector& other) const {
  return Vector(x + other.x, y + other.y);
}

Vector Vector::operator-(const Vector& other) const {
  return Vector(x - other.x, y - other.y);
}

Vector Vector::operator*(double scalar) const {
  return Vector(x * scalar, y * scalar);
}

Vector Vector::operator/(double scalar) const {
  return Vector(x / scalar, y / scalar);
}

Vector& Vector::operator+=(const Vector& other) {
  x += other.x;
  y += other.y;
  return *this;
}

Vector& Vector::operator-=(const Vector& other) {
  x -= other.x;
  y -= other.y;
  return *this;
}

Vector& Vector::operator*=(double scalar) {
  x *= scalar;
  y *= scalar;
  return *this;
}

Vector& Vector::operator/=(double scalar) {
  x /= scalar;
  y /= scalar;
  return *this;
}

double Vector::Length() const {
  return std::sqrt(x * x + y * y);
}

Vector Vector::Normal() const {
  return Vector(-y, x);
}

double Vector::CrossProduct(const Vector& other) const {
  return x * other.x + y * other.y;
}

double Vector::ScalarProduct(const Vector& other) const {
  return x * other.y - y * other.x;
}