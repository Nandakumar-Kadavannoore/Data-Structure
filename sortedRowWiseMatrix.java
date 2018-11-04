	static int sortedRowWise(int matrix[][]) {
		for (int i = 0; i < matrix.length; i++) {
			Arrays.sort(matrix[i]);
		}
		
		for (int i = 0; i < matrix.length; i++) {
			for ( int j = 0; j < matrix[i].length ; j++)
				System.out.println(matrix[i][j]);
		}
		
		return 0;
	}
