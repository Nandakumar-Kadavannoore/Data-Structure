int getTotalNumberOfSequence(int m, int n) {
		int total[][] = new int[m+1][n+1];
		for (int i = 0; i < m+1; i++) {
			for (int j = 0; j < n+1; j++) {
				if ( i == 0 || j == 0)
					total[i][j] = 0;
				else if (i < j)
					total[i][j] = 0;
				else if (j == 1)
					total[i][j] = i;
				else
					total[i][j] = total[i-1][j] + total[i/2][j-1];
			}
		}
		return total[m][n];
		
	}
