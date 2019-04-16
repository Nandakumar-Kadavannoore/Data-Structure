// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Structure for a binary tree node 
struct Node { 
	int key; 
	Node *left, *right; 
}; 

// A utility function to create a new node 
Node* newNode(int key) 
{ 
	Node* node = new Node; 
	node->key = key; 
	node->left = node->right = NULL; 
	return node; 
} 

// Function to find kth node 
// in vertcial order traversal 
int KNodeVerticalOrder(Node* root, int k) 
{ 
	// Base case 
	if (!root || k == 0) 
		return -1; 

	int n = 0; 

	// Variable to store kth node 
	int k_node = -1; 

	// Create a map and store vertical order in 
	// map 
	map<int, vector<int> > m; 
	int hd = 0; 

	// Create queue to do level order traversal 
	// Every item of queue contains node and 
	// horizontal distance 
	queue<pair<Node*, int> > que; 
	que.push(make_pair(root, hd)); 

	while (!que.empty()) { 
		// Pop from queue front 
		pair<Node*, int> temp = que.front(); 
		que.pop(); 
		hd = temp.second; 
		Node* node = temp.first; 

		// Insert this node's data in vector of hash 
		m[hd].push_back(node->key); 

		if (node->left != NULL) 
			que.push(make_pair(node->left, hd - 1)); 
		if (node->right != NULL) 
			que.push(make_pair(node->right, hd + 1)); 
	} 

	// Traverse the map and find kth 
	// node 
	map<int, vector<int> >::iterator it; 
	for (it = m.begin(); it != m.end(); it++) { 
		for (int i = 0; i < it->second.size(); ++i) { 
			n++; 
			if (n == k) 
				return (it->second[i]); 
		} 
	} 

	if (k_node == -1) 
		return -1; 
} 

// Driver code 
int main() 
{ 
	Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->left = newNode(6); 
	root->right->right = newNode(7); 
	root->right->left->right = newNode(8); 
	root->right->right->right = newNode(9); 
	root->right->right->left = newNode(10); 
	root->right->right->left->right = newNode(11); 
	root->right->right->left->right->right = newNode(12); 

	int k = 5; 
	cout << KNodeVerticalOrder(root, k); 

	return 0; 
} 
