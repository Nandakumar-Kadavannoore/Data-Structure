/**
 * Check if Tree is BST
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
		if (isBST(root)) {
			System.out.println("It is BST");
		} else {
			System.out.println("It is not BST");
		}

	}

	private static boolean isBST(Node root) {
		return isBSTUtil(root, Integer.MAX_VALUE, Integer.MIN_VALUE);
	}

	private static boolean isBSTUtil(Node node, int maxValue, int minValue) {
		if (node == null)
			return true;

		if (node.data > maxValue || node.data < minValue)
			return false;

		return (isBSTUtil(node.left, node.data - 1, minValue) && isBSTUtil(node.right, maxValue, node.data + 1));
	}

	int findMinimumValue(Node root) {
		if (root == null)
			return -1;
		Node temp = root;
		while (temp.left != null) {
			temp = temp.left;
		}
		return temp.data;
	}

}
