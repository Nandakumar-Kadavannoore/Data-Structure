	
	private static Node removeOutsideRange(Node root, int min, int max) {
		
		if (root == null)
			return null;
		root.left = removeOutsideRange(root.left, min, max);
		root.right = removeOutsideRange(root.right, min, max);
		
		if (root.data < min) {
			Node rChild = root.right;
			root = null;
			return rChild;
		}
		
		if (root.data > max) {
			Node lchild = root.left;
			root = null;
			return lchild;
		}
		return root;
	}
