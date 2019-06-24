// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find the count 
// of the required nodes 
void countNodes(int N, int X) 
{ 

	// Height of the complete binary 
	// tree with n nodes 
	int height = floor(log2(N)); 

	// If X > height then no node 
	// can be present at that level 
	if (X > height) { 
		cout << "0\n0"; 
		return; 
	} 

	// Corner case 
	if (N == 1) { 
		cout << "1\n1"; 
		return; 
	} 

	// Maximum total nodes that are possible 
	// in complete binary tree with height h 
	int max_total_nodes = (1 << (height + 1)) - 1; 

	// Nodes at the last level 
	int nodes_last_level = (1 << height) - (max_total_nodes - N); 

	// To store the count of nodes 
	// x dist away from root 
	int from_root; 

	// To store the count of nodes 
	// x dist away from leaf 
	int from_leaf; 

	// If X = h then print nodes at last level 
	// else nodes at Xth level 
	if (X == height) 
		from_root = nodes_last_level; 

	// 2^X 
	else
		from_root = 1 << X; 

	// Number of left leaf nodes at (h-1)th level 
	// observe that if nodes are not present at last level 
	// then there are a/2 leaf nodes at (h-1)th level 
	int left_leaf_nodes = ((1 << height) - nodes_last_level) / 2; 

	// If X = h then print leaf nodes at the last h level 
	// + leaf nodes at (h-1)th level 
	if (X == 0) { 
		from_leaf = nodes_last_level + left_leaf_nodes; 
	} 
	else { 

		// First calculate nodes for leaves present at height h 
		int i = X; 

		while (nodes_last_level > 1 && i > 0) { 
			nodes_last_level = ceil((float)nodes_last_level / (float)2); 
			i--; 
		} 

		from_leaf = nodes_last_level; 

		// Then calculate nodes for leaves present at height h-1 
		i = X; 
		while (left_leaf_nodes > 1 && i > 0) { 
			left_leaf_nodes = ceil((float)left_leaf_nodes / (float)2); 
			i--; 
		} 

		// Add both the resuls 
		from_leaf += left_leaf_nodes; 
	} 

	cout << from_root << endl 
		<< from_leaf; 
} 

// Driver code 
int main() 
{ 
	int N = 38, X = 3; 

	countNodes(N, X); 

	return 0; 
} 
