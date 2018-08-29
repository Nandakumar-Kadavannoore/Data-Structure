class Node {
	int key;
	Node left, right;
	Node (int key) {
		this.key = key;
		left = right = null;
	}
}

class Is_Binary {
	
	int countNodes(Node root) {
		if (root == null)
			return 0;
		return (1 + countNodes(root.left) + countNodes(root.right));
	}
	
	boolean isCompleteUtil(Node root, int index, int numberNode) {
		if (root == null)
			return true;
		
		if (index >= numberNode)
			return false;
		
		return isCompleteUtil(root.left, 2 * index + 1, numberNode) &&
				isCompleteUtil(root.right, 2 * index + 2, numberNode);
	}
	
	boolean isHeapUtil(Node root) {
		
		if (root.left == null && root.right == null)
			return true;
		
		if (root.right == null) 
			return root.key >= root.left.key;
			else {
				if (root.key >= root.left.key &&
						root.key >= root.right.key)
					return isHeapUtil(root.left) && isHeapUtil(root.right);
				else
					return false;
			}
	}
	
	boolean isHeap(Node root) {
		if (root == null)
			return true;
		
		int nodeCount = countNodes(root);
		
		if (isCompleteUtil(root, 0, nodeCount) && isHeap(root))
			return true;
		
		return false;
	}
	
	
}
