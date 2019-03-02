static void rearrange(int a[], int size) 
{ 
  int positive = 0, negative = 1, temp; 
  
    while (true) { 
  
    /* Move forward the positive pointer till 
    negative number number not encountered */
    while (positive < size && a[positive] >= 0) 
        positive += 2; 
  
    /* Move forward the negative pointer till 
        positive number number not encountered */
    while (negative < size && a[negative] <= 0) 
        negative += 2; 
  
    // Swap array elements to fix their position. 
    if (positive < size && negative < size) { 
        temp = a[positive]; 
        a[positive] = a[negative]; 
        a[negative] = temp; 
    } 
  
    /* Break from the while loop when any index 
    exceeds the size of the array */
    else
        break; 
    } 
}
