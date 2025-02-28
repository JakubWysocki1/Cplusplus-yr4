#pragma once

class Node {
	friend class BinaryTree;
	friend class BinarySearchTree;
private:
	int data;
	Node *left;
	Node *right;

public:
	Node(int data);
	
};