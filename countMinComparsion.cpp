// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the count of comparisons from left to right 
// and right to left in linear search among m queries 
pair<int, int> countCamparisions(int n, int arr[], int m, int qry[]) 
{ 
	int i; 
	unordered_map<int, int> index; 
	for (i = 1; i <= n; i++) { 

		// arr[i] occurs at i 
		index[arr[i]] = i; 
	} 

	// Count of comparisons for left to right and right to left 
	int ltr = 0, rtl = 0; 
	for (i = 1; i <= m; i++) { 
		int x = qry[i]; 
		ltr += index[x]; 
		rtl += n - index[x] + 1; 
	} 
	return make_pair(ltr, rtl); 
} 

// Driver Code 
int main() 
{ 
	// -1 will be ignored as it is 1-based indexing 
	int arr[] = { -1, 2, 4, 5, 1 }; 
	int n = (sizeof(arr) / sizeof(arr[0])) - 1; 

	int q[] = { -1, 4, 2 }; 
	int m = (sizeof(q) / sizeof(q[0])) - 1; 

	pair<int, int> res = countCamparisions(n, arr, m, q); 
	cout << res.first << " " << res.second; 
} 
