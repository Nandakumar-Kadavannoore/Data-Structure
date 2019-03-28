// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the count of valid sub-strings 
int CountSubstring(char str[], int n) 
{ 

	// Variable ans to store all the possible substrings 
	// Intialize its value as total number of substrings 
	// that can be formed from the given string 
	int ans = (n * (n + 1)) / 2; 

	// Stores recent index of the characters 
	int a_index = 0; 
	int b_index = 0; 
	int c_index = 0; 

	for (int i = 0; i < n; i++) { 

		// If character is a update a's index 
		// and the variable ans 
		if (str[i] == 'a') { 
			a_index = i + 1; 
			ans -= min(b_index, c_index); 
		} 

		// If character is b update b's index 
		// and the variable ans 
		else if (str[i] == 'b') { 
			b_index = i + 1; 
			ans -= min(a_index, c_index); 
		} 

		// If character is c update c's index 
		// and the variable ans 
		else { 
			c_index = i + 1; 
			ans -= min(a_index, b_index); 
		} 
	} 

	return ans; 
} 

// Driver code 
int main() 
{ 
	char str[] = "babac"; 
	int n = strlen(str); 

	cout << CountSubstring(str, n); 

	return 0; 
} 
