
// Function to check tree is continuous or not 
bool treeContinuous(struct Node *ptr) 
{ 
    // if next node is empty then return true 
    if (ptr == NULL) 
        return true; 
  
    // if current node is leaf node then return true 
    // because it is end of root to leaf path 
    if (ptr->left == NULL && ptr->right == NULL) 
        return true; 
  
    // If left subtree is empty, then only check right 
    if (ptr->left == NULL) 
       return (abs(ptr->data - ptr->right->data) == 1) && 
              treeContinuous(ptr->right); 
  
    // If right subtree is empty, then only check left 
    if (ptr->right == NULL) 
       return (abs(ptr->data - ptr->left->data) == 1) && 
              treeContinuous(ptr->left); 
  
    // If both left and right subtrees are not empty, check 
    // everything 
    return  abs(ptr->data - ptr->left->data)==1 && 
            abs(ptr->data - ptr->right->data)==1 && 
            treeContinuous(ptr->left) && 
            treeContinuous(ptr->right); 
} 
