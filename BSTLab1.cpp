#include <iostream>

using namespace std;

// Implement the node class we will need for our Binary Search Tree
class Node {
	public:
		// the Node should contain
		// 	- an integer "key" that holds the value of the Node
		// 	- a pointer to each child possible child node ("right" and "left")
	int key;
	Node* left;
	Node* right;
	Node(int val) : key(val), left(nullptr), right(nullptr){}
		// Write a constructor for the Node
		// input: only an integer value for "key", no pointer arguments
		// 		right and left pointers should be null
};


// The BST created below contains the following values:
// {7, 0, 18, -2, 6, 13, 21, -1, 12, 15, 19, 99}
Node* createTree() {
    // root (level 0)
    Node* root = new Node(7);

    // level 1 (children of root)
	root->left = new Node(0);
	root->right = new Node(18);
    // level 2 (children of 0)
	root->left->left = new Node(-2);
	root->left->right = new Node(6);
    // level 2 (children of 18)
	root->right->left = new Node(13);
	root->right->right = new Node(21);
    // level 3 (children of -2)
	root->left->left->right = new Node(-1);
    // level 3 (children of 13)
	root->right->left->left = new Node(12);
	root->right->left->right = new Node(15);
    // level 3 (children of 21)
	root->right->right->left = new Node(19);
	root->right->right->right = new Node(99);
	
    return root;
}

// Write a function that will search the BST for a target value
//	input: integer target to search for,
			// pointer to root Node
// 	returns: true or false depending on if the value is found
// You should write this function recursively! What is the base case? What is the general case?
bool searchTree(int target, Node* root) {

	// Base cases
	if (root == nullptr){
		return false;
	}
	if (target == root->key){
			return true;
	}
	// General case
	if (target < root->key){	
		return searchTree(target, root->left);
	}
	if (target > root->key){	
		return searchTree(target, root->right);
	}
	return false;	
}

// Write a function that will return the total number of Nodes in the tree
// 	input: pointer to the root Node
// 	returns: number of nodes currently in the tree
// You should write this function recursively!
int treeSize(Node* root) {
	// base case
	if (root == nullptr){
		return 0;
	}
	// General case
	return 1 + treeSize(root->left) + treeSize(root->right);
}


// Return the number of leaf nodes in the tree.
// A leaf is a node with no children.
int countLeaves(Node* root) {
	// base case
	if (root == nullptr){
		return 0;
	}
	if (root->right == 0 && root->left == 0){
		return 1;
	}
	// General case
	return countLeaves(root->left) + countLeaves(root->right);
}

// BONUS! Write a function that will determine the height of the tree
int treeHeight(Node* root) {
	// base case
	if (root == nullptr){
		return -1;
	}
	// General case
	return 1 + (treeHeight(root->left) > treeHeight(root->right) ? treeHeight(root->left) : treeHeight(root->right)); 
}
