// C++ Program to implement
// the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find maximum difference
// between adjacent array elements
int maxAdjacentDifference(vector<int> A)
{
	// Store the maximum difference
	int diff = 0;

// Traverse the array
	for (int i = 1; i < (int)A.size(); i++) {

		// Update maximum difference
		diff = max(diff, A[i] - A[i - 1]);
	}

	return diff;
}

// Function to calculate the minimum
// of maximum difference between
// adjacent array elements possible
// by removing a single array element
int MinimumValue(int arr[], int N)
{
	// Stores the required minimum
	int MinValue = INT_MAX;

	for (int i = 0; i < N; i++) {

		// Stores the updated array
		vector<int> new_arr;

		for (int j = 0; j < N; j++) {

			// Skip the i-th element
			if (i == j)
				continue;

			new_arr.push_back(arr[j]);
		}

		// Update MinValue
		MinValue
			= min(MinValue,
				maxAdjacentDifference(new_arr));
	}

	// return MinValue
	return MinValue;
}

// Driver Code
int main()
{
	int arr[] = { 1, 3, 7, 8 };
	int N = sizeof(arr) / sizeof(int);
	cout << MinimumValue(arr, N);

	return 0;
}
