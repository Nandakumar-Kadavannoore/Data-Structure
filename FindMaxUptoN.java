private static int findMaxForN(Node root, int n) {
		if (root == null)
			return -1;
		if (root.data == n)
			return n;
		else if (root.data < n) {
			int result = findMaxForN(root.right, n);
			if (result == -1)
				return root.data;
			else
				return result;
		} 
		
		else if (root.data > n)
			return findMaxForN(root.left, n);
		return -1;
	}
