// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the 
// sum of digits of n 
int digitSum(int n) 
{ 
	int sum = 0; 
	while (n > 0) { 
		sum += (n % 10); 
		n /= 10; 
	} 
	return sum; 
} 

// Function that returns true 
// if n is palindrome 
bool isPalindrome(int n) 
{ 
	// Find the appropriate divisor 
	// to extract the leading digit 
	int divisor = 1; 
	while (n / divisor >= 10) 
		divisor *= 10; 

	while (n != 0) { 
		int leading = n / divisor; 
		int trailing = n % 10; 

		// If first and last digit 
		// not same return false 
		if (leading != trailing) 
			return false; 

		// Removing the leading and trailing 
		// digit from number 
		n = (n % divisor) / 10; 

		// Reducing divisor by a factor 
		// of 2 as 2 digits are dropped 
		divisor = divisor / 100; 
	} 
	return true; 
} 

// Function that returns true if 
// the digit sum of n is palindrome 
bool isDigitSumPalindrome(int n) 
{ 

	// Sum of the digits of n 
	int sum = digitSum(n); 

	// If the digit sum is palindrome 
	if (isPalindrome(sum)) 
		return true; 
	return false; 
} 

// Driver code 
int main() 
{ 
	int n = 56; 

	if (isDigitSumPalindrome(n)) 
		cout << "Yes"; 
	else
		cout << "No"; 

	return 0; 
} 
