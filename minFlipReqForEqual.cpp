// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find minimum operations
// required to convert string A to B
int minimumOperation(string a, string b)
{

	// Store the size of the string
	int n = a.length();
	int i = 0;

	// Store the required result
	int minoperation = 0;

	// Traverse the string, a
	while (i < n) {

		// If a[i] is equal to b[i]
		if (a[i] == b[i]) {
			i = i + 1;
			continue;
		}

		// Check if swapping adjacent
		// characters make the same-indexed
		// characters equal or not
		else if (a[i] == b[i + 1]
				&& a[i + 1] == b[i]
				&& i < n - 1) {

			minoperation++;
			i = i + 2;
		}

		// Otherwise, flip the current bit
		else if (a[i] != b[i]) {
			minoperation++;
			i = i + 1;
		}
		else {
			++i;
		}
	}

	// Print the minimum number of operations
	cout << minoperation;
}

// Driver Code
int main()
{
	// Given Input
	string a = "10010010", b = "00001000";

	// Function Call
	minimumOperation(a, b);

	return 0;
}
