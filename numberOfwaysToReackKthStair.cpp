// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

const int MOD = 1000000007; 

// Function to return the number 
// of ways to reach the kth step 
int number_of_ways(int arr[], int n, int k) 
{ 
	if (k == 1) 
		return 1; 

	// Create the dp array 
	int dp[k + 1]; 
	memset(dp, -1, sizeof dp); 

	// Broken steps 
	for (int i = 0; i < n; i++) 
		dp[arr[i]] = 0; 

	dp[0] = 1; 
	dp[1] = (dp[1] == -1) ? 1 : dp[1]; 

	// Calculate the number of ways for 
	// the rest of the positions 
	for (int i = 2; i <= k; ++i) { 

		// If it is a blocked position 
		if (dp[i] == 0) 
			continue; 

		// Number of ways to get to the ith step 
		dp[i] = dp[i - 1] + dp[i - 2]; 

		dp[i] %= MOD; 
	} 

	// Return the required answer 
	return dp[k]; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 3 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 6; 

	cout << number_of_ways(arr, n, k); 

	return 0; 
} 
