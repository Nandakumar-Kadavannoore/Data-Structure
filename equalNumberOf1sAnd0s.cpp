// C++ implementation of the approach 
#include <iostream> 
using namespace std; 

// To store whether the tree contains a sub-tree 
// with equal number of 0's and 1's 
bool hasValidSubTree = false; 

// Represents a node of the tree 
struct node { 
	int data; 
	struct node *right, *left; 
}; 

// To create a new node 
struct node* newnode(int key) 
{ 
	struct node* temp = new node; 
	temp->data = key; 
	temp->right = NULL; 
	temp->left = NULL; 
	return temp; 
} 

// Function to perform inorder traversal on 
// the tree and print the nodes in that order 
void inorder(struct node* root) 
{ 
	if (root == NULL) 
		return; 
	inorder(root->left); 
	cout << root->data << endl; 
	inorder(root->right); 
} 

// Function to return the size of the 
// sub-tree rooted at the current node 
int size(struct node* root) 
{ 

	int a = 0, b = 0; 

	// If root is null or the valid sub-tree 
	// has already been found 
	if (root == NULL || hasValidSubTree) 
		return 0; 

	// Size of the right sub-tree 
	a = size(root->right); 

	// 1 is added for the parent 
	a = a + 1; 

	// Size of the left sub-tree 
	b = size(root->left); 

	// Total size of the tree 
	// rooted at the current node 
	a = b + a; 

	// If the current tree has equal 
	// number of 0's and 1's 
	if (a % 2 == 0 && root->data == a / 2) 
		hasValidSubTree = true; 

	return a; 
} 

// Function to update and return the sum 
// of all the tree nodes rooted at 
// the passed node 
int sum_tree(struct node* root) 
{ 
	if (root == NULL) 
		return 0; 

	int a = 0, b = 0; 

	// If left child exists 
	if (root->left != NULL) 
		a = sum_tree(root->left); 

	// If right child exists 
	if (root->right != NULL) 
		b = sum_tree(root->right); 
	root->data += (a + b); 

	return root->data; 
} 

// Driver code 
int main() 
{ 
	struct node* root = newnode(1); 
	root->right = newnode(0); 
	root->right->right = newnode(1); 
	root->right->right->right = newnode(1); 
	root->left = newnode(0); 
	root->left->left = newnode(1); 
	root->left->left->left = newnode(1); 
	root->left->right = newnode(0); 
	root->left->right->left = newnode(1); 
	root->left->right->left->left = newnode(1); 
	root->left->right->right = newnode(0); 
	root->left->right->right->left = newnode(1); 
	root->left->right->right->left->left = newnode(1); 

	sum_tree(root); 
	size(root); 

	if (hasValidSubTree) 
		cout << "Yes"; 
	else
		cout << "No"; 

	return 0; 
} 
