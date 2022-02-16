// C++ code to implement the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find permutation
int solution(vector<string>& sw,
			vector<string>& tw)
{
	unordered_set<string> s;
	for (int i = 0; i < sw.size(); i++) {
		sort(sw[i].begin(), sw[i].end());
		s.insert(sw[i]);
	}
	int ans = 0;

	// Loop to check how many string
	// can be formed
	for (int i = 0; i < tw.size(); i++) {
		string test = tw[i];
		sort(test.begin(), test.end());

		// To track the number
		// Of the words formed
		bool check = 0;

		for (int j = 0; j < test.size(); j++) {

			// Substring from 0 to 'i'
			// and remove one alphabet
			// and append rest of the string
			string search
				= test.substr(0, j)
				+ test.substr(j + 1);

			// Check if the word is available
			// in the set
			if (s.find(search) != s.end()) {
				check = 1;
				break;
			}
		}
		if (check)
			ans++;
	}
	return ans;
}

// Driver Code
int main()
{
	vector<string> str = { "ohr", "tm", "ek" };
	vector<string> str1 = { "mat", "hr" };

	cout << solution(str, str1);
	return 0;
}
