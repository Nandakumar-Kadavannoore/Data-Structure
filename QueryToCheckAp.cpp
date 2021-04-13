// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to check if the given range
// of queries form an AP or not in the
// given array arr[]
void findAPSequence(int arr[], int N,
					int Q[][2], int M)
{
	// Stores length of the longest
	// subarray forming AP for every
	// array element
	int dp[N + 5] = { 0 };

	// Iterate over the range [0, N]
	for (int i = 0; i + 1 < N;) {

		// Stores the index of the last
		// element of forming AP
		int j = i + 1;

		// Iterate until the element at
		// index (j, j + 1) forms AP
		while (j + 1 < N
			&& arr[j + 1] - arr[j]
					== arr[i + 1] - arr[i])

			// Increment j by 1
			j++;

		// Traverse the current subarray
		// over the range [i, j - 1]
		for (int k = i; k < j; k++) {

			// Update the length of the
			// longest subarray at index k
			dp[k] = j - k;
		}

		// Update the value of i
		i = j;
	}

	// Traverse the given queries
	for (int i = 0; i < M; i++) {

		// Print the result
		if (dp[Q[i][0]]
			>= Q[i][1] - Q[i][0]) {
			cout << "Yes" << endl;
		}

		// Otherwise
		else {
			cout << "No" << endl;
		}
	}
}

// Driver Code
int main()
{
	int arr[] = { 1, 3, 5, 7, 6, 5, 4, 1 };
	int Q[][2] = { { 0, 3 }, { 3, 4 }, { 2, 4 } };
	int N = sizeof(arr) / sizeof(arr[0]);
	int M = sizeof(Q) / sizeof(Q[0]);

	findAPSequence(arr, N, Q, M);

	return 0;
}
