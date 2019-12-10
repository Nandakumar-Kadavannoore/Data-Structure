// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Structure for the node of the tree 
struct Tree { 
	int val; 
	Tree* left; 
	Tree* right; 
	Tree(int _val) 
	{ 
		val = _val; 
		left = NULL; 
		right = NULL; 
	} 
}; 

// Dfs Function 
void dfs(Tree* node, int maxx, int& count) 
{ 
	// Base case 
	if (node == NULL) { 
		return; 
	} 
	else { 

		// Increment the count if the current 
		// node's value is greater than the 
		// maximum value in it's ancestors 
		if (node->val > maxx) 
			count++; 

		// Left traversal 
		dfs(node->left, max(maxx, node->val), count); 

		// Right traversal 
		dfs(node->right, max(maxx, node->val), count); 
	} 
} 

// Driver code 
int main() 
{ 

	Tree* root = new Tree(4); 
	root->left = new Tree(5); 
	root->right = new Tree(2); 
	root->right->left = new Tree(3); 
	root->right->right = new Tree(6); 

	// To store the required count 
	int count = 0; 

	dfs(root, INT_MIN, count); 

	cout << count; 

	return 0; 
} 
