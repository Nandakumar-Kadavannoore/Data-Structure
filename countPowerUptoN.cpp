// C++ program for the above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to count the number 
// of powers of prime numbers upto N 
int countPowerOfPrimes(int N) 
{ 

	// Sieve array 
	int prime[N + 1]; 

	// Sieve of Eratosthenes 

	// Initialize all numbers as prime 
	for (int i = 0; i <= N; i++) 
		prime[i] = 1; 

	// Mark 0 and 1 as non prime 
	prime[0] = 0; 
	prime[1] = 0; 

	for (int i = 2; i * i <= N; i++) { 
		// If a prime number is found 
		if (prime[i] == 1) { 
			// Mark all multiples 
			// of i as non-prime 
			for (int j = i * i; 
				j <= N; j += i) { 
				prime[j] = 0; 
			} 
		} 
	} 

	// Stores all prime 
	// numbers upto N 
	vector<int> v; 

	// Push all the primes into v 
	for (int i = 2; i <= N; i++) { 
		if (prime[i] == 1) { 
			v.push_back(i); 
		} 
	} 

	// Stores the count of 
	// powers of primes up to N 
	int ans = 0; 

	// Iteratre over every 
	// prime number up to N 
	for (auto p : v) { 
		// Store p in temp 
		int temp = p; 

		// Iterate until temp exceeds n 
		while (temp <= N) { 
			// Increment ans by 1 
			ans = ans + 1; 

			// Update temp to 
			// next power of p 
			temp = temp * p; 
		} 
	} 

	// Return ans as the final answer 
	return ans; 
} 

// Driver Code 
int main() 
{ 
	// Given Input 
	int n = 9; 

	// Function call to count 
	// the number of power of 
	// primes in the range [1, N] 
	cout << countPowerOfPrimes(n); 

	return 0; 
}
