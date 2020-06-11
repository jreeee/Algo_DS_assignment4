#include <iostream>
#include "tree.hpp"


int main(int argc, char* argv[])
 {
   
   Tree t;
   //building a tree and testing various methods
   std::cout << t.isempty() << "\n";
   //it is quiet weird; when i use methods like that everything is normal
   //when using add() in the while loop it won't properly work tho
   t.add(8);
   std::cout << t.isempty() << "\n";
   t.add(3);
   std::cout << t.maximum()->key << "\n";
   std::cout << t.minimum()->key << "\n";
   t.add(10);
   t.add(6);
   t.add(1);
   t.add(14);
   t.add(3);
   t.add(13);
   t.add(4);
   t.add(7);
   t.add(2);
   t.add(5);
   t.add(0);
   Node* root = t.search(8);
   t.printBST();
   std::cout << t.maximum()->key << "\n";
   std::cout << t.minimum()->key << "\n";
   std::cout << t.isempty() << "\n";
   t.rm(t.maximum());
   std::cout << t.maximum()->key << "\n";
   //t.rm(t.search(8));
   t.printBST();
   t.rm(t.search(3));
   t.printBST();
   t.rm(t.search(4));
   t.printBST();
   
   //the tree is now under your control :)
   //change it with the provided commands however you like

   std::cout << "What would you like to do? \n\na - add node\nr - remove node\ns - search\np - print\nh - help\n";
   std::cout << "x - max \nn - min\ns - successor \nr - predecessor\no - root\ny - empty?\ne - exit\n";
   char in;
   int i;
   while(true) {
     std::cin >> in;

     if (in == 'a') {
       std::cout << "please enter the value of the node you want to add\n";
       std::cin >> i;
       t.add(i);
     }
     if (in == 'r') {
       std::cout << "please enter the value of the node you want to remove\n";
       std::cin >> i;
       Node * ptr = t.search(i);
       t.rm(ptr);
       (ptr == nullptr) ? std::cout << "there was no corresponding node\n" : std::cout << "node " << i << " deleted\n";
     }
     if (in == 's') {
       std::cout << "please enter the value of the node you are searching\n";
       std::cin >> i;
       Node * ptr = t.search(i);
       (ptr == nullptr) ? std::cout << "there was no corresponding node\n" : std::cout << "node " << i << " was found\n";
     }
     if (in == 'o') std::cout << "the root value is " << t.root()->key << "\n";
     if (in == 'p') t.printBST();
     if (in == 'y') t.isempty() ? std::cout << "the tree is empty\n" : std::cout << "the tree isn't empty\n";
     if (in == 'x') t.isempty() ? std::cout << "the tree is empty\n" : std::cout << t.maximum()->key << " is the maximum of the tree\n";
     if (in == 'n') t.isempty() ? std::cout << "the tree is empty\n" : std::cout << t.minimum()->key << " is the minimum of the tree\n";
     if (in == 'h') std::cout << "a - add node\nr - remove node\ns - search\np - print\nh - help\nx - max \nn - min\ns - successor \nr - predecessor\no - root\ny - empty?\ne - exit\n";
     if (in == 'e') {
       std::cout << "bye\n"; 
       break;
     }
   }

  return 0;
 }
