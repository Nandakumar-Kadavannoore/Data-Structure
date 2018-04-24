/**
 * Find the number of nodes within given range
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
		System.out.println("The number of nodes of given range is "+getCount(root, 3, 8));

	}


	

	private static int getCount(Node node, int low, int high) {
		
		if (node == null)
			return 0;
		
		if (node.data >= low && node.data <= high) {
			return 1 + getCount(node.left, low, high) +
					getCount(node.right, low, high);
		} else if (node.data < low) {
			return getCount(node.right, low, high);
		} else {
			return getCount(node.left, low, high);
		}
		
	}
}
