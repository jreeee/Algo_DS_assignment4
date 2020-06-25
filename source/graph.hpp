#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <string>
#include <map>
#include <limits>


struct Node {
    
    std::string label;
    std::map<Node*, int> adjacentNodes{}; // the int is for the weight od the egde
    Node *parent = nullptr;
    int distance = std::numeric_limits<int>::max(); // aka key, set by default to infinity
   
    Node(std::string name);
    
    bool operator==(Node const& n) const;
    void connect(int weight, Node *n);
    void rmcon(Node *n);
    void chparent(Node *n);
    void ptNode(std::string & s, bool dir) const;
};

/*
I couldn't get that to work properly, so I am using a workaround by utilizing a array
struct MinHeapNode {
    
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
    MinHeap();
    ~MinHeap();
    MinHeapNode generate(std::vector<Node> const& vn);
    MinHeapNode restruct();
    void add(Node *n);
    void swap(MinHeapNode* one, MinHeapNode* two);
    int extract();

};
*/
class Graph {

    public:

    Graph(bool b);

    bool directed() const;
    Node* add(Node n);
    void rm(Node *n);
    bool prim();
    void prep();
    bool beFo(Node *n);
    void ptgraph(std::string const& fname) const;
    std::vector<Node*> sortkeys(std::vector<Node*> & vn);

    private:
    std::vector<Node*> nodes_;
    //MinHeap *minPriorityQueue_;
    bool isDirected_;
};

#endif