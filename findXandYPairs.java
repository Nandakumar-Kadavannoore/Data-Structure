// Java program to finds number of pairs (x, y) 
// in an array such that x^y > y^x 

import java.util.Arrays; 

class MainClass 
{ 
	// This function return count of pairs with x as one element 
	// of the pair. It mainly looks for all values in Y[] where 
	// x ^ Y[i] > Y[i] ^ x 
	static int count(int x, int Y[], int n, int NoOfY[]) 
	{ 
		// If x is 0, then there cannot be any value in Y such that 
		// x^Y[i] > Y[i]^x 
		if (x == 0) return 0; 
	
		// If x is 1, then the number of pais is equal to number of 
		// zeroes in Y[] 
		if (x == 1) return NoOfY[0]; 
	
		// Find number of elements in Y[] with values greater than x 
		// getting upperbound of x with binary search 
		int idx = Arrays.binarySearch(Y, x); 
		int ans; 
		if(idx < 0){ 
			idx = Math.abs(idx+1); 
			ans = Y.length - idx; 
		} 
		else{ 
			while (Y[idx]==x) { 
				idx++; 
			} 
			ans = Y.length - idx; 
		} 
	
		// If we have reached here, then x must be greater than 1, 
		// increase number of pairs for y=0 and y=1 
		ans += (NoOfY[0] + NoOfY[1]); 
	
		// Decrease number of pairs for x=2 and (y=4 or y=3) 
		if (x == 2) ans -= (NoOfY[3] + NoOfY[4]); 
	
		// Increase number of pairs for x=3 and y=2 
		if (x == 3) ans += NoOfY[2]; 
	
		return ans; 
	} 
	
	// The main function that returns count of pairs (x, y) such that 
	// x belongs to X[], y belongs to Y[] and x^y > y^x 
	static int countPairs(int X[], int Y[], int m, int n) 
	{ 
		// To store counts of 0, 1, 2, 3 and 4 in array Y 
		int NoOfY[] = new int[5]; 
		for (int i = 0; i < n; i++) 
			if (Y[i] < 5) 
				NoOfY[Y[i]]++; 
	
		// Sort Y[] so that we can do binary search in it 
		Arrays.sort(Y); 
	
		int total_pairs = 0; // Initialize result 
	
		// Take every element of X and count pairs with it 
		for (int i=0; i<m; i++) 
			total_pairs += count(X[i], Y, n, NoOfY); 
	
		return total_pairs; 
	} 
	
	// Driver method 
	public static void main(String args[]) 
	{ 
		int X[] = {2, 1, 6}; 
		int Y[] = {1, 5}; 
	
		System.out.println("Total pairs = " + countPairs(X, Y, X.length, Y.length)); 
	} 
} 
