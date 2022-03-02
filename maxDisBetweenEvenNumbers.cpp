// C++ program to of the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum
// distance between any two occurrence
// of even integers in the given array
int maximizeDistance(int arr[], int n)
{
	// Stores the index of
	// 1st even integer
	int i = 0;

	// Traverse array arr[]
	while (i < n) {
		if (arr[i] % 2 == 0) {
			break;
		}
		i++;
	}
	// Stores the index of
	// last even integer
	int j = n - 1;

	// Traverse array arr[]
	// in reverse direction
	while (j >= 0) {
		if (arr[j] % 2 == 0) {
			break;
		}
		j--;
	}

	// Case where arr[] has less
	// that two even integers
	if (i >= j) {
		return 0;
	}

	// Return Answer
	return j - i;
}

// Driver Code
int main()
{
	int arr[] = { 3, 4, 5, 6, 7, 8 };
	int N = sizeof(arr) / sizeof(int);

	cout << maximizeDistance(arr, N);

	return 0;
}
