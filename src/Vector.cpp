#include "Vector.h"

Vector::Vector(double x, double y) : x_(x), y_(y) {}

Vector Vector::operator+(const Vector &other) const {
  return Vector(x_ + other.x_, y_ + other.y_);
}

Vector Vector::operator-(const Vector &other) const {
  return Vector(x_ - other.x_, y_ - other.y_);
}

Vector Vector::operator*(double scalar) const {
  return Vector(x_ * scalar, y_ * scalar);
}

Vector Vector::operator/(double scalar) const {
  return Vector(x_ / scalar, y_ / scalar);
}

Vector &Vector::operator+=(const Vector &other) {
  x_ += other.x_;
  y_ += other.y_;
  return *this;
}

Vector &Vector::operator-=(const Vector &other) {
  x_ -= other.x_;
  y_ -= other.y_;
  return *this;
}

Vector &Vector::operator*=(double scalar) {
  x_ *= scalar;
  y_ *= scalar;
  return *this;
}

Vector &Vector::operator/=(double scalar) {
  x_ /= scalar;
  y_ /= scalar;
  return *this;
}

bool Vector::operator==(const Vector& other) const {
  return x_ == other.x_ && y_ == other.y_;
}

double Vector::Length() const { return std::sqrt(x_ * x_ + y_ * y_); }

Vector Vector::Normal() const { return Vector(-y_, x_); }

double Vector::CrossProduct(const Vector &other) const {
  return x_ * other.y_ - y_ * other.x_;
}

double Vector::ScalarProduct(const Vector &other) const {
  return x_ * other.x_ + y_ * other.y_;
}