/*
Find the size of tree using a Queue
@author Nandakumar,K
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
		 System.out.println("The Size of the tree is " + size(root));

	}
  
   
	 private static int size(Node root) {
		 if (root == null)
			 return 0;
		 Queue<Node> queue =(Queue<Node>) new LinkedList();
		 queue.offer(root);
		 int count = 1;
		 
		 while (!queue.isEmpty()) {
			 Node temp = queue.poll();
			 if (temp != null) {
				 if (temp.left != null) {
					 count++;
					 queue.offer(temp.left);
				 }
				 if (temp.right != null) {
					 count++;
					 queue.offer(temp.right);
				 }
			 }
		 }
		 return count;
	 }
	 
   }
