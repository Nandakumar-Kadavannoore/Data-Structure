// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to print all the levels 
// of the given tree in sorted order 
void printSortedLevels(int arr[], int n) 
{ 

	// Initialize level with 0 
	int level = 0; 
	for (int i = 0; i < n; level++) { 

		// Number of nodes at current level 
		int cnt = (int)pow(2, level); 

		// Indexing of array starts from 0 
		// so subtract no. of nodes by 1 
		cnt -= 1; 

		// Index of the last node in the current level 
		int j = min(i + cnt, n - 1); 

		// Sort the nodes of the current level 
		sort(arr + i, arr + j + 1); 

		// Print the sorted nodes 
		while (i <= j) { 
			cout << arr[i] << " "; 
			i++; 
		} 
		cout << endl; 
	} 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 5, 6, 4, 9, 2, 1 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	printSortedLevels(arr, n); 

	return 0; 
} 
