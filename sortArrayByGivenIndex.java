// Java program to sort the array in a given index range 
import java.io.*; 
import java.util.*; 
import java.lang.*; 

class GFG { 

	// Function to sort the elements of the array 
	// from index a to index b 
	static void partSort(int[] arr, int N, int a, int b) 
	{ 
		// Variables to store start and end of the index range 
		int l = Math.min(a, b); 
		int r = Math.max(a, b); 

		// Temporary array 
		int[] temp = new int[r - l + 1]; 
		int j = 0; 
		for (int i = l; i <= r; i++) { 
			temp[j] = arr[i]; 
			j++; 
		} 

		// Sort the temporary array 
		Arrays.sort(temp); 

		// Modifying original array with temporary array elements 
		j = 0; 
		for (int i = l; i <= r; i++) { 
			arr[i] = temp[j]; 
			j++; 
		} 

		// Print the modified array 
		for (int i = 0; i < N; i++) { 
			System.out.print(arr[i] + " "); 
		} 
	} 

	// Driver code 
	public static void main(String args[]) 
	{ 
		int[] arr = { 7, 8, 4, 5, 2 }; 
		int a = 1, b = 4; 

		// length of the array 
		int N = arr.length; 

		partSort(arr, N, a, b); 
	} 
} 
