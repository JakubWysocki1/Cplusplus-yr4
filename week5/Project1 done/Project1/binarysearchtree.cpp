#include "binarysearchtree.h"
#include <iostream>
#include <random>

using namespace std;

void BinarySearchTree::insert(int data) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0, 1);

    Node* newNode = new Node(data);

    if (root == nullptr) {
        root = newNode;
    }
    else {
        Node* focusNode = root;
        Node* parent;

        while (true) {
            parent = focusNode;

            if (distribution(rd) == 0) {
                focusNode = focusNode->left;
                if (focusNode == nullptr) {
                    parent->left = newNode;
                    return;
                }
            }
            else {
                focusNode = focusNode->right;
                if (focusNode == nullptr) {
                    parent->right = newNode;
                    return;
                }
            }
        }
    }
}