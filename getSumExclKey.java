class Tree {

class Node {
		int data;
		Node left, right;
	}
	
	private static void getSum(Node node, int key, int totalSum, boolean include) {
		if (node != null) {
			if (include) {
				if (node.left != null && node.left.data == key) {
					
				}
				else if (node.right != null && node.right.data == key) {
					
				} else {
					totalSum += node.data;
				}
					
			}
		}
		
		include = node.data == key ? false : true;
		getSum(node.right, key, totalSum, include);
		getSum(node.left, key, totalSum, include);
	}

}
