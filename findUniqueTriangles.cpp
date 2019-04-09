// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the number of unique triangles 
int UniqueTriangles(int a[], int b[], int c[], int n) 
{ 
	vector<int> sides[n]; 

	// Map to store the frequency of triangles 
	// with same sides 
	map<vector<int>, int> m; 

	for (int i = 0; i < n; i++) { 

		// Push all the sides of the current triangle 
		sides[i].push_back(a[i]); 
		sides[i].push_back(b[i]); 
		sides[i].push_back(c[i]); 

		// Sort the three sides 
		sort(sides[i].begin(), sides[i].end()); 

		// Store the frequency of the sides 
		// of the triangle 
		m[sides[i]] = m[sides[i]] + 1; 
	} 

	map<vector<int>, int>::iterator i; 

	// To store the count of unique triangles 
	int count = 0; 
	for (i = m.begin(); i != m.end(); i++) { 

		// If current triangle has unique sides 
		if (i->second == 1) 
			count++; 
	} 

	return count; 
} 

// Driver code 
int main() 
{ 
	int a[] = { 7, 5, 8, 2, 2 }; 
	int b[] = { 6, 7, 2, 3, 4 }; 
	int c[] = { 5, 6, 9, 4, 3 }; 

	int n = sizeof(a) / sizeof(int); 

	cout << UniqueTriangles(a, b, c, n); 

	return 0; 
} 
