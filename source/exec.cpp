 #include <vector>
 #include <iostream>

template<typename T> 
int partition(std::vector<T>* & a, int p, int r) {
  T piv = a->at(r);
  int i = p;
  for (int j = p; j < r; ++j) {
    if (a->at(j) < piv) {
      T tmp = a->at(i);
      a->at(i) = a->at(j);
      a->at(j) = tmp;
      i = i + 1;
    }
  }
  T tmp = a->at(i);
  a->at(i) = a->at(r);
  a->at(r) = tmp;
  return i;
}

template<typename T> 
void quicksort(std::vector<T>* & a, int p, int r) {
  if (p < r) {
    int q = partition(a, p, r);
    quicksort(a, p, q - 1);
    quicksort(a, q + 1, r);
  }
}

template<typename T> 
void doqs(std::vector<T>* & a) {
  quicksort(a, 0, a->size()-1);
}
 
 int main(int argc, char* argv[])
 {
  std::vector<int>* test = new std::vector<int>{3, 7, 8, 5, 2, 1, 9, 5, 4};
  doqs(test);
  std::vector<char>* testc = new std::vector<char>{'c', 'f', 'g', 'd', 'b', 'a', 'h', 'c', 'h'};
  doqs(testc);
  for (int i = 0; i < test->size(); ++i) {
  std::cout << test->at(i) << " | ";
  }
  std::cout << "\n";
  for (int i = 0; i < testc->size(); ++i) {
  std::cout << testc->at(i) << " | ";
  }
  std::cout << "\n";
  return 0;
 }
