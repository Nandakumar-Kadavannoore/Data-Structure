// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of
// elements required to be removed from
// the ends of an array to obtain a sum K
int minSizeArr(int A[], int N, int K)
{
	// Number of elements removed from the
	// left and right ends of the array
	int leftTaken = N, rightTaken = N;

	// Sum of left and right subarrays
	int leftSum = 0, rightSum = 0;

	// No element is taken from left initially
	for (int left = -1; left < N; left++) {

		if (left != -1)
			leftSum += A[left];

		rightSum = 0;

		// Start taking elements from right side
		for (int right = N - 1; right > left; right--) {

			rightSum += A[right];

			if (leftSum + rightSum == K) {

				// (left + 1): Count of elements
				// removed from the left
				// (N-right): Count of elements
				// removed from the right
				if (leftTaken + rightTaken
					> (left + 1) + (N - right)) {

					leftTaken = left + 1;
					rightTaken = N - right;
				}
				break;
			}
			// If sum is greater than K
			if (leftSum + rightSum > K)
				break;
		}
	}

	if (leftTaken + rightTaken <= N) {

		for (int i = 0; i < leftTaken; i++)
			cout << A[i] << " ";
		for (int i = 0; i < rightTaken; i++)
			cout << A[N - i - 1] << " ";
	}

	// If it is not possible to obtain sum K
	else
		cout << -1;
}

// Driver Code
int main()
{
	int N = 7;

	// Given Array
	int A[] = { 3, 2, 1, 1, 1, 1, 3 };

	// Given target sum
	int K = 10;

	minSizeArr(A, N, K);

	return 0;
}
