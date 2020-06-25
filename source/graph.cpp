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
*/
Node::Node(std::string name) : label{name} {}

//Node::~Node() {} //TODO

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
      s.append("];\n");
    }
  }
}

MinHeap::MinHeap() {
  //root = new MinHeapNode(generate(std::vector<Node> const& vn));
}

MinHeapNode MinHeap::generate(std::vector<Node> const& vn) {
  for (auto i : vn) new Node{i};//do sth
}


Graph::Graph(bool b) : isDirected_{b} {}

//Graph::~Graph() {} //TODO

bool Graph::directed() const {
  return isDirected_;
}

Node* Graph::add(Node n) {
  auto addedNode = new Node{n};
  nodes_.push_back(addedNode);
  return addedNode;
}

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

void Graph::ptgraph() const {
  bool dir = isDirected_;
  std::ofstream myfile;
  myfile.open ("graph.gv");
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