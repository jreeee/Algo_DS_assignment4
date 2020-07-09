#include "M_sort.hpp"
#define infty   2147483647  //max int size (for signed ints anyway)?????


void merge_sort(std::vector<point> & vec, int lhs, int rhs, bool sortx) {
  if (lhs < rhs) {
    int mid = floor((lhs + rhs) / 2);
    merge_sort(vec, lhs, mid, sortx);
    merge_sort(vec, mid+1, rhs, sortx);
    merge(vec, lhs, mid, rhs, sortx);
  }
}

void merge(std::vector<point> & vec, int lhs, int mid, int rhs, bool sortx) {
  int n1 = mid - lhs + 1;
  int n2 = rhs - mid;
  std::vector<point> l_a(n1 +1);
  std::vector<point> r_a(n2 +1);
  int i, j, k;
  for (int i = 0; i <= n1; ++i) {
    l_a[i] = vec[mid + i - 1];
  }
  //l_a.push_back(infty);
  for (j = 0; j < n2; ++j) {
    r_a[i] = vec[mid + j];
  }
  i = j = 1;
  for (k = lhs; k < rhs; ++k) {
    if (sortx) {
      if ((l_a[i].x <= r_a[i].x) && (l_a[i].y <= r_a[i].y)) {
        vec[k] = l_a[i];
        ++i;
      }
      else {
        vec[k] = r_a[i];
        ++j;
      }
    }
    else {
      if ((l_a[i].y <= r_a[i].y) && (l_a[i].x <= r_a[i].x)) {
        vec[k] = l_a[i];
        ++i;
      }
      else {
        vec[k] = r_a[i];
        ++j;
      }
    }
  }
}