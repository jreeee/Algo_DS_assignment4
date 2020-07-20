#ifndef DNC_HPP
#define DNC_HPP

#include "M_sort.hpp" //used to sort the vector to the x or y axis for find_closest_points
#include "naive.hpp"  //used if f_c_p needs to compare three points
#include "point.hpp"

//implemented combine as shown in the slides
std::pair<point, point> combine(std::vector<point> & y, int l_x, 
                                std::pair<point, point> p1_p2, 
                                std::pair<point, point> p3_p4) {

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
    while ((j <= 7) && ((i + j) < y_copy.size())) {
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

/*
implemented find_closest_points similar to the slides
added support for edge cases i.e. the size of x being 2 or 3
other than that it is pretty much what stood on the slides
*/
std::pair<point, point> find_closest_points(std::vector<point> & x, 
                                            std::vector<point> & y) {

  //edge cases
  if (x.size() == 2) {
    return std::pair<point, point>(x[0], x[1]);
  }
  if (x.size() == 3) {
    return naive_alg(x);
  }

  //implemented based off of the slides
  int m = floor(x.size()/2);
  int l_x = (x[m].x + x[m+1].x) / 2;
  std::vector<point> x_l (m);
  for (int i = 0; i < x_l.size(); ++i) {
    x_l[i] = x[i];
  }
  std::vector<point> x_r (x.size() - m);
  for (int i = 0; i < x_r.size(); ++i) {
    x_r[i] = x[m + i];
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
  if ((d2 <= d1) && (d2 <= d3)) {
    return p3_p4;
  }
  return p5_p6;
}

/*
function that uses a vector to first generate the two axis using merge sort
then it calls the divide and conquer algorithm
*/
std::pair<point, point> div_n_conc(std::vector<point> & vec) {
  std::vector<point> x_ax{vec};
  std::vector<point> y_ax{vec};
  bool sortx = true;
  bool sorty = false;

  merge_sort(x_ax, 0, x_ax.size()-1, sortx);
  partial_sort(x_ax, sortx);
  merge_sort(y_ax, 0, y_ax.size()-1, sorty);
  partial_sort(y_ax, sorty);

  return find_closest_points(x_ax, y_ax);
}

#endif