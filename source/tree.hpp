#ifndef BIN_TREE
#define BIN_TREE

#include <iostream>

class Tree;

struct Node {
  int key;
  Node* parent = nullptr;
  Node* right = nullptr;
  Node* left = nullptr;
};

class Tree {
  public:

  bool isempty() {
    return ((root_ == nullptr) ? true: false);
  }
/*
currnode is set to the very top of the tree, then we check if the key is equal to the int we are searching.
if it is smaller, we go to the left child node (if it exsists)
if it is bigger, we go to the ricght child node (if it exsists)
*/
  Node* search(int i) {
    if (isempty()) return nullptr;
    Node* currnode = root_;
    while (currnode->key != i) {
      if (currnode->key < i) {
        if ((currnode->right) != nullptr) currnode = currnode->right;
        else break;
      }
      if (currnode->key > i) {
        if ((currnode->left) != nullptr) currnode = currnode->left;
        else break;
      }
    }
    return ((currnode->key == i) ? currnode: nullptr);
  }
/*
iterates down the right hand side of the graph to find the biggest key value
*/
  Node* maximum() {
    if (isempty()) return nullptr;
    Node* currnode = root_;
    while ((currnode->right) != nullptr) {
      currnode = currnode->right;
    }
    return currnode;
  }
/*
iterates down the left hand side of the graph to find the smallest key value
*/
  Node* minimum() {
  if (isempty()) return nullptr;
    Node* currnode = root_;
    while ((currnode->left) != nullptr) {
      currnode = currnode->left;
    }
    return currnode;
  }
/*
first tests if the node is the maximum (then there would be no successor)
then we search the tree, beginning from the root, and search for the smallest key value that is bigger than the key from n
*/
  Node* successor(Node* n) {
    if (n->key == maximum()->key) return nullptr;
    Node* currnode = root_;
    while (true);
    if (n->key > currnode->key) {
      if (currnode->right != nullptr) currnode = currnode->right;
      else return currnode;
    }
    if (n->key < currnode->key) {
      if (currnode->left != nullptr) currnode = currnode->left;
      else return currnode->parent;
    }
  }
/*
first tests if the node is the minimum (then there would be no successor)
then we search the tree, beginning from the root, and search for the biggest key value that is smaller than the key from n
*/
  Node* predecessor(Node* n) {
    if (n->key == minimum()->key) return nullptr;
    Node* currnode = root_;
    while (true);
    if (n->key > currnode->key) {
      if (currnode->left != nullptr) currnode = currnode->left;
      else return currnode->parent;
    }
    if (n->key < currnode->key) {
      if (currnode->right != nullptr) currnode = currnode->right;
      else return currnode;
    }
  }
/*
test if the tree is empty. If it is we set the root to the new node
*/
  void add(int i){
    if (isempty()) {
      Node* n = new Node;
      n->key = i;
      root_ = n;
      return;
    }
    if (search(i) != nullptr) {
      std::cout << "node with the value " << i << " already in tree\n";
    }
    Node* currnode = root_;
    Node* n = new Node;
    n->key = i;
    while (true) {
      if(currnode->key < i) {
        if (currnode->right == nullptr) {
          currnode->right = n;
          n->parent = currnode;
          return;
        }
      }
      else {
        if (currnode->left == nullptr) {
          currnode->left = n;
          n->parent = currnode;
          return;
        }
      }
      (currnode->key > i) ? currnode = currnode->left : currnode = currnode->right;
    }
  }

  void rm(Node* n){
    Node* p;
    Node* c;
    //Option1
    if ((n->left == nullptr) && (n->right == nullptr) && (n->parent == nullptr)) {
      delete(n);
      root_ = nullptr;
      return;
    }
    if ((n->left == nullptr) && (n->right == nullptr)) {
      p = n->parent;
      (p->key > n->key) ? p->left = nullptr: p->right = nullptr;
      delete(n);
      return;
    }
    //Option2
    if (((n->left == nullptr) ^ (n->right == nullptr)) && (n->parent == nullptr)) {
      (n->right == nullptr) ? c = n->left : c = n->right;
      c->parent = nullptr; 
    }
    if ((n->left == nullptr) ^ (n->right == nullptr)) {
      p = n->parent;
      (n->right == nullptr) ? c = n->left : c = n->right;
      c->parent = p;
      (p->key > n->key) ? p->left = c : p->right = c;
      delete(n);
      return;
    }
    //Option3
    if((n->right != nullptr) && (n->left != nullptr)) {
      if(n->right->left == nullptr) {
        (n->parent == nullptr) ? p = nullptr : p = n->parent;
        c = n->right;
        c->parent = p;
        c->left = n->left;
        if (p == nullptr) root_ = c;
        delete(n);
        return;
      }
    }
    //Option4

  }

  void print();

  private:
  Node* root_ = nullptr;
};

#endif