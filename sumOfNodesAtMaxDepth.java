/**
 * Sum of nodes at maximum depth of a Binary Tree
 * @author Nandakumar K
 */
package tree;

class Node {
	int data;
	Node left;
	Node right;

	Node(int item) {
		data = item;
		left = right = null;
	}
}

class MainClass {

	public static void main(String... args) {
		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.left = new Node(4);
		root.left.right = new Node(5);
		root.right.left = new Node(6);
		root.right.right = new Node(7);
		root.right.left.right = new Node(8);
		root.right.right.right = new Node(9);
		System.out.println("Sum of nodes at maximum depth of a Binary Tree is "+ process(root));
	}
	
	/**
	 * Helper function for Processing all necessary Operations 
	 * @param root
	 * @return integer
	 */
	public static int process(Node root) {
		int maxDepthValue = maxDepth(root);
		return sumMaxlevel(root, maxDepthValue);
	}

	/**
	 * Helper function for sum maximum level
	 * @param node
	 * @param maxDepthValue
	 * @return integer
	 */
	private static int sumMaxlevel(Node node, int maxDepthValue) {
		if (node == null)
			return 0;
		if (maxDepthValue == 1)
			return node.data;
		return sumMaxlevel(node.left, maxDepthValue - 1) + sumMaxlevel(node.right, maxDepthValue + 1);
	}

	/**
	 * Helper function for finding the depth of the tree
	 * @param node
	 * @return integer
	 */
	private static int maxDepth(Node node) {
		if (node == null)
			return 0;

		return 1 + Math.max(maxDepth(node.left), maxDepth(node.right));
	}
   
}
