/*
Check if two trees are equal or not
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
    if (identicalTree(root,root))
    System.out.println("The trees are identical");
    else
    System.out.printLn("The trees are not identical");
	}
	 boolean identicalTree(Node treeOne, Node treeTwo) {
		 if (treeOne == null && treeTwo == null)
			 return true;
		 if (treeOne != null && treeTwo != null) {
			 return (
					 (treeOne.data == treeTwo.data) &&
					 identicalTree(treeOne.left, treeTwo.left) &&
					 identicalTree(treeOne.right, treeTwo.right)
					 );
		 }
		 return false;
	 }
   }
