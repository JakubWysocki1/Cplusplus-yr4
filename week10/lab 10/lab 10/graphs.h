#pragma once
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Node {
    friend class MarkSweep;
public:
    Node(int v) {
        val = v;
        marked = false;
    }
    
private:
    bool marked;
    int val;
    vector<Node*> neighbours;
    
};

// Mark and Sweep Algorithm
class MarkSweep {
public:
    MarkSweep(vector<vector<int>>& adjacency_matrix);
    void mark();
    void sweep();
    void collect_garbage();

private:
     // Vector of nodes representing objects in heap
    vector<vector<int>> adjacency_matrix; // Adjacency matrix for heap graph
    stack<Node*> roots; // Stack of root objects
};
