private static int countNegative(int matrix[][], int n, int m) {
		int count= 0;
		for (int i = 0; i < n ; i++) {
			for (int j = 0; j <  m ; j++) {
				if (matrix[i][j] < 0)
					count++;
				else 
					break;
			}
		}
		return count;
	}
	
