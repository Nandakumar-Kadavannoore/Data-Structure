// C++ program for the above approach 

#include <bits/stdc++.h> 
using namespace std; 

// Function to find the magnitude 
// of the given vector 
double magnitude(double arr[], int N) 
{ 
	// Stores the final magnitude 
	double magnitude = 0; 

	// Traverse the array 
	for (int i = 0; i < N; i++) 
		magnitude += arr[i] * arr[i]; 

	// Return square root of magnitude 
	return sqrt(magnitude); 
} 

// Function to find the dot 
// product of two vectors 
double dotProduct(double arr[], 
				double brr[], int N) 
{ 
	// Stores dot product 
	double product = 0; 

	// Traverse the array 
	for (int i = 0; i < N; i++) 
		product = product + arr[i] * brr[i]; 

	// Return the product 
	return product; 
} 

void angleBetweenVectors(double arr[], 
						double brr[], int N) 
{ 
	// Stores dot product of two vectors 
	double dotProductOfVectors 
		= dotProduct(arr, brr, N); 

	// Stores magnitude of vector A 
	double magnitudeOfA 
		= magnitude(arr, N); 

	// Stores magnitude of vector B 
	double magnitudeOfB 
		= magnitude(brr, N); 

	// Stores angle between given vectors 
	double angle = dotProductOfVectors 
				/ (magnitudeOfA * magnitudeOfB); 

	// Print the angle 
	cout << angle; 
} 

// Driver Code 
int main() 
{ 
	// Given magnitude arrays 
	double arr[] = { -0.5, -2, 1 }; 
	double brr[] = { -1, -1, 0.3 }; 

	// Size of the array 
	int N = sizeof(arr) / sizeof(arr[0]); 

	// Function call to find the 
	// angle between two vectors 
	angleBetweenVectors(arr, brr, N); 

	return 0; 
}
