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

  std::vector<int>* c = new std::vector<int>(k+1);
  std::vector<int>* b = new std::vector<int>(a->size());
  int i;

  for (i = 0;  i < a->size(); ++i ) {
    ++c->at(a->at(i));
  }

  for (i = 1; i <= k; ++i) {
    c->at(i) += c->at(i-1);
  }
  
  for (i = 0; i < a->size(); ++i) {
    b->at(c->at(a->at(i))-1) = a->at(i);
    --c->at(a->at(i));
  }

  delete a;
  a = b;
  return* a;

}
void docs(std::vector<int>* & a, bool print = true) {

  int k = a->at(0);

  for (int i = 0; i < a->size(); ++i) {
    if (a->at(i) < 0) {
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
  std::vector<int>* t4 = new std::vector<int>{6, 1, 2, 4, 1, 3, 4, 6, 1, 3, 2};
  std::vector<int>* t5 = new std::vector<int>{8, 1, 0, 4, 7, 3, 0, 6, 1, 7, 2};

  doqs(t1);
  doqs(t2);
  doqs(t3, false);
  doqs(t3);

  docs(t4);
  docs(t5);

  return 0;
 }
