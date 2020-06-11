#include <iostream>
#include "tree.hpp"


int main(int argc, char* argv[])
 {
   Tree test;
   std::cout << test.isempty() << "\n";
   test.add(8);
   std::cout << test.isempty() << "\n";
   test.add(3);
   std::cout << test.maximum()->key << "\n";
   std::cout << test.minimum()->key << "\n";
   test.add(10);
   test.add(6);
   test.add(1);
   test.add(14);
   test.add(3);
   test.add(13);
   test.add(4);
   test.add(7);
   test.add(2);
   Node* root = test.search(8);
   test.printBST();
   std::cout << test.maximum()->key << "\n";
   std::cout << test.minimum()->key << "\n";
   std::cout << test.isempty() << "\n";
   test.rm(test.maximum());
   std::cout << test.maximum()->key << "\n";
   test.rm(test.search(8));
   test.printBST();

   Tree t1;
   t1.add(4);
   t1.printBST();
   t1.rm(t1.root());
   //t1.printBST();
   

  return 0;
 }
