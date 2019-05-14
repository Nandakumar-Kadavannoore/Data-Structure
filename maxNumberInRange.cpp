// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the maximum 
// size of the required interval 
int maxSize(vector<int>& v, int n) 
{ 
	// Insert the borders for array 
	v.push_back(0); 
	v.push_back(100001); 
	n += 2; 

	// Sort the elements in ascending order 
	sort(v.begin(), v.end()); 

	// To store the maximum size 
	int mx = 0; 
	for (int i = 1; i < n - 1; i++) { 

		// To store the range [L, R] such that 
		// only v[i] lies within the range 
		int L = v[i - 1] + 1; 
		int R = v[i + 1] - 1; 

		// Total integers in the range 
		int cnt = R - L + 1; 
		mx = max(mx, cnt); 
	} 

	return mx; 
} 

// Driver code 
int main() 
{ 
	vector<int> v = { 200, 10, 5 }; 
	int n = v.size(); 

	cout << maxSize(v, n); 

	return 0; 
} 
