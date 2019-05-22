// Java implementation of the approach 
public class GFG { 

	// Maximum distinct characters possible 
	static final int MAX = 256; 

	// To store the frequency of the characters 
	static int freq[][]; 

	// Function to pre-calculate the frequency array 
	static void preCalculate(String str, int n) 
	{ 

		// Only the first character has 
		// frequency 1 till index 0 
		freq[(int)str.charAt(0)][0] = 1; 

		// Starting from the second 
		// character of the string 
		for (int i = 1; i < n; i++) { 
			char ch = str.charAt(i); 

			// For every possible character 
			for (int j = 0; j < MAX; j++) { 

				// Current character under consideration 
				char charToUpdate = (char)j; 

				// If it is equal to the character 
				// at the current index 
				if (charToUpdate == ch) 
					freq[j][i] = freq[j][i - 1] + 1; 
				else
					freq[j][i] = freq[j][i - 1]; 
			} 
		} 
	} 

	// Function to return the frequency of the 
	// given character in the sub-string str[l...r] 
	static int getFrequency(char ch, int l, int r) 
	{ 

		if (l == 0) 
			return freq[(int)ch][r]; 
		else
			return (freq[(int)ch][r] - freq[(int)ch][l - 1]); 
	} 

	// Function to return the last non-repeating character 
	static String lastNonRepeating(String str, int n, int l, int r) 
	{ 

		// Starting from the last character 
		for (int i = r; i >= l; i--) { 

			// Current character 
			char ch = str.charAt(i); 

			// If frequency of the current character is 1 
			// then return the character 
			if (getFrequency(ch, l, r) == 1) 
				return ("" + ch); 
		} 

		// All the characters of the 
		// sub-string are repeating 
		return "-1"; 
	} 

	// Driver code 
	public static void main(String[] args) 
	{ 
		String str = "GeeksForGeeks"; 
		int n = str.length(); 

		int queries[][] = { { 2, 9 }, { 2, 3 }, { 0, 12 } }; 
		int q = queries.length; 

		// Pre-calculate the frequency array 
		freq = new int[MAX][n]; 
		preCalculate(str, n); 

		for (int i = 0; i < q; i++) { 
			System.out.println(lastNonRepeating(str, n, 
												queries[i][0], 
												queries[i][1])); 
		} 
	} 
} 
