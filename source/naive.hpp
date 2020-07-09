#ifndef NAIVE_HPP
#define NAIVE_HPP

#include "point.hpp"

/*
bruteforcing the smallest element by comparing every point with every other point
very inefficient but accurate
checks every point i with every point j, the ony problem is that it can't when there
are two identical points since it has to make sure not to return the distance when 
i = vec[n] and j = vec[n]. 
This brings the problem that it can't detect two identical points
with a different n (even when I tried to implement a check it wouldn't work)
I circumvented this by giving each point a distinct id, and checking that.
*/
std::pair<point, point> naive_alg(std::vector<point> const& vec) {

  //initializing a pair and distance of it, so that it can be checked and overwritten
  auto cl_pts = std::pair<point, point>(vec[0], vec[1]);
  float o_d = dist(cl_pts.first, cl_pts.second);

  /*
  first we have two nested for loops
  then we check if we have the same point, if we have we skip it
  if the distance of the two points is lesser than the current distance
  we set the points as our new closest points and update the distance
  */
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