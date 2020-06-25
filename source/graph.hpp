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
    /* functions & methods */
    bool operator==(Node const& n) const;
    //we don't need a change weight method since we can just overwrite with connect()
    void connect(int weight, Node *n);
    void rmcon(Node *n);
    void chparent(Node *n);
    void ptNode(std::string & s, bool dir) const;
};

struct MinHeapNode {
    /* data */
    Node *node = nullptr;
    MinHeapNode *parent = nullptr;
    MinHeapNode *left = nullptr;
    MinHeapNode *right = nullptr;
    int key  = std::numeric_limits<int>::max();
};


class MinHeap {
private:
    MinHeapNode *root;
    int size;

public:
    MinHeap(/* args */);
    ~MinHeap();
    MinHeapNode generate(std::vector<Node> const& vn);
    MinHeapNode restruct();
    void add(Node *n);
    void swap(MinHeapNode* one, MinHeapNode* two);
    int extract();

};

class Graph {

    public:
    Graph(bool b);

    bool directed() const;
    Node* add(Node n);
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