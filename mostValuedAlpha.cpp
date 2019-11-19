// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

const int MAX = 26; 

// Function to return the maximum 
// valued alphabet 
char maxAlpha(string str, int len) 
{ 

	// To store the first and the last 
	// occurrence of all the characters 
	int first[MAX], last[MAX]; 

	// Set the first and the last occurrence 
	// of all the characters to -1 
	for (int i = 0; i < MAX; i++) { 
		first[i] = -1; 
		last[i] = -1; 
	} 

	// Update the occurrences of the characters 
	for (int i = 0; i < len; i++) { 

		int index = (str[i] - 'a'); 

		// Only set the first occurrence if 
		// it hasn't already been set 
		if (first[index] == -1) 
			first[index] = i; 

		last[index] = i; 
	} 

	// To store the result 
	int ans = -1, maxVal = -1; 

	// For every alphabet 
	for (int i = 0; i < MAX; i++) { 

		// If current alphabet doesn't appear 
		// in the given string 
		if (first[i] == -1) 
			continue; 

		// If the current character has 
		// the highest value so far 
		if ((last[i] - first[i]) > maxVal) { 
			maxVal = last[i] - first[i]; 
			ans = i; 
		} 
	} 

	return (char)(ans + 'a'); 
} 

// Driver code 
int main() 
{ 
	string str = "abbba"; 
	int len = str.length(); 

	cout << maxAlpha(str, len); 

	return 0; 
} 
