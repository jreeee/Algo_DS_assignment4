#ifndef DNC_HPP
#define DNC_HPP

#include "point.hpp"
#include <vector>
#include <cmath>

//std::pair<std::vector<point>, std::vector<point>> gen_axis(std::vector<point> const& vec_o) {}

std::pair<point, point> combine(std::vector<point> & y, int l_x, std::pair<point, point> p1_p2, std::pair<point, point> p3_p4) {
  auto d1 = dist(p1_p2.first, p1_p2.second);
  auto d2 = dist(p3_p4.first, p3_p4.second);
  auto p5_p6 = p3_p4;
  auto d = d2;
  if (d1 < d2) {
   p5_p6 = p1_p2;
   d = d1;
  } 
  std::vector<point> y_copy;
  for (auto p : y) {
    if (((l_x - d) <= p.x) || (p.x <= (l_x + d))) {
      y_copy.push_back(p);
    }
  }
  for (int i = 0; i < y_copy.size(); ++i) {
    int j = 1;
    while ((j <= y_copy.size()) && (i + j < y_copy.size())) {
      auto d3 = dist(y_copy[i], y_copy[i+j]);
      if (d3 < d) {
        p5_p6 = std::pair<point, point>(y_copy[i], y_copy[i+j]);
        d = d3;
      }
      ++j;
    }
  }
  return p5_p6;
}

std::pair<point, point> find_closest_points(std::vector<point> & x, std::vector<point> & y) {
  int m = floor(x.size()/2);
  int l_x = (x[m].x + x[m+1].x) / 2;
  std::vector<point> x_l (m);
  for (int i = 0; i < x_l.size(); ++i) {
    x_l[i] = x[i];
  }
  std::vector<point> x_r (x.size() - m);
  for (int i = m; i < x.size(); ++i) {
    x_l[i] = x[i];
  }
  auto p1_p2 = find_closest_points(x_l, y);
  auto p3_p4 = find_closest_points(x_r, y);
  auto p5_p6 = combine(y, l_x, p1_p2, p3_p4);
  auto d1 = dist(p1_p2.first, p1_p2.second);
  auto d2 = dist(p3_p4.first, p3_p4.second);
  auto d3 = dist(p5_p6.first, p5_p6.second);
  if ((d1 <= d2) && (d2 <= d3)) {
    return p1_p2;
  }
  else if ((d2 <= d1) && (d2 <= d3)) {
    return p3_p4;
  }
  else {
    return p5_p6;
  }
}

#endif