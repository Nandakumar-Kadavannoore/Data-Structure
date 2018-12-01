// CPP program to find Levelorder 
// Predecessor of given node in the 
// Binary Tree 

#include <bits/stdc++.h> 
using namespace std; 

// Tree Node 
struct Node { 
	struct Node *left, *right; 
	int value; 
}; 

// Utility function to create a 
// new node with given value 
struct Node* newNode(int value) 
{ 
	Node* temp = new Node; 
	temp->left = temp->right = NULL; 
	temp->value = value; 

	return temp; 
} 

// Function to find the Level Order Predecessor 
// of a given Node in Binary Tree 
Node* levelOrderPredecessor(Node* root, Node* key) 
{ 
	// Base Case 
	if (root == NULL) 
		return NULL; 

	// If root equals to key 
	if (root == key) { 

		// There is no Predecessor of 
		// root node 
		return NULL; 
	} 

	// Create an empty queue for level 
	// order traversal 
	queue<Node*> q; 

	// Enqueue Root 
	q.push(root); 

	// Temporary node to keep track of the 
	// last node 
	Node* prev = NULL; 

	while (!q.empty()) { 
		Node* nd = q.front(); 
		q.pop(); 

		if (nd == key) 
			break; 
		else
			prev = nd; 

		if (nd->left != NULL) { 
			q.push(nd->left); 
		} 

		if (nd->right != NULL) { 
			q.push(nd->right); 
		} 
	} 

	return prev; 
} 

// Driver code 
int main() 
{ 
	struct Node* root = newNode(20); 
	root->left = newNode(10); 
	root->left->left = newNode(4); 
	root->left->right = newNode(18); 
	root->right = newNode(26); 
	root->right->left = newNode(24); 
	root->right->right = newNode(27); 
	root->left->right->left = newNode(14); 
	root->left->right->left->left = newNode(13); 
	root->left->right->left->right = newNode(15); 
	root->left->right->right = newNode(19); 

	struct Node* key = root->left->right->right; 

	struct Node* res = levelOrderPredecessor(root, key); 

	if (res) 
		cout << "LevelOrder Predecessor of " << key->value 
			<< " is " << res->value; 
	else
		cout << "LevelOrder Predecessor of " << key->value 
			<< " is "
			<< "NULL"; 

	return 0; 
} 
