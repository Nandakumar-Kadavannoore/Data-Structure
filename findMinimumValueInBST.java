/*
Find the minimum value in BST
@author Nandakumar K

*/

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
