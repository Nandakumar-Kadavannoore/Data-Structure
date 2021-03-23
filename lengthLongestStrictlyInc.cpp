// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the
// longest subset satisfying given conditions
void maxLenSubset(int a[], int n)
{
	// Sort the array in ascending order
	sort(a, a + n);

	// Stores the starting index and maximum
	// length of the required subset
	int index = 0, maxlen = -1;

	// Pointer to traverse the array
	int i = 0;

	// Iterate while i < n
	while (i < n) {

		// Stores end point
		// of current subset
		int j = i;

		// Store the length of
		// the current subset
		int len = 1;

		// Continue adding elements to the current
		// subset till the condition satisfies
		while (j < n - 1) {

			if (2 * a[j] >= a[j + 1]) {

				// Increment length of
				// the current subset
				len++;
			}
			else
				break;

			// Increment the pointer j
			j++;
		}

		// If length of the current subset
		// exceeds overall maximum length
		if (maxlen < len) {

			// Update maxlen
			maxlen = len;

			// Update index
			index = i;
		}

		// Increment j
		j++;

		// Update i
		i = j;
	}

	// Store the starting index of
	// the required subset in i
	i = index;

	// Print the required subset
	while (maxlen > 0) {

		// Print the array element
		cout << a[i] << " ";

		// Decrement maxlen
		maxlen--;

		// Increment i
		i++;
	}
}

// Driver Code
int main()
{
	// Given array
	int a[] = { 3, 1, 5, 11 };

	// Store the size of the array
	int n = sizeof(a) / sizeof(int);

	maxLenSubset(a, n);

	return 0;
}
