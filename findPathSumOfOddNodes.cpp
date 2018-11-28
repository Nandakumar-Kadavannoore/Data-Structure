// C++ program to find sum of all odd nodes 
// in the path connecting two given nodes 

#include<bits/stdc++.h> 
using namespace std; 

// Binary Tree node 
struct Node 
{ 
	int data; 
	struct Node* left; 
	struct Node* right; 
}; 

// Utitlity function to create a 
// new Binary Tree node 
struct Node* newNode(int data) 
{ 
	struct Node* node = new Node; 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	
	return node; 
} 

// Function to check if there is a path from root 
// to the given node. It also populates 
// 'arr' with the given path 
bool getPath(Node* root, vector<int>& arr, int x) 
{ 
	// if root is NULL 
	// there is no path 
	if (!root) 
		return false; 

	// push the node's value in 'arr' 
	arr.push_back(root->data); 

	// if it is the required node 
	// return true 
	if (root->data == x) 
		return true; 

	// else check whether the required node lies 
	// in the left subtree or right subtree of 
	// the current node 
	if (getPath(root->left, arr, x) || getPath(root->right, arr, x)) 
		return true; 

	// required node does not lie either in the 
	// left or right subtree of the current node 
	// Thus, remove current node's value from 
	// 'arr'and then return false 
	arr.pop_back(); 
	return false; 
} 

// Function to get the sum of odd nodes in the 
// path between any two nodes in a binary tree 
int sumOddNodes(Node* root, int n1, int n2) 
{ 
	// vector to store the path of 
	// first node n1 from root 
	vector<int> path1; 

	// vector to store the path of 
	// second node n2 from root 
	vector<int> path2; 

	getPath(root, path1, n1); 
	getPath(root, path2, n2); 

	int intersection = -1; 

	// Get intersection point 
	int i = 0, j = 0; 
	while (i != path1.size() || j != path2.size()) { 

		// Keep moving forward until no intersection 
		// is found 
		if (i == j && path1[i] == path2[j]) { 
			i++; 
			j++; 
		} 
		else { 
			intersection = j - 1; 
			break; 
		} 
	} 
	
	int sum = 0; 
	
	// claculate sum of ODD nodes from the path 
	for (int i = path1.size() - 1; i > intersection; i--) 
		if(path1[i]%2) 
			sum += path1[i]; 

	for (int i = intersection; i < path2.size(); i++) 
		if(path2[i]%2) 
			sum += path2[i]; 
			
	return sum;		 
} 

// Driver Code 
int main() 
{ 
	struct Node* root = newNode(1); 
	
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->right = newNode(6); 
	
	int node1 = 5; 
	int node2 = 6; 
	
	cout<<sumOddNodes(root, node1, node2); 
	
	return 0; 
} 
