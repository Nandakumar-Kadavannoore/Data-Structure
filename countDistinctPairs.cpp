/ Function for returning 
// sum of digits of a number 
int digitSum(int n) 
{ 
    int sum = 0; 
    while (n > 0) { 
        sum += n % 10; 
        n = n / 10; 
    } 
    return sum; 
} 
  
// Function to return the total pairs 
// of elements with equal sum of digits 
int totalPairs(int arr1[], int arr2[], int n, int m) 
{ 
  
    // set is used to avoid duplicate pairs 
    set<pair<int, int> > s; 
  
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
  
            // check sum of digits 
            // of both the elements 
            if (digitSum(arr1[i]) == digitSum(arr2[j])) { 
  
                if (arr1[i] < arr2[j]) 
                    s.insert(make_pair(arr1[i], arr2[j])); 
                else
                    s.insert(make_pair(arr2[j], arr1[i])); 
            } 
        } 
    } 
  
    // return size of the set 
    return s.size(); 
} 
