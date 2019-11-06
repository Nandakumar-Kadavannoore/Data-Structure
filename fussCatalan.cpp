// C++ program for nth Fuss–Catalan Number 

#include <iostream> 
using namespace std; 

// Returns value of Binomial Coefficient C(n, k) 
unsigned long int binomialCoeff(unsigned int n, 
								unsigned int k) 
{ 
	unsigned long int res = 1; 

	// Since C(n, k) = C(n, n-k) 
	if (k > n - k) 
		k = n - k; 

	// Calculate value of 
	//[n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1] 
	for (int i = 0; i < k; ++i) { 
		res *= (n - i); 
		res /= (i + 1); 
	} 

	return res; 
} 

// A Binomial coefficient based function 
// to find nth Fuss–Catalan number in O(n) time 
unsigned long int Fuss_catalan(unsigned int n) 
{ 
	// Calculate value of 3nCn 
	unsigned long int c = binomialCoeff(3 * n, n); 

	// return 3nCn/(2n+1) 
	return c / (2 * n + 1); 
} 

// Driver code 
int main() 
{ 
	for (int i = 0; i < 10; i++) 
		cout << Fuss_catalan(i) << " "; 
	return 0; 
} 
