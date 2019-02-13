// C++ program to print first shortest 
// root to leaf path 
#include <bits/stdc++.h> 
using namespace std; 

// Binary tree node 
struct Node { 
	struct Node* left; 
	struct Node* right; 
	int data; 
}; 

// Function to create a new 
// Binary node 
struct Node* newNode(int data) 
{ 
	struct Node* temp = new Node; 

	temp->data = data; 
	temp->left = NULL; 
	temp->right = NULL; 

	return temp; 
} 

// Recursive function used by leftMostShortest 
// to print the first shortest root to leaf path 
void printPath(int Data, unordered_map<int, 
							int> parent) 
{ 
	// If the root's data is same as 
	// its parent data then return 
	if (parent[Data] == Data) 
		return; 

	// Recur for the function printPath 
	printPath(parent[Data], parent); 

	// Print the parent node's data 
	cout << parent[Data] << " "; 
} 

// Function to perform level order traversal 
// until we find the first leaf node 
void leftMostShortest(struct Node* root) 
{ 
	// Queue to store the nodes 
	queue<struct Node*> q; 

	// Push the root node 
	q.push(root); 

	// Initialize the value of first 
	// leaf node to occur as -1 
	int LeafData = -1; 

	// To store the current node 
	struct Node* temp = NULL; 

	// Map to store the parent node's data 
	unordered_map<int, int> parent; 

	// Parent of root data is set as it's 
	// own value 
	parent[root->data] = root->data; 

	// We store first node of the smallest level 
	while (!q.empty()) { 
		temp = q.front(); 
		q.pop(); 

		// If the first leaf node has been found 
		// set the flag variable as 1 
		if (!temp->left && !temp->right) { 
			LeafData = temp->data; 
			break; 
		} 
		else { 

			// If current node has left 
			// child, push in the queue 
			if (temp->left) { 
				q.push(temp->left); 

				// Set temp's left node's parent as temp 
				parent[temp->left->data] = temp->data; 
			} 

			// If current node has right 
			// child, push in the queue 
			if (temp->right) { 
				q.push(temp->right); 

				// Set temp's right node's parent 
				// as temp 
				parent[temp->right->data] = temp->data; 
			} 
		} 
	} 

	// Recursive function to print the first 
	// shortest root to leaf path 
	printPath(LeafData, parent); 

	// Print the leaf node of the first 
	// shortest path 
	cout << LeafData << " "; 
} 

// Driver code 
int main() 
{ 
	struct Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->right->left = newNode(5); 
	root->right->right = newNode(7); 
	root->left->left->left = newNode(10); 
	root->left->left->right = newNode(11); 
	root->right->right->left = newNode(8); 

	leftMostShortest(root); 

	return 0; 
} 
