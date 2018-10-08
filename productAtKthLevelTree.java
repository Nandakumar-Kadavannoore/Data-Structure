static int productAtKthLevel(String tree, int k) 
    { 
        int level = -1; 
          
        // Initialize result 
        int product = 1;  
          
        int n = tree.length(); 
      
        for (int i = 0; i < n; i++)  
        { 
            // increasing level number 
            if (tree.charAt(i) == '(') 
                level++; 
      
            // decreasing level number 
            else if (tree.charAt(i) == ')') 
                level--; 
      
            else 
            { 
                // check if current level is 
                // the desired level or not 
                if (level == k) 
                    product *= (tree.charAt(i) - '0'); 
            } 
        } 
      
        // required product 
        return product; 
    } 
