#pragma once

class Node {
	friend class BinaryTree;
private:
	int data;
	Node *left;
	Node *right;

public:
	Node(int data);
	
};