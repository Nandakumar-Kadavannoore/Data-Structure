// CPP program to find the largest 
// palindromic subsequence 

#include <bits/stdc++.h> 
using namespace std; 

// Function to find the largest 
// palindromic subsequence 
string largestPalinSub(string s) 
{ 
	string res; 

	char mx = s[0]; 

	// Find the largest character 
	for (int i = 1; i < s.length(); i++) 
		mx = max(mx, s[i]); 

	// Append all occurrences of largest character 
	// to the resultant string 
	for (int i = 0; i < s.length(); i++) 
		if (s[i] == mx) 
			res += s[i]; 

	return res; 
} 

// Driver Code 
int main() 
{ 
	string s = "geeksforgeeks"; 

	cout << largestPalinSub(s); 
} 
