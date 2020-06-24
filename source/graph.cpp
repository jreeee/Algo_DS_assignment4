#include "graph.hpp"
#include <iostream>

Graph::Graph() {}

Graph::Graph(bool b) :
  isDirected_{b}, minPriorityQueue_{new MinHeap} {}

Graph::Graph(std::vector<Node> const& vn, MinHeap *mh, bool b) :
   nodes_{vn}, minPriorityQueue_{mh}, isDirected_{b} {}

Graph::~Graph() {} //TODO


/* 
Implementation of functions related to struct Node

first we have a basic constructor, intializing the Node with the default values and the set label
then we have a destructor, deleting the contents of our node

for methods we have a == operator, checking if a node with the same name already exists
as well as connect() which adds (or overwrites) a connection and its weight
between this node and the node provided as an argument
rmcon tries to remove the weight and connection
chparent assigns the node a new parent node
*/
Node::Node(std::string name) : label{name} {}

Node::~Node() {} //TODO

bool Node::operator==(Node const& n) const {
  return n.label == label;
}

void Node::connect(int weight, Node *n) {
  adjacentNodes.emplace((n, weight));
}

void Node::rmcon(Node *n) {
  adjacentNodes.erase(*n);
}

void Node::chparent(Node *n) {
  parent = n;
}


MinHeap::MinHeap() {
  //root = new MinHeapNode(generate(std::vector<Node> const& vn));
}

MinHeapNode MinHeap::generate(std::vector<Node> const& vn) {
  for (auto i : vn) new Node{i};//do sth
}