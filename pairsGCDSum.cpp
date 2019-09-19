// CPP progarm to find the number of pairs 
// such that gcd equals to 1 
#include <bits/stdc++.h> 
using namespace std; 

#define N 100050 

int lpf[N], mobius[N]; 

// Function to calculate least 
// prime factor of each number 
void least_prime_factor() 
{ 
	for (int i = 2; i < N; i++) 

		// If it is a prime number 
		if (!lpf[i]) 

			for (int j = i; j < N; j += i) 

				// For all multiples which are not 
				// visited yet. 
				if (!lpf[j]) 
					lpf[j] = i; 
} 

// Function to find the value of Mobius function 
// for all the numbers from 1 to n 
void Mobius() 
{ 
	for (int i = 1; i < N; i++) { 

		// If number is one 
		if (i == 1) 
			mobius[i] = 1; 
		else { 

			// If number has a squared prime factor 
			if (lpf[i / lpf[i]] == lpf[i]) 
				mobius[i] = 0; 

			// Multiply -1 with the previous number 
			else
				mobius[i] = -1 * mobius[i / lpf[i]]; 
		} 
	} 
} 

// Function to find the number of pairs 
// such that gcd equals to 1 
int gcd_pairs(int a[], int n) 
{ 
	// To store maximum number 
	int maxi = 0; 

	// To store frequency of each number 
	int fre[N] = { 0 }; 

	// Find frequency and maximum number 
	for (int i = 0; i < n; i++) { 
		fre[a[i]]++; 
		maxi = max(a[i], maxi); 
	} 

	least_prime_factor(); 
	Mobius(); 

	// To store number of pairs with gcd equals to 1 
	int ans = 0; 

	// Traverse through the all possible elements 
	for (int i = 1; i <= maxi; i++) { 
		if (!mobius[i]) 
			continue; 

		int temp = 0; 
		for (int j = i; j <= maxi; j += i) 
			temp += fre[j]; 

		ans += temp * (temp - 1) / 2 * mobius[i]; 
	} 

	// Return the number of pairs 
	return ans; 
} 

// Driver code 
int main() 
{ 
	int a[] = { 1, 2, 3, 4, 5, 6 }; 

	int n = sizeof(a) / sizeof(a[0]); 

	// Function call 
	cout << gcd_pairs(a, n); 

	return 0; 
} 
