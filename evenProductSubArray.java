// Function to count subarrays with even product 
    static void evenproduct(int arr[], int length) 
    { 
        // Stores count of subarrays 
        // with even product 
        int count = 0; 
  
        // Traverse the array 
        for (int i = 0; i < arr.length; i++) { 
  
            // Initialize product 
            int product = 1; 
  
            for (int j = i; j < arr.length; j++) { 
  
                // Update product of the subarray 
                product *= arr[j]; 
  
                if (product % 2 == 0) 
                    ++count; 
            } 
        } 
  
        // Print total count of subarrays 
        System.out.println(count); 
    } 
