#pragma once

#include <vector>

const double FPS = 1000 / 100;

const double TIME_INTERVAL = FPS / 1000;

const int BOX_WIDTH = 800;

const int BOX_HEIGHT = 600;

const int PARTICLE_SIZE = 10;

const Vector LEFT_WALL_NORMAL = Vector(1, 0);

const Vector RIGHT_WALL_NORMAL = Vector(-1, 0);

const Vector TOP_WALL_NORMAL = Vector(0, -1);

const Vector BOTTOM_WALL_NORMAL = Vector(0, 1);