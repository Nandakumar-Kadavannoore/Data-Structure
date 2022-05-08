/*package whatever //do not write package name here */

import java.io.*;// Java program for above approach
class MainClass
{

// Function to check if it is possible
// to make the array elements consecutive
public static boolean ispossible(int arr[], int n)
{

	// If the first element left unchanged
	// The valid sequence should look like
	// arr[0], arr[0]+1, arr[0]+2 ...
	int[] possibility1 = new int[n];
	for (int i = 0; i < n; i++)
	possibility1[i] = i + arr[0];

	// If incremented the first element
	// The valid sequence should look like
	// arr[0]+1, arr[0]+2, arr[0]+3 ...
	int[] possibility2 = new int[n];
	for (int i = 0; i < n; i++)
	possibility2[i] = i + arr[0] + 1;

	// If decremented the first element
	// The valid sequence should look like
	// arr[0]-1, arr[0]-2, arr[0]-3 ...
	int[] possibility3 = new int[n];
	for (int i = 0; i < n; i++)
	possibility3[i] = i + arr[0] - 1;

	// Now check if it is possible to convert
	// array in any of the above mentioned
	// three possibilities, which were,
	// either increment, decrement or
	// left unchanged. So the gap between
	// current and desired should not be
	// greater than 2
	Boolean canposs1 = true, canposs2 = true;
	Boolean canposs3 = true;

	// Is it possible to convert array
	// in possibility 1
	for (int i = 0; i < n; i++) {
	if (Math.abs(possibility1[i] - arr[i]) > 1) {
		canposs1 = false;
		break;
	}
	}

	// Is it possible to convert array
	// in possibility 2
	for (int i = 0; i < n; i++) {
	if (Math.abs(possibility2[i] - arr[i]) > 1) {
		canposs2 = false;
		break;
	}
	}

	// Is it possible to convert array
	// in possibility 3
	for (int i = 0; i < n; i++) {
	if (Math.abs(possibility3[i] - arr[i]) > 1) {
		canposs3 = false;
		break;
	}
	}

	// If any one is possible
	// then "YES" else "NO"
	if (canposs1 || canposs2 || canposs3) {
	return true;
	}
	return false;
}

public static void main (String[] args)
{
	int N = 4;
	int arr[] = { 1, 2, 3, 7 };

	// Function call
	if (ispossible(arr, N)) {
	System.out.print("YES");
	}
	else {
	System.out.print("NO");
	}
}
}
