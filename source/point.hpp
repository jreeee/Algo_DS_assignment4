#ifndef POINT_HPP
#define POINT_HPP
#include <cmath>

//basic struct containing the x and y coordinates stored as int
struct point {
  float x;
  float y;
  int id;   //unique number to identify the point used for the naive algorithm
};

//function to calculate the distance between two points
float dist(point const& a, point const& b) {
  int x_ = abs(a.x - b.x);
  int y_ = abs(a.y - b.y);
  return sqrt(x_ * x_ + y_ * y_);
}

//function to check if two points are the same point
bool p_eq(point const& a, point const& b) {
  return (a.id == b.id);
}

#endif