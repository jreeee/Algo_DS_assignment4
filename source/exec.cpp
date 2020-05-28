 #include <vector>
 #include <iostream>

/*Implementation of quicksort, starting with the partition function, then the quicksort function and finishing off with the doqs (do quicksort) function*/
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

/* This is just a small function automatically setting p and r, aswell as giving you the option to print the sorted array */
template<typename T> 
void doqs(std::vector<T>* & a, bool print = true) {

  quicksort(a, 0, a->size()-1);

  if (print) {
    for (int i = 0; i < a->size(); ++i) {
  std::cout << a->at(i) << " | ";
  }
  std::cout << "\n";
  }
}

/*Now follows the implemantation of counting sort*/
std::vector<int> countingsort(std::vector<int>* & a, int k) {

  std::vector<int>* b = new std::vector<int>(a->size()+1);
  std::vector<int>* c = new std::vector<int>(k+1);

  for (int j = 0; j < a->size(); ++j ) {
    c->at(a->at(j))++;

  }
  for (int i = 2; i <= k; ++i) {
    c->at(i) += c->at(i-1);

  }
  for (int j = a->size(); j > 1; --j) {
    b->at(c->at(a->at(j))) = a->at(j);

    for (int i = 0; i < b->size(); ++i) {
    std::cout << b->at(i) << " | ";
    }
    std::cout << "\n";

    c->at(a->at(j))--;

    for (int i = 0; i < c->size(); ++i) {
    std::cout << c->at(i) << " | ";
    }
    std::cout << "\n";

  } 
  return* b;
}
void docs(std::vector<int>* & a, bool print = true) {

  int k = a->at(0);

  for (int i = 0; i < a->size(); ++i) {
    if (a->at(i) <= 0) {
      std::cout << "Your array does not the requirements for counting sort (only positive integers allowed) \n";
      return;
    }
    if (a->at(i) > k) {
      k = a->at(i);
    }
  }
  countingsort(a, k);

  if (print) {
  for (int i = 0; i < a->size(); ++i) {
  std::cout << a->at(i) << " | ";
  }
  std::cout << "\n";
  }
}

int main(int argc, char* argv[])
 {
  std::vector<int>* t1 = new std::vector<int>{3, 7, 8, 5, 2, 1, 9, 5, 4};
  std::vector<char>* t2 = new std::vector<char>{'c', 'f', 'g', 'd', 'b', 'a', 'h', 'c', 'h'};
  std::vector<int>* t3 = new std::vector<int>{-3, 7, 8, -5, -2, 1, 9, 5, -4};
  std::vector<int>* t4 = new std::vector<int>{6, 1, 2, 4, 1, 3,4, 6, 1, 3, 2};

  doqs(t1);
  doqs(t2);
  doqs(t3, false);
  doqs(t3);

  docs(t4);

  return 0;
 }
