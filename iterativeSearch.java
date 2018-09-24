
	private boolean iterativeSearch(Node root, int key) {
		while (root != null) {
			
			if (key > root.data)
				 root = root.right;
			else if (key < root.data)
				  root = root.left;
			else
				return true;
		}
		return false;
	}
	
