// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the factorial of
// a number N
int fact(int N)
{
	// Base Case
	if (N == 1 || N == 0)
		return 1;

	// Find the factorial recursively
	return N * fact(N - 1);
}

// Function to find the prefix
// factorial array
void prefixFactorialArray(int arr,
						int N)
{
	// Find the prefix sum array
	for (int i = 1; i < N; i++) {
		arr[i] += arr[i - 1];
	}

	// Find the factorials of each
	// array element
	for (int i = 0; i < N; i++) {
		arr[i] = fact(arr[i]);
	}

	// Print the resultant array
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
}

// Driver Code
int main()
{
	int arr[] = { 1, 2, 3, 4 };
	int N = sizeof(arr) / sizeof(arr[0]);
	prefixFactorialArray(arr, N);

	return 0;
}
