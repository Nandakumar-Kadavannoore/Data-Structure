// C++ program for Count the number of
// sub-sequences of an array where the last digit
// of the product of the subsequence is K.
#include <bits/stdc++.h>
using namespace std;

int dp[1001][10];
// recursive utility function
int countSubsequencesUtil(int n, int k, int p,
						vector<int>& a)
{
	// Base case
	if (n == 0) {
		if (p == k)
			return 1;
		else
			return 0;
	}

	// return pre calculated value from
	// look-up table
	if (dp[n][p] != -1)
		return dp[n][p];

	// return the total number obtained through
	// option1 and option2
	return dp[n][p]
		= countSubsequencesUtil(n - 1, k,
								(p * a[n - 1]) % 10, a)
			+ countSubsequencesUtil(n - 1, k, p, a);
}
// Function to Count the number of subseqeunces
int countSubsequences(vector<int>& a, int k)
{
	// initialize the table with -1
	memset(dp, -1, sizeof(dp));

	int n = a.size();
	int ans = countSubsequencesUtil(n, k, 1, a);

	// if k is 1 return 1 less
	if (k == 1)
		return ans - 1;

	return ans;
}

// Driver Code
int main()
{
	vector<int> a = { 2, 3, 4, 2 };
	int k = 2;

	cout << countSubsequences(a, k);

	return 0;
}
