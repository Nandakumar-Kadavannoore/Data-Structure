// C++ program to implement above approach 

#include <bits/stdc++.h> 
#define maxLen 10 
using namespace std; 

// variable to store states of dp 
int dp[maxLen]; 

// variable to check if a given state 
// has been solved 
bool v[maxLen]; 

// Function to find the maximum sum subsequence 
// such that no two elements are adjacent 
int maxSum(int arr[], int i, int n) 
{ 
	// Base case 
	if (i >= n) 
		return 0; 

	// To check if a state has 
	// been solved 
	if (v[i]) 
		return dp[i]; 
	v[i] = 1; 

	// Required recurrence relation 
	dp[i] = max(maxSum(arr, i + 1, n), 
				arr[i] + maxSum(arr, i + 2, n)); 

	// Returning the value 
	return dp[i]; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 12, 9, 7, 33 }; 

	int n = sizeof(arr) / sizeof(int); 

	cout << maxSum(arr, 0, n); 

	return 0; 
} 
