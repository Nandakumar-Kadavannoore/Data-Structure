// C++ program to print postorder traversal 
// iteratively 

#include <bits/stdc++.h> 
using namespace std; 

// Binary Tree Node 
struct Node { 
	int data; 
	struct Node* left; 
	struct Node* right; 
}; 

// Helper function to create a 
// new Binary Tree node 
struct Node* newNode(int data) 
{ 
	struct Node* node = new Node; 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	return (node); 
} 

// Function to perform postorder 
// traversal iteratively 
void iterativePostorder(Node* root) 
{ 
	stack<pair<Node*, int> > st; 
	st.push(make_pair(root, 0)); 

	while (!st.empty()) { 
		struct Node* temp = st.top().first; 
		int b = st.top().second; 
		st.pop(); 

		if (temp == NULL) 
			continue; 

		if (b == 0) { 
			st.push(make_pair(temp, 1)); 

			if (temp->left != NULL) 
				st.push(make_pair(temp->left, 0)); 
		} 
		else if (b == 1) { 
			st.push(make_pair(temp, 2)); 

			if (temp->right != NULL) 
				st.push(make_pair(temp->right, 0)); 
		} 
		else
			cout << temp->data << " "; 
	} 
} 

// Driver Code 
int main() 
{ 
	// Construct the below Binary Tree 
	//	 1 
	//	 / \ 
	//	 2 3 
	// / \ 
	// 4	 5 
	Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 

	iterativePostorder(root); 

	return 0; 
} 
