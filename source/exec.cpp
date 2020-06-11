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
   test.add(5);
   test.add(0);
   Node* root = test.search(8);
   test.printBST();
   std::cout << test.maximum()->key << "\n";
   std::cout << test.minimum()->key << "\n";
   std::cout << test.isempty() << "\n";
   test.rm(test.maximum());
   std::cout << test.maximum()->key << "\n";
   //test.rm(test.search(8));
   test.printBST();
   test.rm(test.search(3));
   test.printBST();
   test.rm(test.search(4));
   test.printBST();
   
   Tree* t = new Tree();
   std::cout << "What would you like to do? \n\na - add node\nr - remove node\ns - search\np - print\nh - help\n";
   std::cout << "x - max \nn - min\ns - successor \nr - predecessor\no - root\ny - empty?\ne - exit\n";
   char in;
   int i;
   while(true) {
     std::cin >> in;

     if (in == 'a') {
       std::cout << "please enter the value of the node you want to add\n";
       std::cin >> i;
       t->add(i);
     }
     if (in == 'r') {
       std::cout << "please enter the value of the node you want to remove\n";
       std::cin >> i;
       Node * ptr = t->search(i);
       (ptr == nullptr) ? std::cout << "there was no corresponding node\n" : std::cout << "node " << i << " deleted\n";
     }
     if (in == 's') {
       std::cout << "please enter the value of the node you are searching\n";
       std::cin >> i;
       Node * ptr = t->search(i);
       (ptr == nullptr) ? std::cout << "there was no corresponding node\n" : std::cout << "node " << i << " was found\n";
     }
     if (in == 'o') std::cout << "the root value is " << t->root()->key << "\n";
     if (in == 'p') t->printBST();
     if (in == 'y') t->isempty() ? std::cout << "the tree is empty\n" : std::cout << "the tree isn't empty\n";
     if (in == 'x') t->isempty() ? std::cout << "the tree is empty\n" : std::cout << t->maximum()->key << " is the maximum of the tree\n";
     if (in == 'n') t->isempty() ? std::cout << "the tree is empty\n" : std::cout << t->minimum()->key << " is the minimum of the tree\n";
     if (in == 'h') std::cout << "a - add node\nr - remove node\ns - search\np - print\nh - help\nx - max \nn - min\ns - successor \nr - predecessor\no - root\ny - empty?\ne - exit\n";
     if (in == 'e') break;
   }

  return 0;
 }
