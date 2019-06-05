// java program to decode a median 
// string to the original string 

public class GFG { 
	
	// function to calculate the 
	// median back string 
	static String decodeMedianString(String s) 
	{ 
		
		// length of string 
		int l = s.length(); 
	
		// initialize a blank string 
		String s1 = ""; 
	
		// Flag to check if length is 
		// even or odd 
		boolean isEven = (l % 2 == 0) ? 
						true : false; 
	
		// traverse from first to last 
		for (int i = 0; i < l; i += 2) 
		{ 
	
			// if len is even then add 
			// first character to 
			// beginning of new string 
			// and second character to 
			// end 
			if (isEven) { 
				s1 = s.charAt(i) + s1; 
				s1 += s.charAt(i+1); 
			} 
			else { 
	
				// if current length is 
				// odd and is greater 
				// than 1 
				if (l - i > 1) { 
	
					// add first character 
					// to end and second 
					// character to 
					// beginning 
					s1 += s.charAt(i); 
					s1 = s.charAt(i+1) + s1; 
				} 
				else { 
	
					// if length is 1, 
					// add character 
					// to end 
					s1 += s.charAt(i); 
				} 
			} 
		} 
	
		return s1; 
	} 
	
	// Driver code 
	public static void main(String args[]) 
	{ 
		String s = "eekgs"; 
		
		System.out.println( 
					decodeMedianString(s)); 
	} 
} 
