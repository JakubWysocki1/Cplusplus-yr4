#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class GraphNode {
public:
    bool Marked;
    vector<GraphNode*> adj_list;
};

void mark(GraphNode* node) {
    if (node == nullptr || node->Marked) {
        return;
    }
    node->Marked = true;
    for (auto adj : node->adj_list) {
        mark(adj);
    }
}

void sweep(vector<GraphNode*>& objects) {
    for (auto it = objects.begin(); it != objects.end(); ) {
        if (!(*it)->Marked) {
            delete* it;
            it = objects.erase(it);
        }
        else {
            (*it)->Marked = false;
            ++it;
        }
    }
}

void mark_and_sweep(vector<GraphNode*>& roots, vector<vector<bool>>& adj_matrix) {
    // Mark reachable objects
    stack<GraphNode*> worklist;
    for (auto root : roots) {
        worklist.push(root);
    }
    while (!worklist.empty()) {
        auto node = worklist.top();
        worklist.pop();
        mark(node);
        for (int i = 0; i < adj_matrix.size(); ++i) {
            if (adj_matrix[node - &objects[0]][i]) {
                worklist.push(&objects[i]);
            }
        }
    }
    // Sweep unreachable objects
    sweep(objects);
}

int main() {
    // Create objects
    GraphNode* a = new GraphNode();
    GraphNode* b = new GraphNode();
    GraphNode* c = new GraphNode();
    GraphNode* d = new GraphNode();
    GraphNode* e = new GraphNode();
    // Set adjacency list
    a->adj_list.push_back(b);
    b->adj_list.push_back(c);
    c->adj_list.push_back(d);
    d->adj_list.push_back(b);
    d->adj_list.push_back(e);
    // Create roots
    vector<GraphNode*> roots = { a, e };
    // Create adjacency matrix
    vector<vector<bool>> adj_matrix = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };
    // Run mark-and-sweep algorithm
    mark_and_sweep(roots, adj_matrix);
    // Clean up
    return 0;
}
