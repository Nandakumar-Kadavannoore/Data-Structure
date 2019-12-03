
edit
play_arrow

brightness_4
// C++ program to find 
// Sum of GCD over all subarrays. 
  
#include <bits/stdc++.h> 
using namespace std; 
  
// Utility function to calculate 
// sum of gcd of all sub-arrays. 
  
int findGCDSum(int n, int a[]) 
{ 
    int GCDSum = 0; 
    int tempGCD = 0; 
    for (int i = 0; i < n; i++) { 
        // Fixing the starting index of a subarray 
        for (int j = i; j < n; j++) { 
            // Fixing the ending index of a subarray 
            tempGCD = 0; 
            for (int k = i; k <= j; k++) { 
                // Finding the GCD of this subarray 
                tempGCD = __gcd(tempGCD, a[k]); 
            } 
            // Adding this GCD in our sum 
            GCDSum += tempGCD; 
        } 
    } 
    return GCDSum; 
} 
  
// Driver Code 
int main() 
{ 
    int n = 5; 
    int a[] = { 1, 2, 3, 4, 5 }; 
    int totalSum = findGCDSum(n, a); 
    cout << totalSum << "\n"; 
} 
