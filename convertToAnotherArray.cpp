// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to check if a digit x is
// present in the number N or not
int isPresent(int n, int x)
{
	// Convert N to string
	string num = to_string(n);

	// Traverse the string num
	for (int i = 0; i < num.size();
		i++) {

		// Return first occurrence
		// of the digit x
		if ((num[i] - '0') == x)
			return i;
	}
	return -1;
}

// Function to remove the character
// at a given index from the number
int removeDigit(int n, int index)
{
	// Convert N to string
	string num = to_string(n);

	// Store the resultant string
	string ans = "";

	// Traverse the string num
	for (int i = 0;
		i < num.size(); i++) {
		if (i != index)
			ans += num[i];
	}

	// If the number becomes empty
	// after deletion, then return -1
	if (ans == "" || (ans.size() == 1
					&& ans[0] == '0'))
		return -1;

	// Return the number
	int x = stoi(ans);
	return x;
}

// Function to check if A can be
// reduced to B by performing the
// operations any number of times
bool reduceNtoX(int a, int b,
				int d[], int n)
{
	// Create a queue
	queue<int> q;

	// Push A into the queue
	q.push(a);

	// Hashmap to check if the element
	// is present in the Queue or not
	unordered_map<int, bool> visited;

	// Set A as visited
	visited[a] = true;

	// Iterate while the queue is not empty
	while (!q.empty()) {

		// Store the front value of the
		// queue and pop it from it
		int top = q.front();
		q.pop();

		if (top < 0)
			continue;

		// If top is equal to B,
		// then return true
		if (top == b)
			return true;

		// Traverse the array, D[]
		for (int i = 0; i < n; i++) {

			// Divide top by D[i] if
			// it is possible and
			// push the result in q
			if (d[i] != 0 && top % d[i] == 0
				&& !visited[top / d[i]]) {

				q.push(top / d[i]);
				visited[top / d[i]] = true;
			}

			// If D[i] is present at the top
			int index = isPresent(top, d[i]);
			if (index != -1) {

				// Remove the first occurrence
				// of D[i] from the top and
				// store the new number
				int newElement
					= removeDigit(top, index);

				// Push newElement into the queue q
				if (newElement != -1
					&& (!visited[newElement])) {
					q.push(newElement);
					visited[newElement] = true;
				}
			}
		}
	}

	// Return false if A can
	// not be reduced to B
	return false;
}

// Driver Code
int main()
{

	int A = 5643, B = 81;
	int D[] = { 3, 8, 1 };
	int N = sizeof(D) / sizeof(D[0]);

	if (reduceNtoX(A, B, D, N))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
