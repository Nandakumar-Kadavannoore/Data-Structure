

// C++ program for the above approach 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to count minimum removals 
// required to arrange all 0s before 1s 
int minimumDeletions(string s) 
{ 
    // Count the occurences of 0 in s 
    int right_0 = count(s.begin(), s.end(), '0'); 
  
    int left_1 = 0; 
      
    // Size of the string 
    int n = s.size(); 
      
    // Stores the minimum 
    // number of removals required 
    int res = INT_MAX; 
      
    // Iterate over each of the  
    // characters in the string s 
    for (int i = 0; i < n; i++)  
    { 
        // If the i-th character  
        // is found to be '0' 
        if (s[i] == '0')  
        { 
            right_0 -= 1; 
        } 
        else 
        { 
            left_1 += 1; 
        } 
          
        // Store the minimum of res 
        // and right_0 + left_1 in res 
        res = min(res, right_0 + left_1); 
    } 
    
    // Return the final result 
    return res; 
} 
  
  
// Driver Code 
int main() 
{ 
    string s = "001101"; 
    int count = minimumDeletions(s); 
      
    cout << count; 
    return 0; 
}
