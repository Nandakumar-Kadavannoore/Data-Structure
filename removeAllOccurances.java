public static int[] removeElements(int[] arr, int key) 
    { 
  
        // return a new array except given key 
        return Arrays.stream(arr) 
            .filter(val -> val != key) 
            .toArray(); 
    } 
