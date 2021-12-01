// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the length of
// recurring substring in range [l, r]
int recurringSubstring(string s, int l, int r)
{
	// Length of the string
	int N = s.size();

	// Variable to store the index of
	// the character in the alphabet
	int a[N];

	for (int i = 0; i < N; i++) {
		a[i] = (s[i] - 'a') + 1;
	}

	// Prefix array to store the sum
	int prefix[N];
	prefix[0] = a[0];

	for (int i = 1; i < N; i++) {
		prefix[i] = prefix[i - 1] + a[i];
	}

	l = l - 1;
	r = r - 1;

	// If l is greater than 0
	if (l != 0) {
		return prefix[r] - prefix[l - 1];
	}
	// If l is less or equal to 0
	else {
		return prefix[r];
	}
}

// Driver Code
int main()
{
	string s = "cbbde";
	int l = 2, r = 5;

	cout << recurringSubstring(s, l, r);

	return 0;
}
