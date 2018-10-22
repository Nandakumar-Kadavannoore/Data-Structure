static int maxEvenSubarray(int array[], int N) 
    { 
        int ans = 0; 
        int count = 0; 
  
        // Iterate the loop 
        for (int i = 0; i < array.length; i++) { 
            // Check whether the element is 
            // even in continuous fashion 
            if (array[i] % 2 == 0) { 
                count++; 
            } 
            else { 
                // If element are not even in continuous 
                // fashion. Reinitialize the count 
                ans = Math.max(ans, count); 
                count = 0; 
            } 
        } 
  
        // Check for the last element in the array 
        ans = Math.max(ans, count); 
        return ans; 
    } 
