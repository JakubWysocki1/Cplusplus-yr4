#include "binarytree.h"
#include <iostream>
using namespace std;


BinaryTree::BinaryTree() {
	root = nullptr;
};

void BinaryTree::insert(int data) {
	Node* newNode = new Node(data);

	if (root == nullptr) {
		root = newNode;
	}
	else {
		Node* focusNode = root;
		Node* parent;

        while (true) {
            parent = focusNode;

            if (data < focusNode->data) {
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
};

void BinaryTree::preOrderTraversal() {
    if (this->root != nullptr) {
        
        preOrderTraversal(this->root->left);
        preOrderTraversal(this->root->right);
    }
};

void BinaryTree::preOrderTraversal(Node* focusNode) {
    if (focusNode != nullptr) {
        cout << focusNode->data << " ";
        preOrderTraversal(focusNode->left);
        preOrderTraversal(focusNode->right);
    }
};

void BinaryTree::inOrderTraversal() {
    if (this->root != nullptr) {
        inOrderTraversal(this->root->left);
        
        inOrderTraversal(this->root->right);
    }
};
void BinaryTree::inOrderTraversal(Node* focusNode) {
    if (focusNode != nullptr) {
        inOrderTraversal(focusNode->left);
        cout << focusNode->data << " ";
        inOrderTraversal(focusNode->right);
    }
};

void BinaryTree::postOrderTraversal() {
    if (this->root != nullptr) {
        postOrderTraversal(this->root->left);
        preOrderTraversal(this->root->right);
        
    }
};

void BinaryTree::postOrderTraversal(Node* focusNode) {
    if (focusNode != nullptr) {
        postOrderTraversal(focusNode->left);
        postOrderTraversal(focusNode->right);
        cout << focusNode->data << " ";
    }
};

void BinaryTree::calcDepth() {
    if (this->root != nullptr) {
        cout << calcDepth(this->root);
        
    }
    
};

int BinaryTree::calcDepth(Node* focusnode) {
    if (focusnode != nullptr){

        /* compute the depth of each subtree */
        int lDepth = calcDepth(focusnode->left);
        int rDepth = calcDepth(focusnode->right);

        /* use the larger one */
        if (lDepth > rDepth) {
            return (lDepth + 1);
        }
        else {
            return (rDepth + 1);
        }
    }
    else {
        return 0;
    }
};