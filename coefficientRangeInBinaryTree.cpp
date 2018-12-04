// CPP program to find Coefficient of 
// Range in a Bianry Tree 

#include <bits/stdc++.h> 
using namespace std; 

// A tree node 
struct Node { 
	float data; 
	struct Node *left, *right; 
}; 

// A utility function to create a new node 
struct Node* newNode(float data) 
{ 
	struct Node* node = (struct Node*) 
		malloc(sizeof(struct Node)); 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

// Returns maximum value in a given Binary Tree 
float findMax(struct Node* root) 
{ 
	// Base case 
	if (root == NULL) 
		return INT_MIN; 

	// Return maximum of 3 values: 
	// 1) Root's data 2) Max in Left Subtree 
	// 3) Max in right subtree 
	float res = root->data; 
	float lres = findMax(root->left); 
	float rres = findMax(root->right); 
	if (lres > res) 
		res = lres; 
	if (rres > res) 
		res = rres; 

	return res; 
} 

// Returns minimum value in a given Binary Tree 
float findMin(struct Node* root) 
{ 
	// Base case 
	if (root == NULL) 
		return INT_MAX; 

	// Return minimum of 3 values: 
	// 1) Root's data 2) Min in Left Subtree 
	// 3) Min in right subtree 
	float res = root->data; 
	float lres = findMin(root->left); 
	float rres = findMin(root->right); 
	if (lres < res) 
		res = lres; 
	if (rres < res) 
		res = rres; 

	return res; 
} 

// Function to find the value of the Coefficient 
// of range in the Binary Tree 
float coefRange(Node* root) 
{ 
	float max = findMax(root); 
	float min = findMin(root); 

	return (max - min) / (max + min); 
} 

// Driver Code 
int main(void) 
{ 
	// Contruct the Binary Tree 
	struct Node* root = newNode(2); 
	root->left = newNode(7); 
	root->right = newNode(5); 
	root->left->right = newNode(6); 
	root->left->right->left = newNode(1); 
	root->left->right->right = newNode(11); 
	root->right->right = newNode(9); 
	root->right->right->left = newNode(4); 

	cout << "Coefficient of Range is " << coefRange(root); 

	return 0; 
} 
