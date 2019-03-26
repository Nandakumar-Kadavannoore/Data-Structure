// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

int recamanGenerator(int arr[], int n) 
{ 
	// First term of the sequence is always 0 
	arr[0] = 0; 

	// Fill remaining terms using recursive 
	// formula 
	for (int i = 1; i <= n; i++) { 
		int temp = arr[i - 1] - i; 
		int j; 

		for (j = 0; j < i; j++) { 

			// If arr[i-1] - i is negative or 
			// already exists 
			if ((arr[j] == temp) || temp < 0) { 
				temp = arr[i - 1] + i; 
				break; 
			} 
		} 

		arr[i] = temp; 
	} 
} 

// Function that returns minimum changes required 
int recamanArray(int arr[], int n) 
{ 

	// Set to store first n Recaman numbers 
	unordered_set<int> s; 

	// Generate and store 
	// first n Recaman numbers 
	int recaman[n]; 
	recamanGenerator(recaman, n); 

	// Insert first n Recaman numbers to set 
	for (int i = 0; i < n; i++) 
		s.insert(recaman[i]); 

	for (int i = 0; i < n; i++) { 

		// If current element of the array 
		// is present in the set 
		auto it = s.find(arr[i]); 
		if (it != s.end()) 
			s.erase(it); 
	} 

	// Return the remaining number of 
	// elements in the set 
	return s.size(); 
} 

// Driver code 
int main() 
{ 

	int arr[] = { 7, 11, 20, 4, 2, 1, 8, 6 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	cout << recamanArray(arr, n); 

	return 0; 
} 
