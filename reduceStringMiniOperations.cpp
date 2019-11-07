// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the minimum 
// possible length str can be reduced 
// to with the given operation 
int minLength(string str, int len) 
{ 

	// Stack to store the characters 
	// of the given string 
	stack<char> s; 

	// For every character of the string 
	for (int i = 0; i < len; i++) { 

		// If the stack is empty then push the 
		// current character in the stack 
		if (s.empty()) { 
			s.push(str[i]); 
		} 
		else { 

			// Get the top character 
			char c = s.top(); 

			// If the top element is not equal 
			// to the current element and it 
			// only differs in the case 
			if (c != str[i] 
				&& toupper(c) == toupper(str[i])) { 

				// Pop the top element from stack 
				s.pop(); 
			} 

			// Else push the current element 
			else { 
				s.push(str[i]); 
			} 
		} 
	} 

	return s.size(); 
} 

// Driver code 
int main() 
{ 
	string str = "ASbBsd"; 
	int len = str.length(); 

	cout << minLength(str, len); 

	return 0; 
} 
