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
	void deleteNode(int number);
	void checkBalanced();

	
	

protected:
	void preOrderTraversal(Node* focusNode);
	void inOrderTraversal(Node* focusNode);
	void postOrderTraversal(Node* focusNode);
	Node* root;
	int calcDepth(Node* focusnode);
	Node* deleteNode(Node* focuNnode, int number);
	int calcRight(Node* focusnode);
	int calcLeft(Node* focusnode);
	bool checkBalanced(Node* focusnode);
	
};