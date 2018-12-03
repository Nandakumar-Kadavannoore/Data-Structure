// C++ program to find minimum range 
// increments to sort an array 

#include <bits/stdc++.h> 
using namespace std; 

// Function to find minimum range 
// increments to sort an array 
int minMovesToSort(int arr[], int n) 
{ 
	int moves = 0; 

	int i, mn = arr[n - 1]; 

	for (i = n - 2; i >= 0; i--) { 

		// If current element is found greater than 
		// last element 
		// Increment all terms in 
		// range i+1 to n-1 
		if (arr[i] > mn) 
			moves += arr[i] - mn; 

		mn = arr[i]; // Minimum in range i to n-1 
	} 

	return moves; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = { 3, 5, 2, 8, 4 }; 

	int n = sizeof(arr) / sizeof(arr[0]); 

	cout << minMovesToSort(arr, n); 

	return 0; 
} 
