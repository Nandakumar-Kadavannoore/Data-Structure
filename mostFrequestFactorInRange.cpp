// CPP program to find most common factor 
// in a range. 
#include <bits/stdc++.h> 
using namespace std; 

int mostCommon(int lower, int higher) 
{ 
	// Check whether lower number 
	// and higher number are same 
	if (lower == higher) 
		return lower; 
	else
		return 2; 
} 

// Driver Code 
int main() 
{ 
	int lower = 10; // Lower number 
	int higher = 20; // Higher number 

	printf("The most frequent factor %d\n", 
			mostCommon(lower, higher)); 
	return 0; 
} 
