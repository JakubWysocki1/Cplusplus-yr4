//x00164430
/*
References:
https://www.geeksforgeeks.org/introduction-to-binary-tree-data-structure-and-algorithm-tutorials/
https://www.geeksforgeeks.org/find-the-maximum-depth-or-height-of-a-tree/
https://prepinsta.com/cpp-program/deletion-in-binary-search-tree/

*/
#include <iostream>
#include "node.h"
#include "binarytree.h"
using namespace std;


int main() {
	
	BinaryTree tree;

	tree.insert(53);

	//tree.insert(67);
	//tree.insert(69);
	//tree.insert(96);
	//tree.insert(100);
	//tree.insert(31);
	//tree.insert(61);

	cout << "PreOrderTraversal:" << endl;
	tree.preOrderTraversal();

	cout << endl << "InOrderTraversal:" << endl;
	tree.inOrderTraversal();

	cout << endl <<"PostOrderTraversal:" << endl;
	tree.postOrderTraversal();

	cout << endl << "TreeDepth:" << endl;
	tree.calcDepth();


	cout << endl << "AfterDeletion:" << endl;
	tree.deleteNode(53);
	tree.preOrderTraversal();


	//cout << endl << "Check Balanced:" << endl;
	//tree.checkBalanced();



	
	return 0;

}