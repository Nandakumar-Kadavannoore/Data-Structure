// C++ implementation of above approach 

#include <bits/stdc++.h> 
using namespace std; 

// Function to return length of 
// smallest subarray containing both 
// maximum and minimum value 
int minSubarray(int A[], int n) 
{ 

	// find maximum and minimum 
	// values in the array 
	int minValue = *min_element(A, A + n); 
	int maxValue = *max_element(A, A + n); 

	int pos_min = -1, pos_max = -1, ans = INT_MAX; 

	// iterate over the array and set answer 
	// to smallest difference between position 
	// of maximum and position of minimum value 
	for (int i = 0; i < n; i++) { 

		// last occurrence of minValue 
		if (A[i] == minValue) 
			pos_min = i; 

		// last occurrence of maxValue 
		if (A[i] == maxValue) 
			pos_max = i; 

		if (pos_max != -1 or pos_min != -1) 
			ans = min(ans, abs(pos_min - pos_max) + 1); 
	} 

	return ans; 
} 

// Driver code 
int main() 
{ 
	int A[] = { 1, 5, 9, 7, 1, 9, 4 }; 
	int n = sizeof(A) / sizeof(A[0]); 

	cout << minSubarray(A, n); 

	return 0; 
} 
