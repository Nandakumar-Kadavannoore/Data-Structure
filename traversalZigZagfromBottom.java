// Java program for traversing a matrix from column n-1 

class MainClass { 

	// Function used for traversing over the given matrix 
	static void traverseMatrix(int[][] mat, int n) 
	{ 

		// Initial cell coordinates 
		int cur_x = 0, cur_y = n - 1; 

		// Variable used for keeping track of last move 
		String prev_move = ""; 

		// Variable used for keeping count 
		// of cells traversed till next move 
		int move_cnt = 1; 
		int cell_cnt = 1; 
		System.out.print(Integer.toString( 
							mat[cur_x][cur_y]) 
						+ " "); 

		while (cell_cnt < n * n) { 

			// odd numbered move 
			// [SINGLE VERTICAL/HORIZONTAL] 
			if (move_cnt % 2 == 1) { 
				// last move was made in north east direction 
				if (prev_move == "NORTH_WEST" || prev_move == "") { 
					// move left 
					if (cur_y != 0) { 
						--cur_y; 
						prev_move = "LEFT"; 
					} 
					// move down 
					else { 
						++cur_x; 
						prev_move = "DOWN"; 
					} 
				} 

				// last move was made in south east direction 
				else { 

					// move down 
					if (cur_x != n - 1) { 
						++cur_x; 
						prev_move = "DOWN"; 
					} 

					// move left 
					else { 
						--cur_y; 
						prev_move = "LEFT"; 
					} 
				} 
				System.out.print(Integer.toString( 
									mat[cur_x][cur_y]) 
								+ " "); 
				++cell_cnt; 
			} 

			// even numbered move/s [DIAGONAL/S] 
			else { 
				if ((move_cnt >> 1) % 2 == 1) { 

					// move south east 
					while (cur_x < n - 1 && cur_y < n - 1) { 
						++cur_x; 
						++cur_y; 
						prev_move = "SOUTH_EAST"; 
						System.out.print( 
							Integer.toString( 
								mat[cur_x][cur_y]) 
							+ " "); 
						++cell_cnt; 
					} 
				} 
				else { 

					// move north west 
					while (cur_x > 0 && cur_y > 0) { 
						--cur_x; 
						--cur_y; 
						prev_move = "NORTH_WEST"; 
						System.out.print( 
							Integer.toString( 
								mat[cur_x][cur_y]) 
							+ " "); 
						++cell_cnt; 
					} 
				} 
			} 
			++move_cnt; 
		} 
	} 

	// Driver function 
	public static void main(String[] args) 
	{ 

		// number of rows and columns 
		int n = 5; 

		// 5x5 matrix 
		int[][] mat = { 
			{ 1, 2, 3, 4, 5 }, 
			{ 6, 7, 8, 9, 10 }, 
			{ 11, 12, 13, 14, 15 }, 
			{ 16, 17, 18, 19, 20 }, 
			{ 21, 22, 23, 24, 25 } 
		}; 

		traverseMatrix(mat, n); 

		System.exit(0); 
	} 
} 
