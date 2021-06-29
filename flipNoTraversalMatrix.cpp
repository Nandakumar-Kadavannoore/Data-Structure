// C++ program for the above approach

#include "bits/stdc++.h"
using namespace std;

// The four direction coordinates changes
// from the current cell
int direction[][2] = { { -1, 0 }, { 0, 1 },
					{ 0, -1 }, { 1, 0 } };

// Function that returns true if there
// exists any path from the top-left to
// the bottom-right cell of 0s
bool dfs(vector<vector<int> >& matrix,
		int i, int j, int N, int M)
{

	// If the bottom-right cell is
	// reached
	if (i == N - 1 and j == M - 1) {
		return true;
	}

	// Update the cell to 1
	matrix[i][j] = 1;

	// Traverse in all four directions
	for (int k = 0; k < 4; k++) {

		// Find the new coordinates
		int newX = i + direction[k][0];
		int newY = j + direction[k][1];

		// If the new cell is valid
		if (newX >= 0 and newX < N
			and newY >= 0 and newY < M
			and matrix[newX][newY] == 0) {

			// Recursively call DFS
			if (dfs(matrix, newX,
					newY, N, M)) {

				// If path exists, then
				// return true
				return true;
			}
		}
	}

	// Return false, if there doesn't
	// exists any such path
	return false;
}

// Function to flip the minimum number
// of cells such that there doesn't
// exists any such path from (0, 0) to
// (N - 1, M - 1) cell consisting of 0s
int solve(vector<vector<int> >& matrix)
{

	int N = matrix.size();
	int M = matrix[0].size();

	// Case 1: If no such path exists
	// already
	if (!dfs(matrix, 0, 0, N, M)) {
		return 0;
	}

	// Case 2: If there exists only
	// one path
	if (!dfs(matrix, 0, 0, N, M)) {
		return 1;
	}

	// Case 3: If there exists two-path
	return 2;
}

// Driver Code
int main()
{
	vector<vector<int> > mat = {
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	};
	cout << solve(mat);

	return 0;
}
