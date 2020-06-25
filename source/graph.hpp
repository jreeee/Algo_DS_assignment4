#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <string>
#include <map>
#include <limits>


struct Node {
    /* data */
    std::string label;
    std::map<Node*, int> adjacentNodes{}; // the int is for the weight od the egde
    Node *parent = nullptr;
    int distance = std::numeric_limits<int>::max(); // aka key, set by default to infinity
    /* constructors */
    Node(std::string name);
    ~Node();
    /* functions / methods */
    bool operator==(Node const& n) const;
    //we don't need a change weight method since we can just overwrite with connect()
    void connect(int weight, Node *n);
    void rmcon(Node *n);
    void chparent(Node *n);
    std::string ptNode(std::string & s) const;
};

struct MinHeapNode {
    /* data */
    Node *node;
    MinHeapNode *parent;
    MinHeapNode *left;
    MinHeapNode *right;
    /* constructors */
    MinHeapNode(/* args */);
    ~MinHeapNode();
};


class MinHeap {
private:
    MinHeapNode *root;

public:
    MinHeap(/* args */);
    ~MinHeap();
    MinHeapNode generate(std::vector<Node> const& vn);
    MinHeapNode restruct();
    MinHeapNode add();
    int extract();

};

class Graph {

    public:
    Graph();
    Graph(bool b);
    Graph(std::vector<Node*> const& vn, MinHeap *mh, bool b);
    ~Graph();

    void add(Node n);
    void rm(Node *n);
    bool prim();
    bool beFo();
    void ptgraph() const;

    private:
    std::vector<Node*> nodes_;
    MinHeap *minPriorityQueue_;
    bool isDirected_;
};

#endif