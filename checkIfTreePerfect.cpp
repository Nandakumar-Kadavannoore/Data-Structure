// C++ program to check if the 
// given binary tree is perfect 
#include <bits/stdc++.h> 
using namespace std; 

// A binary tree node 
struct Node { 
	int data; 
	Node *left, *right; 
}; 

// Utility function to allocate memory for a new node 
Node* newNode(int data) 
{ 
	Node* node = new (Node); 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

// Function to check if the given tree is perfect 
bool CheckPerfectTree(Node* root) 
{ 
	queue<Node*> q; 

	// Push the root node 
	q.push(root); 

	// Flag to check if leaf nodes have been found 
	int flag = 0; 

	while (!q.empty()) { 
		Node* temp = q.front(); 
		q.pop(); 

		// If current node has both left and right child 
		if (temp->left && temp->right) { 
			// If a leaf node has already been found 
			// then return false 
			if (flag == 1) 
				return false; 

			// If a leaf node has not been discovered yet 
			// push the left and right child in the queue 
			else { 
				q.push(temp->left); 
				q.push(temp->right); 
			} 
		} 

		// If a leaf node is found mark flag as one 
		else if (!temp->left && !temp->right) { 
			flag = 1; 
		} 

		// If the current node has only one child 
		// then return false 
		else if (!temp->left || !temp->right) 
			return false; 
	} 

	// If the given tree is perfect return true 
	return true; 
} 

// Driver code 
int main() 
{ 
	Node* root = newNode(7); 
	root->left = newNode(5); 
	root->right = newNode(6); 
	root->left->left = newNode(8); 
	root->left->right = newNode(1); 
	root->right->left = newNode(3); 
	root->right->right = newNode(9); 
	root->right->right->right = newNode(13); 
	root->right->right->left = newNode(10); 

	if (CheckPerfectTree(root)) 
		printf("Yes"); 
	else
		printf("No"); 

	return 0; 
} 
