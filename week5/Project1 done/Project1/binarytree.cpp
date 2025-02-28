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
    if (root != nullptr) {
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
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
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
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
    if (root != nullptr) {
        postOrderTraversal(root->left);
        preOrderTraversal(root->right);
        cout << root->data << " ";
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

        cout << calcDepth(root);
        
    
};

int BinaryTree::calcDepth(Node* focusnode) {
    
        ///* compute the depth of each subtree */
        //int lDepth = calcDepth(focusnode->left);
        //int rDepth = calcDepth(focusnode->right);

        ///* use the larger one */
        //if (lDepth > rDepth) {
        //    return (lDepth + 1);
        //}
        //else {
        //    return (rDepth + 1);
        //}

        int lDepth = calcLeft(focusnode);
        int rDepth = calcRight(focusnode);

        if (lDepth > rDepth) {
            return (lDepth);

        }
        else {
            return (rDepth);
        }


};

void BinaryTree::deleteNode(int number) {
    deleteNode(root, number);

};

Node* BinaryTree::deleteNode(Node* focusnode, int number) {
    //if node is empty stop
    if (focusnode == NULL) {
        return NULL;
    }

    if (focusnode->left == nullptr && focusnode->right == nullptr) {
        delete focusnode;
        return nullptr;
    }

    //if the number to be deleted is smaller than nodes its on left subtree
    if (focusnode->data > number) {
        focusnode->left = deleteNode(focusnode->left, number);
    }
    //if the number to be deleted is greater than nodes its on right subtree
    else if (focusnode->data < number) {
        focusnode->right = deleteNode(focusnode->right, number);
    }
    else { //if nuumber is the same as in the node then thats the node
        // Left child NULL
        if (focusnode->left == NULL) {
            Node* temp = focusnode->right;
            delete focusnode;
            return temp;
        }
        // Right child NULL
        else if (focusnode->right == NULL) {
            Node* temp = focusnode->left;
            delete focusnode;
            return temp;
        }
        else {
            // Finding the inorder successor
            Node* temp = focusnode->right;
            // Finding the leftmost node in right subtree
            while (temp->left != NULL) temp = temp->left;
            // Changing value of root
            focusnode->data = temp->data;
            // Deleting the leftmost node;
            focusnode->right = deleteNode(focusnode->right, temp->data);
        }
    }
    return focusnode;

};

int BinaryTree::calcLeft(Node* focusnode) {
    if (focusnode != nullptr) {
        int lDepth = calcLeft(focusnode->left);

        return (lDepth + 1);
    }

    return 0;
}

int BinaryTree::calcRight(Node* focusnode) {
    if (focusnode != nullptr) {
        int rDepth = calcRight(focusnode->right);

        return (rDepth + 1);
    }

    return 0;
    
    
}

void BinaryTree::checkBalanced() {
    if (checkBalanced(root)) {
        cout << "Balanced";
    }
    else {
        cout << "Not Balanced";
    }
};

bool BinaryTree::checkBalanced(Node* focusNode){
    int lNode = calcLeft(focusNode);
    int rNode = calcRight(focusNode);

    cout << "Left side depth:" << lNode << endl;
    cout << "Right side depth:" << rNode << endl;
    if (lNode != rNode) {
        return false;
    }

    return true;
};