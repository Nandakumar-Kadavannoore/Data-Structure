// C++ program to implement 
// the above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to print both the arrays 
void PrintBothArrays(int a[], int n) 
{ 

	// Store both arrays 
	vector<int> v1, v2; 

	// Used for hashing 
	unordered_map<int, int> mpp; 

	// Iterate for every element 
	for (int i = 0; i < n; i++) { 

		// Increase the count 
		mpp[a[i]]++; 

		// If first occurrence 
		if (mpp[a[i]] == 1) 
			v1.push_back(a[i]); 

		// If second occurrence 
		else if (mpp[a[i]] == 2) 
			v2.push_back(a[i]); 

		// If occurs more than 2 times 
		else { 
			cout << "Not possible"; 
			return; 
		} 
	} 

	// Sort in increasing order 
	sort(v1.begin(), v1.end()); 

	// Print the increasing array 
	cout << "Strictly increasing array is:\n"; 
	for (auto it : v1) 
		cout << it << " "; 

	// Sort in reverse order 
	sort(v2.begin(), v2.end(), greater<int>()); 

	// Print the decreasing array 
	cout << "\nStrictly decreasing array is:\n"; 
	for (auto it : v2) 
		cout << it << " "; 
} 

// Driver code 
int main() 
{ 

	int a[] = { 7, 2, 7, 3, 3, 1, 4 }; 
	int n = sizeof(a) / sizeof(a[0]); 
	PrintBothArrays(a, n); 

	return 0; 
} 
