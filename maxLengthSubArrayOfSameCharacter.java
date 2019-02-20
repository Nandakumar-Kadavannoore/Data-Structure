// Java implementation of the approach 

// Class that represents a single element 
// of the given array and stores it's first 
// and the last occurrence in the array 
class Element { 
	int firstOcc, lastOcc; 

	public Element() 
	{ 
		firstOcc = lastOcc = -1; 
	} 

	// Function to update the occurrence 
	// of a particular character in the array 
	public void updateOccurrence(int index) 
	{ 

		// If first occurrence is set to something 
		// other than -1 then it doesn't need updating 
		if (firstOcc == -1) 
			firstOcc = index; 

		// Last occurrence will be updated everytime 
		// the character appears in the array 
		lastOcc = index; 
	} 
} 

class MainClass { 

	// Function to return the maximum length of the 
	// sub-array that starts and ends with the same element 
	public static int maxLenSubArr(char arr[], int n) 
	{ 

		Element elements[] = new Element[26]; 
		for (int i = 0; i < n; i++) { 
			int ch = arr[i] - 'a'; 

			// Initialize the current character 
			// if haven't already 
			if (elements[ch] == null) 
				elements[ch] = new Element(); 

			// Update current character's occurrence 
			elements[ch].updateOccurrence(i); 
		} 

		int maxLen = 0; 
		for (int i = 0; i < 26; i++) { 

			// If current character appears in the given array 
			if (elements[i] != null) { 

				// Length of the longest sub-array that starts 
				// and ends with the same element 
				int len = elements[i].lastOcc - elements[i].firstOcc + 1; 
				maxLen = Math.max(maxLen, len); 
			} 
		} 

		// Return the maximum length of 
		// the required sub-array 
		return maxLen; 
	} 

	// Driver code 
	public static void main(String[] args) 
	{ 
		char arr[] = { 'g', 'e', 'e', 'k', 's' }; 
		int n = arr.length; 

		System.out.print(maxLenSubArr(arr, n)); 
	} 
} 
