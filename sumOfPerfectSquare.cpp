// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function that returns true if the the sum of all the 
// perfect squares of the given array is divisible by x 
bool check(int arr[], int x, int n) 
{ 
	long long sum = 0; 
	for (int i = 0; i < n; i++) { 
		double x = sqrt(arr[i]); 

		// If arr[i] is a perfect square 
		if (floor(x) == ceil(x)) { 
			sum += arr[i]; 
		} 
	} 

	if (sum % x == 0) 
		return true; 
	else
		return false; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 2, 3, 4, 9, 10 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int x = 13; 

	if (check(arr, x, n)) { 
		cout << "Yes"; 
	} 
	else { 
		cout << "No"; 
	} 
	return 0; 
} 
