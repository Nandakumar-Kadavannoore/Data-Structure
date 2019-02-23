
	class Node {
		int data;
		Node left, right;
		
		Node (int data) {
			this.data = data;
			left = right = null;
		}
	}
	
    private Node createNewNode(int data) {
    	return new Node(data);
    }
    
    private void convertTree(Node node) {
    	if (node == null)
    		return;
    	convertTree(node.right);
    	if (node.data == 0)
    		node.data = -1;
    	convertTree(node.left);
    }
    
    private int sumTree(Node node) {
    	int leftValue = 0, rightValue = 0;
    	
    	if (node == null)
    		 return 0;
    	leftValue = sumTree(node.left);
    	rightValue = sumTree(node.right);
    	
    	node.data = node.data + leftValue + rightValue;
    	
    	return node.data;
    }
    
    private boolean checkSubTree(Node node, boolean flag) {
    	if (node == null)
    		return false;
    	
    	  if (!flag)
    		  flag = checkSubTree(node.left, flag);
    	  if (!flag)
    		  flag = checkSubTree(node.right, flag);
    	  if (node.data == 0) {
    		  flag = true;
    		  return flag;
    	  }
    	return flag;
    }
