// C++ program to minimize insertions in
// Array to make ratio of each pair as K

#include <bits/stdc++.h>
using namespace std;

// Function to minimize insertions
// in Array to make ratio
// of each pair as K
int find_min_additions(
	int arr[], int n, int x)
{
	// Initialize a hashmap
	// and store the frequencies
	// of the array elements
	unordered_map<int, int> m;

	// Traverse the array
	// and store the frequencies
	for (int i = 0; i < n; i++) {
		m[arr[i]]++;
	}

	// sort the array
	sort(arr, arr + n);

	// Initialize the cnt_pairs to store the
	// count of the available pairs
	int cnt_pairs = 0;

	for (int i = 0; i < n; ++i) {

		// Check if the pair with ratio k is
		// present for arr[i]
		if (m[arr[i] * x] > 0
			&& m[arr[i]] > 0) {

			// Consider them as a pair
			// and remove from the hashmap
			m[arr[i] * x]--;
			m[arr[i]]--;

			// Add the count of the pairs
			cnt_pairs += 2;
		}
	}

	// Return the count of single elements
	// that need another element
	// to make ratio k
	return n - cnt_pairs;
}

// Driver code
int main()
{
	int arr[] = { 1, 2, 2, 2, 4, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int K = 2;

	cout << find_min_additions(arr, n, K);
}
