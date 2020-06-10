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

  Node* maximum() {
    if (isempty()) return nullptr;
    Node* currnode = root_;
    while ((currnode->right) != nullptr) {
      currnode = currnode->right;
    }
    return currnode;
  }

  Node* minimum() {
  if (isempty()) return nullptr;
    Node* currnode = root_;
    while ((currnode->left) != nullptr) {
      currnode = currnode->left;
    }
    return currnode;
  }

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

  void add(Node* n){
    if (isempty()) {
      root_ = n;
      return;
    }
    if (search(n->key) != nullptr) {
      std::cout << "node with the value " << n->key << " already in tree\n";
    }
    Node* currnode = root_;
    while (true) {
      if(currnode->key < n->key) {
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
      (currnode->key > n->key) ? currnode = currnode->left : currnode = currnode->right;
    }
  }

  void rm(Node* n){
    Node* p = n->parent;
    if ((n->left == nullptr) && (n->right == nullptr)) {
      (p->key > n->key) ? p->left = nullptr: p->right = nullptr;
      delete(n);
      return;
    }

    if ((n->left == nullptr) ^ (n->right == nullptr)) {
      Node* c;
      (n->right == nullptr) ? c = n->left : c = n->right;
      c->parent = p;
      (p->key > n->key) ? p->left = c : p->right = c;
      delete(n);
      return;
    }

  }

  void print();

  private:
  Node* root_;
};

#endif