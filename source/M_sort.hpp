#ifndef MS_HPP
#define MS_HPP

#include "point.hpp"

/*
merge, implemented based mostly on the slides with slight variations here and there
gets passed the bool sortx to determine whether to sort for x or y
*/
void merge(std::vector<point> & vec, int lhs, int mid, int rhs, bool sortx) {

  //determining the sizes for the two subarrays, initializing and filling them
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

  //merging the subarrays back into one as shown in the slides
  i = j = 0;
  k = lhs;
  if (sortx) {                          //if we want to sort for x
    while((i < l_s) && (j < r_s)) {
      if (l_a[i].x <= r_a[j].x) {
        vec[k] = l_a[i];
        ++i;
      }
      else {
        vec[k] = r_a[j];
        ++j;
      }
      ++k;
    }
  }
  else {                                //if we want to sort for y
    while((i < l_s) && (j < r_s)) {
      if (l_a[i].y <= r_a[j].y) {
        vec[k] = l_a[i];
        ++i;
      }
      else {
        vec[k] = r_a[j];
        ++j;
      }
      ++k;
    }
  }

  //filling in remaining elements (if existent)
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

//merge sort, implemented based on the slides provided 
//plus additional bool to differentiate between sort_x and sort_y
void merge_sort(std::vector<point> & vec, int lhs, int rhs, bool sortx) {
  if (lhs < rhs) {
    int mid = floor(lhs + (rhs - lhs) / 2);
    merge_sort(vec, lhs, mid, sortx);
    merge_sort(vec, mid+1, rhs, sortx);
    merge(vec, lhs, mid, rhs, sortx);
  }
}

/*
when using merge sort we can only sort for either x or y.
so if we want to sort the unsorted value we can do that as follows:
for sorting y:
since we have a sorted array for the x value,
we can simply iterate over the array and check which elements have the same x value.
if we find an element which shares the same x value as its successor we check
how many more elements have that specific x value. once we have all we can just
use merge sort and start at the first element with the value 
and end at the last element with that value. 
Sorting for x is analog to sorting for y.
sortx is used the same way as in merge sort; to differentiate if you want to sort for x or y.
however the value is swapped; sortx = true means that the array is already sorted for x.
This is to keep it consistent with merge sort, otherwise the call to sort for x would be
merge_sort(vector, left, right, true)
partial_sort(vector, false)
*/
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