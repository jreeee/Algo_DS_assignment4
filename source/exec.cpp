 #include <vector>
 #include <iostream>

/* small function to print out the elements of an array*/
template<typename T>
void printarr(std::vector<T>* & a) {
  for (int i = 0; i < a->size(); ++i) {
  std::cout << a->at(i) << " | ";
  }
  std::cout << "\n\n";
}

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
  printarr(a);
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

  delete a, c;
  a = b;
  return* a;

}
/* and a little method that tests if all values are positive and can also print the sorted array */
void docs(std::vector<int>* & a, bool print = true) {

  int k = a->at(0);

  for (int i = 0; i < a->size(); ++i) {
    if (a->at(i) < 0) {
      std::cout << "Your array does not the requirements for counting sort (only positive integers and 0 allowed) \n\n";
      return;
    }
    if (a->at(i) > k) {
      k = a->at(i);
    }
  }
  countingsort(a, k);

  if (print) {
    printarr(a);
  }
}

/* little array input and sort - selection, sadly you can only create int-arrays*/
void build() {
  std::cout << "please enter the size of your array\n";
  int length;
  std::cin >> length;
   if (length <= 0) {
     std::cout << "invalid length\n";
     return;
   }
  std::vector<int>* a = new std::vector<int>(length);
  std::cout << "please enter now its content\n";
  int element;
  for (int i = 0; i < a->size(); ++i) {
    std::cin >> element;
    a->at(i) = element;
  }

  std::cout << "your array looks like this:\n";

  printarr(a);

  std::cout << "\ndo you want to use quicksort[q] or counting sort[c]?\n";
  char sort;
  std::cin >> sort;
  if (sort == 'c') docs(a);
  if (sort == 'q') doqs(a);
  if ((sort != 'c') && (sort != 'q')) std::cout << sort <<"is not a valid char\n";
}

int main(int argc, char* argv[])
 {
  //a couple of examples
  std::vector<int>* t1 = new std::vector<int>{3, 7, 8, 5, 2, 1, 9, 5, 4};
  std::vector<char>* t2 = new std::vector<char>{'c', 'f', 'g', 'd', 'b', 'a', 'h', 'c', 'h'};
  std::vector<int>* t3 = new std::vector<int>{-3, 7, 8, -5, -2, 1, 9, 5, -4};
  std::vector<double>* t4 = new std::vector<double>{-2.1, 2.3, 4.78, 4.77, -5.03, 1.341, 3.1415, 0.002, -1.22};
  std::vector<int>* t5 = new std::vector<int>{6, 1, 2, 4, 1, 3, 4, 6, 1, 3, 2};
  std::vector<int>* t6 = new std::vector<int>{8, 1, 0, 4, 7, 3, 0, 6, 1, 7, 2};
  std::vector<int>* t7 = new std::vector<int>{8, 1, 0, 4, -7, 3, 0, 6, 1, 7, 2};

  std::cout << "sorting a couple of arrays using quick sort\n\n";
  std::cout << "array 1:\n";
  printarr(t1);
  doqs(t1);
  std::cout << "array 2:\n";
  printarr(t2);
  doqs(t2);
  std::cout << "array 3:\n";
  printarr(t3);
  doqs(t3, false);
  printarr(t3);
  std::cout << "array 4:\n";  
  printarr(t4);
  doqs(t4);

  std::cout << "sorting a couple of int arrays using counting sort\n\n";
  std::cout << "array 5:\n";
  printarr(t5);
  docs(t5);
  std::cout << "array 6:\n";
  printarr(t6);
  docs(t6);
  std::cout << "array 7:\n";
  printarr(t7);
  docs(t7);

  //interactive input method
  char loop = 'y';
  std::cout << "now you can enter some arrays to test the algorithms\n";
  while (loop != 'x') {
    build();
    std::cout << "\ntry another array[any key except x] or exit [x]?\n";
    std::cin >> loop; 
  }
  return 0;
 }
