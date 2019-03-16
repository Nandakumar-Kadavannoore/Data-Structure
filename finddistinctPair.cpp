// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

void findpair(int l, int r) 
{ 
	int c = 0; 
	for (int i = l; i <= r; i++) { 
		for (int j = i + 1; j <= r; j++) { 
			if (j % i == 0 && j != i) { 
				cout << i << ", " << j; 
				c = 1; 
				break; 
			} 
		} 
		if (c == 1) 
			break; 
	} 
} 

int main() 
{ 
	int l = 1, r = 10; 
	findpair(l, r); 
} 
