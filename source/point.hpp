#ifndef POINT_HPP
#define POINT_HPP
#include <cmath>  //sqrt()
#include <vector> //since this file is included in all other files so is vector

//basic struct containing the x and y coordinates stored as int
struct point {
  float x;
  float y;
  int id;   //unique number to identify the point used for the naive algorithm
};

//function to calculate the distance between two points
float dist(point const& a, point const& b) {
  auto x_ = pow((a.x - b.x), 2.0);
  int y_ = pow((a.y - b.y), 2.0);
  return sqrt(x_ + y_);
}

//function to check if two points are in fact the same point
bool p_eq(point const& a, point const& b) {
  return (a.id == b.id);
}

#endif