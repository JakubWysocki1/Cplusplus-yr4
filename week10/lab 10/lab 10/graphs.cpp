
#include<iostream>
using namespace std;
#include <vector>
#include <stack>
#include "graphs.h"


MarkSweep::MarkSweep(vector<vector<int>>& adjacency_matrixin) {
    adjacency_matrix = adjacency_matrixin;

    // Create nodes in heap and add to heap vector
    for (int i = 0; i < adjacency_matrix.size(); i++) {
        Node* node = new Node(i);
        roots.push(node);
        
    }
}


void MarkSweep::mark() {
    // Mark reachable objects using Depth-First Search
    while (!roots.empty()) { //loop until vector is empty
        Node* current = roots.top();
        roots.pop();
        if (!current->marked) {
            current->marked = true;
            cout << "Marked" << endl;
            // Mark all adjacent objects
            for (int i = 0; i < adjacency_matrix[current->val].size(); i++) {
                if (adjacency_matrix[current->val][i]  == 1) {
                    current->neighbours.push_back(new Node(i));
                }
            }
        }
    }
}


void MarkSweep::sweep() {
    // Sweep unreachable objects
    for (int i = 0; i < adjacency_matrix.size(); i++) {
        Node* node = new Node(i);
        if (!node->marked) {
            delete node;
            cout << "Deleted Node" << endl;
        }
        else {
            node->marked = false;
        }
    }
}

void MarkSweep::collect_garbage() {
    mark();
    sweep();
}
