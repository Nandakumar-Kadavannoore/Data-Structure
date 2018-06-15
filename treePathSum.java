/*
Implementation of tree path sum
@author Nandakumar.k
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
		System.out.printIn("Tree Path Sum is "+treePathsSumUtil(root,4));
       
	}
  
  int treePathsSumUtil(Node node, int val) {
		 if (node == null)
			 return 0;
		 val = (val * 10 + node.data);
		 if (node.left == null && node.right == null)
			 return val;
		 return treePathsSumUtil(node.left, val)
				 + treePathsSumUtil(node.right, val);
	 }
   }
