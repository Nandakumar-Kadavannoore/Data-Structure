// Java implementation of the approach 
class MainClass { 

	// Function to return the count of all identical rows 
	public static int countIdenticalRows(int mat[][]) 
	{ 

		int count = 0; 

		for (int i = 0; i < mat.length; i++) { 

			// First element of current row 
			int first = mat[i][0]; 
			boolean allSame = true; 

			// Compare every element of the current row 
			// with the first element of the row 
			for (int j = 1; j < mat[i].length; j++) { 

				// If any element is different 
				if (mat[i][j] != first) { 
					allSame = false; 
					break; 
				} 
			} 

			// If all the elements of the 
			// current row were same 
			if (allSame) 
				count++; 
		} 

		return count; 
	} 

	// Driver code 
	public static void main(String[] args) 
	{ 
		int mat[][] = { { 1, 1, 2 }, 
						{ 2, 2, 2 }, 
						{ 5, 5, 2 } }; 
		System.out.print(countIdenticalRows(mat)); 
	} 
} 
