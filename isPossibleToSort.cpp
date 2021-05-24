// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to check if it is possible
// to sort the array or not
void isPossibleToSort(int arr[], int N)
{
	// Stores the index if there are two
	// consecutive 1's in the array
	int idx = -1;

	// Traverse the given array
	for (int i = 1; i < N; i++) {

		// Check adjacent same elements
		// having values 1s
		if (arr[i] == 1
			&& arr[i - 1] == 1) {
			idx = i;
			break;
		}
	}

	// If there are no two consecutive
	// 1s, then always remove all the
	// 1s from array & make it sorted
	if (idx == -1) {
		cout << "YES";
		return;
	}

	for (int i = idx + 1; i < N; i++) {

		// If two consecutive 0's are
		// present after two conseutive
		// 1's then array can't be sorted
		if (arr[i] == 0 && arr[i - 1] == 0) {
			cout << "NO";
			return;
		}
	}

	// Otherwise, print Yes
	cout << "YES";
}

// Driver Code
int main()
{
	int arr[] = { 1, 0, 1, 0, 1, 1, 0 };
	int N = sizeof(arr) / sizeof(arr[0]);
	isPossibleToSort(arr, N);

	return 0;
}
