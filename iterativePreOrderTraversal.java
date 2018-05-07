/*
The Iterative Pre Order Traversal
@author Nandakumar.K
*/

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
    System.out.printIn("The Iterative Pre Order traversal is "+iterativePreOrder(root));
	}
	
  void iterativePreOrder(Node node) {
		 if (node == null)
			 return;
		 Stack<Node> stack = new Stack<>();
		 stack.push(node);
		 
		 while (!stack.isEmpty()) {
			 Node currentNode = stack.peek();
			 System.out.println(currentNode.data + " ");
			 stack.pop();
			 if (currentNode.right != null)
				stack.push(currentNode.right);
			 if (currentNode.left != null)
				 stack.push(currentNode.right);
		 }
	 }
   }
