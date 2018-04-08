/**
 * Sum of all leaf nodes of the Tree
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
		System.out.println("Sum of all leaf nodes is " + leftLeaveSum(root));
	}

	/**
	 * Helper function to check node is leaf or not
	 * 
	 * @param node
	 * @return
	 */
	private static boolean isLeaf(Node node) {
		if (node == null)
			return false;
		if (node.left == null && node.right == null)
			return true;
		return false;
	}

	/**
	 * Helper function to find sum of all leaf nodes
	 * 
	 * @param node
	 * @return
	 */
	private static int leftLeaveSum(Node node) {
		int result = 0;

		if (node != null) {
			if (isLeaf(node.left))
				result += node.left.data;
			else
				result += leftLeaveSum(node.left);
			result += leftLeaveSum(node.right);
		}
		return result;
	}
}
