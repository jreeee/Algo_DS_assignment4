#ifndef MS_HPP
#define MS_HPP

#include "point.hpp"
#include <vector>
#include <iostream> //debug


void merge(std::vector<point> & vec, int lhs, int mid, int rhs, bool sortx) {
  int l_s = mid - lhs + 1;
  int r_s = rhs - mid;
  std::vector<point> l_a(l_s);
  std::vector<point> r_a(r_s);
  int i, j, k;
  for (int i = 0; i < l_s; ++i) {
    l_a[i] = vec[lhs + i];
  }
  for (j = 0; j < r_s; ++j) {
    r_a[j] = vec[mid + j + 1];
  }

  i = j = 0;
  k = lhs;
  if (sortx) {
    while((i < l_s) && (j < r_s)) {
      if ((l_a[i].x <= r_a[j].x) ) { //&& (l_a[i].y <= r_a[j].y)
        vec[k] = l_a[i];
        ++i;
      }
      else {
        vec[k] = r_a[j];
        ++j;
      }
      ++k;
    }
    while (i < l_s) {
      vec[k] = l_a[i];
      i++;
      k++;
    }
    while (j < r_s) {
      vec[k] = r_a[j];
      j++;
      k++;
    }
  }
  else {
    while((i < l_s) && (j < r_s)) {
      if ((l_a[i].y <= r_a[j].y) ) { //&& (l_a[i].y <= r_a[j].y) needs should check, that x is also ascendig
        vec[k] = l_a[i];
        ++i;
      }
      else {
        vec[k] = r_a[j];
        ++j;
      }
      ++k;
    }
    while (i < l_s) {
      vec[k] = l_a[i];
      i++;
      k++;
    }
    while (j < r_s) {
      vec[k] = r_a[j];
      j++;
      k++;
    }
  }
}

void merge_sort(std::vector<point> & vec, int lhs, int rhs, bool sortx) {
  if (lhs < rhs) {
    int mid = floor(lhs + (rhs - lhs) / 2);
    merge_sort(vec, lhs, mid, sortx);
    merge_sort(vec, mid+1, rhs, sortx);
    merge(vec, lhs, mid, rhs, sortx);
  }
}

void partial_sort(std::vector<point> & vec, bool sortx) {
  int bg = 0;
  if (sortx) {
    for (int i = 0; i < vec.size()-1; ++i) {
      bg = i;
      while ((i < vec.size()-1) && (vec[i].x == vec[i+1].x)) {
        ++i;
      }
      if (bg != i) {
        merge_sort(vec, bg, i, false);
      }
    }
  }
  else {
    for (int i = 0; i < vec.size()-1; ++i) {
      bg = i;
      while ((i < vec.size()-1) && (vec[i].y == vec[i+1].y)) {
        ++i;
      }
      if (bg != i) {
        merge_sort(vec, bg, i, true);
      }
    }
  }
}

#endif