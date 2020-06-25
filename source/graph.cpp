#include "graph.hpp"
#include <iostream>
#include <fstream>


/* 
Implementation of functions related to struct Node

first we have a basic constructor, intializing the Node with the default values and the set label
then we have a destructor, deleting the contents of our node

for methods we have a == operator, checking if a node with the same name already exists
as well as connect() which adds (or overwrites) a connection and its weight
between this node and the node provided as an argument
rmcon tries to remove the weight and connection
chparent assigns the node a new parent node
ptnode gets passed on a string and iterates trough its adjacent nodes, appending them
to the string. depending on the type of graph we switch the connection symbol between nodes
and depending on if they have a parent node we colour their connection  
*/
Node::Node(std::string name) : label{name} {}

bool Node::operator==(Node const& n) const {
  return n.label == label;
}

void Node::connect(int weight, Node *n) {
  if (weight < std::numeric_limits<int>::max()) {
    adjacentNodes.emplace(std::make_pair(n, weight));
  }
}

void Node::rmcon(Node *n) {
  adjacentNodes.erase(n);
}

void Node::chparent(Node *n) {
  parent = n;
}

void Node::ptNode(std::string & s, bool dir) const {
  std::string line = dir ? "->" : "--";
  for (auto i : adjacentNodes) {
    if (&i != nullptr) {
      s.append(label);
      s.append(line);
      s.append(i.first->label);
      s.append(" [label = ");
      s.append(std::to_string(i.second));
      s.append(", color = ");
      s.append((i.first->parent == this) ? "green" : "black");
      s.append("];\n");
    }
  }
}
/* 
Implementation of MinHeap

MinHeap::MinHeap() {}

void MinHeap::add(Node *n) {
  size++;
  if (root == nullptr) {
    root = new MinHeapNode{n};
    return;
  }
  if (root->node->distance > n->distance) {
    auto tmp = new MinHeapNode{n};
    root->parent = tmp;
    tmp->left = root;
    root = tmp;
    restruct();
    return;
  }
  auto tmp = root;
  while ((n->distance > tmp->left->node->distance ) && (n->distance > tmp->right->node->distance)) {
    //Do sth
  }
}

void MinHeap::swap(MinHeapNode* one, MinHeapNode* two){
  std::swap(one->key, two->key);
  std::swap(one->node, two->node);
}

MinHeapNode MinHeap::generate(std::vector<Node> const& vn) {
  //for (auto i : vn) new HeapNode{Node{i}};
}
*/

/*
Implementation of the Graph

when constructing you can choose to either have a directed or undirected graph

to that graph you can add Nodes with add() or remove with rm()
since I was unable to implement the MinHeap I tried to substitute it with an array
this array contains Nodes and their key/weight/distance.
this was needed for prim().
I also implemented a function which sets all Nodes to the 
highest possible int and their parents to the nullpointer, which is used for both
prim() and beFo().
I couldn't get prim to work, however beFo() somewhat runs.
for some reason I struggeled with this assignment much more than the other ones.
lastly there is a print function that works really well, you only have to write
the filename as an argument and it will make a ile with that title containing the graph
in graphiz.
*/
Graph::Graph(bool b) : isDirected_{b} {}

bool Graph::directed() const {
  return isDirected_;
}

//method to add nodes to the graph
Node* Graph::add(Node n) {
  //checking if there is already a node with the same name
  for (auto i : nodes_) {
    std::cerr << "Node already in graph\n";
    if (n.label == i->label) return i;
  }
  //if not we create a new node and add it to the node_ - vector
  auto addedNode = new Node{n};
  nodes_.push_back(addedNode);
  return addedNode;
}

//method to remove nodes from the graph
void Graph::rm(Node *n) {
  for (auto i = nodes_.begin(); i != nodes_.end(); ++i) {
    if (n == *i) {
      nodes_.erase(i);
      if (n != nullptr) {
        delete(n);
      }
      return;
    }
  }
}

//sorts the array it gets
std::vector<Node*> Graph::sortkeys(std::vector<Node*> & vn) {
  for (int i = 0; i < vn.size(); ++i) {
    for (int j = i; j < vn.size(); ++j) {
      if (vn[j]->distance > vn[i]->distance) std::swap(vn[j], vn[i]);
    }
  }
  for (auto i : vn) {
    std::cout << i->distance <<"\n";
  }
  return vn;
}

//a basic function called before our algorithms to initialize the nodes correctly
void Graph::prep() {
  for (auto &i : nodes_) {
    i->distance = std::numeric_limits<int>::max();
    i->parent = nullptr;
  }
}

//I give up, I can't get prim() to work, I don't even know what I am doing anymore
bool Graph::prim() {
  //this is our "fake" MinHeap, storing Nodes and their values
  std::vector<Node*> tmp;
  for (auto i : nodes_) {
    for (auto j : i->adjacentNodes) {
      auto n = new Node{*j.first};
      n->distance = j.second;
      tmp.push_back(n);
    }
  }
  auto root = nodes_.front();
  root->distance = 0;
  prep();
  while (tmp.empty() == false){
    auto n = tmp.back();
    tmp.pop_back();
    for (auto i : n->adjacentNodes) {
      bool cond1 = false;
      bool cond2 = false;
      for (auto j : tmp) {
        if (j == i.first) {
          cond1 == true;
          break;
        }
      }
      if (i.second < i.first->distance) cond2 = true;
      if (cond1 && cond2) {
        i.first->parent = n;
        i.first->distance = i.second;
      }
    }
  }
}
//Bellmann Ford kinda works
bool Graph::beFo(Node *n) {
  prep();
  n->distance = 0;
  for (int size = 1; size < nodes_.size(); ++size) {
    for (auto &i : nodes_) {
      for (auto j : i->adjacentNodes) {
        //relaxing it, if possible
        if (j.first->distance > (j.second + i->distance)) {
          j.first->parent = i;
          j.first->distance = j.second + i->distance;
        }
      }
    }
  }
  //looking for negative cycles
  for (auto &i : nodes_) {
    for (auto j : i->adjacentNodes) {
      if (j.first->distance > (j.second + i->distance)) return false;
    }
  }
  return true;
}

void Graph::ptgraph(std::string const& fname) const {
  bool dir = isDirected_;
  std::ofstream myfile;
  myfile.open(fname);
  std::string s ("#This file contains the dot-format description of the graph.\n");
  s.append(isDirected_ ? "digraph {\n\n" : "graph {\n\n");
  for (auto const& i : nodes_) {
    i->ptNode(s, dir);
  }
  s.append("\n}");
  std::cout << "\n" << s << "\n";
  myfile << s;
  myfile.close();
}