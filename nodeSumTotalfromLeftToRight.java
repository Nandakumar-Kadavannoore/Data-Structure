/*
To add Node Sum values from left to right
@author Nandakumar.K
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
    Sum sum = new Sum();
    addSmallerUtil(root, sum);

	}
  
   class Sum {
		 int value = 0;
	 }
	 
	 void addSmallerUtil(Node node, Sum sum) {
		 if (node == null)
			 return;
		 addSmallerUtil(node.left, sum);
		 sum.value += node.data;
		 node.data = sum.value;
		 addSmallerUtil(node.right, sum);
	 }
	 
  
  }
