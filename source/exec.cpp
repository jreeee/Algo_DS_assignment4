#include <iostream>
#include "tree.hpp"


int main(int argc, char* argv[])
 {
   Tree test;
   std::cout << test.isempty() << "\n";
   test.add(8);
   std::cout << test.isempty() << "\n";
   test.add(4);
   std::cout << test.maximum()->key << "\n";
   std::cout << test.minimum()->key << "\n";
   test.rm(test.maximum());
   std::cout << test.maximum()->key << "\n";
   std::cout << test.isempty() << "\n";
   test.rm(test.maximum());
   std::cout << test.maximum()->key << "\n";
   std::cout << test.isempty() << "\n";
   test.rm(test.maximum());
   std::cout << test.maximum()->key << "\n";
   std::cout << test.isempty() << "\n";
  return 0;
 }
