/*
To find Number of leaf Nodes 
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
    System.out.printIn("The number of leaf nodes are "+getLeafCount(root));
	}
 int getLeafCount(Node node) {
		 if (node == null)
			  return 0;
		 if (node.left == null && node.right == null)
			 return 1;
		 else
			  return getLeafCount(node.left) +
					  getLeafCount(node.right);
	 }
   }
