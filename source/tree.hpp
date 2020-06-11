#ifndef BIN_TREE
#define BIN_TREE

#include <iostream>
#include <fstream>
#include <string>

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
    return (root_ == nullptr) ? true: false;
  }

  Node* root() {
    return root_;
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
    if (n->right == nullptr) return nullptr;
    Node* currnode = n->right;
    while (true) {
      if (n->key > currnode->key) {
        if (currnode->right != nullptr) currnode = currnode->right;
        else return currnode;
      }
      if (n->key < currnode->key) {
        if (currnode->left != nullptr) currnode = currnode->left;
        else return currnode;
      }
    }
  }
/*
first tests if the node is the minimum (then there would be no successor)
then we search the tree, beginning from the root, and search for the biggest key value that is smaller than the key from n
*/
  Node* predecessor(Node* n) {
    if (n->left == nullptr) return nullptr;
    Node* currnode = n->left;
    while (true){
      if (n->key > currnode->key) {
        if (currnode->left != nullptr) currnode = currnode->left;
        else return currnode;
      }
      if (n->key < currnode->key) {
        if (currnode->right != nullptr) currnode = currnode->right;
        else return currnode;
      }
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
      std::cout << "node " << i << " successfully added to the tree\n";
      return;
    }
    if (search(i) != nullptr) {
      std::cout << "node with the value " << i << " already in tree\n";
      return;
    }
    Node* currnode = root_;
    Node* n = new Node;
    n->key = i;
    while (true) {
      if(currnode->key < i) {
        if (currnode->right == nullptr) {
          currnode->right = n;
          n->parent = currnode;
          std::cout << "node " << i << " successfully added to the tree\n";
          return;
        }
      }
      else {
        if (currnode->left == nullptr) {
          currnode->left = n;
          n->parent = currnode;
          std::cout << "node " << i << " successfully added to the tree\n";
          return;
        }
      }
      (currnode->key > i) ? currnode = currnode->left : currnode = currnode->right;
    }
  }

  void rm(Node* n){
    if (n == nullptr) return;
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
      delete(n);
      return;
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
    c = successor(n);
    n->key = c->key;
    rm(c);
    delete(c);
    return;
  }
/*
print() creates a file in the build folder (or overrites it), namely tree.gv 
it then recursively executes tostring, each adding two new lines to the string s if the node has at least one child
after all nodes are written down, s is finished by adding a closing curly bracket.
s is then printed to the terminal aswell as being written into tree.gv, which is then closed.
*/
  void printBST(){
    std::ofstream myfile;
    myfile.open ("tree.gv");
    std::string s ("#This string will contain the dot-format description of the tree.\ndigraph G {\n");
    root_ = root();
    tostring(root_, s);
    s.append("}\n");
    std::cout << "\n" << s << "\n";
    myfile << s;
    myfile.close();
  }
/*
First we check if the node is a nullpointer or if both of its children are nullpointer.
If they are, we are done with that node.
If that was not the case we check if the left child is a nullpointer, if it is we add one to our NIL-number
and append it behind "current_node_key -> " in s.
If our node has a left child, we append "current_node_key -> left_child_key" to s.
After that is done we execute tostring for said child.
For the right child we do basically the same, except every instance of "left" is swapped with "right"
*/
  void tostring(Node* n, std::string& s) {
    if (n == nullptr)return;
    if ((n->left == nullptr) && (n->right == nullptr) && (n->key == root_->key)) {
      s.append(std::to_string(n->key));
      s.append("\n");
      return;
    }
    if ((n->left == nullptr) && (n->right == nullptr)) return;

    std::string c1 ("NIL");

    s.append(std::to_string(n->key));
    s.append(" -> ");
    if (n->left != nullptr) {
      s.append(std::to_string(n->left->key));
      s.append(";\n");
      tostring(n->left, s);
    }
    else {
      printNIL(n, s);
    }
    s.append(std::to_string(n->key));
    s.append(" -> ");
    if (n->right != nullptr) {
      s.append(std::to_string(n->right->key));
      s.append(";\n");
      tostring(n->right, s);
    }
    else {
      printNIL(n, s);
    }
  }
/*
small helper function that gives each NIL a unique value and defines its shape as a point
*/
  void printNIL (Node* n, std::string& s) {
    std::string c1 ("NIL");
    c1.append(std::to_string(n->key));
    s.append(c1);
    s.append(";\n");
    s.append(c1);
    s.append(" [shape=point];\n");
  }

  private:
  Node* root_ = nullptr;
};

#endif