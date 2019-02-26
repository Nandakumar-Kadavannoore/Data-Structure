// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 
#define MAX 100000 
#define ll long long int 

// To store first N Catalan numbers 
ll catalan[MAX]; 

// Function to find first n Catalan numbers 
void catalanDP(ll n) 
{ 

	// Initialize first two values in table 
	catalan[0] = catalan[1] = 1; 

	// Fill entries in catalan[] using recursive formula 
	for (int i = 2; i <= n; i++) { 
		catalan[i] = 0; 
		for (int j = 0; j < i; j++) 
			catalan[i] += catalan[j] * catalan[i - j - 1]; 
	} 
} 

// Function to return the minimum changes required 
int CatalanSequence(int arr[], int n) 
{ 

	// Find first n Catalan Numbers 
	catalanDP(n); 

	unordered_multiset<int> s; 

	// a and b are first two 
	// Catalan Sequence numbers 
	int a = 1, b = 1; 
	int c; 

	// Insert first n catalan elements to set 
	s.insert(a); 
	if (n >= 2) 
		s.insert(b); 

	for (int i = 2; i < n; i++) { 
		s.insert(catalan[i]); 
	} 

	unordered_multiset<int>::iterator it; 

	for (int i = 0; i < n; i++) { 

		// If catalan element is present 
		// in the array then remove it from set 
		it = s.find(arr[i]); 
		if (it != s.end()) 
			s.erase(it); 
	} 

	// Return the remaining number of 
	// elements in the set 
	return s.size(); 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 1, 1, 2, 5, 41 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	cout << CatalanSequence(arr, n); 

	return 0; 
} 
