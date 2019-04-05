// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find longest prefix suffix 
vector<int> compute_lps(string s) 
{ 
	int n = s.size(); 

	// To store longest prefix suffix 
	vector<int> lps(n); 

	// Length of the previous 
	// longest prefix suffix 
	int len = 0; 

	// lps[0] is always 0 
	lps[0] = 0; 
	int i = 1; 

	// Loop calculates lps[i] for i = 1 to n - 1 
	while (i < n) { 
		if (s[i] == s[len]) { 
			len++; 
			lps[i] = len; 
			i++; 
		} 

		// (pat[i] != pat[len]) 
		else { 
			if (len != 0) 
				len = lps[len - 1]; 
			// Also, note that we do not increment 
			// i here 

			// If len = 0 
			else { 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 

	return lps; 
} 

// Function to find the longest substring 
// which is prefix as well as a 
// sub-string of s[1...n-2] 
void Longestsubstring(string s) 
{ 
	// Find longest prefix suffix 
	vector<int> lps = compute_lps(s); 
	int n = s.size(); 

	// If lps of n-1 is zero 
	if (lps[n - 1] == 0) { 
		cout << -1; 
		return; 
	} 

	for (int i = 0; i < n - 1; i++) { 

		// At any position lps[i] equals to lps[n - 1] 
		if (lps[i] == lps[n - 1]) { 
			cout << s.substr(0, lps[i]); 
			return; 
		} 
	} 

	// If answer is not possible 
	if (lps[lps[n - 1] - 1] == 0) 
		cout << -1; 
	else
		cout << s.substr(0, lps[lps[n - 1] - 1]); 
} 

// Driver code 
int main() 
{ 
	string s = "fixprefixsuffix"; 

	// function call 
	Longestsubstring(s); 

	return 0; 
} 
