// C++ program for the above approach 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to evaluate given expression 
int compute(int a, int b) 
{ 
    // Store the result 
    int ans = a * b + a - b; 
    return ans; 
} 
  
// Function to find the maximum value of 
// the given expression possible for any 
// unique pair from the given array 
void findMaxValue(int arr[], int N) 
{ 
    // Sort the array in ascending order 
    sort(arr, arr + N); 
  
    // Evaluate the expression for 
    // the two largest elements 
    int maxm = compute(arr[N - 1], arr[N - 2]); 
  
    // Evaluate the expression for 
    // the two smallest elements 
    maxm = max(maxm, compute(arr[1], arr[0])); 
  
    // Print the maximum 
    cout << maxm; 
} 
  
// Driver Code 
int main() 
{ 
    // Given array 
    int arr[] = { -4, -5, 0, 1, 3 }; 
  
    // Store the size of the array 
    int N = sizeof(arr) / sizeof(arr[0]); 
  
    findMaxValue(arr, N); 
  
    return 0; 
}
