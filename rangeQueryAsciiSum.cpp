// C++ implementation of 
// the above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Structure of a node 
// of a Segment Tree 
struct treeNode { 
	int square_sum; 
}; 

// Function to construct the Segment Tree 
void buildTree(string s, treeNode* tree, 
			int start, int end, 
			int treeNode) 
{ 
	// If start and end are equal 
	if (start == end) { 

		// Assign squares of positions 
		// of the characters 
		tree[treeNode].square_sum 
			= pow(s[start] - 'a' + 1, 2); 

		return; 
	} 

	// Stores the mid value of 
	// the range [start, end] 
	int mid = start + ((end - start) / 2); 

	// Recursive call to left subtree 
	buildTree(s, tree, start, 
			mid, 2 * treeNode); 

	// Recursive call to right subtree 
	buildTree(s, tree, mid + 1, 
			end, 1 + 2 * treeNode); 

	// Update the current node 
	tree[treeNode].square_sum 
		= tree[(2 * treeNode)].square_sum 
		+ tree[(2 * treeNode) + 1].square_sum; 
} 

// Function to perform the queries of type 2 
int querySquareSum(treeNode* tree, int start, 
				int end, int treeNode, 
				int l, int r) 
{ 
	// No overlap 
	if ((l > end) || (r < start)) { 
		return 0; 
	} 

	// If l <= start and r >= end 
	if ((l <= start) && (r >= end)) { 

		// Return the value of treeNode 
		return tree[treeNode].square_sum; 
	} 

	// Calculate middle of the range [start, end] 
	int mid = start + ((end - start) / 2); 

	// Function call to left subtree 
	int X = querySquareSum(tree, start, 
						mid, 2 * treeNode, 
						l, r); 

	// Function call to right subtree 
	int Y = +querySquareSum(tree, mid + 1, end, 
							1 + 2 * treeNode, l, r); 

	// Return the sum of X and Y 
	return X + Y; 
} 

// Function to perform update 
// queries on a Segment Tree 
void updateTree(string s, treeNode* tree, 
				int start, int end, 
				int treeNode, int idx, char X) 
{ 
	// If start is equal to end 
	// and idx is equal to start 
	if ((start == end) && (idx == start)) { 

		// Base Case 
		s[idx] = X; 
		tree[treeNode].square_sum 
			= pow(X - 'a' + 1, 2); 

		return; 
	} 

	// Calculate middle of the range [start, end] 
	int mid = start + ((end - start) / 2); 

	// If idx <= mid 
	if (idx <= mid) { 

		// Function call to left subtree 
		updateTree(s, tree, start, mid, 
				(2 * treeNode), idx, X); 
	} 

	// Otherwise 
	else { 

		// Function call to the right subtree 
		updateTree(s, tree, mid + 1, end, 
				(2 * treeNode) + 1, idx, X); 
	} 

	// Update the current node 
	tree[treeNode].square_sum 
		= tree[(2 * treeNode)].square_sum 
		+ tree[(2 * treeNode) + 1].square_sum; 
} 

// Fucntion to perform the given queries 
void PerformQuery(string S, 
				vector<vector<string> > Q) 
{ 
	int n = S.size(); 

	// Stores the segment tree 
	treeNode* tree = new treeNode[(4 * n) + 1]; 

	// Traverse the segment tree 
	for (int i = 0; i <= (4 * n); i = i + 1) { 

		// Assign 0 to each node 
		tree[i].square_sum = 0; 
	} 

	// Builds segment tree 
	buildTree(S, tree, 0, n - 1, 1); 

	// Traverse the query array Q[][] 
	for (int i = 0; i < Q.size(); i++) { 

		// If query is of type S 
		if (Q[i][0] == "S") { 

			// Stores the left boundary 
			int L = stoi(Q[i][1]); 

			// Stores the right boundary 
			int R = stoi(Q[i][2]); 

			// Prints the sum of squares of the 
			// alphabetic positions of the characters 
			cout << querySquareSum(tree, 0, 
								n - 1, 1, L, R) 
				<< endl; 
		} 

		// Otherwise 
		else if (Q[i][0] == "U") { 

			// Stores the index of the 
			// character to be updated 
			int I = stoi(Q[i][1]); 

			// Update the segment tree 
			updateTree(S, tree, 0, n - 1, 
					1, I, Q[i][2][0]); 
		} 
	} 
} 

// Driver Code 
int main() 
{ 
	// Input 
	string S = "geeksforgeeks"; 
	vector<vector<string> > Q = { { "S", "0", "2" }, 
								{ "S", "1", "2" }, 
								{ "U", "1", "a" }, 
								{ "S", "0", "2" }, 
								{ "S", "4", "5" } }; 
	// Function call 
	PerformQuery(S, Q); 
}
