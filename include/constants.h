#pragma once

#include <vector>

const double FPS = 1000 / 100;

const double TIME_INTERVAL = FPS / 1000;

double average_velocity = 10;

const double TOLERANCE = TIME_INTERVAL * average_velocity;

const Vector LEFT_WALL_NORMAL = Vector(1, 0);

const Vector RIGHT_WALL_NORMAL = Vector(-1, 0);

const Vector TOP_WALL_NORMAL = Vector(0, -1);

const Vector BOTTOM_WALL_NORMAL = Vector(0, 1);