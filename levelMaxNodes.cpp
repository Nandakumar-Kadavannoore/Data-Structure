// C++ program to print the level 
// with maximum number of nodes 

#include <bits/stdc++.h> 
using namespace std; 

// Function for DFS in a tree 
void dfs(int node, int parent, int height[], int vis[], 
		vector<int> tree[]) 
{ 
	// calculate the level of every node 
	height[node] = 1 + height[parent]; 

	// mark every node as visited 
	vis[node] = 1; 

	// iterate in the subtree 
	for (auto it : tree[node]) { 

		// if the node is not visited 
		if (!vis[it]) { 

			// call the dfs function 
			dfs(it, node, height, vis, tree); 
		} 
	} 
} 

// Function to insert edges 
void insertEdges(int x, int y, vector<int> tree[]) 
{ 
	tree[x].push_back(y); 
	tree[y].push_back(x); 
} 

// Function to print all levels 
void printLevelswithMaximumNodes(int N, int vis[], int height[]) 
{ 
	int mark[N + 1]; 
	memset(mark, 0, sizeof mark); 

	int maxLevel = 0; 
	for (int i = 1; i <= N; i++) { 

		// count number of nodes 
		// in every level 
		if (vis[i]) 
			mark[height[i]]++; 

		// find the maximum height of tree 
		maxLevel = max(height[i], maxLevel); 
	} 

	int maxi = 0; 

	for (int i = 1; i <= maxLevel; i++) { 
		maxi = max(mark[i], maxi); 
	} 

	// print even number of nodes 
	cout << "The levels with maximum number of nodes are: "; 
	for (int i = 1; i <= maxLevel; i++) { 
		if (mark[i] == maxi) 
			cout << i << " "; 
	} 
} 

// Driver Code 
int main() 
{ 
	// Construct the tree 

	/* 1 
	/ \ 
	2 3 
	/ \ \ 
4 5 6 
	/ \ / 
	7 8 9 */

	const int N = 9; 

	vector<int> tree[N + 1]; 

	insertEdges(1, 2, tree); 
	insertEdges(1, 3, tree); 
	insertEdges(2, 4, tree); 
	insertEdges(2, 5, tree); 
	insertEdges(5, 7, tree); 
	insertEdges(5, 8, tree); 
	insertEdges(3, 6, tree); 
	insertEdges(6, 9, tree); 

	int height[N + 1]; 
	int vis[N + 1] = { 0 }; 

	height[0] = 0; 

	// call the dfs function 
	dfs(1, 0, height, vis, tree); 

	// Function to print 
	printLevelswithMaximumNodes(N, vis, height); 

	return 0; 
} 
