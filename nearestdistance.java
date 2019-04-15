// Java program to find distance of nearest 
// cell having 1 in a binary matrix. 

import java.io.*; 

class GFG { 
	
	static int N = 3; 
	static int M = 4; 
	
	// Print the distance of nearest cell 
	// having 1 for each cell. 
	static void printDistance(int mat[][]) 
	{ 
		int ans[][] = new int[N][M]; 
	
		// Initalize the answer matrix with INT_MAX. 
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < M; j++) 
				ans[i][j] = Integer.MAX_VALUE; 
	
		// For each cell 
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < M; j++) 
			{ 
				// Traversing the whole matrix 
				// to find the minimum distance. 
				for (int k = 0; k < N; k++) 
					for (int l = 0; l < M; l++) 
					{ 
						// If cell contain 1, check 
						// for minimum distance. 
						if (mat[k][l] == 1) 
							ans[i][j] = 
							Math.min(ans[i][j], 
								Math.abs(i-k) 
								+ Math.abs(j-l)); 
					} 
			} 
	
		// Printing the answer. 
		for (int i = 0; i < N; i++) 
		{ 
			for (int j = 0; j < M; j++) 
				System.out.print( ans[i][j] + " "); 
	
			System.out.println(); 
		} 
	} 
	
	// Driven Program 
	public static void main (String[] args) 
	{ 
		int mat[][] = { {0, 0, 0, 1}, 
						{0, 0, 1, 1}, 
						{0, 1, 1, 0} }; 
	
		printDistance(mat); 
	} 
} 

