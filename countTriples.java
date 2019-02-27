 static long count_triples(int n, int k) 
    { 
        int i = 0, j = 0, l = 0; 
        int count = 0; 
  
        // iterate for all 
        // triples pairs (i, j, l)
       // all value
        for (i = 1; i <= n; i++) { 
            for (j = 1; j <= n; j++) { 
                for (l = 1; l <= n; l++) { 
  
                    // if the condition 
                    // is satisfied 
                    if ((i + j) % k == 0
                        && (i + l) % k == 0
                        && (j + l) % k == 0) 
                        count++; 
                } 
            } 
        } 
        return count; 
    } 
  
