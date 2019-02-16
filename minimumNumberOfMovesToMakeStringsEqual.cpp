// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the minimum number of 
// pre-processing moves required on string A 
int Preprocess(string A, string B) 
{ 
	// Length of the given strings 
	int n = A.size(); 

	// To store the required answer 
	int ans = 0; 

	// Run a loop upto n/2 
	for (int i = 0; i < n / 2; i++) { 

		// To store frequency of 4 characters 
		map<char, int> mp; 
		mp[A[i]]++; 
		mp[A[n - i - 1]]++; 
		mp[B[i]]++; 
		mp[B[n - i - 1]]++; 
		int sz = mp.size(); 

		// If size is 4 
		if (sz == 4) 
			ans += 2; 

		// If size is 3 
		else if (sz == 3) 
			ans += 1 + (A[i] == A[n - i - 1]); 

		// If size is 2 
		else if (sz == 2) 
			ans += mp[A[i]] != 2; 
	} 

	// If n is odd 
	if (n % 2 == 1 && A[n / 2] != B[n / 2]) 
		ans++; 

	return ans; 
} 

// Driver code 
int main() 
{ 
	string A = "abacaba", B = "bacabaa"; 
	cout << Preprocess(A, B); 

	return 0; 
} 
