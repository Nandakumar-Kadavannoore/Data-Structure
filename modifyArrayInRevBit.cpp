// C++ implementation of
// the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to convert binary
// number to equivalent decimal
int binaryToDecimal(string n)
{
	string num = n;
	int dec_value = 0;

	// Set base value to 1, i.e 2^0
	int base = 1;

	int len = num.length();
	for (int i = len - 1; i >= 0; i--) {
		if (num[i] == '1')
			dec_value += base;
		base = base * 2;
	}

	return dec_value;
}

// Function to convert a decimal
// to equivalent binary representation
string decimalToBinary(int n)
{
	// Stores the binary representation
	string binstr = "";

	while (n > 0) {

		// Since ASCII value of
		// '0', '1' are 48 and 49
		binstr += (n % 2 + 48);
		n = n / 2;
	}

	// As the string is already reversed,
	// no further reversal is required
	return binstr;
}

// Function to convert the reversed binary
// representation to equivalent integer
int reversedBinaryDecimal(int N)
{
	// Stores reversed binary
	// representation of given decimal
	string decimal_to_binar
		= decimalToBinary(N);

	// Stores equivalent decimal
	// value of the binary representation
	int binary_to_decimal
		= binaryToDecimal(decimal_to_binar);

	// Return the resultant integer
	return binary_to_decimal;
}

// Utility function to print the sorted array
void printSortedArray(int arr[], int size)
{
	// Sort the array
	sort(arr, arr + size);

	// Traverse the array
	for (int i = 0; i < size; i++)

		// Print the array elements
		cout << arr[i] << " ";

	cout << endl;
}

// Utility function to reverse the
// binary representations of all
// array elements and sort the modified array
void modifyArray(int arr[], int size)
{
	// Traverse the array
	for (int i = 0; i < size; i++) {

		// Passing array elements to
		// reversedBinaryDecimal function
		arr[i] = reversedBinaryDecimal(
			arr[i]);
	}

	// Pass the array to
	// the sorted array
	printSortedArray(arr, size);
}

// Driver Code
int main()
{
	int arr[] = { 98, 43, 66, 83 };
	int n = sizeof(arr) / sizeof(arr[0]);

	modifyArray(arr, n);

	return 0;
}
