// C++ program for the above approach 

#include <bits/stdc++.h> 
using namespace std; 

// Function to count maximum number 
// of cars parked at the same 
int maxCars(int arr[][2], int N) 
{ 
	// Stores info about 
	// entry and exit times 
	pair<int, bool> a[2 * N]; 

	// Convert given array to new array 
	for (int i = 0; i < N; i++) { 
		a[2 * i] = { arr[i][0], true }; 
		a[2 * i + 1] = { arr[i][1], false }; 
	} 

	// Sort array in ascending 
	// order of time 
	sort(a, a + 2 * N); 

	// Stores current maximum 
	// at every iteration 
	int curMax = 0; 

	// Stores final maximum number 
	// of cars parked at any time 
	int maxFinal = 0; 

	// Traverse the array 
	for (int i = 0; i < 2 * N; ++i) { 

		// When car entered 
		if (a[i].second) { 
			curMax++; 
		} 

		// When car exits 
		else { 
			if (curMax > maxFinal) { 
				maxFinal = curMax; 
			} 
			curMax--; 
		} 
	} 

	// Print the answer 
	cout << maxFinal; 
} 

// Driver Code 
int main() 
{ 
	// Given array 
	int arr[][2] = { { 1012, 1136 }, 
					{ 1317, 1412 }, 
					{ 1015, 1020 } }; 

	// Size of the array 
	int N = sizeof(arr) / sizeof(arr[0]); 

	// Function Call 
	maxCars(arr, N); 

	return 0; 
}
