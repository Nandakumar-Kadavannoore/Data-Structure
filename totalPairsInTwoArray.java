int totalPairs(int arr1[], int arr2[], int K, int n, int m) 
{ 
  
    // set is used to avoid duplicate pairs 
    set<pair<int, int> > s; 
  
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
  
            // check which element is greater and 
            // proceed according to it 
            if (arr1[i] > arr2[j]) { 
  
                // check if modulo is equal to K 
                if (arr1[i] % arr2[j] == K) 
                    s.insert(make_pair(arr1[i], arr2[j])); 
            } 
            else { 
                if (arr2[j] % arr1[i] == K) 
                    s.insert(make_pair(arr2[j], arr1[i])); 
            } 
        } 
    } 
  
    // return size of the set 
    return s.size(); 
} 
