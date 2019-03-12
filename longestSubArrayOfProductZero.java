// Java implementation of the approach 
class MainClass { 

	// Function to return the length of the 
	// longest sub-array whose product 
	// of elements is 0 
	static int longestSubArray(int arr[], int n) 
	{ 
		boolean isZeroPresent = false; 
		for (int i = 0; i < n; i++) { 
			if (arr[i] == 0) { 
				isZeroPresent = true; 
				break; 
			} 
		} 

		if (isZeroPresent) 
			return n; 

		return 0; 
	} 

	// Driver code 
	public static void main(String args[]) 
	{ 
		int arr[] = { 1, 2, 3, 0, 1, 2, 0 }; 
		int n = arr.length; 
		System.out.print(longestSubArray(arr, n)); 
	} 
} 
