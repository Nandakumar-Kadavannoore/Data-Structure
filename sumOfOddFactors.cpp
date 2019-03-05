// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 
#define ll long long int 

const int MAX = 100001; 

ll prefix[MAX]; 

// Function to calculate the prefix sum 
// of all the odd factors 
void sieve_modified() 
{ 
	for (int i = 1; i < MAX; i += 2) { 

		// Add i to all the multiples of i 
		for (int j = i; j < MAX; j += i) 
			prefix[j] += i; 
	} 

	// Update the prefix sum 
	for (int i = 1; i < MAX; i++) 
		prefix[i] += prefix[i - 1]; 
} 

// Function to return the sum of 
// all the odd factors of the 
// numbers in the given range 
ll sumOddFactors(int L, int R) 
{ 
	return (prefix[R] - prefix[L - 1]); 
} 

// Driver code 
int main() 
{ 
	sieve_modified(); 
	int l = 6, r = 10; 
	cout << sumOddFactors(l, r); 
	return 0; 
} 
