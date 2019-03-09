// C++ program to find number 
// of siblings of a given node 
#include <bits/stdc++.h> 
using namespace std; 

// Represents a node of an n-ary tree 
class Node { 
public: 
	int key; 
	vector<Node*> child; 

	Node(int data) 
	{ 
		key = data; 
	} 
}; 

// Function to calculate number 
// of siblings of a given node 
int numberOfSiblings(Node* root, int x) 
{ 
	if (root == NULL) 
		return 0; 

	// Creating a queue and 
	// pushing the root 
	queue<Node*> q; 
	q.push(root); 

	while (!q.empty()) { 
		// Dequeue an item from queue and 
		// check if it is equal to x If YES, 
		// then return number of children 
		Node* p = q.front(); 
		q.pop(); 

		// Enqueue all children of 
		// the dequeued item 
		for (int i = 0; i < p->child.size(); i++) { 
			// If the value of children 
			// is equal to x, then return 
			// the number of siblings 
			if (p->child[i]->key == x) 
				return p->child.size() - 1; 
			q.push(p->child[i]); 
		} 
	} 
} 

// Driver program 
int main() 
{ 
	// Creating a generic tree as shown in above figure 
	Node* root = new Node(50); 
	(root->child).push_back(new Node(2)); 
	(root->child).push_back(new Node(30)); 
	(root->child).push_back(new Node(14)); 
	(root->child).push_back(new Node(60)); 
	(root->child[0]->child).push_back(new Node(15)); 
	(root->child[0]->child).push_back(new Node(25)); 
	(root->child[0]->child[1]->child).push_back(new Node(70)); 
	(root->child[0]->child[1]->child).push_back(new Node(100)); 
	(root->child[1]->child).push_back(new Node(6)); 
	(root->child[1]->child).push_back(new Node(1)); 
	(root->child[2]->child).push_back(new Node(7)); 
	(root->child[2]->child[0]->child).push_back(new Node(17)); 
	(root->child[2]->child[0]->child).push_back(new Node(99)); 
	(root->child[2]->child[0]->child).push_back(new Node(27)); 
	(root->child[3]->child).push_back(new Node(16)); 

	// Node whose number of 
	// siblings is to be calculated 
	int x = 100; 

	// Function calling 
	cout << numberOfSiblings(root, x) << endl; 

	return 0; 
} 
