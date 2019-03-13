#include <stdio.h> 
#include <string.h> 

int getSteps(int arr[], int n) 
{ 
	// Count to keep track of the number of steps done. 
	int count = 0; 

	// Modulus array to store all elements mod 4 
	int modulus[4] = { 0 }; 

	// sum to check if given task is possible 
	int sum = 0; 

	// Loop to store all elements mod 4 and calculate sum; 
	int i; 
	for (i = 0; i < n; i++) { 
		int mod = arr[i] % 4; 
		sum += mod; 
		modulus[mod]++; 
	} 

	// If sum is not divisible by 4, not possible 
	if (sum % 4 != 0) { 
		return -1; 
	} 
	else { 

		// Find minimum of modulus[1] and modulus[3] 
		// and increment the count by the minimum 
		if (modulus[1] > modulus[3]) { 
			count += modulus[3]; 
		} 
		else { 
			count += modulus[1]; 
		} 
		// Update the values in modulus array. 
		modulus[1] -= count; 
		modulus[3] -= count; 

		// Use modulus[2] to pair remaining elements. 
		modulus[2] += modulus[1] / 2; 
		modulus[2] += modulus[3] / 2; 

		// incrememnt count to half of remaining 
		// modulus[1] or modulus of [3] elements. 
		count += modulus[1] / 2; 
		count += modulus[3] / 2; 

		// increment count by half of modulus[2] 
		count += modulus[2] / 2; 

		return count; 
	} 
} 

// Driver Code 
int main() 
{ 
	// size of array 
	int n = 7; 
	// input array 
	int arr[] = { 1, 2, 3, 1, 2, 3, 8 }; 

	int count = getSteps(arr, n); 

	printf("%d", count); 
} 
