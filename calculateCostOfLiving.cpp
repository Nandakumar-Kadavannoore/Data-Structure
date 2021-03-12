// C++ implementation of the above approach 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to calculate total 
// cost of visiting array 
// elements in increasing order 
int calculateDistance(int arr[], int N) 
{ 
    // Stores the pair of element 
    // and their positions 
    vector<pair<int, int> > v; 
  
    // Traverse the array arr[] 
    for (int i = 0; i < N; i++) 
  
        // Push the pair {arr[i], i} in v 
        v.push_back({ arr[i], i }); 
  
    // Sort the vector in ascending order. 
    sort(v.begin(), v.end()); 
  
    // Stores the total cost 
    int ans = 0; 
  
    // Stores the index of last element visited 
    int last = 0; 
  
    // Traverse the vector v 
    for (auto j : v) { 
  
        // Increment ans 
        ans += abs(j.second - last); 
  
        // Assign 
        last = j.second; 
    } 
  
    // Return ans 
    return ans; 
} 
  
// Driver Code 
int main() 
{ 
    int arr[] = { 4, 3, 2, 5, 1 }; 
    int N = sizeof(arr) / sizeof(arr[0]); 
    cout << calculateDistance(arr, N); 
}
