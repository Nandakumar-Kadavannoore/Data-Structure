private boolean deadend(Node root, int min, int max) {
		if (root == null)
			return false;
		
		if (min == max)
			return true;
		return deadend(root.left, min, max) ||
				deadend(root.right, min, max);
	}
