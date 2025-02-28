#include<iostream>
using namespace std;
#include <vector>
#include "graphs.h"

int main() {


    vector<vector<int>> adjacency_matrix = { {0, 1, 0, 0, 0, 0},
                                             {0, 0, 1, 0, 0, 1},
                                             {1, 0, 0, 0, 0, 0},
                                             {0, 1, 0, 0, 1, 0},
                                             {0, 0, 0, 0, 0, 1},
                                             {0, 0, 0, 0, 0, 0} };


    // Create MarkSweep object and perform garbage collection
    MarkSweep mark_sweep(adjacency_matrix);
    mark_sweep.collect_garbage();

    // Print the marks of all nodes
    /*mark_sweep.printMarks();*/

    return 0;
}