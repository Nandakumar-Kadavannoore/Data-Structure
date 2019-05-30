// Java implementation of the approach 
class GFG { 

	// Function that returns true 
	// if n is prime 
	static boolean isPrime(int n) 
	{ 
		if (n <= 1) 
			return false; 

		// Check from 2 to n 
		for (int i = 2; i < n; i++) { 
			if (n % i == 0) 
				return false; 
		} 
		return true; 
	} 

	// Function to find the count 
	// of 0s and 1s at prime indices 
	static void countPrimePosition(int arr[]) 
	{ 

		// To store the count of 0s and 1s 
		int c0 = 0, c1 = 0; 
		int n = arr.length; 
		for (int i = 0; i < n; i++) { 

			// If current 0 is at 
			// prime position 
			if (arr[i] == 0 && isPrime(i)) 
				c0++; 

			// If current 1 is at 
			// prime position 
			if (arr[i] == 1 && isPrime(i)) 
				c1++; 
		} 
		System.out.println("Number of 0s = " + c0); 
		System.out.println("Number of 1s = " + c1); 
	} 

	// Driver code 
	public static void main(String[] args) 
	{ 
		int[] arr = { 1, 0, 1, 0, 1 }; 
		countPrimePosition(arr); 
	} 
} 
