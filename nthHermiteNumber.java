// Java program to find nth Hermite number 
import java.util.*; 

class MainClass { 

	// Function to return nth Hermite number 
	static int getHermiteNumber(int n) 
	{ 

		// Base condition 
		if (n == 0) 
			return 1; 

		else if (n == 1) 
			return 1; 

		else
			return -2 * (n - 1) * getHermiteNumber(n - 2); 
	} 

	// Driver Code 
	public static void main(String[] args) 
	{ 
		int n = 6; 

		// Print nth Hermite number 
		System.out.println(getHermiteNumber(n)); 
	} 
} 
