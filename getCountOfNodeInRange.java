 int getCount(Node node, int low, int high) 
    { 
        // Base Case 
        if(node == null) 
            return 0; 
  
        // If current node is in range, then  
        // include it in count and recur for  
        // left and right children of it 
        if(node.data >= low && node.data <= high) 
            return 1 + this.getCount(node.left, low, high)+ 
                this.getCount(node.right, low, high); 
                  
        // If current node is smaller than low,  
        // then recur for right child 
        else if(node.data < low) 
            return this.getCount(node.right, low, high); 
          
        // Else recur for left child 
        else
            return this.getCount(node.left, low, high);      
    } 
  
