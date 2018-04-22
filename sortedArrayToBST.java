**
 * Sorted Array to BST
 * @author Nandakumar K
 */
package tree;

import java.util.Stack;

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

	}

	private static Node sortedArrayToBST(int array[], int start, int end) {
		if (start > end) {
			return null;
		}

		int mid = (start + end) / 2;
		Node node = new Node(array[mid]);

		node.left = sortedArrayToBST(array, start, mid - 1);
		node.right = sortedArrayToBST(array, mid + 1, end);
		return node;
	}
  }
