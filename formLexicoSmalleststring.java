class MainClass 
{ 

	// Function that returns the 
	// modified lexicographically 
	// smallest String after 
	// performing minimum number 
	// of given operations 
	static String formStringMinOperations(char[] s) 
	{ 
		
		// Stores the initial frequencies 
		// of characters 0s, 1s and 2s 
		int count[] = new int[3]; 
		for (char c : s) 
		{ 
			count[(int)c - 48] += 1; 
		} 

		// Stores number of processed characters 
		// upto that point of each type 
		int processed[] = new int[3]; 

		// Required number of characters of each type 
		int reqd = (int) s.length / 3; 
		for (int i = 0; i < s.length; i++) 
		{ 

			// If the current type has already 
			// reqd number of characters, no 
			// need to perform any operation 
			if (count[s[i] - '0'] == reqd) 
			{ 
				continue; 
			} 

			// Process all 3 cases 
			if (s[i] == '0' && count[0] > reqd 
					&& processed[0] >= reqd) 
			{ 

				// Check for 1 first 
				if (count[1] < reqd) 
				{ 
					s[i] = '1'; 
					count[1]++; 
					count[0]--; 
				} 
				
				// Else 2 
				else if (count[2] < reqd) 
				{ 
					s[i] = '2'; 
					count[2]++; 
					count[0]--; 
				} 
			} 

			// Here we need to check processed[1] only 
			// for 2 since 0 is less than 1 and we can 
			// replace it anytime 
			if (s[i] == '1' && count[1] > reqd) 
			{ 
				if (count[0] < reqd) 
				{ 
					s[i] = '0'; 
					count[0]++; 
					count[1]--; 
				} 
				else if (count[2] < reqd 
						&& processed[1] >= reqd) 
				{ 
					s[i] = '2'; 
					count[2]++; 
					count[1]--; 
				} 
			} 

			// Here we can replace 2 with 0 and 1 anytime 
			if (s[i] == '2' && count[2] > reqd) 
			{ 
				if (count[0] < reqd) 
				{ 
					s[i] = '0'; 
					count[0]++; 
					count[2]--; 
				} 
				else if (count[1] < reqd) 
				{ 
					s[i] = '1'; 
					count[1]++; 
					count[2]--; 
				} 
			} 

			// keep count of processed 
			// characters of each type 
			processed[s[i] - '0']++; 
		} 
		return String.valueOf(s); 
	} 

	// Driver Code 
	public static void main(String[] args) 
	{ 
		String s = "011200"; 
		System.out.println(formStringMinOperations(s.toCharArray())); 
	} 
} 

