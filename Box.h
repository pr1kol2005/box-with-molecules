#pragma once

#include "Vector.h"
#include "Particle.h"

class Box {
private:
    int width;
    int height;

    Box(int width = 0, int height = 0);

    Vector GetNormal(const Vector& pos) const;
};