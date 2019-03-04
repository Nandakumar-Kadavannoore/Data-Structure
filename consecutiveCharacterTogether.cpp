// C++ implemetation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the modified string 
string groupCharacters(string s, int len) 
{ 

	// Store original string 
	string temp = ""; 

	// Remove all white spaces 
	for (int i = 0; i < len; i++) 
		if (s[i] != ' ') 
			temp = temp + s[i]; 

	len = temp.length(); 

	// To store the resultant string 
	string ans = ""; 
	int i = 0; 

	// Traverse the string 
	while (i < len) { 

		// Group upper case characters 
		if (int(temp[i]) >= int('A') 
			&& int(temp[i]) <= int('Z')) { 
			while (i < len && int(temp[i]) >= int('A') 
				&& int(temp[i]) <= int('Z')) { 
				ans = ans + temp[i]; 
				i++; 
			} 
			ans = ans + " "; 
		} 

		// Group numeric characters 
		else if (int(temp[i]) >= int('0') 
				&& int(temp[i]) <= int('9')) { 
			while (i < len && int(temp[i]) >= int('0') 
				&& int(temp[i]) <= int('9')) { 
				ans = ans + temp[i]; 
				i++; 
			} 
			ans = ans + " "; 
		} 

		// Group arithmetic operators 
		else { 
			while (i < len && int(temp[i]) >= int('*') 
				&& int(temp[i]) <= int('/')) { 
				ans = ans + temp[i]; 
				i++; 
			} 
			ans = ans + " "; 
		} 
	} 

	// Return the resultant string 
	return ans; 
} 

// Driver code 
int main() 
{ 
	string s = "34FTG234+ +- *"; 
	int len = s.length(); 
	cout << groupCharacters(s, len); 
	return 0; 
} 
