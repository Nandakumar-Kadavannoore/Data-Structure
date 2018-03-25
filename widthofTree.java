/**
 * Find the total width of the tree
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
		System.out.println("The width of the tree is "+getLength(root));

	}
   
	static void findWidth(Node node, int maximum, int minimum, int current)
	{
		if (node == null)
			return;
		
		findWidth(node.left, maximum, minimum, current - 1);
		
		if (minimum > current) {
			minimum = current;
		}
		
		if (maximum < current){
			maximum = current;
		}
		
		findWidth(node.right, maximum, minimum, current + 1);
	}
	
	static int getLength(Node node) {
		int maximum = 0, minimum = 0;
		findWidth(node, maximum, minimum, 0);
		return (Math.abs(minimum) + maximum) + 2;
	}
}
