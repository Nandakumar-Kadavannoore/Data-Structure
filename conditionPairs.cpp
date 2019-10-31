// C++ implementation of the approach 
#include <bits/stdc++.h> 
#define MAX 100001 
using namespace std; 

// Structure to hold details of 
// each interval 
typedef struct
{ 
	int l, r, v; 
} interval; 

// Comparator to sort intervals 
// based on velocity 
bool cmp(interval a, interval b) 
{ 
	return a.v < b.v; 
} 

// Function that returns true if the 
// assignment of directions is possible 
bool isPossible(int range[][3], int N) 
{ 
	interval test[N]; 
	for (int i = 0; i < N; i++) { 
		test[i].l = range[i][0]; 
		test[i].r = range[i][1]; 
		test[i].v = range[i][2]; 
	} 

	// Sort the intervals based on velocity 
	sort(test, test + N, cmp); 

	for (int i = 0; i < N; i++) { 
		int count[MAX] = { 0 }; 
		int current_velocity = test[i].v; 

		int j = i; 

		// Test the condition for all intervals 
		// with same velocity 
		while (j < N && test[j].v == current_velocity) { 
			for (int k = test[j].l; k <= test[j].r; k++) { 
				count[k]++; 

				// If for any velocity, 3 or more intervals 
				// share a common point return false 
				if (count[k] >= 3) 
					return false; 
			} 
			j++; 
		} 

		i = j - 1; 
	} 

	return true; 
} 

// Driver code 
int main() 
{ 
	int range[][3] = { { 1, 2, 3 }, 
					{ 2, 5, 1 }, 
					{ 3, 10, 1 }, 
					{ 4, 4, 1 }, 
					{ 5, 7, 10 } }; 
	int n = sizeof(range) / sizeof(range[0]); 

	if (isPossible(range, n)) 
		cout << "Yes"; 
	else
		cout << "No"; 

	return 0; 
} 
