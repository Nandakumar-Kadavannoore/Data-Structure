static int sorted_partitions(int arr[]) 
    { 
        // Find minimum value from right for every index 
        int n = arr.length; 
        int[] right_min = new int[n + 1]; 
        right_min[n] = Integer.MAX_VALUE; 
        for (int i = n - 1; i >= 0; i--) { 
            right_min[i] = Math.min(right_min[i + 1], arr[i]); 
        } 
  
        // Finding the shortest prefix such that all the elements 
        // in the prefix are less than or equal to the elements 
        // in the rest of the array.  
        int partitions = 0; 
        for (int current_max = arr[0], i = 0; i < n; i++) { 
            current_max = Math.max(current_max, arr[i]); 
            
            // if current max is less than the right prefix min, 
            // we increase number of partitions. 
            if (current_max <= right_min[i + 1]) 
                partitions++; 
        } 
  
        return partitions; 
    } 
