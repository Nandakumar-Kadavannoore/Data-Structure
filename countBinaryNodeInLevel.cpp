// C++ program to find number of full nodes 
// at a given level 
#include <bits/stdc++.h> 
using namespace std; 

// A binary tree node 
struct Node { 
	int data; 
	struct Node *left, *right; 
}; 

// Utility function to allocate memory for a new node 
struct Node* newNode(int data) 
{ 
	struct Node* node = new (struct Node); 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

// Function that returns the height of binary tree 
int height(struct Node* root) 
{ 
	if (root == NULL) 
		return 0; 

	int lheight = height(root->left); 
	int rheight = height(root->right); 

	return max(lheight, rheight) + 1; 
} 

// Level Order traversal to find the number of nodes 
// having two children 
void LevelOrder(struct Node* root, int level, int& count) 
{ 
	if (root == NULL) 
		return; 

	if (level == 1 && root->left && root->right) 
		count++; 

	else if (level > 1) { 
		LevelOrder(root->left, level - 1, count); 
		LevelOrder(root->right, level - 1, count); 
	} 
} 

// Returns the number of full nodes 
// at a given level 
int CountFullNodes(struct Node* root, int L) 
{ 
	// Stores height of tree 
	int h = height(root); 

	// Stores count of nodes at a given level 
	// that have two children 
	int count = 0; 

	LevelOrder(root, L, count); 

	return count; 
} 

// Driver code 
int main() 
{ 
	struct Node* root = newNode(7); 
	root->left = newNode(5); 
	root->right = newNode(6); 
	root->left->left = newNode(8); 
	root->left->right = newNode(1); 
	root->left->left->left = newNode(2); 
	root->left->left->right = newNode(11); 
	root->right->left = newNode(3); 
	root->right->right = newNode(9); 
	root->right->right->right = newNode(13); 
	root->right->right->left = newNode(10); 
	root->right->right->right->left = newNode(4); 
	root->right->right->right->right = newNode(12); 

	int L = 3; 

	cout << CountFullNodes(root, L); 

	return 0; 
} 
