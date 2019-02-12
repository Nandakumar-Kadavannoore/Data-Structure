// C++ program to print the elements of a 
// stack from bottom to top 
#include <bits/stdc++.h> 
using namespace std; 

// Recursive function to print stack elements 
// from bottom to top without changing 
// their order 
void PrintStack(stack<int> s) 
{ 
	// If stack is empty then return 
	if (s.empty()) 
		return; 
	

	int x = s.top(); 

	// Pop the top element of the stack 
	s.pop(); 

	// Recursively call the function PrintStack 
	PrintStack(s); 

	// Print the stack element starting 
	// from the bottom 
	cout << x << " "; 

	// Push the same element onto the stack 
	// to preserve the order 
	s.push(x); 
} 

// Driver code 
int main() 
{ 
	// Stack s 
	stack<int> s; 

	s.push(1); 
	s.push(2); 
	s.push(3); 
	s.push(4); 

	PrintStack(s); 

	return 0; 
} 
