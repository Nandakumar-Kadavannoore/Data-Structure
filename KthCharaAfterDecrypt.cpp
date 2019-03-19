// C++ implementation of the approach 
#include <cstdlib> 
#include <iostream> 
using namespace std; 

// Function to print kth charecter of 
// String s after decrypting it 
char findKthChar(string s, int k) 
{ 

	// Get the length of string 
	int len = s.length(); 

	// Initialise pointer to charecter 
	// of input string to zero 
	int i = 0; 

	// Total length of resultant string 
	int total_len = 0; 

	// Traverse the string from starting 
	// and check if each character is 
	// alphabet then increament total_len 
	while (i < len) { 
		if (isalpha(s[i])) { 

			total_len++; 

			// If total_leg equal to k then 
			// return string else increment i 
			if (total_len == k) 
				return s[i]; 

			i++; 
		} 

		else { 

			// Parse the number 
			int n = 0; 
			while (i < len && !isalpha(s[i])) { 
				n = n * 10 + (s[i] - '0'); 
				i++; 
			} 

			// Update next_total_len 
			int next_total_len = total_len * n; 

			// Get the position of kth charecter 
			if (k <= next_total_len) { 
				int pos = k % total_len; 

				// Position not found then update 
				// position with total_len 
				if (!pos) { 
					pos = total_len; 
				} 

				// Recursively find the kth position 
				return findKthChar(s, pos); 
			} 
			else { 

				// Else update total_len 
				// by next_total_len 
				total_len = next_total_len; 
			} 
		} 
	} 

	// Return -1 if charecter not found 
	return -1; 
} 

// Driver code 
int main() 
{ 
	string s = "ab2c3"; 
	int k = 5; 

	cout << findKthChar(s, k); 

	return 0; 
} 
