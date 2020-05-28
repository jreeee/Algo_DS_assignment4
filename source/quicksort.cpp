#include <vector>

template<typename T> 
void quicksort(std::vector<T>* a, int p, int r) {
  //std::vector<T>* arr ={a};
  if (p < r) {
    int q = partition(a, p, r);
    quicksort(a, p, q - 1);
    quicksort(a, q + 1, r);
  }
}

template<typename T> 
int partiton(std::vector<T>* a, int p, int r) {
  T x = a[r];
  int i = p - 1;
  for (int k = 0, (j == p) && (k < r), ++k) {
    if (a[j] <= x) {
      i = i+1;
      T tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
    }
  }
  T tmp = a[i+1];
  a[i+1] = a[r];
  a[r] = tmp;
  return i+1;
}