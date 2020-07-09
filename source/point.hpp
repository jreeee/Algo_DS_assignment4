#ifndef POINT_HPP
#define POINT_HPP
#include <cmath>

struct point {
  float x;
  float y;
};

float dist(point const& a, point const& b) {
  int x_ = abs(a.x - b.x);
  int y_ = abs(a.y - b.y);
  return sqrt(x_ * x_ + y_ * y_);
}
#endif