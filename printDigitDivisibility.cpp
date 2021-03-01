// C++ program for the above approach 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find digits for each array 
// element that doesn't divide any digit 
// of the that element 
void indivisibleDigits(int arr[], int N) 
{ 
    // Traverse the array arr[] 
    for (int i = 0; i < N; i++) { 
  
        int num = 0; 
  
        cout << arr[i] << ": "; 
  
        // Iterate over the range [2, 9] 
        for (int j = 2; j < 10; j++) { 
  
            int temp = arr[i]; 
  
            // Stores if there exists any digit 
            // in arr[i] which is divisible by j 
            bool flag = true; 
  
            while (temp > 0) { 
  
                // If any digit of the number 
                // is divisible by j 
                if ((temp % 10) != 0 
                    && (temp % 10) % j == 0) { 
  
                    flag = false; 
                    break; 
                } 
  
                temp /= 10; 
            } 
  
            // If the digit j doesn't 
            // divide any digit of arr[i] 
            if (flag) { 
                cout << j << ' '; 
            } 
        } 
  
        cout << endl; 
    } 
} 
  
// Driver Code 
int main() 
{ 
    int arr[] = { 4162, 1152, 99842 }; 
    int N = sizeof(arr) / sizeof(arr[0]); 
  
    indivisibleDigits(arr, N); 
  
    return 0; 
