#pragma once
#include <iostream>
#include "node.h"

class BinaryTree {
public:
	BinaryTree();
	void insert(int data);
	void preOrderTraversal();
	void inOrderTraversal();
	void postOrderTraversal();
	void calcDepth();

	

protected:
	void preOrderTraversal(Node* focusNode);
	void inOrderTraversal(Node* focusNode);
	void postOrderTraversal(Node* focusNode);
	Node* root;
	int calcDepth(Node* focusnode);
	
};