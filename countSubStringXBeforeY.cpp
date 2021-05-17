// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to count occurrences of
// the string Y in the string S for
// every occurrence of X in S
void countOccurrences(string S,
					string X,
					string Y)
{
	// Stores the count of
	// occurrences of X
	int count = 0;

	// Stores the lengths of the
	// three strings
	int N = S.length(), A = X.length();
	int B = Y.length();

	// Traverse the string S
	for (int i = 0; i < N; i++) {

		// If the current substring
		// is Y, then increment the
		// value of count by 1
		if (S.substr(i, B) == Y)
			count++;

		// If the current substring
		// is X, then print the count
		if (S.substr(i, A) == X)
			cout << count << " ";
	}
}

// Driver Code
int main()
{
	string S = "abcdefdefabc";
	string X = "abc";
	string Y = "def";
	countOccurrences(S, X, Y);

	return 0;
}
