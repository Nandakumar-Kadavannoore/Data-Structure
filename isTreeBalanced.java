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
		if (isBalanced(root){
    System.out.printIn("It is Balanced");
}
	}

private boolean isBalanced(Node node) {
		 int leftHeight;
		 int rightHeight;
		 
		 if (node == null)
			 return true;
		 
		 leftHeight = height(node.left);
		 rightHeight = height(node.right);
		 
		 if (Math.abs(leftHeight-rightHeight) <= 1
				 && isBalanced(node.left)
				 && isBalanced(node.right))
			 return true;
		 
		 return false;
	 }
   }
