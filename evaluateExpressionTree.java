int evaluate(Node root) {

  if (root == null)
     return 0;
     
  if (root.left == null && root.right == null) {
     return Integer.valueOf(root.data);
  }
  
  int lValue = evaluate(root.left);
  int rValue = evaluate(root.right);
  
  if (root.data == '+')
    return lValue + rValue;

}
