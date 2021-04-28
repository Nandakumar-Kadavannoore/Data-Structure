// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to construct the
// lexicographically largest string
// having sum of characters as N
string getString(int N)
{
	// Stores the resulting string
	string ans = "";

	// Iterate until N is at least 26
	while (N >= 26) {

		// Append 'z' to the string ans
		ans += 'z';

		// Decrement N by 26
		N -= 26;
	}

	// Append character at index (N + 'a')
	ans += char(N + 'a' - 1);

	// Return the resultant string
	return ans;
}

// Driver Code
int main()
{
	int N = 30;
	cout << getString(N);

	return 0;
}
