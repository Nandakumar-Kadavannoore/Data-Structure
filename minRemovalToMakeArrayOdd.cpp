// C++ implementation of the above approach 
#include <iostream> 
using namespace std; 

// Function to find minimum removals 
int findCount(int arr[], int n) 
{ 
	// Count odd numbers 
	int countOdd = 0; 
	for (int i = 0; i < n; i++) 
		if (arr[i] % 2 == 1) 
			countOdd++; 

	// If the counter is odd return 0 
	// otherwise return 1 
	if (countOdd % 2 == 0) 
		return 1; 
	else
		return 0; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = { 1, 2, 3, 5, 1 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	cout << findCount(arr, n); 

	return 0; 
} 
