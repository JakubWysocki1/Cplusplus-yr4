#pragma once
#include <iostream>
#include "node.h"

class BinaryTree {
public:
	BinaryTree();
	~BinaryTree();
	void insert();

protected:
	Node* root;
	
};