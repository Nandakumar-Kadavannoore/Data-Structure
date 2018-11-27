
# Function to find the minimum steps  
# to convert string a to string b 
def convert(n, a, b): 
  
    # List to mark the positions needed to  
    # be negated 
    l = [0] * n 
    for i in range(n): 
  
        # If two character are not same  
        # then they need to be negated 
        if(a[i] != b[i]): 
            l[i] = 1
  
    # To count the blocks of 1 
    cc = 0
  
    # To count the number of 1's in each  
    # block of 1's 
    vl = 0
    for i in range(n): 
        if (l[i] == 0): 
            if(vl != 0): 
                cc += 1
            vl = 0
        else: 
            vl += 1
  
    # For the last block of 1's 
    if(vl != 0): 
        cc += 1
  
    print(cc)
