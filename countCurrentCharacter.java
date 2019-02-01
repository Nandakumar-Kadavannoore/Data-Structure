// Java implementation of the approach 
import java.util.*; 
import java.lang.*; 
import java.io.*; 

class GFG 
{ 
	
// Function to return the count 
// of the required sub-strings 
static int maxSubStrings(String s, int k) 
{ 
	int maxSubStr = 0, n = s.length(); 

	// Iterate over all characters 
	for (int c = 0; c < 26; c++) 
	{ 
		char ch = (char)((int)'a' + c); 

		// Count with current character 
		int curr = 0; 
		for (int i = 0; i <= n - k; i++) 
		{ 
			if (s.charAt(i) != ch) 
				continue; 
			int cnt = 0; 
			while (i < n && s.charAt(i) == ch && 
										cnt != k) 
			{ 
				i++; 
				cnt++; 
			} 
			i--; 

			// If the substring has a length 
			// k then increment count with 
			// current character 
			if (cnt == k) 
				curr++; 
		} 

		// Update max count 
		maxSubStr = Math.max(maxSubStr, curr); 
	} 
	return maxSubStr; 
} 

// Driver Code 
public static void main(String []args) 
{ 
	String s = "aaacaabbaa"; 
	int k = 2; 
	System.out.println(maxSubStrings(s, k)); 
} 
} 


