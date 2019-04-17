// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Tree node structure 
struct Node { 
	int data; 
	Node *left, *right; 
}; 

struct Node* newNode(int data) 
{ 
	struct Node* node = new Node; 
	node->data = data; 
	node->left = node->right = NULL; 

	return (node); 
} 

// Function to find height of a tree 
int height(Node* root, int& ans) 
{ 
	if (root == NULL) 
		return 0; 

	int left_height = height(root->left, ans); 

	int right_height = height(root->right, ans); 

	// Update the answer, because diameter of a 
	// tree is nothing but maximum value of 
	// (left_height + right_height + 1) for each node 
	ans = max(ans, 1 + left_height + right_height); 

	return 1 + max(left_height, right_height); 
} 

// Computes the diameter of binary tree 
// with given root 
int diameter(Node* root) 
{ 
	if (root == NULL) 
		return 0; 

	// Variable to store the final answer 
	int ans = INT_MIN; 

	int height_of_tree = height(root, ans); 
	return ans; 
} 

// Driver code 
int main() 
{ 
	struct Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 

	printf("%d", diameter(root)); 

	return 0; 
} 
