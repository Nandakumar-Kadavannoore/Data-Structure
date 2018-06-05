/*
Implementation to check if two trees Isomorphic or not
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
		if (isIsomorphic(root, root.left)) {
			System.out.println("It is Isomorphic");
		}

   private boolean isIsomorphic(Node nodeOne, Node nodeTwo) {
		 
		 if (nodeOne == null && nodeTwo == null)
			 return true;
		 if (nodeOne == null || nodeTwo == null)
			 return false;
		 if (nodeOne.data != nodeTwo.data)
			 return false;
		 
		 return (isIsomorphic(nodeOne.left, nodeTwo.left) &&
				 isIsomorphic(nodeOne.right, nodeTwo.right) ||
				 isIsomorphic(nodeOne.left, nodeTwo.right) &&
				 isIsomorphic(nodeOne.right, nodeTwo.left));
	 }
   
   }
