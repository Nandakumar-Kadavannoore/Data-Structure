// C++ program for the above approach 

#include <bits/stdc++.h> 
using namespace std; 

// Function to find the minimum number 
// of increments or decrements required 
// to convert array into a power sequence 
int minOperations(int a[], int n) 
{ 
	// Initialize the count to f(X) for X = 1 
	int ans = accumulate(a, a + n, 0) - n; 

	// Calculate the value of f(X) 
	// X ^ (n - 1) <= f(1) + a[n - 1] 
	for (int x = 1;; x++) { 

		int curPow = 1, curCost = 0; 

		// Calculate F(x) 
		for (int i = 0; i < n; i++) { 
			curCost += abs(a[i] - curPow); 
			curPow *= x; 
		} 

		// Check if X ^ (n - 1) > f(1) + a[n - 1] 
		if (curPow / x > ans + a[n - 1]) 
			break; 

		// Update ans to store the 
		// minimum of ans and F(x) 
		ans = min(ans, curCost); 
	} 

	// Return the minimum number 
	// of operations required 
	return ans; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = { 1, 5, 7 }; 
	int N = sizeof(arr) / sizeof(arr[0]); 

	cout << minOperations(arr, N); 

	return 0; 
} 
