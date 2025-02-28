#include <iostream>
#include <random>
using namespace std;


template <typename T>
class BinaryTree;

template <typename T>
class TreeNode {
    friend class BinaryTree<T>;
public:
    TreeNode<T>(T valin) {
        val = valin;
    }
private:
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;
};



template <typename T>
class BinaryTree {
private:
	TreeNode <T>* root;

    TreeNode <T>* insertnode(T numIn, TreeNode<T>* nodeIn) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> distribution(0, 1);

        if (nodeIn == nullptr)
        {
            return (new TreeNode<T>(numIn));
        }
        else if (distribution(rd) == 0)
        {
            nodeIn->left = insertnode(numIn, nodeIn->left);
        }
        else if (distribution(rd) == 1)
        {
            nodeIn->right = insertnode(numIn, nodeIn->right);
        }

        return nodeIn;

    }

    void preOrderTraversal(TreeNode<T>* focusNode) {
        if (focusNode != nullptr) {
            cout << focusNode->val << " ";
            preOrderTraversal(focusNode->left);
            preOrderTraversal(focusNode->right);
        }
    }

public:
    void preOrderTraversal() {
        if (root != nullptr) {
            cout << root->val << " ";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    };

    void insertnode(T numIn) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> distribution(0, 1);

        if (root == nullptr)
        {
            root = new TreeNode<T>(numIn);
            return;
        }
        if (distribution(rd) == 0)
        {
            root->left = insertnode(numIn, root->left);
            return;
        }
        root->right = insertnode(numIn, root->right);
        return;
    }
   

};


int main() {
    BinaryTree <float>* tree = new BinaryTree<float>();
    tree->insertnode(0.3);
    tree->insertnode(0.5);
    tree->preOrderTraversal();
    cout << endl;

    BinaryTree <string>* tree2 = new BinaryTree<string>();
    tree2->insertnode("test");
    tree2->insertnode("test2");
    tree2->preOrderTraversal();
    cout << endl;



    return 0;
}


