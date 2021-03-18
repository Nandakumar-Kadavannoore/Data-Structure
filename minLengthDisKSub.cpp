// C++ program for the above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to count the minimum number 
// of distinct elements present in any 
// subsequence of length K of the given array 
void findMinimumDistinct(int A[], int N, int K) 
{ 

	// Stores the frequency 
	// of each array element 
	unordered_map<int, int> mp; 

	// Traverse the array 
	for (int i = 0; i < N; i++) 

		// Update frequency 
		// of array elements 
		mp[A[i]]++; 

	// Store the required result 
	int count = 0; 

	// Store the length of the 
	// required subsequence 
	int len = 0; 

	// Store the frequencies 
	// in decreasing order 
	vector<int> counts; 

	// Travere the map 
	for (auto i : mp) 

		// Push the frequencies 
		// into the HashMap 
		counts.push_back(i.second); 

	// Sort the array in decreasing order 
	sort(counts.begin(), counts.end(), 
		greater<int>()); 

	// Add the elements into the subsequence 
	// starting from one with highest frequency 
	for (int i = 0; i < counts.size(); i++) { 

		// If length of subsequence is >= k 
		if (len >= K) 
			break; 
		len += counts[i]; 
		count++; 
	} 

	// Print the result 
	cout << count; 
} 

// Driver Code 
int main() 
{ 
	int A[] = { 3, 1, 3, 2, 3, 4, 5, 4 }; 
	int K = 4; 

	// Store the size of the array 
	int N = sizeof(A) / sizeof(A[0]); 

	// Function Call to count minimum 
	// number of distinct elmeents 
	// present in a K-length subsequence 
	findMinimumDistinct(A, N, K); 

	return 0; 
}
