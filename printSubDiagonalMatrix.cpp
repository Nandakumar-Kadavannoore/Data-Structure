// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 
#define R 4 
#define C 4 

// Function to print the sub diagonal 
// elements of the given matrix 
void printSubDiagonal(int arr[R][C]) 
{ 
	for (int i = 1; i < R; i++) { 
		cout << arr[i][i - 1] << " "; 
	} 
} 

// Driver code 
int main() 
{ 
	int arr[R][C] = { { 1, 2, 3, 4 }, 
					{ 5, 6, 7, 8 }, 
					{ 9, 10, 11, 12 }, 
					{ 13, 14, 15, 16 } }; 

	printSubDiagonal(arr); 

	return 0; 
} 
