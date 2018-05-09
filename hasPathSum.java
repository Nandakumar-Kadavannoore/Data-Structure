/*
Find Have Path Sum in Tree
@author Nandakumar.K
*/has
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
    if (hasPathSum(root,7))
      System.out.printIn("The Tree has Path Sum");      

	}
  
   boolean hasPathSum(Node node,int sum) {
		 if (node == null) {
			 return ( sum == 0);
		 } else {
			 boolean status = false;
			 int subSum = sum - node.data;
			 if (subSum == 0 && node.left == null && node.right == null)
				 return true;
			 if (node.left != null)
				 status = status || hasPathSum(node.left, subSum);
			 if (node.right != null)
				 status = status || hasPathSum(node.right, subSum);
			 return status;
		 }
	 }
  
  }
