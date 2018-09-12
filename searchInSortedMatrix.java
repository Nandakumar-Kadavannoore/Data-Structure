private static void searchMatrix(int[][] matrix, int n, int x) {
		int i = 0, j = n - 1;
		while ( i < n && j >= 0) {
			if (matrix[i][j] == x) {
				System.out.println("Found");
				return;
			}
			if (matrix[i][j] > x) 
				j--;
			else
				i++;
			
		}
		System.out.println("Not Found");
		return;
	}
