int longestSubarray(int a[], int n, int x) 
{ 
    int count = 0; 
  
    int length = 0; 
  
    // Iterate in the array 
    for (int i = 0; i < n; i++) { 
  
        // check if array element 
        // greater then X or not 
        if (a[i] > x) { 
            count += 1; 
        } 
        else { 
  
            length = max(length, count); 
  
            count = 0; 
        } 
    } 
  
    // After iteration complete 
    // check for the last segment 
    if (count) 
        length = max(length, count); 
  
    return length; 
} 
  
