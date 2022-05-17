// C++ code to implement the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to return next same parity
// element in the array
vector<int> findElement(int* arr, int n)
{
	// Initialize the vector with -1
	vector<int> SPE(n, -1);
	int Next_Even, Next_Odd;

	// To check if odd and even
	// are more than one or not
	int Count_Even = 0, Count_Odd = 0;

	for (int i = 2 * n - 1; i >= 0; i--) {

		// Duplicate array
		if (i >= n) {
			if (arr[i % n] & 1) {
				Next_Odd = arr[i % n];
				Count_Odd++;
			}
			else {
				Next_Even = arr[i % n];
				Count_Even++;
			}
		}

		// Original array
		else {
			if (arr[i] & 1) {
				if (Count_Odd > 1) {
					SPE[i] = Next_Odd;
					Next_Odd = arr[i];
				}
			}
			else {
				if (Count_Even > 1) {
					SPE[i] = Next_Even;
					Next_Even = arr[i];
				}
			}
		}
	}

	return SPE;
}

// Driver Code
int main()
{
	int arr[] = { 2, 4, 3, 6, 5 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	vector<int> v = findElement(arr, N);
	for (auto i : v) {
		cout << i << " ";
	}
}
