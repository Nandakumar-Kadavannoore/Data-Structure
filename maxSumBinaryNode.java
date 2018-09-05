public static int maxSum(Node root)
    {
        if (root == null)
        return 0;
 
    int res = maxSum(root.left);
 
    // if left and right link are null 
    // then add all the three Node
    if (root.left != null && 
        root.right != null) 
    {
        int sum = root.data + 
                  root.left.data + 
                  root.right.data;
        res = Math.max(res, sum);
    }
 
    return Math.max(res, maxSum(root.right));
    }
     
