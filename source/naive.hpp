#ifndef NAIVE_HPP
#define NAIVE_HPP

#include "point.hpp"
#include <vector>

std::pair<point, point> naive_alg(std::vector<point> const& vec) {
  auto cl_pts = std::pair<point, point>(vec[0], vec[1]);
  float o_d = dist(cl_pts.first, cl_pts.second);
  for (auto &i : vec) {
    for (auto &j : vec) {
      if (!p_eq(i, j)) {
        float n_d = dist(i, j); 
        if (n_d < o_d) {
        o_d = n_d;
        cl_pts = std::pair<point, point>(i, j);
        }
      }
    }
  }
  return cl_pts;
}
#endif