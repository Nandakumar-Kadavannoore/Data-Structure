// CPP program to print maximum element 
// among all right child nodes 
#include <bits/stdc++.h> 
using namespace std; 

// A Binary Tree Node 
struct Node { 
	int data; 
	struct Node *left, *right; 
}; 

// Utility function to create a new tree node 
Node* newNode(int data) 
{ 
	Node* temp = new Node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Function to find maximum element 
// among all right child nodes using 
// Inorder Traversal 
int maxOfRightElement(Node* root) 
{ 
	// Temp variable 
	int res = INT_MIN; 

	// If tree is empty 
	if (root == NULL) 
		return -1; 

	// If right child exists 
	if (root->right != NULL) 
		res = root->right->data; 

	// Return maximum of three values 
	// 1) Recursive max in right subtree 
	// 2) Value in right child node 
	// 3) Recursive max in left subtree 
	return max({ maxOfRightElement(root->right), 
				res, 
				maxOfRightElement(root->left) }); 
} 

// Driver Code 
int main() 
{ 
	// Create binary tree 
	// as shown below 

	/* 7 
		/ \ 
	6 5 
	/ \ / \ 
	4 3 2 1 */
	Node* root = newNode(7); 
	root->left = newNode(6); 
	root->right = newNode(5); 
	root->left->left = newNode(4); 
	root->left->right = newNode(3); 
	root->right->left = newNode(2); 
	root->right->right = newNode(1); 

	cout << maxOfRightElement(root); 

	return 0; 
} 
