// C++ implementation of the above approach 
#include <iostream> 
using namespace std; 

// Function to print all possible order 
void printAllOrder(int n) 
{ 
	// total number of elements in a matrix 
	// of order m * n is equal (m*n) 
	// where m is number of rows and n is 
	// number of columns 
	for (int i = 1; i <= n; i++) { 

		// if n is divisible by i then i 
		// and n/i will be the one 
		// possible order of the matrix 
		if (n % i == 0) { 

			// print the given format 
			cout << i << " " << n / i << endl; 
		} 
	} 
} 

// Driver code 
int main() 
{ 
	int n = 10; 
	printAllOrder(n); 
	return 0; 
} 
